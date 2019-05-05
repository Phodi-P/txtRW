#include<iostream>
#include"txtRW_class.hpp"
using namespace std;
int main()
{
    txtRW txtRW;

    //Writing to specific line on a file
    txtRW.writeline("input.txt",2,"This is line3");

    //Append to specific line on a file
    txtRW.appendline("input.txt",2," editted");

    //Reading from specific line on a file
    std::cout << txtRW.readline("input.txt",2) << endl;

    //Parsing to file example

        //Preparing char vector to parse to file
        vector<char> vecToFile;
        vecToFile.push_back('A');
        vecToFile.push_back('B');
        vecToFile.push_back('C');

    //You can also use any type of basic vector type (double, int, float, bool, string, char)
    //The function is already overloaded for these variable types
    txtRW.parse2File("vector.txt",vecToFile);


    //Parsing from file example

    vector<char> fileToVec;

    //You must use parse2Vector[Corresponding Type]
    //Ex. parse2VectorD for double
    //    parse2VectorI for int
    //    parse2VectorF for float
    //    parse2VectorB for bool
    //    parse2VectorS for string
    //    parse2VectorC for char
    fileToVec = txtRW.parse2VectorC("vector.txt");

        //Try printing out result
        for(int i = 0 ; i < fileToVec.size() ; i++) cout << fileToVec[i] << endl;

    
    return 0;
}