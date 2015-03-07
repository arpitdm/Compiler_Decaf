#include <iostream>
#include <stdio.h>
#include <list>
#include <string>
#include "project.h"
#include <assert.h>
#include "llvm/IR/Verifier.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

using namespace std;
using namespace llvm;

	program_node::program_node(list<field *> *fdl, list<method_node *> *mdl)
	{
		fdl_ = fdl;
		mdl_ = mdl;
	}
	void program_node::print_()
	{
		printf("\n\nCLASS PROGRAM\n");

		list<field *>::iterator it;
		list<field *>::iterator it1;
		it=fdl_->end();
		it1=fdl_->begin();
		if(*it1!=NULL)
		{
			printf("*******************************************************\n");
			printf("FIELDS\n");					
			for(it=--it;it!=fdl_->begin();it--)
			{
				(*it)->print_();
			}
			(*it)->print_();
		}
		
		list<method_node *>::iterator mtr;
		list<method_node *>::iterator mtr1;
		mtr=mdl_->end();
		mtr1=mdl_->begin();
		if(*mtr1!=NULL)
		{
			printf("*******************************************************\n");
			printf("METHODS\n");				
			for(mtr=mdl_->begin();mtr!=mdl_->end();mtr++)
			{
				(*mtr)->print_();
			}
		}
	}
	method_node::method_node(char *type,char *id, list<arg_node *> *agl,block_node *blk)
	{
		id_ = id;
		type_ = type;
		agl_ = agl;
		blk_ = blk;
	}
	void method_node::print_()
	{
		cout << type_ << " " << id_ << " ( ";
		list<arg_node *>::iterator itr;
		itr=agl_->begin();
		if(*itr!=NULL)
		{
			(*itr)->print_();
			for(itr=++itr;itr!=agl_->end();itr++)
			{
				cout << ", ";
				(*itr)->print_();
			}
			cout << " ) " << endl;
		}
		else
		{
			cout << " ) " << endl;
		}
		blk_->print_();
	}	
	arg_node::arg_node(char *type,char *id)
	{
		id_ = id;
		type_ = type;
	}	
	void arg_node::print_()
	{
		cout << type_ << " " << id_;
	}
	block_node::block_node(list<variable_node *> *vrl, list<statement_node *> *stl)
	{	
		vrl_ = vrl;
		stl_ = stl;
	}
	void block_node::print_()
	{
		list<variable_node *>::iterator vtr;
		vtr=vrl_->begin();
		printf("\t\tBLOCK\n");
		if(*vtr!=NULL)
		{
			printf("\t\t\tVARIABLE_LIST\n");
			printf("\t\t\t\t");
			(*vtr)->print_();
			for(vtr=++vtr;vtr!=vrl_->end();vtr++)
			{
				printf("\t\t\t\t");
				(*vtr)->print_();
			}
			cout << endl;
		}
		list<statement_node *>::iterator str;
		str=stl_->begin();
		if(*str!=NULL)
		{
			printf("\t\t\tSTATEMENT_LIST\n");
			printf("\t\t\t\t");
			(*str)->print_();
			for(str=++str;str!=stl_->end();str++)
			{
				printf("\t\t\t\t");
				(*str)->print_();
			}
			cout << endl;
		}
	}
	variable_node::variable_node(char *type, list<id_node *> *idl)
	{
		idl_ = idl;
		type_ = type;
	}
	void variable_node::print_()
	{
		cout << type_ << " ";
		list<id_node *>::iterator dtr;
		dtr=idl_->begin();
		(*dtr)->print_();
		for(dtr=++dtr;dtr!=idl_->end();dtr++)
		{
			cout << ", ";
			(*dtr)->print_();
		}
		cout << endl;
	}
	id_node::id_node(char *id)
	{
		id_ = id;
	}
	void id_node::print_()
	{
		cout << id_;
	}
	statement_node::statement_node()
	{
	}
	void statement_node::print_()				
	{
	}
	assign_stmt::assign_stmt( location_node *lcn, char *assignop, expr_node *exprn)
	{
		lcn_ = lcn;
		assignop_ = assignop;
		exprn_ = exprn;
	}
	void assign_stmt::print_()
	{
		lcn_->print_();
		cout << " " << assignop_ << " ";
		exprn_->print_();
	}
	method_call_stmt::method_call_stmt(method_call_node *medcalnod)
	{
		this->medcalnod=medcalnod;
	}
	void method_call_stmt::print_()
	{
		medcalnod->print_();
		printf("");
	}
	method_call_expr::method_call_expr(method_call_node *medcalnod)
	{
		this->medcalnod=medcalnod;
	}
	void method_call_expr::print_()
	{
		medcalnod->print_();
		printf("");
	}
	if_else_stmt::if_else_stmt(expr_node *exprn,block_node *blkn,else_block_node *ebn)
	{
		exprn_ = exprn;
		blkn_ = blkn;
		ebn_ = ebn;
	}
	void if_else_stmt::print_()
	{
		printf("IF\t");
		exprn_->print_();
		printf("\t\t\t");
		blkn_->print_();
		ebn_->print_();
	}
	for_stmt::for_stmt(char *id,expr_node *exprn1,expr_node *exprn2,block_node *blk)
	{
		id_ = id;
		exprn1_ = exprn1;
		exprn2_ = exprn2;
		blk_ = blk;
	}
	void for_stmt::print_()
	{
		cout << id_ << " ";
		exprn1_->print_();
		exprn2_->print_();
		blk_->print_();
	}
	return_stmt::return_stmt(expr_node *exprn)
	{
		exprn_ = exprn;
	}
	void return_stmt::print_()
	{
		exprn_->print_();
	}
	break_stmt::break_stmt()
	{
	}
	void break_stmt::print_()
	{
		printf("");
	}
	continue_stmt::continue_stmt()
	{
	}
	void continue_stmt::print_()
	{
		printf("");
	}
	literal_node::literal_node()
	{
	}
	int_literal_node::int_literal_node(int iln)
	{	
		iln_ = iln;
	}
	void int_literal_node::print_()
	{
		cout << iln_;
		codegen_();
	}
	Value * int_literal_node::codegen_()
	{
		Value *ret = ConstantInt::get(getGlobalContext(), APInt(32,iln_));
		ret->dump();
		return ret;
	}
	char_literal_node::char_literal_node(char *cln)
	{
		cln_ = cln;
	}
	void char_literal_node::print_()
	{
		cout << cln_ << endl;
	}
	Value * char_literal_node::codegen_()
	{
		int var_ = *cln_;
		Value *ret = ConstantInt::get(getGlobalContext(), APInt(8,var_));
		ret->dump();
		return ret;
	}
	bool_literal_node::bool_literal_node(char *bln)
	{
		bln_ = bln;
	}
	void bool_literal_node::print_()
	{
		cout << bln_ << endl;
	}
	Value * bool_literal_node::codegen_()
	{
		int var_ = *bln_;
		Value *ret = ConstantInt::get(getGlobalContext(), APInt(1,var_));
		ret->dump();
		return ret;
	}
	plus_node::plus_node(expr_node *l,expr_node *r)
	{	
		printf("plus_codegen\n");
		left=l;
		right=r;
	}
	Value* plus_node::codegen_()
	{
		Value *L = left->codegen_();
		Value *R = right->codegen_();
		if (L == 0 || R == 0) return 0;

		Value *ret = Builder.CreateAdd(L, R, "plustmp");
		ret->dump();
		return ret;
	}
	void plus_node::print_()
	{
		left->print_();
		cout << " + ";
		right->print_();
		cout << endl;
		codegen_();
	}
	minus_node::minus_node(expr_node *l,expr_node *r)
	{
		left=l;
		right=r;
	}
	Value* minus_node::codegen_()
	{
		Value *L = left->codegen_();
		Value *R = right->codegen_();
		if (L == 0 || R == 0) return 0;

		Value *ret = Builder.CreateSub(L, R, "minustmp");
		ret->dump();
		return ret;
	}	
	void minus_node::print_()
	{
		left->print_();
		cout << " - ";
		right->print_();
		cout << endl;
		codegen_();
	}
	mult_node::mult_node(expr_node *l,expr_node *r)
	{
		left=l;
		right=r;
	}
	Value* mult_node::codegen_()
	{
		Value *L = left->codegen_();
		Value *R = right->codegen_();
		if (L == 0 || R == 0) return 0;

		Value *ret = Builder.CreateMul(L, R, "multtmp");
		ret->dump();
		return ret;
	}	
	void mult_node::print_()
	{
		left->print_();
		cout << " * ";
		right->print_();
		cout << endl;
		codegen_();
	}
	div_node::div_node(expr_node *l,expr_node *r)
	{
		left=l;
		right=r;
	}
	Value* div_node::codegen_()
	{
		Value *L = left->codegen_();
		Value *R = right->codegen_();
		if (L == 0 || R == 0) return 0;

		Value *ret = Builder.CreateSDiv(L, R, "divtmp");
		ret->dump();
		return ret;

	}	
	void div_node::print_()
	{
		left->print_();
		cout << " / ";
		right->print_();
		cout << endl;
		codegen_();
	}
	percent_node::percent_node(expr_node *l,expr_node *r)
	{
		left=l;
		right=r;
	}
	Value* percent_node::codegen_()
	{
	
	}	
	void percent_node::print_()
	{
		left->print_();
		cout << " % ";
		right->print_();
		cout << endl;
	}
	less_node::less_node(expr_node *l,expr_node *r)
	{
		left=l;
		right=r;
	}
	Value* less_node::codegen_()
	{
		Value *L = left->codegen_();
		Value *R = right->codegen_();
		if (L == 0 || R == 0) return 0;

		Value *ret = Builder.CreateICmp(CmpInst::ICMP_SLT, L, R, "lesstmp");
		ret->dump();
		return ret;

	}	
	void less_node::print_()
	{
		left->print_();
		cout << " < ";
		right->print_();
		cout << endl;
		codegen_();
	}
	greater_node::greater_node(expr_node *l,expr_node *r)
	{
		left=l;
		right=r;
	}
	Value* greater_node::codegen_()
	{
		Value *L = left->codegen_();
		Value *R = right->codegen_();
		if (L == 0 || R == 0) return 0;

		Value *ret = Builder.CreateICmp(CmpInst::ICMP_SGT, L, R, "greatertmp");
		ret->dump();
		return ret;
	}	
	void greater_node::print_()
	{
		left->print_();
		cout << " > ";
		right->print_();
		cout << endl;
		codegen_();
	}
	leq_node::leq_node(expr_node *l,expr_node *r)
	{
		left=l;
		right=r;
	}
	Value* leq_node::codegen_()
	{
		Value *L = left->codegen_();
		Value *R = right->codegen_();
		if (L == 0 || R == 0) return 0;

		Value *ret = Builder.CreateICmp(CmpInst::ICMP_SLE, L, R, "lesseqtmp");
		ret->dump();
		return ret;
	}	
	void leq_node::print_()
	{
		left->print_();
		cout << " <= ";
		right->print_();
		cout << endl;
		codegen_();
	}
	geq_node::geq_node(expr_node *l,expr_node *r)
	{
		left=l;
		right=r;
	}
	Value* geq_node::codegen_()
	{
		Value *L = left->codegen_();
		Value *R = right->codegen_();
		if (L == 0 || R == 0) return 0;

		Value *ret = Builder.CreateICmp(CmpInst::ICMP_SGE, L, R, "greatereqtmp");
		ret->dump();
		return ret;
	}	
	void geq_node::print_()
	{
		left->print_();
		cout << " >= ";
		right->print_();
		cout << endl;
		codegen_();
	}
	eqeq_node::eqeq_node(expr_node *l,expr_node *r)
	{
		left=l;
		right=r;
	}
	Value* eqeq_node::codegen_()
	{
		Value *L = left->codegen_();
		Value *R = right->codegen_();
		if (L == 0 || R == 0) return 0;

		Value *ret = Builder.CreateICmp(CmpInst::ICMP_EQ, L, R, "eqeqtmp");
		ret->dump();
		return ret;
	}	
	void eqeq_node::print_()
	{
		left->print_();
		cout << " == ";
		right->print_();
		cout << endl;
		codegen_();
	}
	neq_node::neq_node(expr_node *l,expr_node *r)
	{
		left=l;
		right=r;
	}
	Value* neq_node::codegen_()
	{
		Value *L = left->codegen_();
		Value *R = right->codegen_();
		if (L == 0 || R == 0) return 0;

		Value *ret = Builder.CreateICmp(CmpInst::ICMP_NE, L, R, "neqtmp");
		ret->dump();
		return ret;
	}	
	void neq_node::print_()
	{
		left->print_();
		cout << " != ";
		right->print_();
		cout << endl;
		codegen_();
	}
	andand_node::andand_node(expr_node *l,expr_node *r)
	{
		left=l;
		right=r;
	}
	Value* andand_node::codegen_()
	{
		Value *L = left->codegen_();
		Value *R = right->codegen_();
		if (L == 0 || R == 0) return 0;

		Value *ret = Builder.CreateAnd(L, R, "orortmp");
		ret->dump();
		return ret;
	}	
	void andand_node::print_()
	{
		left->print_();
		cout << " && ";
		right->print_();
		cout << endl;
		codegen_();
	}
	oror_node::oror_node(expr_node *l,expr_node *r)
	{
		left=l;
		right=r;
	}
	Value* oror_node::codegen_()
	{
		Value *L = left->codegen_();
		Value *R = right->codegen_();
		if (L == 0 || R == 0) return 0;

		Value *ret = Builder.CreateOr(L, R, "orortmp");
		ret->dump();
		return ret;
	}	
	void oror_node::print_()
	{
		left->print_();
		cout << " || ";
		right->print_();
		cout << endl;
		codegen_();
	}
	void uminus_node::print_()
	{
		exprn_->print_();
	}
	Value* uminus_node::codegen_()
	{
	‍‍‍
	}	
	void lognot_node::print_()
	{
		exprn_->print_();
	}
	Value* lognot_node::codegen_()
	{
	
	}	
	void paren_node::print_()
	{
		exprn_->print_();
	}	
	Value* paren_node::codegen_()
	{
	
	}	


	uminus_node::uminus_node(expr_node *exprn)
	{
		exprn_ = exprn; 
	}
	lognot_node::lognot_node(expr_node *exprn)
	{
		exprn_ = exprn;
	}
	paren_node::paren_node(expr_node *exprn)
	{
		exprn_ = exprn;
	}
	expr_node::expr_node()
	{

	}
	dummy_node::dummy_node()
	{

	}
	Value* dummy_node::codegen_()
	{
	
	}	

	void dummy_node::print_()
	{

	}                                    
	void expr_node::print_()
	{
		printf("in expr_node\n");
	}
	
	else_block_node_1::else_block_node_1(char *els,block_node *blk)
	{
		els_ = els;
		blk_ = blk;
	}	
	void else_block_node_1::print_()
	{
		printf("\t\t\t\tELSE\n\t\t\t");
		blk_->print_();
	}	
	else_block_node_2::else_block_node_2()
	{
		printf("");
	}	
	void else_block_node_2::print_()
	{
		printf("");
	}	
	location_node_single::location_node_single(char *id)
	{
		id_ = id;
	}
	void location_node_single::print_()
	{
		cout << id_ << " ";
	}
		
	location_node_expr::location_node_expr(char *id,expr_node *exprn)
	{
		id_ = id;
		exprn_ = exprn;
	}	
	void location_node_expr::print_()
	{
		cout << id_ << "[";
		exprn_->print_();
		cout << "]";
	}
	Value* location_node::codegen_()
	{
	
	}	
	method_call_node_1::method_call_node_1(char *id,list<expr_node *> *exprlst)
	{
		id_=id;
		exprlst_ = exprlst;
	}
	void method_call_node_1::print_()
	{
		cout << id_;
		list<expr_node *>::iterator etr;
		etr=exprlst_->begin();
		if(*etr!=NULL)
		{
			(*etr)->print_();
			for(etr=++etr;etr!=exprlst_->end();etr++)
			{
				(*etr)->print_();
			}
			cout << endl;
		}
	}
	method_call_node_2::method_call_node_2(char *strlit,list<callout_arg_node *> *calargnod)
	{
		strlit_=strlit;
		calargnod_ = calargnod;
	}
	void method_call_node_2::print_()
	{
		cout << strlit_ ;
		list<callout_arg_node *>::iterator ctr;
		ctr=calargnod_->begin();
		if(*ctr!=NULL)
		{
			(*ctr)->print_();
			for(ctr=++ctr;ctr!=calargnod_->end();ctr++)
			{
				cout << ", ";
				(*ctr)->print_();
			}
			cout << " ) " << endl;
		}
	}
	Value* method_call_expr::codegen_()
	{
	
	}	
	callout_expr_arg_node::callout_expr_arg_node( expr_node *exprn)
	{
		exprn_ = exprn;
	}	
	callout_strlit_arg_node::callout_strlit_arg_node( char *strlit)
	{	
		strlit_ = strlit;
	}
	void callout_expr_arg_node::print_()
	{
		exprn_->print_();
	}	
	void callout_strlit_arg_node::print_()
	{
		cout << strlit_;
	}	
	field_node::field_node(){}
	field_node_single::field_node_single(char *id)
	{
		id_ = id;
		num_ = -1;
		
	}
	void field_node_single::print_()
	{
		cout << id_ << endl;
	}
	Value *field_node_single::codegen_()
	{
		AllocaInst *Alloca = Builder.CreateAlloca( Type::getInt32Ty(getGlobalContext()), 0, id_ );
		Value *V = Alloca;
		return Alloca;
	}
	field_node_array::field_node_array(char *id, int num)
	{
		id_ = id;
		num_ = num;
		
	}
	void field_node_array::print_()
	{
		cout << id_ << "[" << num_ << "]" << endl;	
	}
	Value *field_node_array::codegen_()
	{
		
	}
	field::field(char *type, list<field_node *> *fdl)
	{
		type_ = type;
		fdl_ = fdl;
	}
	void field::print_()
	{
		cout << type_ << " ";
		list<field_node *>::iterator itr;
		for(itr=fdl_->begin(); itr!=fdl_->end(); ++itr)
			(*itr)->print_();

		codegen_();
	cout << endl;
	}	
	Value *field::codegen_()
	{
		list<field_node *>::iterator itr;
		for(itr=fdl_->begin(); itr!=fdl_->end(); ++itr)
		{
			Value *temp = (*itr)->codegen_();
			temp->dump();
			return temp;
		}
	}
