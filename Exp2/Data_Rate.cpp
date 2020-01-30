#include <iostream>
#include <math.h>
using namespace std;

class DataRate{
    private:
        int Bandwidth, Levels, SNR;
        float Max_Capacity;
        string Noise;
    public:
        DataRate(){
            cout << "Enter the Bandwidth: ";
            cin >> Bandwidth;
            Levels = 0;
            
            cout << "Enter levels(Enter 0 if levels not given): ";
            cin >> Levels;

            if(Levels!=0){
                Max_Capacity = ((2 * Bandwidth) * (log(Levels)/log(2)));
                cout << "Bit Rate = " << Max_Capacity << " bps." << endl;
            }
            else{
                cout << "Enter Signal to Noise ratio (SNR): ";
                cin >> SNR;
                Max_Capacity = (Bandwidth * (log(1+SNR)/log(2)));
                cout << "Capacity = " << Max_Capacity << " bps." << endl;
                Levels = pow(2,Max_Capacity/(2*Bandwidth));
                cout << "Levels = " << Levels << " bps." << endl;
            }
        }
};

int main(){
    DataRate ob;
}