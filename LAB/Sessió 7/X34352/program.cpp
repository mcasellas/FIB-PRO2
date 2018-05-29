#include <iostream>
#include <string>
#include <map>
using namespace std;

int main () {
    map<string, int> d;

    char c;

    while (cin >> c) {

        string paraula;
        cin >> paraula;

        if (c == 'a') {
            d[paraula]++;
        }
        else cout << d[paraula] << endl;
    }
}
