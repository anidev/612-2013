#include "File.h"
File::File(char* n): IOAccess(n,fstream::out|fstream::app) {
    Name = n;
}
File::~File() {
    close();
}
void File::addLine(string line) {
    open();
    IOAccess << line << "\n";
    IOAccess.flush();
}
void File::addLine(char* a) {
    string s(a);
    addLine(s);
}
void File::close() {
    if(isOpen())
    {
        IOAccess.flush();
        IOAccess.close();
    }
}
void File::open() {
    if(isClosed())
    {
        IOAccess.open(Name,fstream::out|fstream::app);
    }
}
bool File::isOpen() {
    return IOAccess.is_open();
}
bool File::isClosed() {
    return !isOpen();
}
string File::getName() {
    return Name;
}
