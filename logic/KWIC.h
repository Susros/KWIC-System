//  Logic Layer Component: KWIC
//
//  KWIC System
//
//	The KWIC [Key Word in Context] index system accepts 
//  an ordered set of lines; each line is an ordered set 
//  of words, and each word is an ordered set of characters.
//  Any line may be “circularly shifted” by repeatedly removing
//  the first word and appending it at the end of the line. 
//  The KWIC index system outputs a list of all circular shifts 
//  of all lines in alphabetical order.
//
//  This class will accept input as in vector<string> and return
//  output as in vector<string>.
//
//  Author : Kelvin Yin (contact@kelvinyin.com)

//  Macro
#ifndef __KWIC_H__
#define __KWIC_H__

//  Include libraries
#include <iostream> // String
#include <string>   // String
#include <vector>   // Vector
#include <sstream>  // istringstream, isteam_iterator, back_inserter
#include <iterator> // Iterator

namespace SENG3130A1 {
    class KWIC {
		public :
			//	Default Constructor
			//
			//	This is the default constructor of the class.
			//	This constructor initialise member variables to empty.
			//
			//	Precondition  : No parameter arguments.
			//	Postcondition : Initialise all member variables to empty.
			KWIC();

			//	Constructor with parameter argument
			//
			//	This constrcut accept input and assign input to member
			//	variable.
			//
			//	Precondition  : String vector type data is passed as an argument.
			//	Postcondition : Assign the data value to member variable, input.
			KWIC(const std::vector<std::string>& _input);

			//	Destructor
			//
			//	Precondition  : No parameter argument
			//	Postcondition : Release memory
			~KWIC();

			//
			//	Mutation Functions
			//

			//	Method: setInput
			//
			//	This method set input value
			//
			//	Precondition  : The object has been instantiated. The parameter argument
			//					is non-empty string vector object.
			//	Postcondition : Set input value
			void setInput(const std::vector<std::string>& _input);

			//	Method: getOutput
			//
			//	This method perform KWIC algorithm and return the shifted and sorted list
			//	of string.
			//
			//	Algorithm:
			//	1. Iterate Input. Do:
			//		a. circularly shift
			//	2. Return output
			//
			//	Precondition  : The object has been instantiated. No parameter argument.
			//	Postcondition : Perform the algorithm and return output
			std::vector<std::string> getOutput(); 

			//
			//	Quary Functions
			//
			
			//	Method: getInput
			//
			//	This method return the input
			//
			//	Precondition  : The object has been instantiated. No parameter argument.
			//	Postcondition : Return input.
			std::vector<std::string> getInput() const;

		private :
			//
			//	Member Variable
			//
			
			//	Input data
			std::vector<std::string> input;

			//	Output data
			std::vector<std::string> output;

			//
			//	Member Functions
			//

			//	Method: circularlyShift
			//
			//	This method read text string and circularly shift it then store
			//	it in output variable.
			//
			//	Algorithm:
			//	1. Split text into words and get word counts
			//	2. Loop from 0 to number of work and do:
			//		a. Get the first word
			//		b. Append it in output
			//
			// 	Precondition  : One non-empty string parameter, text, is passed as an argument.
			//	Postcondition : Text is splitted into words and run the algorithm to shit circularly.
			void circularlyShift(const std::string& text);

			//	Method: merge
			//
			//	This method is used to sort output in ascending order
			//
			//	Precondition  : The object has been instantiated.
			//					The parameter arguments have two vector string.
			// 	Postcondition : Sort the values and return it.
			std::vector<std::string> merge(const std::vector<std::string>& left, const std::vector<std::string>& right);

			//	Method: merge_sort
			//
			// 	This method is used to merge the sorting
			//
			//	Precondition  : The object has been instantiated. No parameter arguments.
			//	Postcondition :	The output is splitted into half and return the sortted result.
			std::vector<std::string> merge_sort(std::vector<std::string>& o);
	};
}

#endif
