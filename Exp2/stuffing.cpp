#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
string str;
class Stuffing{
private:
    string stuff_str, de_stuff;
    int asc;
public:
    void charstuff(){
        cout << "\nOriginal Data: " << str << endl;
        int len = str.length();

        stuff_str = "DLESTX" + str + "DLEETX";
        cout << "\nStuffed Data: " << stuff_str << endl;

        de_stuff = stuff_str.replace(0,6,"");
        de_stuff = stuff_str.replace(len,de_stuff.length(),"");
        cout << "\nDe-Stuffed Data: " <<  de_stuff << endl << endl << endl;
    }
    void bitstuff(){
        string binary = "";
        string temp_bin = "";
        for(int i = 0; i <= str.length(); i++){
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
        cout << str;
        cout << "\nEntered String in binary: " << binary << endl;
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
        cout << "\nStuffed Data \t\t: " << binary << endl;
        ones = 0;
        for(int i = 0; i < binary.length(); i++){
            if(binary[i]=='1')
                ones++;
            if(binary[i]=='0')
                ones = 0;
            if(ones==5){
                ones = 0;
                binary.erase(binary.begin()+i+1);
            }
        }
        cout << "\nDe-Stuffed Data \t: " << binary << endl;
        int count = 7, decimal = 0;
        string re_str = "";
        for(int i = 0; i < binary.length(); i++){
            count--;
            if(binary.at(i)=='1')
                decimal += pow(2.0,(float)count);
            if(count==0){
                re_str += (char)decimal;
                decimal = 0;
                count = 7;
            }
        }
        cout << "\nRe-String \t: " << re_str << endl << endl << endl;
    }
};

int main(){
    Stuffing stuff;
    int action;
    do{
        cout << "1. Character Stuffing\n2. Bit Stuffing\n3. Exit\n\nEnter action you want to perform: ";
        cin >> action;
        if(action==1 || action==2){
            cout << "\nEnter string you want to stuff: ";
            cin.ignore();
            getline(cin,str);
        }
        switch(action){
            case 1: stuff.charstuff();  break;
            case 2: stuff.bitstuff();   break;
            case 3: break;
            default: cout << "Invalid input. Try Again";
        }
    }while(action !=3);
}
