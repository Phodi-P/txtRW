#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void txtRW_overwrite(string FileName)
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

void txtRW_writeline(string FileName, int Line,string Data)
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

    txtRW_overwrite(FileName);
}

int txtRW_length(string FileName)
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

string txtRW_readline(string FileName,int Line)
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

int main()
{
    cout << txtRW_readline("in_out.txt",3);
    txtRW_writeline("in_out.txt",3,"HEY IT'S WORKED!! Line 4");
    cout << txtRW_readline("in_out.txt",3);
    return 0;
}