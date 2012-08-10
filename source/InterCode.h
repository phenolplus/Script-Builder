#include <string>
#include <vector>


#ifndef INTERMEDIATE_CODE_CLASS
#define INTERMEDIATE_CODE_CLASS

using namespace std;

class Type // wrapper and constance class
{
    public :
	// types of output
	static const int NONE       = 0; // normal statement
	static const int ARGUMENT   = 1; // the output is passed as argument to next statement
	static const int PIPELINE   = 2; // the output is pipelined to next statement
	static const int REDIRECT_C = 3; // this is the ">" operator in bash
	static const int REDIRECT_P = 4; // this is the ">>" operator in bash
	static const int VAR_ASSIGN = 5; // the output will be assigned to a variable


	// type of statement
	static const int COMMAND = 0; // a command statement
	static const int LOOP    = 1; // a loop structure
	static const int EXPATOM = 2; // an single expression
	static const int EXPRESSION = 3; // a list of expressions

	// convert type number to human readable string
	static string iotypeString(int t) {
	    switch (t) {
		case 0:{
			   return string("normanl");
		       }
		case 1:{
			   return string("pass as argument");
		       }
		case 2:{
			   return string("pipelined to next command");
		       }
		case 3:{
			   return string("redirected to file (cover)");
		       }
		case 4:{
			   return string("redirected to file (padding)");
		       }
		case 5:{
			   return string("assigned to variable");
		       }
		default:{
			    return string("error parsing");
			}
	    }
	}

	static string stypeString(int t) {
	    switch (t){
		case 0:{
			   return string("command");
		       }
		case 1:{
			   return string("loop");
		       }
		case 2:{
			   return string("expression atom");
		       }
		case 3:{
			   return string("expression list");
		       }
		default:{
			    return string("error parsing");
			}
	    }
	}
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


	int insert(Statement*); // insert new statement
	bool insert(Statement*,int); // insert new statement at certain entry

	bool remove(int); // remove a statement

	Statement* readCurrent(); // returns the current statement
	Statement* readStatement(int); // returns a specific statement


	string toString(); // human readable output

    private:
	int size,cursor; // size of IC

	vector< Statement* > code; // list of statements

};

class Command : public Statement // datapath & commands (ls, cd, grep...)
{
    public :
	// constructor
	Command();
	~Command();

	//setters
	void setCommand(string);
	void setArgList(string);
	void setOutName(string);

	void setOType(int);

	//getters
	string getCommand();
	string getOutName();
	int getOType();

	// return type "command"
	int getType();

	// for human reading
	string toString();
    private :
	string command_name; // name of command
	string arg_list; // extra arguments
	string out_name; // name of output container (empty for nothing)


};

class ExpressionAtom : public Statement // an expression atom
{
    public :
	// constructor
	ExpressionAtom();
	~ExpressionAtom();


	//setters
	

	//getters
	

	// return type "atom"
	int getType();

	// for human reading
	string toString();
    private :
	string operand_l, operand_r; // name of operands
	bool unary; // true if it is an unary operationi
	int op_type;
};

class Expression : public Statement
{
    public :
	// constructor
	Expression();
	~Expression();

	// return type "expression"
	int getType();

	// for human reading
	string toString();
    private :
	vector<Expression*> chainList;
	vector<ExpressionAtom*> atomList;
	bool bindingType;

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
	Expression* criteria; // loop invariant
	InterCode* inner_statement; // components of the loop

};



#endif
