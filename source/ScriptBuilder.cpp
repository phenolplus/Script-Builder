#include <iostream>

#include "GraphicShell.h"
#include "Parser.h"
#include "ScriptGen.h"

using namespace std;

int main(int argc, char* argv[])
{
    cout<<"Hello world"<<endl;
    GraphicShell* shell = new GraphicShell();
    // do initialization here

    /** testting goes here **/
    Command* test = new Command();
    test->setCommand("ls");
    test->setArgList("-a -l");
    cout<<test->toString()<<endl;

    cout<<"\n"<<endl;

    InterCode* ic = new InterCode();
    ic->insert(test);

    cout<<ic->toString()<<endl;


    // control given to graphic shell
    shell->init(argc,argv);
    return 0;
}
