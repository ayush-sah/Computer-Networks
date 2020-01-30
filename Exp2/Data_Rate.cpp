#include <iostream>
#include <math.h>
using namespace std;

class DataRate{
    private:
        int Bandwidth, Levels, SNR;
        float Bitrate, Capacity;
        string Noise;
    public:
        DataRate(){
            cout << "Enter the Bandwidth: ";
            cin >> Bandwidth;

            cout << "Is the channel Noiseless(Y/N): ";
            cin >> Noise;

            if (Noise=="Y"){
                cout << "Enter levels: ";
                cin >> Levels;
                Bitrate = ((2 * Bandwidth) * (log(Levels)/log(2)));
                cout << "Bit Rate = " << Bitrate << " bps." << endl;
            }
            else{
                cout << "Enter Signal to Noise ratio (SNR): ";
                cin >> SNR;
                Capacity = (Bandwidth * (log(1+SNR)/log(2)));
                cout << "Capacity = " << Capacity << " bps." << endl;
            }
        }
};

int main(){
    DataRate ob;
}