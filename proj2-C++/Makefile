###
### Makefile for CalcYouLater Project
### CalcYouLater is an RPN calculator
###
### Author:  YOUR NAME HERE

# this is needed to have make follow symlinks in dependency lists -- please keep
# it! (but remove this comment)
MAKEFLAGS += -L 
CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

CalcYouLater: main.o DatumStack.o Datum.o RPNCalc.o
	${CXX} ${CXXFLAGS} -o CalcYouLater main.o DatumStack.o Datum.o RPNCalc.o

test: test.o DatumStack.o Datum.o RPNCalc.o
	${CXX} ${CXXFLAGS} -o test test.o DatumStack.o Datum.o RPNCalc.o

test.o: test.cpp RPNCalc.h DatumStack.h Datum.h
	${CXX} ${CXXFLAGS} -o test.o -c test.cpp

parser.o: parser.cpp
	${CXX} ${CXXFLAGS} -o parser.o -c parser.cpp

main.o: main.cpp RPNCalc.h DatumStack.h Datum.h
	${CXX} ${CXXFLAGS} -o main.o -c main.cpp

DatumStack.o: DatumStack.cpp DatumStack.h Datum.h
	${CXX} ${CXXFLAGS} -o DatumStack.o -c DatumStack.cpp

RPNCalc.o: RPNCalc.cpp RPNCalc.h DatumStack.h Datum.h
	${CXX} ${CXXFLAGS} -o RPNCalc.o -c RPNCalc.cpp

unit_test: unit_test_driver.o DatumStack.o Datum.o RPNCalc.o
	${CXX} ${CXXFLAGS} unit_test_driver.o DatumStack.o Datum.o RPNCalc.o

provide: 
	provide comp15 proj2_calcyoulater 
			DatumStack.h \
			DatumStack.cpp \
			RPNCalc.h \
			RPNCalc.cpp \
			main.cpp \
			Makefile \
			parser.cpp \
			unit_tests.h README

%.cylc:  %.cyl
	./cylc $^
