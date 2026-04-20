#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <regex>
#include <cmath>
#include <fstream>
using namespace std;
#define count1 100
struct employer
{
	string admin_id;
	string admin_name;
	string admin_pass;
};
employer admin[2];
struct employees
{
	string emp_id = "";
	string emp_pass;
	int emp_age;
	string emp_phone;
	double BasicSalary;
	double Bonus;

	double Tax;
	double Taxrate;
	double NetSalary;
	string emp_name;
	string emp_Position;
	float performancescore;
	double overtimehours;
	double overtimerate;
	double sumovertime;
	double deduction;
}employee[count1];

int count2;
int num;
void login();
void option();
void enter();
double calculateNetSalary();
void loadFromFile() {
	ifstream inFile("employees.txt");
	if (!inFile) {

		employee[0].emp_name = "Hesham Emad";
		employee[0].emp_id = "12452";
		employee[0].emp_pass = "6325bh";
		employee[0].emp_Position = "unemployed";
		employee[0].emp_phone = "01144008977";
		employee[0].emp_age = 19;
		employee[0].BasicSalary = 15000;
		employee[0].deduction = 0;
		employee[0].NetSalary = 0;
		employee[0].Bonus = 0;
		employee[0].Tax = 0;
		employee[0].overtimerate = 0;
		employee[0].overtimehours = 0;
		employee[0].performancescore = 0;



		employee[1].emp_name = "Youssef wael";
		employee[1].emp_id = "12569";
		employee[1].emp_pass = "hao12#";
		employee[1].emp_Position = "unemployed";
		employee[1].emp_phone = "01015484390";
		employee[1].emp_age = 18;
		employee[1].BasicSalary = 10000;
		employee[1].deduction = 0;
		employee[1].NetSalary = 0;
		employee[1].Bonus = 0;
		employee[1].Tax = 0;
		employee[1].overtimerate = 0;
		employee[1].overtimehours = 0;
		employee[1].performancescore = 0;


	}

	for (int i = 0; i < count1; i++) {

		if (!(inFile >> employee[i].emp_id
			>> employee[i].emp_pass
			>> employee[i].emp_age
			>> employee[i].emp_phone
			>> employee[i].BasicSalary
			>> employee[i].Bonus
			>> employee[i].Tax
			>> employee[i].Taxrate
			>> employee[i].NetSalary
			>> employee[i].performancescore
			>> employee[i].overtimehours
			>> employee[i].overtimerate
			>> employee[i].sumovertime
			>> employee[i].deduction))
			break;

		inFile.ignore();

		getline(inFile, employee[i].emp_name, '|');
		getline(inFile, employee[i].emp_Position, '|');
	}
	inFile.close();
}
void saveToFile() {
	ofstream outFile("employees.txt");

	for (int i = 0; i < count1; i++) {
		if (employee[i].emp_id != "") {

			outFile << employee[i].emp_id << " "
				<< employee[i].emp_pass << " "
				<< employee[i].emp_age << " "
				<< employee[i].emp_phone << " "
				<< employee[i].BasicSalary << " "
				<< employee[i].Bonus << " "
				<< employee[i].Tax << " "
				<< employee[i].Taxrate << " "
				<< employee[i].NetSalary << " "
				<< employee[i].performancescore << " "
				<< employee[i].overtimehours << " "
				<< employee[i].overtimerate << " "
				<< employee[i].sumovertime << " "
				<< employee[i].deduction << " "
				<< employee[i].emp_name << "|"
				<< employee[i].emp_Position << "|\n";
		}
	}
	outFile.close();
}
void login() {
	while (true)
	{
		cout << " ================================================================" << endl;
		cout << "|                            Log in                               |" << endl;
		cout << " ================================================================ " << endl;
		cout << "[1]- Employee\n[2]- Employer\n[3]- exit " << endl;
		cout << "----------------------------------------------------------------" << endl;

		cout << "Enter your choice: ";
		int choice;
		cin >> choice;
		if (cin.fail()) {
			cout << "  **Error: Invalid input!** " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		string ID, Password;
		bool found = false;

		if (choice == 1)
		{
			cout << "Enter ID: ";
			cin >> ID;
			cout << "Enter Password: ";
			cin >> Password;

			for (int i = 0; i < count1; i++)
			{
				if (ID == employee[i].emp_id && Password == employee[i].emp_pass)
				{
					cout << " ----------------------------------------------------------------" << endl;
					cout << "|               Login successful                                 |" << endl;
					cout << " ----------------------------------------------------------------" << endl;
					found = true;
					cout << " *** welcome " << employee[i].emp_name << " ***\n";
					count2 = i;
					option();
					break;
				}
				else
				{
					continue;
				}
			}
		}
		else if (choice == 2)
		{
			cout << "Enter ID: ";
			cin >> ID;
			cout << "Enter Password: ";
			cin >> Password;

			for (int i = 0; i < 2; i++)
			{
				if (ID == admin[i].admin_id && Password == admin[i].admin_pass)
				{
					cout << " ----------------------------------------------------------------" << endl;
					cout << "|                Login successful                                |" << endl;
					cout << " ----------------------------------------------------------------" << endl;
					found = true;
					cout << " *** welcome " << admin[i].admin_name << " ***\n";
					enter();
					break;
				}
				else
				{
					continue;
				}
			}
		}
		else if (choice == 3)
		{
			cout << "\n  ***Exiting...\n";
			saveToFile();
			exit(0);

		}
		else
		{
			cout << "Wrong choice!\n";
			continue;
		}

		if (!found)
		{
			cout << "ID or Password is wrong\n";
		}
		else
		{
			break;
		}
	}

}



void displayEmployeeInfo() {

	cout << "\n";
	cout << "+---------------------------+---------------+---------------+--------+------------------------------+------------------+\n";
	cout << "|"
		<< left << setw(27) << "Name"
		<< "|" << setw(15) << "ID"
		<< "|" << setw(15) << "Password"
		<< "|" << setw(8) << "Age"
		<< "|" << setw(30) << "Position"
		<< "|" << setw(18) << "Phone"
		<< "|\n";
	cout << "+---------------------------+---------------+---------------+--------+------------------------------+------------------+\n";

	cout << "|"
		<< left << setw(27) << employee[count2].emp_name
		<< "|" << setw(15) << employee[count2].emp_id
		<< "|" << setw(15) << employee[count2].emp_pass
		<< "|" << setw(8) << employee[count2].emp_age
		<< "|" << setw(30) << employee[count2].emp_Position
		<< "|" << setw(18) << employee[count2].emp_phone
		<< "|\n";

	cout << "+---------------------------+---------------+---------------+--------+------------------------------+------------------+\n";
}
void displaySalaryDetails() {

	cout << "\n";
	cout << "+--------------+--------------+------------+--------------+----------+--------------+----------------+\n";
	cout << "|"
		<< left << setw(14) << "Basic"
		<< "|" << setw(14) << "Bonus"
		<< "|" << setw(12) << "OT Hours"
		<< "|" << setw(14) << "OT Bonus"
		<< "|" << setw(10) << "Tax"
		<< "|" << setw(14) << "Deduction"
		<< "|" << setw(16) << "Net Salary"
		<< "|\n";
	cout << "+--------------+--------------+------------+--------------+----------+--------------+----------------+\n";

	cout << "|"
		<< left << setw(14) << employee[count2].BasicSalary
		<< "|" << setw(14) << employee[count2].Bonus
		<< "|" << setw(12) << employee[count2].overtimehours
		<< "|" << setw(14) << employee[count2].sumovertime
		<< "|" << setw(10) << employee[count2].Tax
		<< "|" << setw(14) << employee[count2].deduction
		<< "|" << setw(16) << employee[count2].NetSalary
		<< "|\n";

	cout << "+--------------+--------------+------------+--------------+----------+--------------+----------------+\n";
}
void displayAttendanceRecord() {

	cout << "--------------------------------------------------------------\n";
	cout << "| Attendance Record                                           |\n";
	cout << "--------------------------------------------------------------\n";

	cout << "| Days Present : 22                                           |\n";
	cout << "| Days Absent  : 3                                            |\n";

	cout << "--------------------------------------------------------------\n";
}

void option() {

	while (true) {

		int option;

		cout << "\n****** MENU ******\n";
		cout << "1. Employee Information\n";
		cout << "2. Salary Details\n";
		cout << "3. Attendance\n";
		cout << "4. Exit\n";
		cout << "Your choice: ";
		cin >> option;

		switch (option) {

		case 1:
			displayEmployeeInfo();
			break;

		case 2:
			displaySalaryDetails();
			break;

		case 3:
			displayAttendanceRecord();
			break;

		case 4:
			cout << "\n ***Exiting*** \n";
			break;

		default:
			cout << "Invalid choice.\n";
		}
		if (option == 4)
			break;
	}
	login();
}

void data1() { // جدول البيانات 
	cout << "\n";
	cout << "+-------------------------+---------------+----------------------+------------------------------+----------------+\n";
	cout << "|"
		<< left << setw(25) << " Name"
		<< "|" << setw(15) << " ID"
		<< "|" << setw(22) << " Password"
		<< "|" << setw(30) << " Position"
		<< "|" << setw(16) << " Phone"
		<< "|\n";
	cout << "+-------------------------+---------------+----------------------+------------------------------+----------------+\n";
	for (int i = 0; i < count1; i++) {
		if (employee[i].emp_id == "")
			continue;

		cout << "|"
			<< left << setw(25) << (" " + employee[i].emp_name)
			<< "|" << setw(15) << employee[i].emp_id
			<< "|" << setw(22) << employee[i].emp_pass
			<< "|" << setw(30) << employee[i].emp_Position
			<< "|" << setw(16) << employee[i].emp_phone
			<< "|\n";
	}
	cout << "+-------------------------+---------------+----------------------+------------------------------+----------------+\n";
}
int check() { //تاكيد ID
	string id;
	int count = -1;
	do
	{
		cout << " Enter the employee ID :";
		cin >> id;
		if (cin.fail()) {
			cout << "\n\n  ***Error: Invalid input!*** \n\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		for (int i = 0; i < count1; i++) {

			if (id == employee[i].emp_id)
			{
				count = i;
				break;
			}
		}
		if (count == -1)
			cout << "\n\n  ***Error: Invalid input!***\n\n ";
		else
			break;
	} while (true);
	return count;
}
void updateid() {
	do {
		cout << "  Enter the new id { 5 digits }: ";
		cin >> employee[count2].emp_id;
		regex pattern("^[1-9][0-9]{4}$");
		if (!regex_match(employee[count2].emp_id, pattern))
		{
			cout << "\n\n  ***Error: Invalid input!*** \n\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		break;
	} while (true);
	cout << "\n***" << employee[count2].emp_name << "'s account has been successfully updated [ID]***\n\n";
}
void updatepassword() {

	do
	{
		cout << "  Enter the new password (* 6 characters *) : ";

		cin >> employee[count2].emp_pass;
		regex pattern("^[A-Za-z0-9]{6}$");
		if (!regex_match(employee[count2].emp_pass, pattern))
		{
			cout << "\n\n  ***Error: Invalid input (* 6 characters letters & numbers only *) !*** \n\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		break;

	} while (true);
	cout << "\n***" << employee[count2].emp_name << "'s account has been successfully updated [Password]***\n\n";
}
void updateposition() {
	cout << "  Enter the new position : ";
	cin.ignore();
	getline(cin, employee[count2].emp_Position);
	cout << "\n***" << employee[count2].emp_name << "'s account has been successfully updated [position]***\n\n";

}
void updatephone() {
	do {
		cout << "  Enter the new phone : ";
		cin >> employee[count2].emp_phone;
		regex pattern("^01[0125][0-9]{8}$");
		if (!regex_match(employee[count2].emp_phone, pattern))
		{
			cout << "\n\n  ***Error: Invalid Egyptian phone number!*** \n\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		break;
	} while (true);
	cout << "\n***" << employee[count2].emp_name << "'s account has been successfully updated [Phone]***\n\n";
}
int supdate() {
	do
	{
		cout << " \n***Choose what you want to do on " << employee[count2].emp_name << "'s account***\n\n";
		cout << " [1] id \n\n" << " [2] password \n\n" << " [3] position \n\n" << " [4] phone \n\n" << " [5] exit \n\n";
		cin >> num;
		if (cin.fail()) {
			cout << "\n\n  ***Error: Invalid input!*** \n\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		break;
	} while (true);
	return num;
}
void update() { // تجديد البيانات
	count2 = check();

	do
	{
		num = supdate();
		switch (num)
		{
		case 1:
			updateid();
			break;

		case 2:
			updatepassword();
			break;
		case 3:
			updateposition();
			break;
		case 4:
			updatephone();
			break;
		case 5:
			cout << "Exiting update...\n";
			return;
			break;
		}
	} while (true);
}
void delete1() {//حذف موظف
	count2 = check();
	employee[count2] = {};
	cout << "\n*** account has been successfully deleted ***\n\n";
}
double calculateovertime() {
	return employee[num].overtimehours * employee[num].overtimerate;
}
double calculatebonus() {
	if (employee[num].performancescore >= 100)
	{
		return 1000;
	}
	else if (employee[num].performancescore >= 70)
	{
		return 500;
	}
	else
	{
		return 0;
	}


}
double calculatetaxes() {

	return employee[num].BasicSalary * employee[num].Taxrate;

}
double calculateDeductions() {
	return  employee[num].deduction;

}
double calculateNetSalary() {
	employee[num].sumovertime = calculateovertime();
	employee[num].Bonus = calculatebonus();
	employee[num].deduction = calculateDeductions();
	employee[num].Tax = calculatetaxes();
	double net = employee[num].BasicSalary - employee[num].Tax - employee[num].deduction + employee[num].sumovertime + employee[num].Bonus;
	return net;
}
void salary() {

	num = check();

	int choice1;
	do {
		cout << "\n Basic salary of " << employee[num].emp_name << "'s : " << employee[num].BasicSalary;


		cout << "\n=============================================================";

		cout << "\n--- Update Menu ---\n";
		cout << "[1]. Update Overtime Hours\n";
		cout << "[2]. Update Overtime Rate\n";
		cout << "[3]. Update Performance Score\n";
		cout << "[4]. Update Deduction\n";
		cout << "[5]. Update Taxes rate\n";
		cout << "[6]. Exit Update\n\n";
		cout << "Enter your choice: \n";
		cin >> choice1;

		if (cin.fail()) {
			cout << "\n\n  ***Error: Invalid input!*** \n\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		switch (choice1) {
		case 1:
			cout << "Enter new Overtime Hours: ";
			cin >> employee[num].overtimehours;
			break;

		case 2:
			cout << "Enter new Overtime Rate: ";
			cin >> employee[num].overtimerate;
			break;

		case 3:
			cout << "Enter new Performance Score: ";
			cin >> employee[num].performancescore;
			break;

		case 4:
			cout << "Enter new Deduction: ";
			cin >> employee[num].deduction;
			break;

		case 5:
			cout << "Enter new rate Taxes: ";
			cin >> employee[num].Taxrate;
			break;

		case 6:


			cout << "Employee updated successfully!\n";
			employee[num].NetSalary = calculateNetSalary();
			cout << "======================================================";
			cout << "\n Net salary of " << employee[num].emp_name << "'s : " << employee[num].NetSalary;


			return;
			break;

		default:
			cout << "Invalid choice!\n";

		}
		if (choice1 == 6)
			break;
	} while (true);




}
int soperation() {
	do
	{
		data1();
		cout << "\n *** Select the next operation *** \n\n";
		cout << " [1] Add :\n\n" << " [2] Update :\n\n" << " [3] delete :\n\n";
		cout << " [4] salary :\n\n" << " [5] attendance :\n\n" << " [6] logout :\n\n";
		cin >> num;
		if (cin.fail()) {
			cout << "\n\n  ***Error: Invalid input!*** " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		break;
	} while (true);
	return num;
}

void enter() {//الدخول 
	do
	{
		num = soperation();

		switch (num) {

		case 1:
			break;
		case 2:

			update();
			break;
		case 3:

			delete1();
			break;
		case 4:
			salary();
			break;
		case 5:

			break;
		case 6:
			cout << "\n ***Exiting*** \n";

			break;
		default:
			cout << "\n\n  ***Error: Invalid input!*** " << endl;
		}
		if (num == 6)
		{
			break;
		}
	} while (true);
	login();
}

int main()

{
	loadFromFile();



	admin[0].admin_id = "2601";
	admin[0].admin_pass = "2025";
	admin[0].admin_name = "Mostafa Ahmed";


	login();
}
