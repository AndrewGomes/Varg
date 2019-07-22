// Author: Andrew Gomes, NID: an289864
// Date: 8/22/2017
// Variadic argument methods - assignment #1

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "Varg.h"

// Reads in a list of arguments and determines the most frequently occuring character. 
// The first argument must be an integer to determine the size of the list.
char mostFrequentChar(int n, ...) {
	if (n == 0) {
		return '\0';
	}
	
	va_list args;
	va_start(args, n);
	
	// Read the list of arguments and store the number of times that specific character occurs
	// into an int array in which each position in the array indicates a position in the alphabet.
	// The element at that position is the count of occurences.
	// Therefore, if counter[25] == 3, then that means 'z' occured 3 times.
	//
	// However, at the same time, we want to return the FIRST character to reach that number of occurences.
	// If you call this function using: mostFrequentChar(5, 'c', 'b', 'c', 'b', 'a') then the output should be 'c'
	// as 'c' was the first character to reach two occurences. 'b' also reached two occurences but it came after 'c'.
	int i;
	int counter[26] = { 0 };
	char firstHighestChar = '\0';
	int mostFrequentOccurences = 0;
	for (i = 0; i < n; i++) {
		int index = (va_arg(args, int) - 'a');
		counter[index]++;
		if (counter[index] > mostFrequentOccurences) {
			firstHighestChar = index + 'a';
			mostFrequentOccurences = counter[index];
		}
	}
	
	va_end(args);
	return firstHighestChar;
}

// Reads in a list of arguments and determines the most frequently occuring character. 
// Does not require the first argument to be an integer indicating size.
// The last argument must be '\0' to stop the function.
char fancyMostFrequentChar(char c, ...) {
	if (c == '\0') {
		return '\0';
	}
	
	va_list args;
	va_start(args, c);

	int counter[26] = { 0 };
	char firstHighestChar = '\0';
	int mostFrequentOccurences = 0;
	
	// Counts the first argument since it's not being used as a size variable
	// but instead being used as an actual argument!
	counter[c - 'a']++;
	firstHighestChar = c;
	mostFrequentOccurences = 1;
	
	// Same as the above function but keeps reading until encountering '\0'.
	char next;
	while ((next = va_arg(args, int)) != '\0') {
		int index = next - 'a';
		counter[index]++;
		if (counter[index] > mostFrequentOccurences) {
			firstHighestChar = index + 'a';
			mostFrequentOccurences = counter[index];
		}
	}
	
	va_end(args);
	return firstHighestChar;
}

double difficultyRating() {
	return 2.00;
}

double hoursSpent() {
	return 3.28;
}