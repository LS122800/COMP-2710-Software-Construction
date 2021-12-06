//Author - Logan Sayle
//UserID - lss0031
//FileName - project1_Sayle_lss0031.cpp
/*Compilation Instructions -
	Navigate to the directory containing the .cpp file
	type g++ project1_Sayle_lss0031.cpp -o project1
	To run the program type
	.\project1
*/
/*Outside Sources -
	Google Images - I googled "c++ code" to see standard c++ format such as #include <iostream>.
	Project 1 Hints - I used the code from the project 1 hints file as a framework to right the rest of the program.
*/

#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main() {
	float loan = -1;
	float interest_rate = -1;
	float monthly_payment = -1;
	float interest_rate_c = -1;
	int cur_month = 0;
	float tot_interest = 0;
	float interest_paid = 0;
	float principal = 0;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	while (loan < 1) {
		cout << "\nLoan Amount: ";
		cin >> loan;
		if (loan < 1)
		{
			cout << "Please Enter a Positive Loan.";
		}
	}

	while (interest_rate < 1) {
		cout << "Interest Rate (percent per year): ";
		cin >> interest_rate;
		if (interest_rate < 1)
		{
			cout << "Please Enter a Positive Interest Rate.\n";
		}
	}
	
	interest_rate /= 12;
	interest_rate_c = interest_rate / 100;

	while (monthly_payment <= (interest_rate_c * loan)) {
		cout << "Monthly Payments: ";
		cin >> monthly_payment;
		if (monthly_payment <= (interest_rate_c * loan))
		{
			cout << "Please Enter a Large Enough Monthly Payment.\n";
		}
	}

	cout << endl;

	cout << "*****************************************************************\n"
 	<< "\tAmortization Table\n"
 	<< "*****************************************************************\n"
 	<< "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

 	while (loan > 0) {
		if (cur_month == 0) {
			cout << cur_month++ << "\t$" << loan;
			if (loan < 1000) cout << "\t";
				cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
			} else {
				if (loan > principal)
				{
					tot_interest += interest_paid;
					interest_paid = loan * interest_rate_c;
					principal = monthly_payment - interest_paid;
					loan -= principal;
				} else {
					tot_interest += interest_paid;
					interest_paid = loan * interest_rate_c;
					principal = loan;
					monthly_payment = principal + interest_paid;
					loan -= principal;
				}
				if (loan > 1000)
				{
					cout << cur_month++ << "\t$" << loan;
					cout << "\t$" << monthly_payment << "\t" << interest_rate << "\t$" << interest_paid << "\t\t$" << principal << "\n";
				} else {
					cout << cur_month++ << "\t$" << loan;
					cout << "\t\t$" << monthly_payment << "\t" << interest_rate << "\t$" << interest_paid << "\t\t$" << principal << "\n";
				}
			}
	}

	tot_interest += interest_paid;
 	cout << "****************************************************************\n";
	cout << "\nIt takes " << --cur_month << " months to pay off "
 	<< "the loan.\n"
 	<< "Total interest paid is: $" << tot_interest;
	cout << endl << endl;
	return 0;
}