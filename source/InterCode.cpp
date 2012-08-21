#include <iostream>

#include "InterCode.h"

using namespace std;
/** ********** class InterCode ********** */
InterCode::InterCode() {
    cursor = 0;
    size = 0;
}

InterCode::~InterCode() {
    for(int path=0;path<size;path++) {
	// clean up all pointers
	delete [] (code[path]);
    }
}

// inserts a new statement at the end of the list
int InterCode::insert(Statement* next_statement) {
    // add new statement
    code.push_back(next_statement);
    size = code.size();

    cursor = size - 1;

    // returns the location of the entered code
    return (cursor); 
}

bool InterCode::insert(Statement* next_statement, int position) {
    // verify position
    if(position >= size) {
	// failure, out off range
	return false;
    }

    // insert statement
    code.insert(code.begin()+position, next_statement);
    size = code.size();

    cursor = position;
    // done
    return true;
}

bool InterCode::remove(int position) {
    if(position >= size) {
	return false;
    }
    delete [] code[position];
    code.erase(code.begin()+position);
    return true;
}

Statement* InterCode::readCurrent() {
    return code[cursor];
}

Statement* InterCode::readStatement(int number) {
    if(number<size){
	return code[number];
    } else {
	return 0;
    }
}

string InterCode::toString() {
    // title
    string content = "Inter Code contents: \n";

    // go through all statements
    for (int sta=0;sta<size;sta++) {
	content += code[sta]->toString();
	content += "\n";
    }

    content += "\nInter Code finish\n";
    return content;
}

/** ********** class Command ********** */
Command::Command() {
    arg_list = string("");
    command_name = string("");
    out_name = string("");

    Statement::o_type = 0;
}

Command::~Command() {

}

// set up command name
void Command::setCommand(string cmd) {
    command_name = cmd;
}

// set up argument list
void Command::setArgList(string arg) {
    arg_list = arg;
}

// set uo name of output container
void Command::setOutName(string name) {
    out_name = name;
}

// set command output type
void Command::setOType(int type) {
    Statement::o_type = type;
}

// get full command
string Command::getCommand() {
    return (command_name + string(" ") + arg_list);
}

// get name of output container
string Command::getOutName() {
    return out_name;
}

int Command::getOType() {
    return Statement::o_type;
}

// return type command
int Command::getType() {
    return Type::COMMAND;
}


// human readable output
string Command::toString() {
    string content = "type = command : ";
    content += (Command::command_name + " ");
    content += Command::arg_list;
    content += " ==> output type is ";
    content += Type::iotypeString(Statement::o_type);
    return content;
}

/** ********** class ExpressionAtom ********** */
Expression::Expression() {

}

Expression::Expression(bool isAND) {

}

Expression::~Expression() {

}

void Expression::setIsANDBinded(bool is) {

}

void Expression::pushItem(Expression* expin) {

}

bool Expression::pushItem(Expression* expin, int at) {
    return false;
}

bool Expression::isANDBinded() {
    return bindingType;
}

Expression* Expression::getItemAt(int at) {
    return NULL;
}

int Expression::getDepth() {
    return 0;
}

int Expression::getType() {
    return Type::EXPRESSION;
}

string Expression::toString() {

    string content = "type = expression\n";
    content += " ==> output type is ";
    content += Type::iotypeString(Statement::o_type);

    return content;
}

/** ********** class ExpressionAtom ********** */
ExpressionAtom::ExpressionAtom() {

}

ExpressionAtom::ExpressionAtom(string Lop,int option) {

}

ExpressionAtom::ExpressionAtom(string Lop,string Rop,int option) {

}

ExpressionAtom::~ExpressionAtom() {

}

bool ExpressionAtom::setOperandL(string Lop,int option) {
    return false;
}

bool ExpressionAtom::setOperandR(string Rop) {
    return false;
}

bool ExpressionAtom::setOperand(string Lop, string Rop, int option) {
    return false;
}

string ExpressionAtom::getOperandL() {
    return operand_l;
}

string ExpressionAtom::getOperandR() {
    return operand_r;
}

int ExpressionAtom::getOperator() {
    return op_type;
}

bool ExpressionAtom::isUnary() {
    return unary;
}

/** ********** class Loop ********** */
Loop::Loop() {

}

Loop::Loop(int) {

}

Loop::~Loop() {

}

void Loop::setLoopType(int) {

}

void Loop::assignInvariant(Expression* invar) {

}

int Loop::getType() {
    return Type::LOOP;
}

// human readable output
string Loop::toString() {
    return string("this is a loop\n");
}

/** ********** class ForLoop ********** */
ForLoop::ForLoop() {

}

ForLoop::ForLoop(vector<string> delist) {

}

ForLoop::~ForLoop() {

}

void ForLoop::addToList(string item) {

}

bool ForLoop::removeFromList(string item) {
   return false;
}

bool ForLoop::removeFromList(int index) {
    return false;
}

void ForLoop::clearList() {

}

int ForLoop::lengthOfList() {
    return 0;
}

string ForLoop::getItem(int index) {
    return string("");
}
