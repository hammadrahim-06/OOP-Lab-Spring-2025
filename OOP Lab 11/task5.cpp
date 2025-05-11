#include <iostream>

using namespace std;

class LowBalanceError : public exception {

    private:
        double shortfall;
        string errMsg;
    public:
        LowBalanceError(double diff) : shortfall(diff) {
            errMsg = "LowBalanceError - Shortfall amount: $" + to_string(shortfall);
        }
        const char* what() const noexcept override {
            return errMsg.c_str();
        }

};

template <typename U>
class Wallet {
    private:
        U funds;
    public:
        Wallet(U initialAmount = 1000) : funds(initialAmount) {
            cout << "Current funds: $" << funds << endl;
        }
        void debit(U requested) {
            if(requested > funds) {
                throw LowBalanceError(requested - funds);
            } else {
                funds -= requested;
                cout << "$" << requested << " has been debited." << endl;
            }
        }
};

int main() {

    Wallet<double> userWallet(509.90);

    try {
        cout << "Attempting to withdraw: $" << 800 << endl;
        userWallet.debit(800);
    } catch(LowBalanceError& ex) {
        cout << ex.what() << endl;
    }

}