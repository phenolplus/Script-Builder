#include <iostream>

#include "GraphicShell.h"
#include "Parser.h"
#include "ScriptGen.h"

int main(int argc, char* argv[])
{
    std::cout<<"Hello world"<<std::endl;
    GraphicShell* shell = new GraphicShell(argc,argv);

    return 0;
}
