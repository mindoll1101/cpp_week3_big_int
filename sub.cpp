#include<string>
#include<cstring>
#include<iostream>

using std::string;

void sub(string num1, string num2){
    int count = 0;
    int num1_length = num1.length();
    int num2_length = num2.length();
    string result = "";
    int sub = 0;
    int carry = 0;

    while(1){
        int num1_c = 0;
        int num2_c = 0;
        if(num1_length != 0){
            num1_length -= 1;
            num1_c = (int)num1[num1_length]-48;
        }
        
        if(num2_length != 0){
            num2_length -= 1;
            num2_c = (int)num2[num2_length]-48;
        }

        sub = num1_c - num2_c;
        if(carry > 0){
            sub -= 1;
            carry = 0;
        }

        if(sub < 0){
            carry = 1;
            sub = 10 + sub;
            result = std::to_string(sub) + result;
        }
        else{
            result = std::to_string(sub) + result;
        }

        if(num1_length == 0 && num2_length == 0){
            break;
        }
    }
    if(carry > 0){
        string ndec = "1";
        for(int i = 0; i < result.lenght(); i++){
            ndec = ndec + "0";
        }
        sub(ndec, result);
    }
    else{
        std::cout << "Sub                   >> " + result << std::endl;
    }
    
}