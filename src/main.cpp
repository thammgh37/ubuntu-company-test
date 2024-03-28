#include "../include/main.h"
#include "mystring.h"
using namespace std;
class Account{
    private:
        int balance;
        string name;
    public:
        Account(string name = "none",int balance = 0) : name{name}, balance{balance}{}
        Account(const Account& source){
            this->name = source.get_name();
            this->balance = source.balance;
        }
        string get_name() const{
            return this->name;
        }
        int get_balance(){
            return this->balance;
        }
};
void reverse_array(int* &arr, int size) {
    //-- Write your code below this line 
    int* rev = new int[size];
    for (int i = 0 ;i < size;i++){
        rev[i] = arr[size - i - 1];
    }
    delete[] arr;
    arr = rev;
    //-- Write your code above this line
}
void pass(vector<int> vec){
    vec[0] = 10;
}
void print_str(string str) {
    cout << str << endl;
    return;
}
int main(){
    void (*printFuncPointer)(string) = print_str;
    printFuncPointer("thammgh37");
}