#include "mystring.h"

MyString::MyString(char* str){
    if (str == NULL){
        this->str = NULL;
        this->size = 0;
        return;
    }
    size_t size = strlen(str);
    char* buff = new char[size];
    strcpy(buff, str);
    this->str = buff;
    this->size = size;
}

MyString::MyString(const MyString& source){
    if (source.str == NULL){
        this->str = NULL;
        this->size = 0;
        return;
    }
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
    if(this->str == NULL){
        cout << "Delete NULL string" << endl;
        return;
    }
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
    for (int i = 0; i<size; i++){
        this->str[i] = toupper(this->str[i]);
    }
    return *this;
}
void MyString::print(){
    for(int i=0;i<size;i++){
        cout << this->str[i];
    }
    cout << endl;
}