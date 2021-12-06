//Author - Logan Sayle
//UserID - lss0031
//FileName - project2_Sayle_lss0031.cpp
/*Compilation Instructions -
	Navigate to the directory containing the .cpp file 
	type g++ project3_Sayle_lss0031.cpp -o project3
	To run the program type
	.\project3
*/
/*Outside Sources - 
	I used project 3 hints from the canvas files as a framework for parts of the program.
	I used 2 pages from the website cplusplus.com: "Basic Input/Output" and "vector output to text file"
	I used a stackoverflow page titled "read integers from a file into a vector in c++"
*/
#include <fstream> 
#include <iostream>
#include <vector> 
using namespace std;
//input: File Name
//Return: Places the numbers from the text file into a vector
vector<int> read_file(string);
//input: File Name, Vector to add to file
//Return: Places the content of the given vector into the given file
void write_file(string, vector<int>);
//input: two vectors generated from read_file
//Return: Sorts and merges the vectors into a single vector
vector<int> merge(vector<int>, vector<int>);
//input: vector whose values should be displayed
//Return: outputs the values in the vector line by line
void print_list(vector<int>);

//input: File name to check
//Return: True or False whether the file opened correctly
bool check_file(string);

int main() {
	//variables
	string file1;
	string file2;
	string out_file;
	vector<int> v1;
	vector<int> v2;
	vector<int> merged;

	cout << "***Welcome to Logan's sorting program***\n";
	//Retrieve name of file 1 from user
	do {
		cout << "Enter the first input file name: ";
		cin >> file1;
		if (!check_file(file1))
		{
			cout << "Error Opening File. Please try again.\n";
		}
	} while (!check_file(file1));
	//Receive and display values from file 1
	v1 = read_file(file1);
	cout << "The list of " << v1.size() << " numbers in file " << file1 << " is:";
	print_list(v1);
	//Retrieve name of file 2 from user
	do {
		cout << "\n" << "Enter the second input file name: ";
		cin >> file2;
		if (!check_file(file2))
		{
			cout << "Error Opening File. Please try again.\n";
		}
	} while (!check_file(file2));
	//Receive and display values from file 2
	v2 = read_file(file2);
	cout << "The list of " << v2.size() << " numbers in file " << file1 << " is:";
	print_list(v2);
	//Merge vectors and display sorted values
	merged = merge(v1, v2);
	//Retrieve name of output file from user
	cout << "\n" << "Enter the output file name:";
	cin >> out_file;
	//Output merged vector to output file
	cout << "***Please check the new file - " << out_file << "***";
	cout << "***Goodbye.***";
	write_file(out_file, merged);
}

//User-Defined Functions Implementation
vector<int> read_file(string file) {
	vector<int> v;
	std::ifstream input_file;
	input_file.open(file.c_str());
	if (input_file) {
		int i;
		while(input_file >> i) {
			v.push_back(i);
		}
	}
	input_file.close();
	return v;
}

void write_file(string file, vector<int> v) {
	std::ofstream out_file;
	out_file.open(file.c_str());
	for (int i = 0; i < v.size(); i++)
	{
		out_file << v[i] << "\n";
	}
	out_file.close();
}

vector<int> merge(vector<int> v1, vector<int> v2){
	//variables
	int v1_count = 0;
	int v2_count = 0;
	vector<int> merged;
	/* Compare both vectors. */
	while (v1_count < v1.size() && v2_count < v2.size()) {
		if (v1[v1_count] > v2[v2_count]) {
			merged.push_back(v2[v2_count]);
			v2_count++;
		} else {
			merged.push_back(v1[v1_count]);
			v1_count++;
		}
	}
	/* Add any remaining numbers from vector one. */
	if (v1_count < v1.size()) {
		for (v1_count; v1_count < v1.size(); v1_count++)
		{
			merged.push_back(v1[v1_count]);
		}
	}
	/* Add any remaining numbers from vector two. */
	if (v2_count < v2.size()) {
		for (v2_count; v2_count < v2.size(); v2_count++)
		{
			merged.push_back(v2[v2_count]);
		}
	}
	return merged;
}

void print_list(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << "\n" << v[i];
	}
}

bool check_file(string file) {
	/* Input file stream. (ifstream) */
	std::ifstream stream;
	/* Check whether file exists. */
	stream.open(file.c_str());
	if (stream.fail()) {
		return false;
	}
	stream.close();
	return true;
}