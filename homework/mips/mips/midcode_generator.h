﻿#pragma once

#include <fstream>
#include <string>
#include "symbol.h"

using namespace std;

enum class Judge {
	BEQ,
	BNE,
	BGE,
	BLT,
	BGT,
	BLE
};

const string kIntType = "int";
const string kCharType = "char";

class MidcodeGenerator {
private:
	ofstream midcode_;

	void PrintBez(int label, string expression);
	void PrintBnz(int label, string expression);

	void PrintBeq(int label, string expression1, string expression2);
	void PrintBne(int label, string expression1, string expression2);
	void PrintBge(int label, string expression1, string expression2);
	void PrintBgt(int label, string expression1, string expression2);
	void PrintBle(int label, string expression1, string expression2);
	void PrintBlt(int label, string expression1, string expression2);
public:
	MidcodeGenerator();
	void OpenMidcodeFile(string fileName);
	void FileClose();

	void PrintFuncDeclare(Symbol* function);
	void PrintVoidFuncDeclare(Symbol* function);
	void PrintReturn(bool isVoid, string value);

	void PrintLabel(int label);
	void PrintGotoLabel(int label);
	void PrintStep(string name1, string name2, string op, int step);

	void PrintBezOrBnz(int label, string expression, bool isFalseBranch);
	void PrintBeqOrBne(int label, string expression, string expression2, Judge judge, bool isFalseBranch);
	void PrintBgeOrBlt(int label, string expression, string expression2, Judge judge, bool isFalseBranch);
	void PrintBgtOrBle(int label, string expression, string expression2, Judge judge, bool isFalseBranch);
	
	void PrintString(int stringNumber);
	void PrintInteger(string number);
	void PrintChar(string c);
	void PrintLineBreak();

	void PrintScanf(string type, string identifier);

	void PrintAssignValue(string name, string arrayIndex, string value);
	void PrintLoadToTempReg(string name, string arrayIndex, int tempRegNumber);

	void PrintPushParameter(string value);
	void PrintCallFunction(string name);
	void PrintAssignReturn(int tempRegCount);

	void PrintRegOpReg(int resultReg, int opReg1, int opReg2, string op);
	void PrintRegOpNumber(int resultReg, int opReg, string number, string op);
	void PrintNumberOpReg(int resultReg, string number, int opReg, string op);
	void PrintNumberOpNumber(int resultReg, string number1, string number2, string op);
};

