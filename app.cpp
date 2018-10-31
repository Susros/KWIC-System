//	Interactive Keyword in Context
//
//	This KWIC is designed in Layered Software Architecture.
//	There are three layers used in this design.
//
//	Presentation Layer
//	------------------------
//	In this layer, the input and output are displayed in the screen.
//	This layer uses components from logic layer.
//	
//	Directory: ./
//
//	Files in this layer are:
//	  - app.cpp: User interfaces such as displaying input and output
//
//	Logic Layer
//	---------------------
//	This layer helps the app to perform complete KWIC algorithm and
//	communicate data layer to save and retrieve data value.
//
//	Directory: ./logic/
//
//	Files in this layer are:
//	  - KWIC.h     : Class that contains all necessary methods for
//			  	     KWIC System.
//	  - KWIC.cpp   : KWIC Class implementation
//
//	===========================================================================
//	This app has user interface to add or delete text instead of reading from
//	input file. The app has function to print KWIC results.
//
//	User Interface
//	----------------
//	+ Add command for adding a new line once the key ‘a' is entered.
//	+ Delete command for deleting a line once the key ‘d' is entered.
//	+ Print command for printing shifts sorted alphabetically once the key ‘p' is entered.
//	+ Quit command for exiting the system once the key ‘q' is entered.
//
//
//  Author : Kelvin Yin (contact@kelvinyin.com)

// Include libraries
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

// Logic Layer
#include "logic/KWIC.h"

using namespace std;
using namespace SENG3130A1;

int main() {
	// Print Header
	cout << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "++                                               ++" << endl;
	cout << "++          Key Word in Context System           ++" << endl;
	cout << "++                                               ++" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << endl;

	// Input storage
	vector<string> input;

	// Output storage
	vector<string> output;

	// User command key
	char key = char();

	// User input
	string text = "";

	// To clear dump after string input
	//char dump = char();
	
	// KWIC
	KWIC kwic;

	// User command
	do {
		// Print input message
		cout << "Add(a), Delete(d), Print(p), Quit(q): ";
		
		// Get input key
		cin >> key;

		cin.get();

		// Do as command
		switch(key) {
			// Add text into input
			case 'a':
			case 'A':
				// Print the cursor
				cout << "> ";

				// Keyboard input	
				getline(cin, text);

				// Add to storage
				input.push_back(text);
				
				break;
		
			// Delete text from input
			case 'd':
			case 'D':
                // Check if the list is empty
				if (input.size() == 0) {
                    cout << "------------------------------------" << endl;
                    cout << "No input values." << endl;
                    cout << "------------------------------------" << endl;
				} else {
                    // Print the cursor
                    cout << "> ";

                    // Keyboard input	
                    getline(cin, text);

                    // Remove value from input
                    input.erase(remove(input.begin(), input.end(), text), input.end());
                }
				break;

			// Print KWIC Result
			case 'p':
			case 'P':
				// Check if the list is empty
				if (input.size() == 0) {
                    cout << "------------------------------------" << endl;
                    cout << "No input values." << endl;
                    cout << "------------------------------------" << endl;
				} else {
                    // KWIC Algorithm
                    kwic = KWIC(input);

                    // Output from KWIC
                    output = kwic.getOutput();

                    // Print output
                    cout << "------------------------------------" << endl;

                    for(vector<string>::iterator it = output.begin(); it != output.end(); it++) {
                        cout << *it << endl;
                    }

                    cout << "------------------------------------" << endl; 
                }
				break;

			// Quit the app
			case 'q':
			case 'Q':
				break;

			// Undefined key
			default:
				cout << "Invalid Key!" << endl;

		}

	} while(key != 'q' && key != 'Q');

	cout << endl << "[Process Complete]" << endl;

	return 0;
}
