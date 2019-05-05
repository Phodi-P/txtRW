# txtRW

## About
* txtRW is a C++ class for text file reading and writing.

## Usage
* `readline(string FileName, int Line)` returns a line of string from a file on a specific line location.
* `writeline(string FileName, int Line, string Data)` is for writing a line of string to a file on a specific line location.
* `appendline(string FileName, int Line, string Data)` is for appending string to existing line in a file on a specific line location.
* `linecount(string FileName)` returns number of lines of a file.

* `parse2File(string FileName, vector<type>)` Parse data from vector to file.
    * only supported double, int, float, bool, string and char.

* `parse2Vector[Corresponding Type](string FileName)` Parse data from file to vector.
    * only supported double, int, float, bool, string and char.
    * `parse2VectorD(string FileName)` for parsing to double vector.
    * `parse2VectorI(string FileName)` for parsing to int vector.
    * `parse2VectorF(string FileName)` for parsing to float vector.
    * `parse2VectorB(string FileName)` for parsing to bool vector.
    * `parse2VectorS(string FileName)` for parsing to string vector.
    * `parse2VectorC(string FileName)` for parsing to char vector.

## Notes
* The line number argument starts from 0.