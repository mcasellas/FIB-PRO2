OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o 
	g++ -o program.exe program.o
	rm *.o

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
