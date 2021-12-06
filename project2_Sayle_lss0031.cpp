//Author - Logan Sayle
//UserID - lss0031
//FileName - project2_Sayle_lss0031.cpp
/*Compilation Instructions -
	Navigate to the directory containing the .cpp file 
	type g++ project2_Sayle_lss0031.cpp -o project2
	To run the program type
	.\project2
*/
/*Outside Sources - 
	I used google images to look at sample code for questions on how assert works
	I used project 2 hints from the canvas files as a framework for parts of the program.
*/
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;

//variables
const int aaron_accuracy = 33; //constant 1
const int bob_accuracy = 50; //constant 2
int aaron_wins_1 = 0;
int aaron_wins_2 = 0;
int bob_wins = 0;
int charlie_wins = 0;

/*
* Input: A_alive indicates Aaron is alive true for alive, false for dead
* B_alive indicates Bob is alive
* C_alive indicates Charlie is alive
* Return: true if at least two are alive otherwise return false
*/
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);

/*
* Call by reference
* Strategy 1: Everyone shoots to kill the highest accuracy player alive
* Input: B_alive indicates Bob is alive or dead
* C_alive indicates Aaron is alive or dead
* Return: Change B_alive into false if Bob is killed
* Change C_alive into false if Charlie is killed
*/
void Aaron_shoots1(bool& B_alive, bool& C_alive);

/*
* Call by reference
* Input: A_alive indicates Aaron is alive or dead
* C_alive indicates Charlie is alive or dead
* Return: Change A_alive into false if Aaron is killed
* Change C_alive into false if Charlie is killed
*/
void Bob_shoots(bool& A_alive, bool& C_alive);

/*
* Call by reference
* Input: A_alive indicates Aaron is alive or dead
* B_alive indicates Bob is alive or dead
* Return: Change A_alive into false if Aaron is killed
* Change B_alive into false if Bob is killed
*/
void Charlie_shoots(bool& A_alive, bool& B_alive);

/*
* Call by reference
* Strategy 2: Aaron intentionally misses if both are alive
* Input: B_alive indicates Bob is alive or dead
* C_alive indicates Aaron is alive or dead
* Return: Change B_alive into false if Bob is killed
* Change C_alive into false if Charlie is killed
*/
void Aaron_shoots2(bool& B_alive, bool& C_alive);

//Simple method to implement pause function in linux
void Press_any_key(void);

void strat_1(void);

void strat_2(void);

//TEST PROTOTYPES
void test_at_least_two_alive(void);

void test_Aaron_shoots1(void);

void test_Bob_shoots(void);

void test_Charlie_shoots(void);

void test_Aaron_shoots2(void);

int main() {
//Initializes Random number generator's seed and calls test functions
	cout << "*** Welcome to Logan's Duel Simulator ***\n";
	srand(time(0));
	test_at_least_two_alive();
	Press_any_key();
	test_Aaron_shoots1();
	Press_any_key();
	test_Bob_shoots();
	Press_any_key();
	test_Charlie_shoots();
	Press_any_key();
	test_Aaron_shoots2();
	Press_any_key();

//Starts strategy 1 and runs 10,000 times
	cout << "Ready to test strategy 1 (run 10000 times):\n";
	Press_any_key();
	const int TOTAL_RUNS = 10000; //constant 3
	for (int i = 0; i < TOTAL_RUNS; i++ ){
		strat_1();
	}
	cout << "Aaron won " << aaron_wins_1 << "/10000 duels or " << static_cast<double>(aaron_wins_1) /
	TOTAL_RUNS * 100 << "%\n"
 	<< "Bob won " << bob_wins << "/10000 duels or " << static_cast<double>(bob_wins) / TOTAL_RUNS
	* 100 << "%\n"
 	<< "Charlie won " << charlie_wins << "/10000 duels or " << static_cast<double>(charlie_wins) /
	TOTAL_RUNS * 100 << "%\n"
 	<< endl;

	//Reinitializes variables and starts strategy 2 to run 10,000 times
	bob_wins = 0;
	charlie_wins = 0;
	cout << "Ready to test strategy 2 (run 10000 times):\n";
	Press_any_key();
	for (int i = 0; i < TOTAL_RUNS; i++ ){
		strat_2();
	}
	cout << "Aaron won " << aaron_wins_2 << "/10000 duels or " << static_cast<double>(aaron_wins_2) /
	TOTAL_RUNS * 100 << "%\n"
	 << "Bob won " << bob_wins << "/10000 duels or " << static_cast<double>(bob_wins) / TOTAL_RUNS
	* 100 << "%\n"
	 << "Charlie won " << charlie_wins << "/10000 duels or " << static_cast<double>(charlie_wins) /
	TOTAL_RUNS * 100 << "%\n"
	 << endl;


	if (aaron_wins_1 > aaron_wins_2) {
		cout << "Strategy 1 is better than strategy 2.\n";
	}
	else {
		cout << "Strategy 2 is better than strategy 1.\n";
	}
	return 0;
}



