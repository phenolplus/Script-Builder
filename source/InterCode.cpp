#include <iostream>


#include "InterCode.h"

using namespace std;

InterCode::InterCode();
InterCode::~InterCode();

void InterCode::addCommand();
void InterCode::addLoop();
void InterCode::addPipe();

void InterCode::addVar();

void InterCode::toFile();

void InterCode::printStat();

InterCode::command::command(char type, char arg1, char arg2){
    clist[0] = type;
    clist[1] = arg1;
    clist[2] = arg2;
}
