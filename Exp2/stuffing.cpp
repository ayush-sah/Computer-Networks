#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

class Stuffing{
private:
    string str, stuff_str, de_stuff;
    int asc;
public:
    void charstuff(){
        cout << "Enter string you want to stuff: ";
        getline(cin,str);
        cout << "\nOriginal Data: " << str << endl;
        int len = str.length();

        stuff_str = "DLESTX" + str + "DLEETX";
        cout << "\nStuffed Data: " << stuff_str << endl;

        de_stuff = stuff_str.replace(0,6,"");
        de_stuff = stuff_str.replace(len,de_stuff.length(),"");
        cout << "\nDe-Stuffed Data: " <<  de_stuff << endl;
    }
    void bitstuff(){
        cout << "Enter string you want to stuff: ";
        getline(cin,str);
        string binary = "";
        string temp_bin = "";
        for(int i = 0; i < str.length(); i++){
            asc = str[i];
            reverse(temp_bin.begin(),temp_bin.end());
            binary += temp_bin;
            temp_bin = "";
            while(asc>0){
                if(asc%2==0)
                    temp_bin += "0";
                else
                    temp_bin += "1";
                asc/=2;
            }
        }
        cout << "Entered String in binary: " << binary << endl;
        int ones = 0;
        for(int i = 0; i < binary.length(); i++){
            if(binary[i]=='1')
                ones++;
            if(binary[i]=='0')
                ones = 0;
            if(ones==5){
                ones = 0;
                binary.insert(i+1,"0");
            }
        }
        cout << "Stuffed Data \t\t: " << binary << endl;
        ones = 0;
        for(int i = 0; i < binary.length(); i++){
            if(binary[i]=='1')
                ones++;
            if(binary[i]=='0')
                ones = 0;
            if(ones==5){
                ones = 0;
                binary.erase(binary.begin()+i);
            }
        }
        cout << "De-Stuffed Data \t: " << binary << endl;
    }
};

int main(){
    Stuffing stuff;
    int action;
    stuff.bitstuff();
    /*
    do{
        cout << "1. Character Stuffing\n2. Bit Stuffing\n3. Exit\nEnter action you want to perform: ";
        cin >> action;

        switch(action){
            case 1: stuff.charstuff();
            case 2: stuff.bitstuff();
            case 3: break;
            default: cout << "Invalid input. Try Again";
        }
    }while(action !=3);
    */
}
