#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString{
    private:
        char* str;
        int size;
    public:
        MyString(char* str = NULL,int size = 0) : str{str},size{size}{}
        MyString(const MyString& source){
            char* buff = new char[size+1];
            strcpy(buff,source.str);
            delete [] this->str;
            this->str = buff;
            this->size = source.size;
        }
        MyString(MyString&& source){
            this->size = source.size;
            this->str = source.str;
            source.str = NULL;
            source.size = 0;
        }
        ~MyString(){
            cout << "Delete :";
            for (char* i = str; i < str+size ;i ++){
                cout << *i << endl;
            }
            delete[] str;
        }
        MyString& operator=(const MyString& source){
            if(this == & source){
                return *this;
            }
            char* buff = new char[source.size+1];
            strcpy(buff,source.str);
            delete [] this->str;
            this->str = buff;
            this->size = source.size;
            return *this;
        }
};