#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void print_history(vector<string> history, int position) {

    if(position<1) { ; } // No history
    else {
        cout << "previous: " << endl;
        for(int i = position-1; i >=0; i--) {
            cout << "<" << history[i] << endl;
        }
    }

    if(position+1==history.size()) { ; } // No forward links
    else {
        cout << "forward: " << endl;
        for(int i = position+1; i < history.size(); i++) {
            cout << ">" << history[i] << endl;
        }
    }
    return;
}

int main() {

    vector<string> history;
    int position = -1;
    string input;

    cout << endl <<
        "Welcome to Quixster browser!" << endl <<
        "Enter the url you want to visit" << endl <<
        "Enter 'back' or 'next' to navigate" << endl <<
        "Or 'end' to quit the browser" << endl;

    while(true) {
        cout << endl << "go to: ";
        cin >> input;

        if(input=="end") { break; }

        else if(input=="back" || input=="previous") {
            if(position>0) {
                position--;
                cout << "current website(" << position << "): " <<  history[position] << endl;
                }
            else { cout << "BACK IS EMPTY" << endl; }
        }

        else if(input=="next" || input=="forward") {
            if(position+1<history.size()) {
                position++;
                cout << "current website: " <<  history[position] << endl;
            }
            else { cout << "NEXT IS EMPTY" << endl; }
        }

        else {
            position++;
            if(position < history.size()) { history.resize(position); }
            history.push_back(input);
            cout << "current website(" << position << "): " <<  history[position] << endl;
            }

        print_history(history, position);

    }

    return 0;
}
