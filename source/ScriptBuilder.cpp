#include <iostream>

#include "GraphicShell.h"
#include "Parser.h"
#include "ScriptGen.h"

int main(int argc, char* argv[])
{
    std::cout<<"Hello world"<<std::endl;
    GraphicShell* shell = new GraphicShell();
    // do initialization here

    // control given to graphic shell
    shell->init(argc,argv);
    return 0;
}
