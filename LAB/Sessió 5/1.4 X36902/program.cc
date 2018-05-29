#include <iostream>
#include <stack>
using namespace std;

bool comprovacio(stack<char> pila) {
    char ent;
    cin >> ent;

    while (ent != '.') {
        if (ent == ')') {
            if (not pila.empty() and pila.top() == '(') pila.pop();
            else return false;
        }

        else if (ent == ']') {
            if (not pila.empty() and pila.top() == '[') pila.pop();
            else return false;
        }

        else if (ent == '(' or ent == '[') {
            pila.push(ent);
        }

        cin >> ent;
    }

    if (not pila.empty()) return false;
    return true;
}

int main() {
    stack<char> pila;


    bool result = comprovacio(pila);

    if (result) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
}
