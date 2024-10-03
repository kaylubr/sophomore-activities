#include <iostream>
using namespace std;

int main() {
    int a, b;
    
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    
    int *ptrA = &a;
    int *ptrB = &b;
    
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
    
    cout << "\nAfter swapping:" << endl;
    cout << "First number: " << a << endl;
    cout << "Second number: " << b << endl;
}
