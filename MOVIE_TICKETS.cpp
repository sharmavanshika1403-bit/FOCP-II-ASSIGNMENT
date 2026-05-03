#include <iostream>
using namespace std;

class MovieTicket {
private:
    bool booked[1001][1001];
    int available[1001];

public:
    MovieTicket() {
        for (int i = 0; i < 1001; i++) {
            available[i] = 100;
            for (int j = 0; j < 1001; j++) {
                booked[i][j] = false;
            }
        }
    }

    bool BOOK(int X, int Y) {
        if (booked[X][Y] == true || available[Y] == 0)
            return false;

        booked[X][Y] = true;
        available[Y]--;
        return true;
    }

    bool CANCEL(int X, int Y) {
        if (booked[X][Y] == false)
            return false;

        booked[X][Y] = false;
        available[Y]++;
        return true;
    }

    bool IS_BOOKED(int X, int Y) {
        return booked[X][Y];
    }

    int AVAILABLE_TICKETS(int Y) {
        return available[Y];
    }
};

int main() {
    MovieTicket obj;

    cout << obj.BOOK(1, 101) << endl;         
    cout << obj.BOOK(1, 101) << endl;         
    cout << obj.IS_BOOKED(1, 101) << endl;    
    cout << obj.AVAILABLE_TICKETS(101) << endl; 
    cout << obj.CANCEL(1, 101) << endl;      
    cout << obj.AVAILABLE_TICKETS(101) << endl; 

    return 0;
}