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
	static const int EXPRESSION = 2; // a list of expressions

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
			   return string("expression");
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

class Expression : public Statement
{
    public :
	// constructor
	Expression();
	Expression(bool);
	~Expression();

	// setters
	void setIsANDBinded(bool);

	void pushItem(Expression*);
	bool pushItem(Expression*,int);

	// getters
	bool isANDBinded();
	Expression* getItemAt(int);
	int getDepth();

	// return type "expression"
	int getType();

	// for human reading
	string toString();
	
    protected :
	int depth;

    private :
	vector<Expression*> chainList;
	bool bindingType;
	int size;
};


class ExpressionAtom : public Expression // an expression atom
{
    public :
	// constructor
	ExpressionAtom();
	ExpressionAtom(string,int);
	ExpressionAtom(string,string,int);
	~ExpressionAtom();

	//setters
	bool setOperandL(string,int);
	bool setOperandR(string);
	bool setOperand(string,string,int);

	//getters
	string getOperandL();
	string getOperandR();
	int getOperator();

	bool isUnary();

    private :
	string operand_l, operand_r; // name of operands
	bool unary; // true if it is an unary operationi
	int op_type; // type of operator
};


class Loop : public Statement // control statments (if, while, for...)
{
    public :
	// constructor
	Loop();
	Loop(int);
	~Loop();

	// loop type identifiers
	static const int WHILE = 0;
	static const int FOR   = 1;
	static const int IFEL  = 2;

	// setters
	void setLoopType(int);
	void assignInvariant(Expression*);

	// return type "loop"
	int getType();

	// for human reading
	string toString();

	// members
	Expression* criteria; // loop invariant
	InterCode* inner_statement; // components of the loop
    
    private :
	int loop_type;

};

class ForLoop : public Loop
{
    public :
	// constructor
	ForLoop();
	ForLoop(vector<string>);
	~ForLoop();

	// setters
	void addToList(string);
	bool removeFromList(string);
	bool removeFromList(int);
	
	void clearList();

	// getters
	int lengthOfList();
	string getItem(int);

    private :
	vector<string> varInList;
};

#endif
