#include <bits/stdc++.h>
#include<time.h>
using namespace std;


class Account{
	int accountNo;
	int balance;
	public:
	Account(int accountNo){
		this->accountNo = accountNo;
		this->balance = 1500;
	}
	int getAccountNo(){
		return this->accountNo;
	}
	int getBalance(){
		return this->balance;
	};
	bool setBalance(int amount,int withdraw){
		if(withdraw){
			if(amount > this->balance){
				return false;
			}
			else{
				this->balance -= amount;
				return true;
			}
		} 
		this->balance += amount;
		return true;
	};
};

class ATM{
	unordered_map<int, Account*>account;
	public:
	Account* getAccount(int accNo){
		if(account.count(accNo)){
			return account[accNo];
		}
		return NULL;
	}
//	void createTestAccount(int accNo){ // for test purpose uncommnent this function
//		account.insert({accNo, new Account(accNo)});
//	}
	int createAccount(){
		int newAccNo = rand();
		account.insert({newAccNo, new Account(newAccNo)});
		return newAccNo;
	}
	void removeAccount(int accNo){
		account.erase(accNo);
	}
};

int main() {
	
	srand(time(NULL));
	int userInput;
	int accNo;
	ATM *newAtm = new ATM();
//	newAtm->createTestAccount(123); // for test purpose uncomment this line.
	do{
		cout<<"Select one of the following option -:"<<"\n";
		cout<<"1. Open new Account"<<"\n";
		cout<<"2. Existing Account"<<"\n";
		cout<<"3. Exit"<<"\n";
		cin>>userInput;
		if(userInput == 1){
			cout<<"your account number is "<<newAtm->createAccount()<<"\n";
		}
		else if(userInput == 2){
			cout<<"Please enter your account number:"<<"\n";
			cin>>accNo;
			Account *account = newAtm->getAccount(accNo);
			if(account){
				int existingUserInput;
				int amount;
				do{
					cout<<"Please Select one of the following options for Account No "<<account->getAccountNo()<<" -:"<<"\n";
					cout<<"1. Check balance"<<"\n";
					cout<<"2. Withdraw amount"<<"\n";
					cout<<"3. Deposit amount"<<"\n";
					cout<<"4. Close Account"<<"\n";
					cout<<"5. Exit"<<"\n";
					cin>>existingUserInput;
					if(existingUserInput == 1){
						cout<<"current balance Rs "<<account->getBalance()<<"\n";
					}
					else if(existingUserInput == 2){
						cout<<"Enter withdraw amount:"<<"\n";
						cin>>amount;
						if(account->setBalance(amount, 1)){
							cout<<"Amount Withdrawn"<<"\n";
						} else {
							cout<<"Balance is less then amount to be withdrawn"<<"\n";
						}
					}
					else if(existingUserInput == 3){
						cout<<"Enter deposit amount:"<<"\n";
						cin>>amount;
						account->setBalance(amount, 0);
						cout<<"Amount successfully deposited"<<"\n";
					}
					else if(existingUserInput == 4){
						cout<<"Your Last balance is Rs "<<account->getBalance()<<"\n";
						newAtm->removeAccount(account->getAccountNo());
						cout<<"Account Removed"<<"\n";
						break;
					}
					else if(existingUserInput != 5){
						cout<<"Incorrect Option selected"<<"\n";
					}
				}while(existingUserInput != 5);
			}
			else{
				cout<<"Account Does not exist"<<"\n";
			}
		}
		else if(userInput != 3){
			cout<<"Incorrect Option selected"<<"\n";
		}
	}while(userInput != 3);
}
