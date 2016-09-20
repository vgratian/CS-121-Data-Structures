#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

/*
void print_history(string history[], int position, int size) {

    if(position==1) {
        cout << "previous: EMPTY" << endl;
    }
    else {
        cout << "previous: " << endl;
        for(int i = 0; i < size-1; i++) {
            cout << " " << history[i] << endl;
        }
    }
    return;
}*/

int main() {

    vector<string> history;
    int position = -1;
    string input;

    while(true) {
        cout << "go to: ";
        cin >> input;

        //if(input=="end") { break; }

        if(input=="back" || input=="previous") {
            cout << "back!" << endl;

            if(position>0) {
                position--;
                cout << "current website(" << position << "): " <<  history[position] << endl;
                }
            else { cout << "BACK IS EMPTY" << endl; }
        }

/*        if(current=="next" || current=="forward") {
            if(position<size-1) {
                position++;
            }
            else {
                cout << "NEXT IS EMPTY" << endl;
            }
        } */

        else {

            position++;
            if(position < history.size()) { history.resize(position); }

            history.push_back(input);
            cout << "push!" << endl;
            cout << "current website(" << position << "): " <<  history[position] << endl;
            }

        //print_history(history, position, size);

    }

    return 0;
}
