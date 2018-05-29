#include <iostream>
#include <vector>
using namespace std;

struct parint {
	int max, min;
};

void llegir_vector(vector<int>& v) {
	cout <<"Escribe el tamano del vector:" << endl;
	int numEst;
	cin >> numEst;
	v = vector<int> (numEst);

	cout << "Escribe los elementos del vector:" << endl;  
	
	for (int i=0; i < numEst; ++i) {
	cin >> v[i];
	}
}

void max_min(const vector<int>& v, parint& hola){
	int mida = v.size();
	int min, max;
	min = max = v[0];
	for (int i = 0; i < mida; ++i) {
			if (v[i] > max) max = v[i];
			if (v[i] < min) min = v[i];
	}
	
	hola.min = min;
	hola.max = max;
	
}

int main() {
    vector<int> v;
   
    llegir_vector(v);
    
    parint sortida;
    max_min(v, sortida);
    cout << "El màxim és: " << sortida.max << " i el mínim: " << sortida.min << endl;
}
