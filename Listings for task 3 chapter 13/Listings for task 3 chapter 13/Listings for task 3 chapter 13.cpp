// Listings for task 3 chapter 13.cpp


//Listing 13.10.usebrass2.срр
// usebrass2.срр — пример полиморфизма 
// Компилировать вместе с brass.срр 

#include <iostream> 
#include <string> 
#include "Brass.h" 
const int CLIENTS = 4;
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	Brass* p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;
	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter client's name: "; // ввод имени клиента 
		getline(cin, temp);
		cout << "Enter client's account number: "; // ввод номера счета клиента 
		cin >> tempnum;
		cout << "Enter opening balance: $"; // ввод начального баланса 
		cin >> tempbal;
		cout << "Enter 1 for Brass Account or "
			<< "2 for BrassPlus Account: "; // 1 — Brass Account; 2 — BrassPlus Account 
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2 : ";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "Enter the overdraft limit: $"; // ввод предельного овердрафта 
			cin >> tmax;
			cout << "Enter the interest rate "
				<< "as a decimal fraction: "; // ввод процентной ставки 
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}


	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}


	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i]; // освобождение памяти 
	}
	cout << "Done.\n";
	return 0;
}
