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

    char line[4] = "1:\n";

    // go through all statements
    for (int sta=0;sta<size;sta++) {
        content += line;
        content += code[sta]->toString();
        content += "\n\n";
        line[0]++;
    }

    content += "\nInter Code finish\n";
    return content;
}

/** ********** class Loop ********** */
int Loop::getType() {
    return Type::LOOP;
}

// human readable output
string Loop::toString() {
    return string("this is a loop\n");
}

/** ********** class Command ********** */
Command::Command() {
    arg_list = string("");
    command_name = string("");
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

// return type command
int Command::getType() {
    return Type::COMMAND;
}

// set command output type
void Command::setOType(int type) {
    Statement::o_type = type;
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

/** ********** class BuiltIn ********** */
int BuiltIn::getType() {
    return Type::BUILTIN;
}

// human readable output
string BuiltIn::toString() {
    return string("this is a shell built-in\n");
}
