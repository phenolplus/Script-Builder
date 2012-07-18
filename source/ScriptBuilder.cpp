#include <iostream>

#include "GraphicShell.h"
#include "Parser.h"
#include "ScriptGen.h"

int main(int argc, char* argv[])
{
    std::cout<<"Hello world"<<std::endl;
    GraphicShell* shell = new GraphicShell();
    // do initialization here

    Command* test = new Command();
    test->setCommand("ls");
    test->setArgList("-a -l");
    std::cout<<test->toString()<<std::endl;

    // control given to graphic shell
    shell->init(argc,argv);
    return 0;
}
