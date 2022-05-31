#include<iostream>
using namespace std;

class bankAcc{
    protected:
    int accnum;
    double balance;

    public:

    //constructor with parameters
    bankAcc(int an = 0, double b = 0){
        accnum = an;
        balance = b;

    }

    void setBal(double bal){
        balance = bal;
    }

    void setNum(int an){
        accnum = an;
    }
    int getnum(){
        return accnum;
    }

    double getbal(){
        return balance;
    }

    void deposite(double depositeAmmount){
        balance+=depositeAmmount;
    }

    void withdraw(double withdrawAmmount){
        balance -= withdrawAmmount;
    }

    void disp(){
        cout<<"\nAccount number: "<<accnum;
        cout<<"\nCurrent Balance: "<<balance;
    }
    ~bankAcc(){}


};

class checkingAccount: public bankAcc{
    protected:
    double interest;
    double minbalance;
    double serviceCharges;


    public:

    checkingAccount(){
        interest = 0;
        minbalance = 0;
        serviceCharges = 0;
        balance = 0;
    }

    void setInterest(double inter){
        interest = inter;
    }

    int getInterest(){
        return interest;
    }

    void setMinBalance(double minbal){
        minbalance = minbal;

    }

    double getMinBalance(){
        return minbalance;
    }

    void setServiceCharges(double sc){
        serviceCharges = sc;
    }

    int getServiceCharges(){
        return serviceCharges;
    }

    bool checkMin(){
        if(balance < minbalance){
            return true;
            
        }
        return false;
    }

    void postInterest(){
        cout<<"\nthe customer is now receiving interest from the bank...\n";
        //interest has to be in percentage
        balance += (interest/100)*balance;
    }

    void withdraw(double with){
        bankAcc::withdraw(with);//overriding
        //for each withdrawl, interest would be received by the customer so calling postInterest function here
        //therefore, after each withdrawl, the balance would be: balance = (balance - withdrawl) + interest;
        postInterest();
        cout<<"Withdraw successful\n";
        if(checkMin()){
            balance-=serviceCharges;
        }

    }  

    void disp(){
        cout<<"\nAccount Details: \n";
        bankAcc::disp();

    }
    ~checkingAccount(){}


};

class savingsAccount: public bankAcc{
    protected:
    double interest;

    public:

    savingsAccount(){
        interest = 0; 
        balance = 0;

    }
    void setInterest(double in){
        interest = in;
    }

    int getInterest(){
        return interest;
    }
    void postInterest(){
        balance += (interest/100)*balance;
    }

    void withdraw(double with){
        bankAcc::withdraw(with);//overriding
        postInterest();
    }

    void disp(){
        cout<<"\nAccount Details: \n";
        bankAcc::disp();
    }
    ~savingsAccount(){}
};

void checkingAccMenu(){
    int num=0;
    double bal=0;
    cout<<"\nWELCOME TO CHECKING ACCOUNT\n";
    cout<<"Please Enter your account number and the initial balance that you want to store: ";
    cin>>num>>bal;
    checkingAccount user1;
    user1.setNum(num);
    user1.setBal(bal);
    double minbal;
    cout<<"\nPlease enter the minumum balance of your account: ";
    cin>>minbal;
    user1.setMinBalance(minbal);
    double interest;
    cout<<"Please enter the percentage interest: ";
    cin>>interest;
    user1.setInterest(interest);
    double servicecharges;
    cout<<"Please enter the service charges: ";
    cin>>servicecharges;
    user1.setServiceCharges(servicecharges);
    cout<<"account details stored successfully";
    int choice;
    cout<<"\nPlease enter an option:\n1. Deposite amount\n2. Retrieve account number\n3. retrieve balance\n4. retrieve interest rate\n5. retrieve minimum balance\n6. retrieve service charges\n7. Withdraw\n8. Display Details.\nENTER ANY OTHER NUMBER TO EXIT\n--->";
    cin>>choice;
    while(choice>=1 && choice <=8){
        if(choice == 1){
            double depositeAmm;
            cout<<"Please enter the amount you want to deposite: ";
            cin>>depositeAmm;
            user1.deposite(depositeAmm);
        }
        else if(choice == 2)
            cout<<user1.getnum();
        else if(choice == 3)
            cout<<user1.getbal();
        
        else if(choice == 4)
            cout<<user1.getInterest();
        
        else if(choice == 5)
            cout<<user1.getMinBalance();
        
        else if(choice == 6)
            cout<<user1.getServiceCharges();
        else if(choice == 7){
            double withdraw;
            cout<<"\nPlease enter the amount that you want to withdraw: ";
            cin>>withdraw;
            user1.withdraw(withdraw);
        }
        else if(choice == 8)
            user1.disp();
        else
            break;
        cout<<"\nPlease enter an option:\n1. Deposite amount\n2. Retrieve account number\n3. retrieve balance\n4. retrieve interest rate\n5. retrieve minimum balance\n6. retrieve service charges\n7. Withdraw\n8. Display Details.\nENTER ANY OTHER NUMBER TO EXIT\n--->";
        cin>>choice;
    }

}

void savingsAccMenu(){
    int num=0;
    double bal=0;
    cout<<"\nWELCOME TO SAVINGS ACCOUNT\n";
    cout<<"Please Enter your account number and the initial balance that you want to store: ";
    cin>>num>>bal;
    savingsAccount user1;
    user1.setNum(num);
    user1.setBal(bal);
    cout<<"\naccount details stored successfully\n";

    int choice;
    cout<<"\nPlease enter an option:\n1. Deposite amount\n2. Retrieve account number\n3. retrieve balance\n4. retrieve interest rate\n5. Withdraw\n6. Display Details.\n7. set interest\nENTER ANY OTHER NUMBER TO EXIT\n--->";
    cin>>choice;
    while(choice>=1 && choice <=8){
        if(choice == 1){
            double depositeAmm;
            cout<<"Please enter the amount you want to deposite: ";
            cin>>depositeAmm;
            user1.deposite(depositeAmm);
        }
        else if(choice == 2)
            cout<<user1.getnum();
        else if(choice == 3)
            cout<<user1.getbal();
        
        else if(choice == 4)
            cout<<user1.getInterest();
        
        else if(choice == 5){
            double withdraw;
            cout<<"\nPlease enter the amount that you want to withdraw: ";
            cin>>withdraw;
            user1.withdraw(withdraw);
        }
        else if(choice == 6)
            user1.disp();
        
        else if(choice == 7){
            double interest;
            cout<<"Please enter the interest is percentage: ";
            cin>>interest;
            user1.setInterest(interest);
        }
            
        else
            break;
        cout<<"\nPlease enter an option:\n1. Deposite amount\n2. Retrieve account number\n3. retrieve balance\n4. retrieve interest rate\n5. Withdraw\n6. Display Details.\n7. set interest\nENTER ANY OTHER NUMBER TO EXIT\n--->";
        cin>>choice;
    }

}

int main(){
    int accountchoice;
    cout<<"Enter 1 or 2:\n1. Checking Account\n2. Saving Account...";
    cin>>accountchoice;
    while(accountchoice !=1 && accountchoice != 2){
        cout<<"\nEnter a valid choice(1 or 2) 1 or 2:\n1. Checking Account\n2. Saving Account...";
        cin>>accountchoice;
    }
    if(accountchoice == 1){
        checkingAccMenu();
    }
    else
        savingsAccMenu();
}

