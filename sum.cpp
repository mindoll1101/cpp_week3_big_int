#include<string>
#include<cstring>
#include<iostream>

using std::string;

void sum(string num1, string num2){
    int count = 0;
    int num1_length = num1.length();
    int num2_length = num2.length();
    string result = "";                 //to save result
    int sum = 0;
    int carry = 0;                      //carry of previous digit

    while(1){
        int num1_c = 0;         //to save nth digit
        int num2_c = 0;
        if(num1_length != 0){
            num1_length -= 1;
            num1_c = (int)num1[num1_length]-48;     
        }
        
        if(num2_length != 0){
            num2_length -= 1;
            num2_c = (int)num2[num2_length]-48;
        }

        sum = num1_c + num2_c;
        if(carry > 0){
            sum += 1;
            carry = 0;
        }

        if(sum > 9){                //if the sum of two digits is over than 9, carry.
            carry = 1;
            sum -= 10;
            result = std::to_string(sum) + result;
        }
        else{
            result = std::to_string(sum) + result;
        }

        if(num1_length == 0 && num2_length == 0){       //end of sum.
            break;
        }
    }

    if(carry > 0){
        result = std::to_string(carry) + result;
    }
    std::cout << "Sum                   >> " + result << std::endl;
}