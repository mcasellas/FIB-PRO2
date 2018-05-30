OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o PilaIOEstudiant.o Estudiant.o
	g++ -o program.exe program.o Estudiant.o Estudiant.o

ParInt.o:  Estudiant.cc Estudiant.hh 
	g++ -c ParInt.cc $(OPCIONS)

PilaIOParInt.o:  PilaIOEstudiant.cc PilaIOEstudiant.hh Estudiant.hh 
	g++ -c PilaIOParInt.cc $(OPCIONS)

program.o: program.cc PilaIOEstudiant.hh Estudiant.hh 
	g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
