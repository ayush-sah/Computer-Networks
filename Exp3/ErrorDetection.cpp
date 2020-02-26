#include<iostream>
#include<math.h>
#include<string>
using namespace std;

class ErrorDetection{
    string str[100], ans;
    int action, num, len, ones;
    public:
    ErrorDetection(){
        do{
            cout << "\n1. LRC\n2. VRC\n3. Checksum\n4. CRC\n5. Hamming\n6. Exit\nEnter action you want to perform: ";
            cin >> action;
            switch(action){
                case 1: lrc(); break;
                case 2: vrc(); break;
                case 3: checksum(); break;
                case 4: crc(); break;
                case 5: hamming(); break;
                case 6: break;
                default: cout << "Invalid input. Enter Again.";
            }
        }while(action!=5);
    }

    void getstring(){
        cout << "Enter the string: ";
        num = 0;
        char c;
        str[0] = "";
        while (cin.peek()!='\n'){
            if(cin.peek()==' '){
                num++;
                str[num] = "";
            }
            cin >> c;
            str[num] += c;
        }
        len = str[0].length();
    }

    void lrc(){
        cin.ignore();
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
        cin.ignore();
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
        cin.ignore();
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
        string dividend, divisor, ans = "";
        cout << "Enter Dividend: ";
        cin >> dividend;
        
        cout << "Enter Divisor: ";
        cin >> divisor;

        ans += dividend;
        for(int i = 1; i < divisor.length(); i++)
            ans += '0';
        
        int i = 0;
        while(i <= ans.length() - divisor.length()){
            for(int j = 0; j < divisor.length(); j++)
                ans[i+j] = ans[i+j] == divisor[j]? '0' : '1';
            while((i<ans.length()) && (ans[i]!='1'))
                i++;
        }

        while(ans[0]!='1')
            ans.erase(ans.begin());
        cout << "CRC is : " << dividend + ans << endl;

    }

    void hamming(){
        cin.ignore();
        getstring();
        ans = "";
        int r = 0;
        while(pow(2, ++r) < len + r + 1);
        int totalbits = len + r;
        char *arr = new char[totalbits];
        int k = len, raise = 0;
        for(int i = 0; i < totalbits; i++){
            if(pow(2, raise)==i+1){
                arr[i] = 'P';
                raise++;
            }
            else
                arr[i] = str[0][--k];
        }
    }
};

int main(){
    ErrorDetection obj;
}