#include <iostream>
#include <cstring>
#include <vector>
#include "main.h"

using namespace std;

int main() {
    string inp;
    bool choice;

    cout << "Input: ";
    getline(cin, inp);
    cout <<"Choice (0)(Codding), (1)Decodding: ";
    cin >> choice;

    switch (choice) {
        case 0:

   // inp = Codding(Base64Table, inp);
    cout << "Output codding: ";
    Codding(Base64Table, inp);
    cout << endl;
    break;
        case 1:
    cout << "Output decodding: " ;
    Decodding(Base64Table, inp);
    cout << endl;
    }
        return 0;
    }
