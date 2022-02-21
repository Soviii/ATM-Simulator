//Author: Sovial Sonzeu
//ATM Simulator
#include <iostream>
#include <ctime>

using namespace std;

class account{
public:
    account(string s, string pw){
        name = s;
        createBankID(bankID);
        setPassword(pw);
    }

    string getName(){
        return name;
    }

    static void createBankID(string &bankID){
        for (int i = 0; i < 8; i++)
            bankID += to_string(rand()%9);
    }

    void getBankID() const{
        cout << "Your bank ID is " << bankID << endl;
    }

    void getBalance() const{
        cout << "Your balance is $" << balance << endl;
    }

    bool emptyAccount() const{
        if (balance==0) {
            return true;
        }
        else {
            return false;
        }
    }
    void depositFunds(int funds){
        if(funds > 0) {
            balance += funds;
            cout << "Done!" << endl;
        }
        else{
            cout << "cannot deposit negative amount of funds" << endl;
        }
    }

    void withdrawFunds(int funds){
        if(funds > balance){
            cout << "Insufficient amount of funds" << endl;
        }
        else{
            balance -= funds;
            cout << "Done!" << endl;
        }
    }

    void setPassword(string p){
        password = p;
    }

    string checkPassword(){
        return password;
    }

private:
    string name;
    int balance = 0;
    string bankID;
    string password;
};

//don't need (could use system("cls") if ran in terminal); only used because of CLion IDE
void clearConsole(){
    for(int i = 0; i < 18; i++){
        cout << endl;
    }
}

bool enterPassword(account Sovi){
    string input;

    for(int x = 2; x >= 0; x--){
        cout << "Please enter your password" << endl;

        getline(cin,input);

        clearConsole();


        if(input != Sovi.checkPassword()){
            cout << "Wrong password, you have " << x << " attempts left" << endl << endl;
        }
        else{
            return true;
        }
    }
    return false;
}

void printInterface(account person){

    cout << "----------------------------------------------";
    cout << endl;
    cout << "1. Deposit Money" << endl;
    cout << "2. Withdraw Money" << endl;
    cout << "3. View Balance" << endl;
    cout << "4. View Bank ID" << endl;
    cout << "5. Logout" << endl;
    cout << "----------------------------------------------" << endl;
}

int main() {
    srand(time(nullptr));

    account person("Sovi", "password");

    int option;
    int funds;
    if(enterPassword(person)){

        cout << "Welcome, " << person.getName() << endl;

        do {
            printInterface(person);

            cin >> option;

            switch (option) {

                //deposit money
                case 1:
                    clearConsole();
                    cout << "Enter amount you are wanting to deposit" << endl;
                    cin >> funds;
                    clearConsole();
                    person.depositFunds(funds);
                    break;

                //withdraw money
                case 2:
                    clearConsole();
                    if(person.emptyAccount()){
                        cout << "You have no funds to withdraw from" << endl;
                        break;
                    }
                    cout << "Enter amount you are wanting to withdraw" << endl;
                    cin >> funds;
                    clearConsole();
                    person.withdrawFunds(funds);
                    break;

                //view balance
                case 3:
                    clearConsole();
                    person.getBalance();
                    break;

                //view bankID
                case 4:
                    clearConsole();
                    person.getBankID();
                    break;

                //logout of ATM
                case 5:
                    clearConsole();
                    cout << "Have a nice day!" << endl;
                    break;
            }
        } while(option!=5);
    }
}
