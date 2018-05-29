#include <iostream>
#include <vector>
using namespace std;

void llegir_vector(vector<int>& v) {
	
	int numEst;
	cin >> numEst;
	v = vector<int> (numEst);

	 
	
	for (int i=0; i < numEst; ++i) {
	cin >> v[i];
	}
}

pair<int,int> max_min(const vector<int>& v){
	int mida = v.size();
	int min, max;
	min = max = v[0];
	for (int i = 0; i < mida; ++i) {
			if (v[i] > max) max = v[i];
			if (v[i] < min) min = v[i];
	}
	
	
	return make_pair(max,min);
}

int main() {
    vector<int> v;
   
    llegir_vector(v);
    
    
    pair<int, int> par = max_min(v);
    cout << par.first << " " << par.second << endl;
}
