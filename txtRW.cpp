#include<iostream>
#include<fstream>
#include<string>
#include"txtRW_class.hpp"
using namespace std;

int main()
{
    txtRW txtRW;
    txtRW.writeline("input.txt",2,txtRW.readline("input.txt",2)+" Editted");
    txtRW.appendline("input.txt",0," editted");
    txtRW.appendline("input.txt",99," editted");
    txtRW.appendline("input.txt",99," editted2");
    txtRW.writeline("input.txt",0,"Something");
    txtRW.writeline("input.txt",3,"Something1");
    txtRW.writeline("input.txt",100,"Something1");
    cout << txtRW.readline("input.txt",0);
    return 0;
}