#include<iostream>

#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
class txtRW
{
  public:
  void overwrite(string FileName);
  void writeline(string FileName, int Line,string Data);
  int linecount(string FileName);
  string readline(string FileName,int Line);
};

void txtRW::overwrite(string FileName)
{
    ifstream fin;
    fin.open(("temp_"+FileName).c_str());

    ofstream fout;
    fout.open(FileName.c_str());

    string txtline;
    while(getline(fin,txtline))
    {
        fout << txtline;
        fout << endl;
    }
    fin.close();
    fout.close();
    remove(("temp_"+FileName).c_str());
}

void txtRW::writeline(string FileName, int Line,string Data)
{
    ofstream fout;
    fout.open(("temp_"+FileName).c_str());

    ifstream fin;
    fin.open(FileName.c_str());

    string txtline;
    int count = 0;
    while(getline(fin,txtline))
    {
        if(count == (Line)){fout << Data;}
        else{fout << txtline;}
        fout << endl;
        count ++;
    }
    fin.close();
    fout.close();

    txtRW::overwrite(FileName);
}
int txtRW::linecount(string FileName)
{
    ifstream fin;
    fin.open(FileName.c_str());
    string txtline;
    int count = 0;
    while(getline(fin,txtline))
    {
        count++;
    }
    fin.close();
    return count;
}

string txtRW::readline(string FileName,int Line)
{
    ifstream fin;
    fin.open(FileName.c_str());
    string txtline;
    // int i = 0;
    // do
    // {
    //     getline(fin,txtline);
    //     i++;
    // } while (i < Line);
    
    for(int i = 0; i < Line ; i++)
    {
        getline(fin,txtline);
    }
    fin.close();
    return txtline;
}
int main()
{
    txtRW txtRW;
    cout << txtRW.readline("input.txt",4);
    return 0;
}