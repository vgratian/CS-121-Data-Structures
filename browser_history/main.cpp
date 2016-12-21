#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class browsing_session {
    public:
        vector<string> history;
        int position = -1; // because we have position++ BEFORE pushing inputted url to history
        // so -1 will become 0 and the first url will become history[0]
        string input;

        void welcome_screen() {
            cout << endl <<
                "Welcome to Quixster browser!" << endl <<
                "Enter the url you want to visit" << endl <<
                "Enter 'back' or 'next' to navigate" << endl <<
                "Or 'end' to quit the browser" << endl;
        }

        void run_session() {
            while(true) {
                cout << endl << "go to: ";
                cin >> input;

                if(input=="end") { break; }
                else if(input=="back") { browse_back(history, &position); }
                else if(input=="next") { browse_forward(history, &position); }
                else {
                    // the position of current website is move to next element
                    position++;
                    // if there are urls before our position they will be deleted by resizing the vector:
                    if(position < history.size()) { history.resize(position); }
                    // new inputted url is pushed into the history
                    history.push_back(input);
                    // new inputted url is printed
                    cout << "current website: " <<  history[position] << endl;
                    }

                print_history(history, position);
            }
        }

        void print_history(vector<string> history, int position) {
            if(position<1) { ; } // Skips if there are no back links
            else {
                cout << "previous: " << endl;
                for(int i = position-1; i >=0; i--) {
                    cout << " " << history[i] << endl;
                }
            }

            if(position+1==history.size()) { ; } // Skips if there are no forward links
            else {
                cout << "forward: " << endl;
                for(int i = position+1; i < history.size(); i++) {
                    cout << " " << history[i] << endl;
                }
            }
            return;
        }

        void browse_back(vector<string> history, int *position) {
            if(*position>0) {
                *position -= 1;
                cout << "current website: " <<  history[*position] << endl;
                }
            else { cout << "BACK IS EMPTY" << endl; }
        }

        void browse_forward(vector<string> history, int *position) {
            if(*position+1<history.size()) {
                *position += 1;
                cout << "current website: " <<  history[*position] << endl;
            }
            else { cout << "NEXT IS EMPTY" << endl; }
        }
};


int main() {

    browsing_session a;
    a.welcome_screen();
    a.run_session();

    return 0;
}
