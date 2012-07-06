#include "InterCode.h"


#ifndef PARSER_CLASS
#define PARSER_CLASS

class Parser
{
public:
    Parser();

    InterCode* resultCode();
private:
    InterCode* code;

};

#endif
