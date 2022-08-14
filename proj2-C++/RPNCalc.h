/*
 *  RPNCalc.h
 *  Brandon Shih
 *  3/8/22
 *
 *  COMP 15 Proj2 RPNCalc
 *
 *  This class is a calculator in reverse polish notation as well as a
 *  mini programming language. It contains functions to compute operations,
 *  perform if statements, store information in files or rstrings, and
 *  execute the rstrings.
 */

#ifndef __RPNCALC_H__
#define __RPNCALC_H__

#include "Datum.h"
#include "DatumStack.h"

class RPNCalc {
    public:
        RPNCalc();
        ~RPNCalc();
        void run();
    private:
        DatumStack DS;
        void intCMD(int &I);
        void fBoolCMD();
        void tBoolCMD();
        void notCMD();
        void printCMD();
        void clearCMD();
        void dropCMD();
        void dupCMD();
        void swapCMD();
        void operCMD(std::string cmd);
        void ineqCMD(std::string cmd);
        void rstringCMD(std::string s);
        void execCMD();
        void fileCMD();
        void ifCMD();
        void showStackCMD();
        bool gotInt(std::string s, int *resultp);
        bool gotOp(std::string cmd);
        bool gotEq(std::string cmd);
        void runHelper(std::istream &ss);
        std::string parseRString(std::istream &input);
};

#endif