#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>

using namespace std;

class File {
public:
    File(char*); //File Name
    ~File();
    void addLine(string);
    void addLine(char*);
    void close();
    void open();
    bool isOpen();
    bool isClosed();
    string getName();
private:
    char *Name;
    fstream IOAccess;
};
#endif //FILE_H
