#include <iostream>


#include "InterCode.h"

using namespace std;

/* ********** class Loop ********** */
int Loop::getType() {
    return Type::LOOP;
}

// human readable output
string Loop::toString() {
    return string("this is a loop\n");
}

/* ********** class Command ********** */
Command::Command() {
    Command::arg_list = string("");
    Command::command_name = string("");
    Statement::o_type = 0;
}

Command::~Command() {

}

// set up command name
void Command::setCommand(string cmd) {
    Command::command_name = cmd;
}

// set up argument list
void Command::setArgList(string arg) {
    Command::arg_list = arg;
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
    content += Type::typeString(Statement::o_type);
    return content;
}

/* ********** class BuiltIn ********** */
int BuiltIn::getType() {
    return Type::BUILTIN;
}

// human readable output
string BuiltIn::toString() {
    return string("this is a shell built-in\n");
}
