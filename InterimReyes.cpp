#include <conio.h>
#include <iomanip>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	char choice = 'Y';
	double capital = 2000000;
	int amount_to_borrow;
	double months;
	double equivalent_payment;
	double profit;
	double monthly_payment;
	do {
		system("cls");	
		cout << "Amount to be borrowed: ";
		cin >> amount_to_borrow;
		
		//Asks again if the amount of money to be loaned is more than Mr. Montero's capital
		if (amount_to_borrow > capital) {
			continue;
		}
		
		cout << "Number of months: ";
		cin >> months;
		
		//Restarts if the month input is invalid (less than 1 and more than 12)
		if (months < 1 || months > 12) {
			continue;
		}
		
		//Deduct borrowed money from Mr. Montero's capital
		capital -= amount_to_borrow;
		
		if (months >= 9 && months <= 12) {
			//Handles equivalent payment for 9-12 months
			equivalent_payment = amount_to_borrow + ((amount_to_borrow * 0.035) * months);
			monthly_payment = equivalent_payment / months;
			profit = equivalent_payment - amount_to_borrow;
		} else if (months >= 5 && months <= 8) {
			//Handles equivalent payment for 5-8 months
			equivalent_payment = amount_to_borrow + ((amount_to_borrow * 0.03) * months);
			monthly_payment = equivalent_payment / months;
			profit = equivalent_payment - amount_to_borrow;
		} else {
			//Handles equivalent payment for 1-4 months
			equivalent_payment = amount_to_borrow + ((amount_to_borrow * 0.025) * months);
			monthly_payment = equivalent_payment / months;
			profit = equivalent_payment - amount_to_borrow;
		}
		
		//Add borrowed money with profit to capital
		capital += equivalent_payment;
		
		cout << fixed << setprecision(2);
		cout << "Your monthly payment is: " << monthly_payment << endl;
		cout << "Profit: " << profit << endl;
	
		//Resets values everytime the loops run
		equivalent_payment = 0;
		monthly_payment = 0;
		profit = 0;
	
		cout << "Do you want to borrow money again? (Y/N) ";
		choice = toupper(getch());
	} while (choice == 'Y');
	
	cout << "\n\nMr. Montero's money: " << fixed << setprecision(2) << capital;
}
