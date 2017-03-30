OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o ArbIOParInt.o ParInt.o
	g++ -o program.exe program.o ArbIOParInt.o ParInt.o
	rm *.o

program.o: program.cc PRO2Excepcio.hh ArbIOParInt.hh ParInt.hh
	g++ -c program.cc $(OPCIONS)

ParInt.o: ParInt.cc ParInt.hh
	g++ -c ParInt.cc $(OPCIONS)

ArbIOParInt.o: ArbIOParInt.cc PRO2Excepcio.hh Arbre.hh ArbIOParInt.hh ParInt.hh
	g++ -c ArbIOParInt.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
