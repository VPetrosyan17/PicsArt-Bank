#include <iostream>
#include <string>
#include <unordered_map>

class Bank{
	private:

	//map to store customers balance
	std::unordered_map<std::string, int> customers;

	public:
	
	//Deposit amount to account
	//if does't exist create / if exist adding amount 
	void deposit(const std::string& accountNumber, int amount){
		if(customers.find(accountNumber) == customers.end()){
			customers[accountNumber] = amount;
		}else{
			customers[accountNumber] += amount;
		}
		std::cout << "Deposited " << amount <<"$"<< " Into account: " << accountNumber << std::endl;
	}
	
	//Withdraw amount from one account to another 
	void withdraw(const std::string& accountNumberFrom, const std::string& accountNumberTo, int amount){
		if(customers.find(accountNumberFrom) == customers.end()){
			std::cout<< "Account: " << accountNumberFrom << " does't exist" << std::endl;
		}else if(customers.find(accountNumberTo) == customers.end()){
			std::cout<< "Account: " << accountNumberTo << " does't exist" << std::endl;
		}else if(customers[accountNumberFrom] < amount){
			std::cout << "Something went wrong in account: " << accountNumberFrom << std::endl;
		}else if(customers[accountNumberTo] < amount){
			std::cout << "Something went wrong in account: " << accountNumberTo << std::endl;
		}else{
			customers[accountNumberFrom] -= amount;
			customers[accountNumberTo] += amount;
			std::cout << "Withdrawn amount: " << amount <<"$"<< " from " << accountNumberFrom << " to  " << accountNumberTo << std::endl;
		}
	}

	//balance getter
	int getBalance(const std::string accountNumber){
		return customers[accountNumber];
	}
};

int main(){

	Bank bank;

	//deposit amounts	
	bank.deposit("4089 6785 3894 1009", 2000);
	bank.deposit("1234 2343 3455 0098", 5000);

	//withdraw amount from one account into another
	bank.withdraw("4089 6785 3894 1009", "1234 2343 3455 0098", 200);

	//print the amount of accounts
    std::cout << "The balance of account: 4089 6785 3894 1009 : " << bank.getBalance("4089 6785 3894 1009") <<"$"<< std::endl;
	std::cout << "The balance of account: 1234 2343 3455 0098 : " << bank.getBalance("1234 2343 3455 0098") <<"$"<< std::endl;

	//account does't exist
	bank.withdraw("1111 2222 3333 4444", "1234 2343 3455 0098", 300);

	//insuffiecent balance
	bank.withdraw("1234 2343 3455 0098", "4089 6785 3894 1009", 6000);

}
