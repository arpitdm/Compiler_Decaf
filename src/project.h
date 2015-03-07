#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <list>
#include "llvm/IR/Verifier.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

using namespace std;
using namespace llvm;

static Module *TheModule;
static IRBuilder<> Builder(getGlobalContext());
static std::map<std::string, Value*> NamedValues;

// EXPRESSION NODES

class expr_node
{
	public:
		expr_node();
		virtual void print_()=0;
		virtual Value* codegen_() = 0;
};

class dummy_node : public expr_node
{
        public:
                dummy_node();
                void print_();
		virtual Value* codegen_();
};

class plus_node : public expr_node
{
	protected:
		expr_node *left;
		expr_node *right;
		int value;
	public:
		plus_node(expr_node *l,expr_node *r);
		void print_();
		virtual Value* codegen_();
		
};

class minus_node : public expr_node
{
	protected:
		expr_node *left;
		expr_node *right;
		int value;
	public:
		minus_node(expr_node *l,expr_node *r);
		void print_();
		virtual Value* codegen_();
};

class mult_node : public expr_node
{
	protected:
		expr_node *left;
		expr_node *right;
		int value;
	public:
		mult_node(expr_node *l,expr_node *r);
		void print_();
		virtual Value* codegen_();
};

class div_node : public expr_node
{
	protected:
		expr_node *left;
		expr_node *right;
		int value;
	public:
		div_node(expr_node *l,expr_node *r);
		void print_();
		virtual Value* codegen_();
};

class percent_node : public expr_node
{
	protected:
		expr_node *left;
		expr_node *right;
		int value;
	public:
		percent_node(expr_node *l,expr_node *r);
		void print_();
		virtual Value* codegen_();
};

class less_node : public expr_node
{
	protected:
		expr_node *left;
		expr_node *right;
		int value;
	public:
		less_node(expr_node *l,expr_node *r);
		void print_();
		virtual Value* codegen_();
};

class greater_node : public expr_node
{
	protected:
		expr_node *left;
		expr_node *right;
		int value;
	public:
		greater_node(expr_node *l,expr_node *r);
		void print_();
		virtual Value* codegen_();
};

class geq_node : public expr_node
{
	protected:
		expr_node *left;
		expr_node *right;
		int value;
	public:
		geq_node(expr_node *l,expr_node *r);
		void print_();
		virtual Value* codegen_();
};

class leq_node : public expr_node
{
	protected:
		expr_node *left;
		expr_node *right;
		int value;
	public:
		leq_node(expr_node *l,expr_node *r);
		void print_();
		virtual Value* codegen_();
};

class eqeq_node : public expr_node
{
	protected:
		expr_node *left;
		expr_node *right;
		int value;
	public:
		eqeq_node(expr_node *l,expr_node *r);
		void print_();
		virtual Value* codegen_();
};

class neq_node : public expr_node
{
	protected:
		expr_node *left;
		expr_node *right;
		int value;
	public:
		neq_node(expr_node *l,expr_node *r);
		void print_();
		virtual Value* codegen_();
};

class andand_node : public expr_node
{
	protected:
		expr_node *left;
		expr_node *right;
		int value;
	public:
		andand_node(expr_node *l,expr_node *r);
		void print_();
		virtual Value* codegen_();
};

class oror_node : public expr_node
{
	protected:
		expr_node *left;
		expr_node *right;
		int value;
	public:
		oror_node(expr_node *l,expr_node *r);
		void print_();
		virtual Value* codegen_();
};

class uminus_node : public expr_node
{
	protected:
		expr_node *exprn_;
	public:
		uminus_node(expr_node *exprn);
		void print_();
		virtual Value* codegen_();
};

class lognot_node : public expr_node
{
	protected:
		expr_node *exprn_;
	public:
		lognot_node(expr_node *exprn);
		void print_();
		virtual Value* codegen_();
};

class paren_node : public expr_node
{
	protected:
		expr_node *exprn_;
	public:
		paren_node(expr_node *exprn);
		void print_();
		virtual Value* codegen_();
};

// LITERAL NODES

class literal_node : public expr_node
{
	public:
		literal_node();
		virtual void print_()=0;
//		virtual Value * codegen_()=0;
};

class int_literal_node : public literal_node
{
	protected:
		int iln_;
	public:
		int_literal_node(int iln);
		void print_();
		Value * codegen_();
};

class char_literal_node : public literal_node
{
	protected:
		char *cln_;
	public:
		char_literal_node(char *cln);
		void print_();
		Value * codegen_();
};

class bool_literal_node : public literal_node
{
	protected:
		char *bln_;
	public:
		bool_literal_node(char *bln);
		void print_();
		Value * codegen_();
};

// IDENTIFIER NODE

class id_node
{
	protected:
		char *id_;
	public:
		id_node(char *id);
		void print_();					
};

// VARIABLE NODE

class variable_node
{
	protected:
		list<id_node *> *idl_;
		char *type_;
	public:	
		variable_node(char *type, list<id_node *> *idl);
		void print_();						
};

