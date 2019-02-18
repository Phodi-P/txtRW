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

int txtRW::linecount(string FileName)
{
    ifstream fin;
    fin.open(FileName.c_str());
    string txtline;
    int length = 0;
    while(getline(fin,txtline))
    {
        length++;
    }
    fin.close();
    return length;
}

void txtRW::overwrite(string FileName)
{
    ifstream fin;
    fin.open(("temp_"+FileName).c_str());

    ofstream fout;
    fout.open(FileName.c_str());

    string txtline;
    int lineCount = 0;
    while(getline(fin,txtline))
    {
        if(lineCount < txtRW::linecount(("temp_"+FileName))-1)
        {
            fout << txtline << endl;
        }
        else
        {
            fout << txtline;
        }
        
        lineCount++;
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


string txtRW::readline(string FileName,int Line)
{
    ifstream fin;
    fin.open(FileName.c_str());

    string txtline;

    for(int i = 0; i <= Line ; i++)
    {
        getline(fin,txtline);
    }
    fin.close();
    return txtline;
}