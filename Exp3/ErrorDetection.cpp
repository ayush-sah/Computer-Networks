#include<iostream>
using namespace std;

class ErrorDetection{
    string str[100], ans;
    int action, num, len, ones;
    public:
    ErrorDetection(){
        getstring();
        do{
            cout << "\n1. LRC\n2. VRC\n3. CRC\n4. Checksum\n5. Exit\n6. Change String\nEnter action you want to perform on the string: ";
            cin >> action;
            switch(action){
                case 1: lrc(); break;
                case 2: vrc(); break;
                case 3: crc(); break;
                case 4: checksum(); break;
                case 5: break;
                case 6: getstring(); break;
                default: cout << "Invalid input. Enter Again.";
            }
        }while(action!=5);
    }

    void getstring(){
        cout << "Enter the string: ";
        num = 0;
        char c;
        while (cin.peek()!='\n'){
            if(cin.peek()==' ')
                num++;
            cin >> c;
            str[num] += c;
        }
        len = str[0].length();
    }

    void lrc(){
        ans = "";
        for(int i = 0; i <= num; i++){
            ones = 0;
            for(int j = 0; j < len; j++){
                if(str[i][j]=='1')
                    ones++;
            }
            if(ones%2==0)
                ans += '0';
            else
                ans += '1';
        }
        cout << "LRC is : " << ans;
    }

    void vrc(){
        ans = "";
        for(int i = 0; i < len; i++){
            ones = 0;
            for(int j = 0; j <= num; j++){
                if(str[j][i]=='1')
                    ones++;
            }
            if(ones%2==0)
                ans += '0';
            else
                ans += '1';
        }
        cout << "VRC is : " << ans;
    }

    void checksum(){
        
    }
    
    void crc(){

    }
};

int main(){
    ErrorDetection obj;
}