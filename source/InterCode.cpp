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
}

Command::~Command() {

}

void Command::setCommand(string cmd) {
    Command::command_name = cmd;
}

void Command::setArgList(string arg) {
    Command::arg_list = arg;
}


int Command::getType() {
    return Type::COMMAND;
}

void Command::

// human readable output
string Command::toString() {
    return string("this is a command\n");
}

/* ********** class BuiltIn ********** */
int BuiltIn::getType() {
    return Type::BUILTIN;
}

// human readable output
string BuiltIn::toString() {
    return string("this is a shell built-in\n");
}
