#include <iostream>
#include <vector>
using namespace std;

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

void max_min(const vector<int>& v, int& max, int& min){
	int mida = v.size();
	min = max = v[0];
	for (int i = 0; i < mida; ++i) {
			if (v[i] > max) max = v[i];
			if (v[i] < min) min = v[i];
	}
}

int main() {
    vector<int> v;
    llegir_vector(v);
    int max, min;
      
    max_min(v, max, min);
    cout << "El màxim és: " << max << " i el mínim: " << min << endl;
}
