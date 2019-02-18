#include<iostream>
#include<fstream>
#include<string>
#include"txtRW_class.cpp"
using namespace std;

int main()
{
    txtRW txtRW;
    txtRW.writeline("input.txt",2,txtRW.readline("input.txt",2)+" Editted");
    cout << txtRW.readline("input.txt",2);
    return 0;
}