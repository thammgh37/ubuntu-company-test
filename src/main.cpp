#include "header.h"
#include "mystring.h"

int main(){
    char hello[]="hello world";
    MyString str(hello);
    str.print();
    ++str;
    str.print();
}