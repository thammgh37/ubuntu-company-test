#ifndef MYSTRING_H
#define MYSTRING_H
#include "header.h"

class MyString{
    private:
        char* str;
        int size;
    public:
        MyString(char* str = NULL,size_t size = 0);
        MyString(const MyString& source);
        MyString(MyString&& source);
        ~MyString();
        MyString& operator=(const MyString& source);
        MyString& operator=(MyString&& source);
        MyString& operator++();
        void print();
};
#endif
