#include <iostream>
#include <string>
using namespace std;

int isValid(string input) {
    int stateTable[5][3] = {  // format: {state, a, b}
        {0, 4, 1},   // state 0: |a -> 4(dead)    |b -> 1
        {1, 4, 2},   // state 1: |a -> 4(dead)    |b -> 2
        {2, 3, 2},   // state 2: |a -> 3          |b -> 2
        {3, 3, 3},   // state 3: |a -> 3          |b -> 3
        {4, 4, 4}    // state 4: dead state ni siya, all invalid char goes to dead
    };

    int state = 0;
    
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        switch (c) {
		    case 'a':
		        state = stateTable[state][1];
		        //cout << "letter|state: " << c << " " << state << endl;
		        break;
		    case 'b':
		        state = stateTable[state][2];
		        //cout << "letter|state: " << c << " " << state << endl;
		        break;
		    default:
		        return 3;
		}
        
        if (state == 4) {
            return 1;
        }
    }

    switch (state) {
	    case 3:
	        return 0;
	    case 2:
	        return 2;
	    default:
	        return 1;
	}  
}

int main() {
	cout << "| NAME AND SECTION:" << endl;
    cout << "  Jake R. Clarin - F2" << endl << endl;
    
    cout << "| ABOUT THE PROGRAM:" << endl;
    cout << "  This program only accepts a string that starts with 'bb' and contains 'ba'." << endl << endl;
    cout << "______________________________________________________________________________" << endl << endl;
    
    string input;
    char tryAgain;
    
    do {
        cout << "Enter a string (a/b): ";
        cin >> input;
        
        cout << endl;

        switch (isValid(input)) {
            case 0:
                cout << input << " is a valid string." << endl;
                break;
            case 1:
                cout << "ERROR: Does not start with 'bb' or contain 'ba'." << endl;
                break;
            case 2:
                cout << "ERROR: Does not contain 'ba'." << endl;
                break;
            case 3:
                cout << "ERROR: Contains invalid characters." << endl;
                break;
        }

        cout << endl;
        cout << "_________________________________________" << endl << endl;
        cout << "| Would you like to try again? (Y/N): ";
        cin >> tryAgain;
        cout << "_________________________________________" << endl << endl;
        
    } while (tryAgain == 'y' || tryAgain == 'Y');

    return 0;
}
