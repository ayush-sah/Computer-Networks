#include<iostream>
#include<string>
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
        string bin = "";
        for(int i = 0; i < str.length(); i++){
            asc = str[i];
            while(asc>0){
                if(asc%2==0)
                    bin += "0";
                else
                    bin += "1";
                asc/=2;
            }
        }

        int one = 0;
        for(int i = 0; i < bin.length(); i++){
            if(bin[i]=='1')
                one++;
            if(bin[i]=='0')
                one = 0;
            if(one==5){
                one = 0;
                bin.insert(i+1,"0");
            }
        }
        cout << bin;
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
