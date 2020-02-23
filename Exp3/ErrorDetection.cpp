#include<iostream>
#include<math.h>
using namespace std;

class ErrorDetection{
    string str[100], ans;
    int action, num, len, ones;
    public:
    ErrorDetection(){
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
            if(cin.peek()==' '){
                num++;
            }
            cin >> c;
            str[num] += c;
        }
        len = str[0].length();
    }

    void lrc(){
        getstring();
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
        cout << "LRC is : " << ans << endl;
    }

    void vrc(){
        getstring();
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
        cout << "VRC is : " << ans << endl;
    }

    void checksum(){
        getstring();
        ans = "";
        string temp = "";
        int carry = 0;
        int k = -1;
        for(int i = len-1; i >= k; i--){
            ones = 0;
            ones += carry;
            if(i>=0){
                for(int j = 0; j <= num; j++){
                    if(str[j][i]=='1')
                        ones++;
                }
                if(ones%2==0)
                    ans.insert(0,1,'0');
                else
                    ans.insert(0,1,'1');
            }
            else{
                if(ones==0)
                    break;
                else if(ones>1)
                    k--;
                if(ones%2==0)
                    temp.insert(0,1,'0');
                else
                    temp.insert(0,1,'1');
            }
            carry = ones/2;
        }
        carry = 0;

        while(temp.length()!=ans.length())
            temp.insert(0,1,'0');

        for(int i = len-1; i >= 0; i--){
            ones = 0;
            ones += carry;

            if(temp[i]=='1')
                ones++;
            if(ans[i]=='1')
                ones++;

            if(ones%2==0)
                ans[i] = '0';
            else
                ans[i] = '1';

            carry = ones/2;
        }
        cout << "Checksum is : " << ans << endl;
    }
    
    void crc(){
        string dividend, divisor;
        cout << "Enter Dividend: ";
        cin >> dividend;
        cout << "Enter Divisor: ";
        cin >> divisor;
        for(int i = 0; i < divisor.length()-1;i++)
            dividend += '0';
        int dec_dividend = 0, dec_divisor = 0, power = 0;
        for(int i = dividend.length()-1; i >= 0 ; i--){
            if(dividend[i]=='1')
                dec_dividend += pow(2.0, (float)power);
            power++;
        }
        power = 0;
        for(int i = divisor.length()-1; i >= 0 ; i--){
            if(divisor[i]=='1')
                dec_divisor += pow(2.0, (float)power);
            power++;
        }
        int remainder = dec_dividend / dec_divisor;
    }
};

int main(){
    ErrorDetection obj;
}