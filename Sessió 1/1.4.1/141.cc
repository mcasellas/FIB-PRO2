#include <iostream>
using namespace std;

void intercanvia(int& x, int& y) {
	int aux = x;
	x = y;
	y = aux;
}

int main () {
	cout << "Entra els dos valors a intercanviar:" << endl;
	int x,y;
	cin >> x >> y;
	intercanvia(x,y);
	cout << x << " " << y << endl;
}
