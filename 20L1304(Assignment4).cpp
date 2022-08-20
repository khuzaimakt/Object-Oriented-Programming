#include"bankAccount.h"

// BY: KHUZAIMA TOFEEQ 
// SECTION: BS DS 2A 
// ROLL NO: 20L-1304
// Assignment 4

BankAccount::BankAccount(string name, int ID, double balance): name(name),ID(ID),balance(balance)
{
	total_trans = 0;
	nickName = " ";
	 tran_capacity = 2;
	 transactions = new double[tran_capacity];
	
}

void BankAccount::print() const
{
	cout << "Name: " << name << endl;
	cout << "Nickname: " << nickName << endl;
	cout << "ID: " << ID << endl;
	cout << "Balance: " << balance << endl;
	
		
}

void BankAccount::growTranArray()
{
	double* newarray = new double[tran_capacity * 2];	for (int i = 0; i < tran_capacity * 2; i++)
	{
		newarray[i] = 0;
	}
	for (int i = 0; i < tran_capacity; i++)
	{
		newarray[i] = transactions[i];
    }
	delete[]transactions;
	transactions = newarray;
	newarray = nullptr;
	tran_capacity = tran_capacity * 2;
}
void BankAccount::addtoTran(double amount)
{
	if (total_trans == tran_capacity)
	{
		growTranArray();
		transactions[total_trans] = amount;
		total_trans++;

	}
	else
	{
		transactions[total_trans] = amount;
	total_trans++;
	}
	
}


void BankAccount::withDraw(double amount)
{
	double remain = balance - amount;
	if (remain >= 0)
	{
		addtoTran(-(amount));
		balance = remain;
		
	}
	else
		cout << "Balance not enough to make this transaction " << endl;

}

void BankAccount::deposit(double amount)
{	addtoTran(amount);
	balance = balance + amount;
}

void BankAccount::setNickName(string n)
{
	nickName = n;
}
void BankAccount::printLastNTransactions(int n)const
{
	if (total_trans == 0)
	{
		cout << "No transactions made yet " << endl;	}
  else
		cout << "Transactions: ";
		for (int i = 0, j = total_trans-1; i < n && i< total_trans; i++, j--)
	{
		cout  << transactions[j] << " ";
	}
   cout << endl;


}

double BankAccount::getBalance()const
{
	return balance;
}
BankAccount::~BankAccount()
{
	delete[] transactions;
}
