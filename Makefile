CXX=g++
LD=g++
CFLAGS=-Wall -pedantic -std=c++14 -g
OBJS=main.o CUnit.o CGame.o CCharacter.o CBenefit.o

all: main.o CUnit.o CCharacter.o CBenefit.o CGame.o
	$(LD) -o Semestral_work $(OBJS) -lncurses

main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp
CUnit.o: CUnit.cpp CUnit.h
	$(CXX) $(CFLAGS) -c CUnit.cpp
CCharacter.o: CCharacter.cpp CCharacter.h
	$(CXX) $(CFLAGS) -c CCharacter.cpp
CBenefit.o: CBenefit.cpp CBenefit.h
	$(CXX) $(CFLAGS) -c CBenefit.cpp
CGame.o: CGame.cpp CGame.h
	$(CXX) $(CFLAGS) -c CGame.cpp

clean:
	rm -f acme_program main.o CUnit.o CCharacter.o CBenefit.o CGame.o

