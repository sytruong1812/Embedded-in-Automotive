#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
*Function: searchPattern
*Discription: Search and compare each word in each line in file.text compare with pattern
*Idea: Find and compare 2 similar words need: equal size, equal value of each word
*Input:
*   path: The path to the file
*   pattern: string to look for in file
*Output: None
*/

void searchPattern1(const string path, const string pattern) {
	ifstream file(path, ios::in | ios::binary);
	if (!file.is_open()) {
		cout << "Failed to open this file! Check the path again." << endl;
	}
	string line;
	int lineNumber = 0;
	/* A loop to check each line in the file and save it to a line variable */
	while (getline(file, line)) {
		lineNumber++;
		size_t patternLength = pattern.length();
		size_t lineLength = line.length();
		/* Nested loop to compare each character in two string and pattern */
		for (size_t i = 0; i <= lineLength - patternLength; i++) {
			/* Variable bool to check the results of comparing each
			   character, conditions to print the result
			 */
			bool found = true;
			for (size_t j = 0; j < patternLength; j++) {
				if (line[i + j] != pattern[j]) {
					found = false;
					break;
				}
			}
			if (found == true) {
				cout << "Line " << lineNumber << ", character at " << i + 1 << endl;
			}
		}
	}
	if (file.is_open() && lineNumber == 0) {
		cout << "No line found in file, file is empty!" << endl;
	}
	file.close();
}

void searchPattern2(const string &path, const string &pattern) {
	ifstream file(path, ios::in | ios::binary);
	if (!file.is_open()) {
		cout << "Error path!" << endl;
	}
	string work;
	int lineNumber = 1;
	int count = 0;

	while (file >> work) {
		//cout << work << endl;
		if (work.length() == pattern.length()) {
			for (size_t i = 0; i < work.length(); i++) {	
				bool found = true;
				count++;
				for (size_t j = 0; j < pattern.length(); j++) {
					if (work[i+j] != pattern[j]) {
						found = false;
						break;
					}
				}
				if (work[i] == '\n') {
					lineNumber++;
					count = 0;
				}
				if (found == true) {
					cout << "Line " << lineNumber << ", character at " << count << endl;
				}
			}
		}
		count = count + work.length();
	}
	file.close();
}

void searchPattern3(const string &path, const string &pattern) {
	ifstream file(path, ios::in | ios::binary);
	if (!file.is_open()) {
		cout << "Error path!" << endl;
		return;
	}
	char character;
	int lineNumber = 1;
	int characterCount = 1;
	int patternIndex = 0;

	while (file.get(character)) {
		if (character == '\n') {
			lineNumber++;
			characterCount = 0;
		}
		if (character == pattern[patternIndex]) {
			patternIndex++;
			if (patternIndex == pattern.length()) {
				cout << "Line " << lineNumber << ", character at " << (characterCount - pattern.length() + 1) << endl;
				patternIndex = 0;
			}
		}
		else {
			patternIndex = 0;
		}
		characterCount++;
	}
	file.close();
}


int main(int argc, char* argv[])
{
	/*searchPattern3("input.txt", "Hello");*/

	if (argc != 3) {
		cout << "Syntax Error!" << endl;
		cout << "<program> <path> <pattern>" << endl;
		return 0;
	}
	else {
		cout << "*-----Program Command Line-----*" << endl;
		searchPattern1(argv[1], argv[2]);
	}
	return 0;
}
