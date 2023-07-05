#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
	//A loop to check each line in the file and save it to a line variable
	while (getline(file, line)) {
		lineNumber++;
		size_t patternLength = pattern.length();
		size_t lineLength = line.length();
		// Nested loop to compare each character in two string and pattern
		for (size_t i = 0; i <= lineLength - patternLength; i++) {
			// Variable bool to check the results of comparing each
			//character, conditions to print the result
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
	if (lineNumber == 0) {
		cout << "No line found in file, file is empty!" << endl;
	}
	file.close();
}


void searchPattern2(const string& path, const string& pattern) {
	ifstream file(path, ios::in | ios::binary);
	if (!file.is_open()) {
		cout << "Failed to open this file! Check the path again." << endl;
		return;
	}
	else {
		cout << "Opened file" << endl;
	}

	char character;
	int lineNumber = 0;
	int characterCount = 0;
	int patternIndex = 0;
	size_t lengthPattern = pattern.length();
	/* A loop to check each character in the file and save it to a charater variable */
	while (file.get(character)) {
		characterCount++;
		/*Check the newline character to increment the line counter and reset the word counter*/
		if (character == '\n') {
			lineNumber++;
			characterCount = 0;
		}
		if (character == pattern[patternIndex]) {
			patternIndex++;
			if (patternIndex == lengthPattern) {
				cout << "Line " << lineNumber + 1 << ", character at " << (characterCount - lengthPattern + 1) << endl;
				patternIndex = 0;
			}
		}
		else {
			patternIndex = 0;
		}
	}
	if (lineNumber == 0) {
		cout << "No line found in file, file is empty!" << endl;
	}
	file.close();
}

void searchPattern3(const string& path, const string& pattern) {
	ifstream file(path, ios::in | ios::binary);
	if (!file.is_open()) {
		cout << "Failed to open this file! Check the path again." << endl;
		return;
	}
	else {
		cout << "Opened file" << endl;
	}

	file.seekg(0, ios::end); // Đặt con trỏ đọc tới cuối file để lấy kích thước
	unsigned long long fileSize = file.tellg();		//8byte = 2^(8*8) 
	file.seekg(0, ios::beg); // Đặt con trỏ đọc lại về đầu file
	cout << "Size of file: " << fileSize << endl;

	unsigned long long sizeBuffer = 50;		//Chỉ định size kích thước mỗi lần đọc là 50B

	// Cấp phát động buffer:
	vector<char> buffer(sizeBuffer);

	unsigned long long lineNumber = 0;
	unsigned long long characterCount = 0;	
	unsigned long long patternIndex = 0;

	while (file) {	//Kiểm tra trạng thái đọc file: true/false
		file.read(buffer.data(), sizeBuffer);		//Đọc size (byte) dữ liệu từ file và lưu vào buffer
		unsigned long long bytesRead = file.gcount(); // Số lượng byte thực sự đã đọc được
		for (unsigned long long i = 0; i < bytesRead; i++) {
			characterCount++;
			/*Check the newline character to increment the line counter and reset the word counter*/
			if (buffer[i] == '\n') {
				lineNumber++;
				characterCount = 0;
			}
			if (buffer[i] == pattern[patternIndex]) {
				patternIndex++;
				if (patternIndex == pattern.length()) {
					cout << "Line " << lineNumber + 1 << ", character at " << (characterCount - pattern.length() + 1) << endl;
					patternIndex = 0;
				}
			}
			else {
				patternIndex = 0;
			}
		}
	}
	if (lineNumber == 0 && fileSize == 0) {
		cout << "No line found in file, file is empty!" << endl;
	}
	file.close();
}



int main(int argc, char* argv[])
{
	searchPattern3("input.txt", "789");

	//if (argc != 3) {
	//	cout << "Syntax Error!" << endl;
	//	cout << "<program> <path> <pattern>" << endl;
	//	return 0;
	//}
	//else {
	//	cout << "*-----Program Command Line-----*" << endl;
	//	searchPattern2(argv[1], argv[2]);
	//}
	return 0;
}

