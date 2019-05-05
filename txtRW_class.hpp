#pragma once

#include<fstream>
#include<string>
#include<cstdlib>


class txtRW
{
  public:
  void writeline(std::string FileName, int Line, std::string Data);
  void appendline(std::string FileName, int Line, std::string Data);
  int linecount(std::string FileName);
  std::string readline(std::string FileName, int Line);
  
  private:
  void overwrite(std::string FileName);
};

int txtRW::linecount(std::string FileName)
{
    std::ifstream fin;
    fin.open(FileName.c_str());
    std::string txtline;
    int length = 0;
    while(getline(fin,txtline))
    {
        length++;
    }
    fin.close();
    return length;
}

void txtRW::overwrite(std::string FileName)
{
    std::ifstream fin;
    fin.open(("temp_"+FileName).c_str());

    std::ofstream fout;
    fout.open(FileName.c_str());

    std::string txtline;
    int lineCount = 0;
    while(getline(fin,txtline))
    {
        if(lineCount < txtRW::linecount(("temp_"+FileName))-1)
        {
            fout << txtline << std::endl;
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

void txtRW::writeline(std::string FileName, int Line, std::string Data)
{
    std::ofstream fout;
    fout.open(("temp_"+FileName).c_str());

    std::ifstream fin;
    fin.open(FileName.c_str());

    std::string txtline;
    int count = 0;
    bool isEmpty = true;

    while(getline(fin,txtline))
    {
        isEmpty = false;
        if(count == (Line)){fout << Data;}
        else{fout << txtline;}
        fout << std::endl;
        count++;
    }
    if(count < Line || isEmpty) //Check if targeted line is higher than existing line or the targeted file is empty
    {
        for(int i = count ; i < Line ; i++)
        {
            fout << std::endl;
        }
        fout << Data;
    }
    fin.close();
    fout.close();

    txtRW::overwrite(FileName);
}

std::string txtRW::readline(std::string FileName, int Line)
{
    std::ifstream fin;
    fin.open(FileName.c_str());

    std::string txtline;

    for(int i = 0; i <= Line ; i++)
    {
        getline(fin,txtline);
    }

    fin.close();
    return txtline;
}

void txtRW::appendline(std::string FileName, int Line, std::string Data)
{
    writeline(FileName, Line, readline(FileName,Line) + Data);
}