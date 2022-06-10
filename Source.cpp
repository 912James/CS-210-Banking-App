#include <iostream>
#include <iomanip>
#include <ostream>

using namespace std;

	int main() {

		// Variable declaration
		float initialInvestment;
		float numberOfYears;
		float annualInterest;
		float numberOfMonths;
		float monthlyDeposits;
		float totalAmount;
		float interestAmount;
		float yearlyInterestTotal;
		float initialOpening;


		// Display the customer first sees when running the application
		cout << "**********************************" << endl;
		cout << "********** Data Input ************" << endl;
		cout << "Initial Investment Amount:" << endl;
		cout << "Monthly Deposit:" << endl;
		cout << "Annual Interest:" << endl;
		cout << "Number of years:" << endl;
		cout << "**********************************" << endl;
		cout << endl;

		// Waits for user input before proceeding
		system("PAUSE"); 
		
		// User Input
		cout << endl;
		cout << "**********************************" << endl;
		cout << "********** Data Input ************" << endl;
		cout << "Initial Investment Amount:" << endl;
		cin >> initialInvestment;
		cout << "Monthly Deposit:" << endl;
		cin >> monthlyDeposits;
		cout << "Annual Interest:" << endl;
		cin >> annualInterest;
		cout << "Number of years:" << endl;
		cin >> numberOfYears;
			numberOfMonths = numberOfYears * 12;
		cout << "**********************************" << endl;
		cout << endl;

		// Wait for user input before proceeding
		system("PAUSE"); 

		// Displays the second screen that airgead required showing the customers input
		cout << endl;
		cout << "**********************************" << endl;
		cout << "********** Data Input ************" << endl;
		cout << "Initial Investment Amount: $" << initialInvestment << endl;
		cout << "Monthly Deposit: $" << monthlyDeposits << endl;
		cout << "Annual Interest: " << annualInterest << "%" <<  endl;
		cout << "Number of years: " << numberOfYears << endl;
		cout << "**********************************" << endl;
		cout << endl;

		// Pause gives the user the chance to read their input before seeing the breakdowns
		system("PAUSE");


			//Update total amount to initial investment by initializing totalAmount equals initialInvestment. this is the foundation of the calculations.
			totalAmount = initialInvestment;

			//Displays the year end totals if the customer does no monthly deposits
			cout << endl << "    Balance and Interest Without Additional Monthly Deposits" << endl;
			cout << "================================================================" << endl;
			cout << "Year          Year End Balance          Year End Earned Interest" << endl;
			cout << "----------------------------------------------------------------" << endl;

			//Calculations for yearly interest and year end total
			for (int i = 0; i < numberOfYears; i++) {
				//Calculate yearly interest amount using the required equation
				interestAmount = ((totalAmount) * (annualInterest / 100));

				//Calculate year end total
				totalAmount = totalAmount + interestAmount;

				//Show decimal as dollar amount correctly with set precision to 2 decimal places
				cout << (i + 1) << left << "\t\t$" << fixed << setprecision(2) << setw(20) << totalAmount << "\t\t$" << setw(20) << interestAmount << endl;
			}

			//Calculate monthly interest and month end total by initializing totalAmount equals initialInvestment. this is the foundation of the calculations.
			totalAmount = initialInvestment;

			//Display year end totals when the customer has monthly deposits
			cout << endl << "    Balance and Interest With Additional Monthly Deposits" << endl;
			cout << "================================================================" << endl;
			cout << "Year          Year End Balance          Year End Earned Interest" << endl;
			cout << "----------------------------------------------------------------" << endl;

			//Calculations for yearly interest and year end total
			for (int i = 0; i < numberOfYears; i++) {
				//Initialize yearly interest to 0
				yearlyInterestTotal = 0;

				for (int j = 0; j < 12; j++) {
					//Calculate monthly interest amount
					interestAmount = (((totalAmount + monthlyDeposits) * (annualInterest / 100)) / 12);

					//Calculate month end interest
					yearlyInterestTotal = yearlyInterestTotal + interestAmount;

					//Calculate month end total
					totalAmount = totalAmount + monthlyDeposits + interestAmount;
				}

				cout << (i + 1) << left <<  "\t\t$" << fixed << setprecision(2) << setw(20) << totalAmount << "\t\t$" << setw(20) << yearlyInterestTotal << endl;
			}

			//Initialize totalAmount equaling initialInvestment. this is the base of my calculations
			totalAmount = initialInvestment;

			//Display Monthly Balance. I created this part to show the montly breakdown as was shown in the App Functional Requirement
			cout << endl << "\t\t\t" << "Balance and Interest With Additional Monthly Deposits" << endl;
			cout << "===========================================================================================================" << endl;
			cout << setw(16) << "Month" << setw(16) << "New Balance" << "\t" << setw(16) << "Monthly Deposits" << "\t" << setw(16) << "Interest Amount" << "\t" << setw(16) << "Total Amount" << endl;
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;

			//Calculations for monthly total and monthly interest amount
			for (int i = 0; i < numberOfMonths; i++) {

					//Calculate monthly interest amount
					interestAmount = (((totalAmount + monthlyDeposits) * (annualInterest / 100)) / 12);

					//Calculate month end total
					totalAmount = totalAmount + monthlyDeposits + interestAmount;
					
					//Calculate new monthly initial balance
					initialOpening = totalAmount - monthlyDeposits - interestAmount;

				cout << (i + 1) << left << "\t\t$" << fixed << setprecision(2) << setw(16) << initialOpening << "\t$" << setw(16) << monthlyDeposits << "\t$" << setw(16) << interestAmount << "\t$" << setw(16) << totalAmount << endl;

			}

			return 0;

	}
