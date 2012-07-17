#include <string>
#include <vector>


#ifndef INTERMEDIATE_CODE_CLASS
#define INTERMEDIATE_CODE_CLASS

using namespace std;

class Type
{
    public :
    // type of input & output
    static const int NONE       = 0; // normal statement
    static const int ARGUMENT   = 1; // the output is passed as argument to next statement
    static const int PIPELINE   = 2; // the output is pipelined to next statement
    static const int REDIRECT_C = 3; // this is the ">" operator in bash
    static const int REDIRECT_P = 4; // this is the ">>" operator in bash
    static const int VAR_ASSIGN = 5; // the output will be assigned to a variable


    // type of statement
    static const int COMMAND = 0; // a command statement
    static const int LOOP    = 1; // a loop structure
    static const int BUILTIN = 2; // a shell built-in
};

class Statement // virtual class for statements (bash commands)
{
public :
    // io type modifier
    int o_type;

    // call this fuction to identify type of statement
    virtual int getType() = 0;

    // for human reading
    virtual string toString() = 0;

private :

};

class InterCode // IC class
{
public:
    // contructor
    InterCode();
    ~InterCode();


    void insert(Statement*); // insert new statement
    bool insert(Statement*,int); // insert new statement at certain entry

    void remove();
    bool remove(int);

    Statement* readCurrent(); // returns the current statement
    Statement* readStatement(int); // returns a specific statement


    string toString(); // human readable output

private:
    int size,cursor; // size of IC

    vector< int > typeEntry; // list of statement types
    vector< int > loopEntry; // list of loop locations

    vector< Statement* > code; // list of statements
};

class Loop : public Statement // control statments (if, while, for...)
{
public :
    // constructor
    Loop();
    ~Loop();

    // loop type identifiers
    static const int WHILE = 0;
    static const int FOR   = 1;
    static const int IFEL  = 2;

    // return type "loop"
    int getType();

    // for human reading
    string toString();
private :
    int loop_type;
    InterCode* inner_statement; // components of the loop

};

class Command : public Statement // datapath & commands (ls, cd, grep...)
{
public :
    // constructor
    Command();
    ~Command();

    void setCommand(string);
    void setArgList(string);

    void setOType(int);

    // return type "command"
    int getType();

    // for human reading
    string toString();
private :
    string command_name; // name of command
    string arg_list; // extra arguments


};

class BuiltIn : public Statement // built-in utilities (variable, expression, enviroment...)
{
    public :
    // return type "built-in"
    int getType();

    // for human reading
    string toString();
    private :

};



#endif
