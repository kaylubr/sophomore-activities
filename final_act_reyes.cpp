#include <iostream>
#include <stdlib.h>

using namespace std;

bool isPrime(int n); 
void isEven(int num);
int doubleFactorial(int num);
int logarithm(int num);
int primorial(int num);

int main() {
    char choice;
    do {
        cout << "----- MAIN MENU -----" << endl;
        cout << "A. DOUBLE FACTORIAL" << endl;
        cout << "B. ODD OR EVEN" << endl;
        cout << "C. LOGARITHM" << endl; 
        cout << "D. PRIMORIAL" << endl;
        cout << "E. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        choice = toupper(choice);
        
        switch (choice) {
            case 'A': {
            	system("cls");
                cout << "--- Double Factorial ---" << endl;
                int val;
                cout << "Enter a number: ";
                cin >> val;
                int factorialVal = doubleFactorial(val);
                cout << "The product of " << val << " using double factorial is " << factorialVal << endl;
                break;
            }
            case 'B': {
            	system("cls");
                cout << "--- Odd or Even ---" << endl;
                int num;
                cout << "Enter a number: ";
                cin >> num;
                isEven(num);
                break;
            }
            case 'C': {
            	system("cls");
                int logNum;
                cout << "--- Logarithm ---" << endl;
                cout << "Enter a number: ";
                cin >> logNum;
                int logValue = logarithm(logNum);
                cout << "The logarithm base 2 value of " << logNum << " is " << logValue << endl; 
                break;
            }
            case 'D': {
            	system("cls");
                cout << "--- Primorial ---" << endl;
                int primNum;
                cout << "Enter a number: ";
                cin >> primNum;
                int primVal = primorial(primNum);
                cout << "The primorial of number " << primNum << " is " << primVal << endl; 
                break;
            }
            case 'E':
                cout << "EXITING..." << endl;
                break;
            default: 
                cout << "INVALID INPUT!!" << endl;
        }
    } while (choice != 'E');
}

int doubleFactorial(int num) {
    if (num < 0) return 0; 

    int factorialVal = 1;
    for (int i = num; i > 0; i -= 2) {
        factorialVal *= i;
    }
    
    return factorialVal;
}

void isEven(int num) {
	if (num % 2 == 0) cout << num << " is an even number" << endl;
	else cout << num << " is an odd number" << endl;
}

int logarithm(int num) {
    if (num < 1) {
    	cout << "\nInvalid Input\n";
    	return 0;
	}

    int base_val = 1;
    int value = 0;

    while (base_val * 2 <= num) {
        base_val *= 2;
        value++;
    }

    return value;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;

    if (num % 2 == 0) return false; 

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int primorial(int n) {
    int accumulator = 1; 
    for (int baseVal = 2; baseVal <= n; baseVal++) {
        if (isPrime(baseVal)) {
            accumulator *= baseVal;
        }
    }
    return accumulator;
}

