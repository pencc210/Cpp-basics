#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;

class Check {
    int number;
    double amount;
    bool cashed;

public:
    Check() : number(0), amount(0.0), cashed(false) {} // Default constructor

    Check(int number, double amount, bool cashed)
        : number(number), amount(amount), cashed(cashed) {}

    // Setters
    void setNumber(int number) { this->number = number; }
    void setAmount(double amount) { this->amount = amount; }
    void setCashed(bool cashed) { this->cashed = cashed; }

    // Getters
    int getNumber() const { return number; }
    double getAmount() const { return amount; }
    bool getCashed() const { return cashed; }

    // Input and Output
    void input();
    void output() const;
};

// Input method
void Check::input() {
    cout << "Enter check number: ";
    cin >> number;

    cout << "Enter check amount: ";
    cin >> amount;

    cout << "Was the check cashed? (1 for yes, 0 for no): ";
    cin >> cashed;
}

// Output method
void Check::output() const {
    cout << "Check Number: " << number << endl;
    cout << "Check Amount: $" << amount << endl;
    cout << "Cashed: " << (cashed ? "Yes" : "No") << endl;
}

// Function Prototypes
void depositsInput(double& deposits);
void getOldBalance(double& oldBalance);
void getNewBalance(double& newBalance);
void makeChecksList(vector<Check>& checksList);
double calculateNewBalance(double oldBalance, double deposits,
                           const vector<Check>& checksList, int& numCashedChecks);
void printCashedChecks(const vector<Check>& checksList);
void printUncashedChecks(const vector<Check>& checksList);

int main() {
    double deposits = 0.0;
    depositsInput(deposits);

    double oldBalance;
    getOldBalance(oldBalance);

    double newBalanceBank;
    getNewBalance(newBalanceBank);

    vector<Check> checksList; // Vector to store checks
    makeChecksList(checksList);

    int numCashedChecks = 0;
    double newCalcBalance = calculateNewBalance(oldBalance, deposits, checksList, numCashedChecks);

    // Calculate difference
    double diff = abs(newBalanceBank - newCalcBalance);

    // Output results
    cout << "Number of checks cashed: " << numCashedChecks << endl;
    cout << "Total deposits: $" << deposits << endl;
    cout << "Difference with bank's balance: $" << diff << endl;

    // Print lists of checks
    if (!checksList.empty()) {
        cout << "\nThe cashed checks were:\n";
        printCashedChecks(checksList);

        cout << "\nThe uncashed checks were:\n";
        printUncashedChecks(checksList);
    } else {
        cout << "\nNo checks entered." << endl;
    }

    return 0;
}

// Function Definitions

// Get deposit input
void depositsInput(double& deposits) {
    double money;
    cout << "Please enter your deposits, enter -1 when done:\n";
    while (true) {
        cin >> money;
        if (money == -1)
            break;
        deposits += money;
    }
}

// Get old balance from user
void getOldBalance(double& oldBalance) {
    cout << "Enter the old balance: ";
    cin >> oldBalance;
}

// Get new balance from user
void getNewBalance(double& newBalance) {
    cout << "Enter the new balance: ";
    cin >> newBalance;
}

// Populate list of checks
void makeChecksList(vector<Check>& checksList) {
    int numOfChecks;
    cout << "Enter the number of checks: ";
    cin >> numOfChecks;

    cout << "For each check, please enter the following:\n";
    for (int i = 0; i < numOfChecks; ++i) {
        Check chk;
        chk.input();
        checksList.push_back(chk);
    }
}

// Calculate new balance
double calculateNewBalance(double oldBalance, double deposits,
                           const vector<Check>& checksList, int& numCashedChecks) {
    double cashedChecks = 0.0;
    for (const auto& check : checksList) {
        if (check.getCashed()) {
            cashedChecks += check.getAmount();
            ++numCashedChecks;
        }
    }
    return oldBalance + deposits - cashedChecks;
}

// Print cashed checks
void printCashedChecks(const vector<Check>& checksList) {
    for (const auto& check : checksList) {
        if (check.getCashed()) {
            check.output();
        }
    }
}

// Print uncashed checks
void printUncashedChecks(const vector<Check>& checksList) {
    for (const auto& check : checksList) {
        if (!check.getCashed()) {
            check.output();
        }
    }
}
