#include <string>
#include <vector>


#ifndef INTERMEDIATE_CODE_CLASS
#define INTERMEDIATE_CODE_CLASS

using namespace std;

class InterCode
{

};


class Statement
{
public :
    Statement();
    ~Statement();

    int i_type,o_type;

    void toString();

private :

};

class Loop : public Statement
{
public :

private :


};

class Command : public Statement
{
public :

private :


};



#endif
