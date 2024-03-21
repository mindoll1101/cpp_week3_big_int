#include<iostream>
#include<string>
#include<cstring>

using std::string;

void sum(string num1, string num2);
void sub(string num1, string num2);

int main(){
    string num1, num2;
    std::cout << "Enter first number    >> ";
    getline(std::cin, num1);
    std::cout << "Enter second number   >> ";
    getline(std::cin, num2);


    sum(num1, num2);
    sub(num1, num2);
}