//Implementation of functions. Look above for documentation of them.
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
	if (A_alive) {
		if (B_alive || C_alive) {
				return true;
		} else {
			return false;
		}
	}
	else if (B_alive) {
		if (C_alive) {
			return true;
		} else {
			return false;
		}
	}
	else {
		return false;
	}
}

void test_at_least_two_alive(void) {
	cout << "Unit Testing 1: Function - at_least_two_alive()\n";
	cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << "\tCase passed ...\n";
	cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "\tCase passed ...\n";
	cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "\tCase passed ...\n";
	cout << "\tCase 4: Aaron alive, Bob dead, Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << "\tCase passed ...\n";
	cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
	assert(false == at_least_two_alive(false, false, true));
	cout << "\tCase passed ...\n";
	cout << "\tCase 6: Aaron alive, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << "\tCase passed ...\n";
	cout << "\tCase 7: Aaron dead, Bob alive, Charlie dead\n";
	assert(false == at_least_two_alive(false, true, false));
	cout << "\tCase passed ...\n";
	cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(false, false, false));
	cout << "\tCase passed ...\n";
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
	int shootResult = rand() % 100;
	if (shootResult <= aaron_accuracy)
	{
		if (C_alive) {
			C_alive = false;
		}
		else {
			B_alive = false;
		}
	}
}

void test_Aaron_shoots1(void) {
	cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
	bool bob_a;
	bool charlie_a;

	cout << "\tCase 1: Bob alive, Charlie alive\n"
	<< "\t\tAaron is shooting at Charlie\n";
	bob_a = true;
	charlie_a = true;
	Aaron_shoots1(bob_a, charlie_a);
	assert(true == bob_a); //ensure Aaron is targeting right person

	cout << "\tCase 2: Bob dead, Charlie alive\n"
	<< "\t\tAaron is shooting at Charlie\n";
	bob_a = false;
	charlie_a = true;
	Aaron_shoots1(bob_a, charlie_a);
	assert(false == bob_a); //confirm bob is registering as dead

	cout << "\tCase 3: Bob alive, Charlie dead\n"
	<< "\t\tAaron is shooting at Bob\n";
	bob_a = true;
	charlie_a = false;
	Aaron_shoots1(bob_a, charlie_a);
	assert(false == charlie_a); //confirm charlie is dead
}

void Bob_shoots(bool& A_alive, bool& C_alive) {
int shootResult = rand() % 100;
	if (shootResult <= bob_accuracy)
	{
		if (C_alive) {
			C_alive = false;
		}
		else {
			A_alive = false;
		}
	}
}

void test_Bob_shoots(void) {
	cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
	bool aaron_a;
	bool charlie_a;
	
	cout << "\tCase 1: Aaron alive, Charlie alive\n";
	cout << "\t\tBob is shooting at Charlie\n";
	aaron_a = true;
	charlie_a = true;
	Bob_shoots(aaron_a, charlie_a);
	assert(true == aaron_a); //ensure bob is shooting the right person
	
	cout << "\tCase 2: Aaron dead, Charlie alive\n";
	cout << "\t\tBob is shooting at Charlie\n";
	aaron_a = false;
	charlie_a = true;
	Bob_shoots(aaron_a, charlie_a);
	assert(false == aaron_a); //confirm aaron registers as dead
	
	cout << "\tCase 3: Aaron alive, Charlie dead\n";
	cout << "\t\tBob is shooting at Charlie\n";
	aaron_a = true;
	charlie_a = false;
	Bob_shoots(aaron_a, charlie_a);
	assert(false == charlie_a); //confirm charlie registers as dead
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
	if (B_alive) {
		B_alive = false;
	}
	else {
		A_alive = false;
	}
}

