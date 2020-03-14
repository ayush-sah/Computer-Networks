#include<iostream>
#include<string>
#include <bits/stdc++.h>
#include<math.h>
using namespace std;

class ipaddress{
private:
    string ip, binary[5];
    int dots, slash, octate[5];
public:
    ipaddress(){
        cout << "Enter IP: ";
        cin >> ip;

        //Check whether valid or not
        if(valid()){
            cout << "1. IP address is valid." << endl;

            //Categorize as Classful or classless
            if(slash==1)
                cout << "2. IP address is classful." << endl;
            else
                cout << "2. IP address is classless." << endl;

            //Find out whether its Class A,B,C & Find out network address & Find out default subnet mask
            if(octate[0]<=127){
                cout << "3. IP address is of Class A." << endl;
                cout << "4. Network address is " << octate[0] << ".0.0.0" << endl;
                cout << "5. Default subnet mask is 255.0.0.0" << endl;
            }
            else if(octate[0]<=191){
                cout << "3. IP address is of Class B." << endl;
                cout << "4. Network address is " << octate[0] << "." << octate[1] << ".0.0" <<  endl;
                cout << "5. Default subnet mask is 255.255.0.0" << endl;
            }
            else if(octate[0]<=223){
                cout << "3. IP address is of Class C." << endl;
                cout << "4. Network address is " << octate[0] << "." << octate[1] << "." << octate[2] << ".0" << endl;
                cout << "5. Default subnet mask is 255.255.255.0" << endl;
            }
            else if(octate[0]<=239)
                cout << "3. IP address is of Class D" << endl;
            else
                cout << "3. IP address is of Class E" << endl;
            addresses();
        }
        else
            cout << "1. IP address is not valid." << endl;
    }
    int valid(){
        dots = 0;
        slash = 0;
        string str="";
        int k = 0;
        for(int i = 0; i < ip.length(); i++){
            if(str.length()>3)return 0;
            if(ip[i]=='.'){
                dots++;
                octate[k++] = stoi(str);
                str = "";
            }
            else{
                if(ip[i]=='/'){
                    if(dots==3){
                        slash++;
                        octate[k++] = stoi(str);
                        str = "";
                    }
                    else
                        return 0;
                }
                else{
                    str += ip[i];
                    if((ip[i]<'0') || (ip[i]>'9'))return 0;
                }
            }
        }
        octate[k] = stoi(str);
        if (dots!=3 && (slash!=0 || slash!=1))
            return 0;
        for(int i = 0; i < 4; i++){
            if(octate[i]<0 || octate[i]>255)
                return 0;
        }
        return 1;
    }

    void addresses(){
        if(slash == 0 || octate[4]==0){
        }
        else{
            int temp;
            string temp_bin = "";
            for(int i = 0; i < 4; i++){
                temp_bin = "";
                temp = octate[i];
                while(temp>0){
                    temp_bin += (temp%2==0)?'0':'1';
                    temp /= 2;
                }
                while(temp_bin.length()<8)temp_bin+='0';
                reverse(temp_bin.begin(),temp_bin.end());
                binary[i] = temp_bin;
            }
            string temp1 = "";
            for(int i = 0; i < 4; i++)
                temp1 += binary[i];

            for(int i = 0; i < 32; i++){
                if(i < octate[4]);
                else{
                    temp1[i]='0';
                }
            }

            string s;
            int k=0;
            cout << "6. First Address is ";
            for(int i = 0; i < 4; i++){
                s = "";
                for(int j = 0; j < 8; j++){
                    s += temp1[k++];
                }
                cout << stoi(s,nullptr,2);
                i <= 2 ? cout<<"." : cout<<"/" << octate[4] ;
            }


            for(int i = 0; i < 32; i++){
                if(i < octate[4]);
                else{
                    temp1[i]='1';
                }
            }

            k=0;
            cout << "\n7. Last Address is ";
            for(int i = 0; i < 4; i++){
                s = "";
                for(int j = 0; j < 8; j++){
                    s += temp1[k++];
                }
                cout << stoi(s,nullptr,2);
                i <= 2 ? cout<<"." : cout<<"/" << octate[4] ;
            }
            cout << "\n8. Number of Addresses: " << pow(2,32-octate[4]);
            
            
            k=0;
            cout << "\n9. Broadcast Address is ";
            for(int i = 0; i < 4; i++){
                s = "";
                for(int j = 0; j < 8; j++){
                    s += temp1[k++];
                }
                cout << stoi(s,nullptr,2);
                i <= 2 ? cout<<"." : cout<<"/" << octate[4] ;
            }
        }
    }
};

int main(){
    ipaddress obj;
}
