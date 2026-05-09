#include <iostream>
using namespace std;

class Bank {
private:
    int balance[1001];
    bool exists[1001];

public:
    
    Bank() {
        for (int i = 0; i < 1001; i++) {
            balance[i] = 0;
            exists[i] = false;
        }
    }

    bool CREATE(int X, int Y) {
        if (!exists[X]) {
            exists[X] = true;
            balance[X] = Y;
            return true;
        } else {
            balance[X] += Y;
            return false;
        }
    }

    bool DEBIT(int X, int Y) {
        if (!exists[X] || balance[X] < Y)
            return false;

        balance[X] -= Y;
        return true;
    }

    bool CREDIT(int X, int Y) {
        if (!exists[X])
            return false;

        balance[X] += Y;
        return true;
    }

    int BALANCE(int X) {
        if (!exists[X])
            return -1;

        return balance[X];
    }
};