// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to remove all occurrences
// of a character in the string
string removeCharRecursive(string str,
						char X)
{
	// Base Case
	if (str.length() == 0) {
		return "";
	}

	// Check the first character
	// of the given string
	if (str[0] == X) {

		// Pass the rest of the string
		// to recursion Function call
		return removeCharRecursive(str.substr(1), X);
	}

	// Add the first character of str
	// and string from recursion
	return str[0]
		+ removeCharRecursive(str.substr(1), X);
}

// Driver Code
int main()
{
	// Given String
	string str = "geeksforgeeks";

	// Given character
	char X = 'e';

	// Function Call
	str = removeCharRecursive(str, X);
	cout << str;
	return 0;
}
