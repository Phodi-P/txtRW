#pragma once

#include<fstream>
#include<string>
#include<vector>

class txtRW
{
  public:
  void writeline(std::string FileName, int Line, std::string Data);
  void appendline(std::string FileName, int Line, std::string Data);
  int linecount(std::string FileName);
  std::string readline(std::string FileName, int Line);

  //Overloads for parse2File
  void parse2File(std::string FileName, std::vector<double> Input);
  void parse2File(std::string FileName, std::vector<int> Input);
  void parse2File(std::string FileName, std::vector<float> Input);
  void parse2File(std::string FileName, std::vector<bool> Input);
  void parse2File(std::string FileName, std::vector<std::string> Input);
  void parse2File(std::string FileName, std::vector<char> Input);

  //parse2Vector for various variable type
  std::vector<double> parse2VectorD(std::string FileName);
  std::vector<int> parse2VectorI(std::string FileName);
  std::vector<float> parse2VectorF(std::string FileName);
  std::vector<bool> parse2VectorB(std::string FileName);
  std::vector<std::string> parse2VectorS(std::string FileName);
  std::vector<char> parse2VectorC(std::string FileName);

  private:
  void overwrite(std::string FileName);

};

//Return number of lines in the file
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

//Overwrite target file with temp_file
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

//Write the whole line
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

//Read and return the whole line
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

//Write the at the end of the line
void txtRW::appendline(std::string FileName, int Line, std::string Data)
{
    writeline(FileName, Line, readline(FileName,Line) + Data);
}


void txtRW::parse2File(std::string FileName, std::vector<double> Input)
{
    std::ofstream fout(("temp_"+FileName).c_str());
    fout << "double\n";
    for(int i = 0 ; i < Input.size() ; i++)
    {
        fout << Input[i] << "\n";
    }
    
    fout.close();
    overwrite(FileName);
}

void txtRW::parse2File(std::string FileName, std::vector<int> Input)
{
    std::ofstream fout(("temp_"+FileName).c_str());
    fout << "int\n";
    for(int i = 0 ; i < Input.size() ; i++)
    {
        fout << Input[i] << "\n";
    }
    
    fout.close();
    overwrite(FileName);
}

void txtRW::parse2File(std::string FileName, std::vector<float> Input)
{
    std::ofstream fout(("temp_"+FileName).c_str());
    fout << "float\n";
    for(int i = 0 ; i < Input.size() ; i++)
    {
        fout << Input[i] << "\n";
    }
    
    fout.close();
    overwrite(FileName);
}

void txtRW::parse2File(std::string FileName, std::vector<bool> Input)
{
    std::ofstream fout(("temp_"+FileName).c_str());
    fout << "bool\n";
    for(int i = 0 ; i < Input.size() ; i++)
    {
        fout << Input[i] << "\n";
    }
    
    fout.close();
    overwrite(FileName);
}

void txtRW::parse2File(std::string FileName, std::vector<std::string> Input)
{
    std::ofstream fout(("temp_"+FileName).c_str());
    fout << "string\n";
    for(int i = 0 ; i < Input.size() ; i++)
    {
        fout << Input[i] << "\n";
    }
    
    fout.close();
    overwrite(FileName);
}

void txtRW::parse2File(std::string FileName, std::vector<char> Input)
{
    std::ofstream fout(("temp_"+FileName).c_str());
    fout << "char\n";
    for(int i = 0 ; i < Input.size() ; i++)
    {
        fout << Input[i] << "\n";
    }
    
    fout.close();
    overwrite(FileName);
}

std::vector<double> txtRW::parse2VectorD(std::string FileName)
{
    std::vector<double> Output;

    std::string txtline;
    std::ifstream fin(FileName.c_str());

    getline(fin,txtline);
    if(txtline != "double") return Output;

    while(getline(fin,txtline))
    {
        Output.push_back(stod(txtline));
    }

    fin.close();
    return Output;
}

std::vector<int> txtRW::parse2VectorI(std::string FileName)
{
    std::vector<int> Output;

    std::string txtline;
    std::ifstream fin(FileName.c_str());

    getline(fin,txtline);
    if(txtline != "int") return Output;

    while(getline(fin,txtline))
    {
        Output.push_back(stoi(txtline));
    }

    fin.close();
    return Output;
}

std::vector<float> txtRW::parse2VectorF(std::string FileName)
{
    std::vector<float> Output;

    std::string txtline;
    std::ifstream fin(FileName.c_str());

    getline(fin,txtline);
    if(txtline != "float") return Output;

    while(getline(fin,txtline))
    {
        Output.push_back(stof(txtline));
    }

    fin.close();
    return Output;
}

std::vector<bool> txtRW::parse2VectorB(std::string FileName)
{
    std::vector<bool> Output;

    std::string txtline;
    std::ifstream fin(FileName.c_str());

    getline(fin,txtline);
    if(txtline != "bool") return Output;

    while(getline(fin,txtline))
    {
        Output.push_back(stoi(txtline));
    }

    fin.close();
    return Output;
}

std::vector<std::string> txtRW::parse2VectorS(std::string FileName)
{
    std::vector<std::string> Output;

    std::string txtline;
    std::ifstream fin(FileName.c_str());

    getline(fin,txtline);
    if(txtline != "string") return Output;

    while(getline(fin,txtline))
    {
        Output.push_back((txtline));
    }

    fin.close();
    return Output;
}

std::vector<char> txtRW::parse2VectorC(std::string FileName)
{
    std::vector<char> Output;

    std::string txtline;
    std::ifstream fin(FileName.c_str());

    getline(fin,txtline);
    if(txtline != "char") return Output;

    while(getline(fin,txtline))
    {
        Output.push_back((txtline[0]));
    }

    fin.close();
    return Output;
}