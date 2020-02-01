#include <iostream>
#include <math.h>
using namespace std;

class DataRate{
    private:
        int Bandwidth, value, SNR, check, Levels;
        float Capacity;
        string Noise;
    public:
        DataRate(){
            cout << "Enter the Bandwidth: ";
            cin >> Bandwidth;
            
            cout << "Enter Levels or SNR: ";
            cin >> value;

            check = value;
            while(check>2){check/=2;}
            
            if(check%2==0){
                Capacity = ((2 * Bandwidth) * (log(value)/log(2)));
                cout << "Bit Rate = " << Capacity << " bps." << endl;
            }
            else{
                Capacity = (Bandwidth * (log(1+value)/log(2)));
                cout << "Capacity = " << Capacity << " bps." << endl;
                Levels = pow(2, Capacity/(2*Bandwidth));
                cout << "Levels = " << Levels << " bps." << endl;
            }
        }
};

int main(){
    DataRate ob;
}
