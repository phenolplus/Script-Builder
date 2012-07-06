#include <string>
#include <vector>


#ifndef INTERMEDIATE_CODE_CLASS
#define INTERMEDIATE_CODE_CLASS

using namespace std;

class InterCode
{
public:
    InterCode();
    ~InterCode();

    void addCommand();
    void addLoop();
    void addPipe();

    void addVar();

    void toFile();

    void printStat();


private:
    int size;
    class command
    {
    public:
        command(char,char,char);
    private:
        char clist[3];
    };
};


#endif
