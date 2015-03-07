all:
	flex project.l
	bison -d project.y
	g++ project.cpp -c `llvm-config --cxxflags --ldflags --system-libs --libs core`
	g++ project.tab.c -c `llvm-config --cxxflags --ldflags --system-libs --libs core`
	g++ lex.yy.c -c `llvm-config --cxxflags --ldflags --system-libs --libs core`
	g++ lex.yy.o project.tab.o project.o -o run -lfl `llvm-config --cxxflags --ldflags --system-libs --libs core`
	read file; \
	./run < $$file
clean:
	rm lex.yy.* project.tab.* run project.o 
