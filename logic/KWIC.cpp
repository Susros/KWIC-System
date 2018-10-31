//	Implementation of KWIC.h
//
//  Author        : Zaw Moe Htat (c3193528@uon.edu.au)
//  Course        : SENG 3130 - Software Architecture and Quality Management
//	Assignment    : The Design and Implementation of The KWIC System
//  Program       : B.Eng (Hons) (Software)
//  Last Modified : 11/04/2018

#include "KWIC.h"

namespace SENG3130A1 {
	//	Implementation: Default Constructor
	KWIC::KWIC() {
		input  = std::vector<std::string>();
		output = std::vector<std::string>();
	}

	//	Implementation: Constructor
	KWIC::KWIC(const std::vector<std::string>& _input) {
		input  = _input;
		output = std::vector<std::string>();
	}
	
	//	Implementation: Destructor
	KWIC::~KWIC() {

	}

	//	Implementation: setInput
	void KWIC::setInput(const std::vector<std::string>& _input) {
		input = _input;
	}

	//	Implementation: getOutput
	std::vector<std::string> KWIC::getOutput() {
		//	Iterate input data
		for (std::vector<std::string>::iterator it = input.begin(); it != input.end(); it++) {
			circularlyShift(*it);
		}

		//	Sort and return the output
		return merge_sort(output);
		
	}

	//	Implementation: getInput
	std::vector<std::string> KWIC::getInput() const {
		return input;
	}

	//	Implementation: circularlyShift
	void KWIC::circularlyShift(const std::string& text) {
		//	Create input string stream
		std::istringstream iss(text);

		//	Create vector to store words
		std::vector<std::string> words;

		//	Split text string into words
		copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), std::back_inserter(words));

		//	Shift circularly and insert into output
		for (unsigned i = 0; i < words.size(); i++) {
			//	For constructed text after shifted
			std::string constructed_text = "";
	
			//	Construct words into sentence
			std::vector<std::string>::iterator it = words.begin();			
			
			while(it != words.end()) {
				//	Concat string
				constructed_text += *it;
				
				//	If not end, concat whitespace
				if (it++ != words.end()) {
					constructed_text += " ";
				}
			}

			//	Shift the first word to the end
			words.push_back(words.front());
			words.erase(words.begin());
			
			//	Append the constructed text to output
			output.push_back(constructed_text);
		}
	}

	//	Implementation: merge
	std::vector<std::string> KWIC::merge(const std::vector<std::string>& left, const std::vector<std::string>& right) {
		//	The result for sorting
		std::vector<std::string> result;

		// 	Left iterator
		unsigned left_iterator = 0;
		
		//	Right iterator
		unsigned right_iterator = 0;

		//	Compare two values
		while(left_iterator < left.size() && right_iterator < right.size()) {
			//	Store value in result vector			
			if (left[left_iterator] < right[right_iterator]) {
				result.push_back(left[left_iterator]);
				left_iterator++;
			} else {
				result.push_back(right[right_iterator]);
				right_iterator++;
			}
		}

		//	Remainder left vector
		while(left_iterator < left.size()) {
			result.push_back(left[left_iterator]);
			left_iterator++;
		}

		//	Remainder right vector
		while(right_iterator < right.size()) {
			result.push_back(right[right_iterator]);
			right_iterator++;
		}

		return result;
	} 

	//	Implementation: merge_sort
	std::vector<std::string> KWIC::merge_sort(std::vector<std::string>& o) {
		//	If output only has one value
		if (o.size() == 1) {
			return o;
		}

		//	Get the middle location
		std::vector<std::string>::iterator middle = o.begin() + (o.size() / 2);

		//	Seperate left and right
		std::vector<std::string> left(o.begin(), middle);
		std::vector<std::string> right(middle, o.end());

		//	Sort
		left  = merge_sort(left);
		right = merge_sort(right);
		
		//	Return the result
		return merge(left, right);
	}
	
}
