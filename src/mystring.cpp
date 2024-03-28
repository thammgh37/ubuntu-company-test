#include "mystring.h"

MyString::MyString(char* str,size_t size) : str{str},size{strlen(str)}{}

MyString::MyString(const MyString& source){
    char* buff = new char[size+1];
    strcpy(buff,source.str);
    delete [] this->str;
    this->str = buff;
    this->size = source.size;
}
MyString::MyString(MyString&& source){
    this->size = source.size;
    this->str = source.str;
    source.str = NULL;
    source.size = 0;
}
MyString::~MyString(){
    cout << "Delete :";
    for (char* i = str; i < str+size ;i ++){
        cout << *i;
    }
    cout<<"\n";
    delete[] str;
}

MyString& MyString::operator=(const MyString& source){
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
MyString& MyString::operator=(MyString&& source){
    if(this == & source){
        return *this;
    }
    this->str = source.str;
    this->size = source.size;
    source.str = NULL;
    source.size = 0;
    return *this;
}

MyString& MyString::operator++(){
    char* buff = new char[this->size+1];
    for (int i = 0; i<size; i++){
        buff[i] = toupper(this->str[i]);
    }
    delete[] this->str;
    this->str = buff;
    return *this;
}
void MyString::print(){
    for(int i=0;i<size;i++){
        cout << this->str[i];
    }
    cout << endl;
}