void test_Charlie_shoots(void) {
	cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
	bool aaron_a;
	bool bob_a;
	
	cout << "\tCase 1: Aaron alive, Bob alive\n";
	cout << "\t\tCharlie is shooting at Bob\n";
	aaron_a = true;
	bob_a = true;
	Charlie_shoots(aaron_a, bob_a);
	assert(true == aaron_a); //ensure charlie is shooting the right guy
	assert(false == bob_a);
	
	cout << "\tCase 2: Aaron dead, Bob alive\n";
	cout << "\t\tCharlie is shooting at Bob\n";
	aaron_a = false;
	bob_a = true;
	Charlie_shoots(aaron_a, bob_a);
	assert(false == aaron_a); //confirm aaron registers as dead
	assert(false == bob_a);
	
	cout << "\tCase 3: Aaron alive, Bob dead\n";
	cout << "\t\tCharlie is shooting at Aaron\n";
	aaron_a = true;
	bob_a = false;
	Charlie_shoots(aaron_a, bob_a);
	assert(false == bob_a); //confirm bob registers as dead
	assert(false == aaron_a);
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
	int shootResult = rand() % 100;
	if (!B_alive || !C_alive)
	{
		if (shootResult <= aaron_accuracy)
		{
			if (C_alive) {
				C_alive = false;
			}
			else {
				B_alive = false;
			}
		}
	}
}

void test_Aaron_shoots2(void) {
	cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
	bool bob_a;
	bool charlie_a;
	
	cout << "\tCase 1: Bob alive, Charlie alive\n";
	cout << "\t\tAaron intentionally misses his first shot\n";
	bob_a = true;
	charlie_a = true;
	Aaron_shoots2(bob_a, charlie_a);
	assert(true == bob_a);
	assert(true == charlie_a);
	cout << "\t\tBoth Bob and Charlie are alive\n";
	
	cout << "\tCase 2: Bob dead, Charlie alive\n";
	cout << "\t\tAaron is shooting at Charlie\n";
	bob_a = false;
	charlie_a = true;
	Aaron_shoots2(bob_a, charlie_a);
	assert(false == bob_a);
	
	cout << "\tCase 3: Bob alive, Charlie dead\n";
	cout << "\t\tAaron is shooting at Bob\n";
	bob_a = true;
	charlie_a = false;
	Aaron_shoots2(bob_a, charlie_a);
	assert(false == charlie_a);
}

void Press_any_key(void) {
cout << "Press any key to continue...";
cin.ignore().get();
}

void strat_1(void) {
	bool A_alive = true;
	bool B_alive = true;
	bool C_alive = true;

	while (at_least_two_alive(A_alive,B_alive, C_alive)) {
		if (A_alive) //Aaron shoots first
		{
			Aaron_shoots1(B_alive, C_alive);
		}
		if (B_alive) //Bob shoots second;
		{
			Bob_shoots(A_alive, C_alive);
		}
		if (C_alive)
		{
			Charlie_shoots(A_alive, B_alive);
		}
	}

	//determine winner
	if (A_alive)
	{
		aaron_wins_1++;
	} else if (B_alive) {
		bob_wins++;
	} else if (C_alive) {
		charlie_wins++;
	}
}

void strat_2(void) {
	bool A_alive = true;
	bool B_alive = true;
	bool C_alive = true;

	while (at_least_two_alive(A_alive,B_alive, C_alive)) {
		if (A_alive) //Aaron shoots first
		{
			Aaron_shoots2(B_alive, C_alive);
		}
		if (B_alive) //Bob shoots second;
		{
			Bob_shoots(A_alive, C_alive);
		}
		if (C_alive)
		{
			Charlie_shoots(A_alive, B_alive);
		}
	}

	if (A_alive)
	{
		aaron_wins_2++;
	} else if (B_alive) {
		bob_wins++;
	} else if (C_alive) {
		charlie_wins++;
	}
}	