// LOCATION NODES

class location_node : public expr_node
{
	public:
		virtual void print_()=0;
		virtual Value* codegen_();
};

class location_node_single : public location_node
{
	protected:
		char *id_;
	public:
		location_node_single(char *id);
		void print_();
};

class location_node_expr : public location_node
{
	protected:
		char *id_;
		expr_node *exprn_;
	public:
		location_node_expr(char *id,expr_node *exprn);
		void print_();
};

// STATEMENT NODE

class statement_node
{	
	public:
		statement_node();
		virtual void print_()=0;
};

// BLOCK NODES

class block_node : public statement_node		
{
	protected:
		list<variable_node *> *vrl_;
		list<statement_node *> *stl_;
	public:
		block_node(list<variable_node *> *vrl,list<statement_node *> *stl);
		void print_();
};

class else_block_node
{
	public:
		virtual void print_()=0;
};

class else_block_node_1 : public else_block_node
{
	protected:
		char *els_;
		block_node *blk_;
	public:
		else_block_node_1(char *els,block_node *blk);
		void print_();
};

class else_block_node_2 : public else_block_node
{
	public:
		else_block_node_2();
		void print_();
};

class continue_stmt : public statement_node
{
	public:
		continue_stmt();
		void print_();
};

class break_stmt : public statement_node
{
	public:
		break_stmt();
		void print_();
};

class return_stmt : public statement_node
{
	protected:
		expr_node *exprn_;
	public:
		return_stmt(expr_node *exprn);
		void print_();
};

class for_stmt : public statement_node
{
	protected:
		char *id_;
		expr_node *exprn1_;
		expr_node *exprn2_;
		block_node *blk_;
	public:
		for_stmt(char *id,expr_node *exprn1,expr_node *exprn2,block_node *blk);
		void print_();
};

class if_else_stmt : public statement_node
{
	protected:
		expr_node *exprn_;
		block_node *blkn_;
		else_block_node *ebn_;
	public:
		if_else_stmt(expr_node *exprn,block_node *blkn,else_block_node *ebn);
		void print_();
};


class assign_stmt : public statement_node
{
	protected:
		location_node *lcn_;
		char *assignop_;
		expr_node *exprn_;
	public:
		assign_stmt(location_node *lcn,char *assignop,expr_node *exprn);
		void print_();
};

class arg_node
{
	public:
		char *type_;
		char *id_;
		arg_node(char *type,char *id);
		void print_();
};

class method_node
{
	protected:
		char *type_;
		char *id_;
		list<arg_node *> *agl_;
		block_node *blk_;
	public:
		method_node(char *type,char *id, list<arg_node *> *agl, block_node *blk);
		void print_();

};

class field_node
{
	public:
		char *id_;
		int num_;	
		field_node();
		virtual void print_()=0;
		virtual Value *codegen_()=0;
		void evaluate();
};

class field_node_single : public field_node
{
//	protected:
//		char *id_;
//		int num_;
	public:
		field_node_single(char *id);
		Value *codegen_();
		void print_();
};

class field_node_array : public field_node
{
//	protected:
//		char *id_;
//		int num_;
	public:
		field_node_array(char *id, int num);
		Value *codegen_();
		void print_();
};


class field
{
	protected:
		char *type_;
		list<field_node *> *fdl_;
	public:
		field(char *type, list<field_node *> *fdl);
		Value *codegen_();
		void print_();
};

class program_node
{
	protected:
		list<method_node *> *mdl_;
		list<field *> *fdl_;
	public:
		program_node(list<field *> *fdl, list<method_node *> *mdl);
		void print_();
		void evaluate();
};

class callout_arg_node
{
	public:
		virtual void print_()=0;
};

class callout_expr_arg_node : public callout_arg_node
{
	protected:
		expr_node *exprn_;
	public:
		callout_expr_arg_node(expr_node *exprn);
		void print_();
};

class callout_strlit_arg_node : public callout_arg_node
{
	protected:
		char *strlit_;
	public:
		callout_strlit_arg_node(char *strlit);
		void print_();
};

class method_call_node
{
	public:
		virtual void print_()=0;
};

class method_call_node_1: public method_call_node
{
	protected:
		char *id_;
		list<expr_node *> *exprlst_;
	public:
		method_call_node_1(char *id,list<expr_node *> *exprlst);
		void print_();
};

class method_call_node_2: public method_call_node
{
	protected:
		char *strlit_;
		list<callout_arg_node *> *calargnod_;
	public:
		method_call_node_2(char *strlit,list<callout_arg_node *> *calargnod);
		void print_();
};

class method_call_expr : public expr_node
{
	public:
		method_call_node *medcalnod;
		method_call_expr(method_call_node *medcalnod);
		void print_();
		virtual Value* codegen_();
};

class method_call_stmt : public statement_node
{
	public:
		method_call_node *medcalnod;
		method_call_stmt(method_call_node *medcalnod);
		void print_();
};

extern program_node *root;
