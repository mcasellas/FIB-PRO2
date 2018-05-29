#include <iostream>
using namespace std;

int main()
{
	cout << "Entra els teus nombre enters: ";
	int valor;
	int sum = 0;
	cin >> valor;
	
	while (valor != 0) {
		sum += valor;
		cin >> valor;
	}
	
	cout << "La suma dels nombres és " << sum <<endl;
}

