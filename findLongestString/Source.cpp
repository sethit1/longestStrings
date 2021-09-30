
#include<vector> 
#include<fstream>
#include<iostream> 

void getFile(void); // load CSV file
void ColumnNum(std::fstream&);
void getColumnNum(std::fstream&); // return number of columns in CSV file
void longestStr(int, std::fstream&); // returns vector holding the length of the longest string for each column
int getStrSize(std::fstream&); // get string separated by commas
void printStrSizes(std::vector<int>, int);

const char COMMA = '|';
const char NEWLINE = '\n';

int main() {
	getFile();
}


void getFile() {
	std::fstream csvFile;
	std::string fileName;
	std::cin >> fileName; 
	csvFile.open(fileName, std::ios::in); 
	if (csvFile.is_open()) { 
		ColumnNum(csvFile);
	}
	else { std::cout << "File didn't open.\n"; }
}

void ColumnNum(std::fstream& csvFile) {
	char c;
	int columnNum = 1;
	while (csvFile.get(c)) {
		if (c == COMMA) {
			columnNum++;
		}
		else if (c == NEWLINE) {
				break;
			}
		
	}
	longestStr(columnNum, csvFile);
}

void longestStr(int columnNum, std::fstream& csvFile) {
	std::vector<int> longestStrings(columnNum, 0);
	int strSize;
	while(!csvFile.eof())
	for (int i = 0; i < columnNum; i++) {
		strSize = getStrSize(csvFile);
		if (longestStrings[i] < strSize) {
			longestStrings[i] = strSize;
		}
	}
	printStrSizes(longestStrings, columnNum);
}

int getStrSize(std::fstream& csvFile) {
	int strSize = 0;
	char c;
	while (csvFile.get(c)) {
		if (c == COMMA || c == NEWLINE) {
			break;
		}
		else {
			strSize++; 
		}
	}
	return strSize;
}


void printStrSizes(std::vector<int> longestStrings, int columnNum) {
	for (int i = 0; i < columnNum; i++) {
		std::cout << "Column " << i << ": " << longestStrings[i] << '\n';
	}
}