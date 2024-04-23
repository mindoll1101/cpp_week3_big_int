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
    bool isneg = false;                 //to save result is negative.

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

        if(sub < 0){                //if the sub of two digits is lower than 0, carry.
            carry = 1;
            sub = 10 + sub;
            result = std::to_string(sub) + result;
        }
        else{
            result = std::to_string(sub) + result;
        }
        if(num1_length == 0 && num2_length == 0){
            if(carry > 0){          //if carry is 1 in end of sub, result is negative.
                isneg = true;
                num1 = "1";
                num2 = result;
                result = "";
                carry = 0;
                for(int i = 0; i < num2.length(); i++){     //convert to negative.
                    num1 = num1 + "0";
                }
                num1_length = num1.length();
                num2_length = num2.length();
            }
            else{
                break;
            }
        }
    }
    char pre_c = '0';
    count = 0;                          //count zeros.
    if(result != "0"){
        for(char c : result){               //remove leading zeros.
            if(c == '0' && pre_c == c){
                pre_c = '0';
                if(isneg){
                    count += 1;
                }
                else{
                    count += 1;
                }
            }
            else{
                break;
            }
        }
    }
    if(isneg){
        result = result.replace(0, count, "-");
    }
    else if(count > 0){
        if(count == result.length()){
            count -= 1;
        }
        result = result.substr(count, result.length()-1);
    }

    std::cout << "Sub                   >> " + result << std::endl;
}
