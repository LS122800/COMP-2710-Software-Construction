//Author - Logan Sayle
//UserID - lss0031
//FileName - project4_Sayle_lss0031.cpp
/*Compilation Instructions -
	Navigate to the directory containing the .cpp file 
	type g++ project4_Sayle_lss0031.cpp -o project3
	To run the program type
	.\project4
*/
/*Outside Sources - 
	* I used the hints file to start the project
	* I discussed the assignment with an upperclassman at a club meeting and asked 
	  him about handling the linked list and he recommended making a class for it.
	* Used the w3schools page for "C++ Classes and Objects" to learn how to make the class
*/

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//#define UNIT_TESTING

int tot_pts = 0;

struct trivia_node {
	string question;
	string answer;
	int points;
};

typedef trivia_node* ptr_node;

class quiz_linked_list {
	public:
		quiz_linked_list(string q, string a, int p, quiz_linked_list* n) {
			node.question = q; 
			node.answer = a; 
			node.points = p; 
			next = n;
		}
		quiz_linked_list* get_next() {
			return next;
		}
		string get_question() {
			return node.question;
		}
		string get_answer() {
			return node.answer;
		}
		int get_pts() {
			return node.points;
		}
		trivia_node node;
		quiz_linked_list* next;
};

typedef quiz_linked_list* ptr_list;

ptr_list initialize() {
	ptr_list front;
	string q = "What is the best-selling video game of all time? (Hint: Minecraft or Tetris)";
	string a = "Tetris";
	int p = 20;
	front = new quiz_linked_list(q, a, p, NULL);
	q = "What was Bank of America's original name? (Hint Bank of Italy or Bank of Germany)";
	a = "Bank of Italy";
	p = 50;
	front = new quiz_linked_list(q, a, p, front);
	q = "How long was the shortest war on record? (Hint: how many minutes)";
	a = "38";
	p = 100;
	front = new quiz_linked_list(q, a, p, front);
	return front;
}

ptr_list add_node(string q, string a, int p, ptr_list n) {
	ptr_list front = new quiz_linked_list(q, a, p, n);
	return front;
}

int ask_question(ptr_list list, int q) {
	if (q <= 0) {
		cout << "ERROR - Number of Questions Must Be Greater Than 0\n";
		return 1;
	}
	else if (list == NULL) {
		cout << "ERROR - List is Empty\n";
		return 1;
	}
	else {
		ptr_list front = list;
		ptr_list next = front->get_next();
		int size = 1;
		while (next != NULL) {
			next = next->get_next();
			size++;
		}
		if (size < q) {
			cout << "Warning - there are only " << size << " trivia questions\n";
			return 1;
		} else {
			next = front;
			string a;
			int index = 0;
			do {
				cout << "Question: " << next->get_question() << endl;
				cout << "Answer: ";
				getline(cin, a);
				if (a == "") {
					getline(cin, a);
				}
				if (a == next->get_answer()) {
					cout << "Your answer is correct. You receive " << next->get_pts() << " points.\n";
					tot_pts += next->get_pts();
				} else {
					cout << "Your answer is wrong. The correct answer is: " << next->get_answer() << endl;
				}
				cout << "Your total points : " << tot_pts << "\n\n";
				next = next->get_next();
				index++;
			} while (next != NULL && index < q);
			return 0;
		}
	}
}

ptr_list input_question(ptr_list list) {
	ptr_list front = list;
	string q;
	string a;
	int p;
	cout << "Enter a question: ";
	getline(cin, q);
	cout << "Enter an answer: ";
	getline(cin, a);
	cout << "Enter award points: ";
	while (!(cin >> p) || p <= 0) {
		cout << "ERROR - Points must be greater than 0: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	front = add_node(q, a, p, front);
	cin.clear();
	cin.ignore(1000, '\n');
	return front;
}

void test_ask_question() {
	ptr_list list = initialize();
	int test;
	cout << "*** This is a debug version ***\n";
	cout << "Unit test case 1: Ask no questions. The program should give a warning message.\n";
	test = ask_question(list, 0);
	cout << "Case 1 Passed\n";
	cout << "\nUnit Test Case 2.1: Ask 1 question, tester answers incorrect answer.\n";
	test = ask_question(list, 1);
	assert(0 == tot_pts);
	cout << "Case 2.1 Passed\n";
	cout << "\n Unit Test Case 2.2: Ask 1 question, tester answers correct answer.\n";
	test = ask_question(list, 1);
	assert(100 == tot_pts);
	cout << "Case 2.2 Passed\n";
	tot_pts = 0;
	cout << "\n Unit Test Case 3.1: Ask 3 questions, give all incorrect answers.\n";
	test = ask_question(list, 3);
	assert(0 == tot_pts);
	cout << "Case 3.1 Passed\n";
	cout << "\n Unit Test Case 3.2: Ask 3 questions, give all correct answers.\n";
	test = ask_question(list, 3);
	assert(170 == tot_pts);
	cout << "Case 3.2 Passed \n";
	cout << "\nTest Case 4: Ask 5 questions. The program should give a warning\n";
	test = ask_question(list, 5);
	cout<<"*** End of Debugging Version***";
}

int main() {
	#ifdef UNIT_TESTING
	test_ask_question();
	#else
	ptr_list front = NULL;
	cout << "*** Welcome to Logan's trivia quiz game ***\n";
	cout << "Do you want to input your own questions? (Yes/No): ";
	string ans;
	getline(cin, ans);
	while (ans != "Yes" && ans != "No") {
		cout << "ERROR: Please enter valid response (Yes/No): ";
		getline(cin, ans);
	}
	if (ans == "Yes") {
		string cont;
		do {
			front = input_question(front);
			cout << "Continue? (Yes/No): ";
			getline(cin, cont);
			while (cont != "Yes" && cont != "No") {
				cout << "ERROR: Please enter valid response (Yes/No): ";
				getline(cin, cont);
			}
		} while (cont == "Yes");
	} else {
		front = initialize();
	}
	cout << endl;
	cout << "How many questions would you like to answer? ";
	int questions;
	cin >> questions;
	int test;
	test = ask_question(front, questions);
	while (test == 1) {
		cout << "ERROR: Please enter valid number: ";
		cin >> questions;
		test = ask_question(front, questions);
	}
	cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
	#endif
}