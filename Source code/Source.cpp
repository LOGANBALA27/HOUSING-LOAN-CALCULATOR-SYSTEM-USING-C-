// HOUSING LOAN MANAGEMENT SYSTEM BY LOGAN

#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<mysql.h>
#include<cmath>
#include<iomanip>
using namespace std;


int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;


class db_response
{
public:
	static void ConnectionFunction()
	{
		conn = mysql_init(0);
		if (conn)
		{
			cout << "Database Connected" << endl;
			cout << "Press any key to continue..." << endl;
			system("cls");
		}
		else
			cout << "Failed To Connect!" << mysql_errno(conn) << endl;
		conn = mysql_real_connect(conn, "localhost", "root", "", "housing_loan", 3306, NULL, 0);
		if (conn)
		{
			cout << "Database Connected To MySql" << conn << endl;
			cout << "Press any key to continue..." << endl;
			system("cls");
		}
		else
			cout << "Failed To Connect!" << mysql_errno(conn) << endl;
	}
};

void AddNewItemInDatabase();
void Admin_Staff();
void addStaff();
void modifyStaff();
void deleteStaff();
void viewStaff();
void AdminMenu();
void LoginAdmin();
void LoginStaff();
void Admin_Client();
void addClient();
void modifyClient();
void deleteClient();
void viewClient();
void loancalc();
void addCalc();
void modifyCalc();
void deleteCalc();
void StaffMenu();
void Staff_Client();
void viewCalc();
void report();
void spa(int tab);
void brk(int line);
void addClient_Staff();
void modifyClient_Staff();
void deleteClient_Staff();
void viewClient_Staff();
void viewCalc_Staff();
void report_Staff();

int main()
{
	system("cls");
	system("HOUSING LOAN MANAGEMENT SYSTEM");
	system("color 0f");
	


	db_response::ConnectionFunction();
	
	int option;
	int choose;
	char exitSurity;
    Label1:
	brk(1); 
	spa(4);
	cout << " ******************************************************\n ";
	spa(4);
	cout << " *                                                    * \n ";
	spa(4);
	cout << " *     WELCOME TO HOUSING LOAN MANAGEMENT SYSTEM      *\n";
	spa(4);
	cout << " *                                                    * \n ";
	spa(4);
	cout << " *                                                    * \n ";
	spa(4);
	cout << " ******************************************************\n ";
	brk(1); spa(4);
	cout << "Please choose your role \n";
	brk(1); spa(4);
	cout << "1. ADMIN \n";
	brk(1); spa(4);
	cout <<	"2. STAFF \n"; 
	brk(1); spa(4);
	cout << "3. EXIT \n";
	brk(1); spa(4);
	cin >> choose;
	system("cls");
	brk(1); spa(4);
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choose == 1)
	{
		system("cls");
		LoginAdmin();
		option = 1;
	}
	else if (choose == 2)
	{
		system("cls");
		LoginStaff();
		option = 1;
	}
	else if (choose == 3)
	{
		system("cls");
	ExitProgram:
		brk(1); spa(5);
		cout << "Program terminating. Are you sure? (y/N): ";
		cin >> exitSurity;
		if (exitSurity == 'y' || exitSurity == 'Y')
		{
			exit(0);
		}
		else if (exitSurity == 'n' || exitSurity == 'N')
		{
			system("cls");
			main();
			option = 1;
		}
		else {
			system("cls");
			brk(1); spa(5);
			cout << "Next time choose after read the corresponding line." << endl;
			goto ExitProgram;
		}
	}

	else
	{
		brk(1); spa(5);
		cout << "INVALID KEY!. PLEASE SELECT FROM 1 TO 3. ";
		Sleep(1000);
		option = 0;
		system("cls");
		goto Label1;
	}
}

void AdminMenu()
{
	// Variables
	int choose = 0;
	int option = 0;
	char exitSurity;
	brk(1);spa(4);
Label3:
	brk(1); spa(4);
	cout << "Admin Menus" << endl;
	brk(1);spa(4);
	cout << "1. STAFF" << endl;
	brk(1); spa(4);
	cout << "2. CLIENTS" << endl;
	brk(1); spa(4);
	cout << "3. View Calculation" << endl;
	brk(1); spa(4);
	cout << "4. View Amortization" << endl;
	brk(1); spa(4);
	cout << "5. Exit" << endl;
	brk(1); spa(4);
	cin >> choose;
	system("cls");

	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choose == 1)
	{
		system("cls");
		Admin_Staff();;
		option = 1;
	}
	else if (choose == 2)
	{
		system("cls");
		Admin_Client();
		option = 1;
	}
	else if (choose == 3)
	{
		system("cls");
		viewCalc();
		option = 1;
	}
	else if (choose == 4)
	{
		system("cls");
		report();
		option = 1;
	}

	else if (choose == 5)
	{
		system("cls");
	ExitProgram:
		brk(1); spa(5);
		cout << "Program terminating. Are you sure? (y/N): ";
		cin >> exitSurity;
		if (exitSurity == 'y' || exitSurity == 'Y')
		{
			exit(0);
		}
		else if (exitSurity == 'n' || exitSurity == 'N')
		{
			system("cls");
			AdminMenu();
			option = 1;
		}
		else {
			system("cls");
			brk(1); spa(5);
			cout << "Next time choose after read the corresponding line." << endl;
			goto ExitProgram;
		}
	}

	else
	{
		system("cls");
		brk(1); spa(5);
		cout << "INVALID KEY!. PLEASE SELECT FROM 1 TO 5. ";
		Sleep(1000);
		option = 0;
		system("cls");
		goto Label3;
	}

}

void LoginAdmin() {
	system("cls");

	string username, pass;
	char pas;
	brk(1); spa(4);
	cout << "Admin Login";
	brk(2); spa(4);
	cout << "Please enter your ID : ";
	cin >> username;
	brk(1); spa(4);
	cout << "Please enter your password : "; 
	pas = _getch();
	while (pas != 13)
	{
		if (pas == '\b')
		{
		
			if (pass.size() > 0)
			{
				pass.erase(pass.size() - 1, 1);
				cout << "\b \b";
				pas = _getch();
			}
		}
		else
		{
			pass.push_back(pas);
			cout << '*';
			pas = _getch();
		}
	}

	qstate = mysql_query(conn, "select * from admin");

	if (!qstate)
	{

		res = mysql_store_result(conn);
		while ((row = mysql_fetch_row(res)))
		{
			if (username == row[0] && pass == row[1])
			{
				system("cls");
				brk(1); spa(4);
				cout << " ************************************************** \n ";
				brk(1); spa(4);
				cout << "                 ACCESS GRANTED!!!\n";
				brk(1); spa(4);
				cout << "                    WELCOME \n";
				brk(1); spa(4);
				cout<<"                "<<row[2] << " " << row[3]<<endl;
				brk(1); spa(4);
				cout << " **************************************************\n ";
				brk(1); spa(4);

				AdminMenu();
			}

		}
		string ka;
		system("cls");
		brk(1); spa(3);
		cout << "************************************************************************************ \n";
		brk(1); spa(3);
		cout << "          ACCESS DENIED!!! USERNAME AND PASSWORD NOT EXIST IN DATABASE!!!\n";
		brk(1); spa(3);
		cout << "************************************************************************************\n";
		brk(1); spa(3);
		cout << " PRESS ANY KEY AND ENTER TO LOGIN AGAIN. ";
		cin >> ka;
		system("cls");
		LoginAdmin();
	}
	else
	{
		brk(1); spa(4);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

}

void LoginStaff() {
	system("cls");

	char pas;
	string username, pass;
	brk(1); spa(4);
	cout << "Staff Login";
	brk(2); spa(4);
	cout << "Please enter your ID : "; cin >> username;
	brk(1); spa(4);
	cout << "Please enter your password : "; pas = _getch();
	while (pas != 13)
	{
		if (pas == '\b')
		{
			
			if (pass.size() > 0)
			{
				pass.erase(pass.size() - 1, 1);
				cout << "\b \b";
				pas = _getch();
			}
		}
		else
		{
			pass.push_back(pas);
			cout << '*';
			pas = _getch();
		}
	}

	qstate = mysql_query(conn, "select * from staff");

	if (!qstate)
	{

		res = mysql_store_result(conn);
		while ((row = mysql_fetch_row(res)))
		{
			if (username == row[0] && pass == row[1])
			{
				system("cls");
				brk(1); spa(4);
				cout << " ************************************************** \n ";
				brk(1); spa(4);
				cout << "                 ACCESS GRANTED!!!\n";
				brk(1); spa(4);
				cout << "                    WELCOME \n";
				brk(1); spa(4);
				cout << "                " << row[2] << " " << row[3] << endl;
				brk(1); spa(4);
				cout << " **************************************************\n ";
				brk(1); spa(4);

				StaffMenu();
			}

		}
		string ka;
		system("cls");
		brk(1); spa(3);
		cout << "************************************************************************************ \n";
		brk(1); spa(3);
		cout << "          ACCESS DENIED!!! USERNAME AND PASSWORD NOT EXIST IN DATABASE!!!\n";
		brk(1); spa(3);
		cout << "************************************************************************************\n";
		brk(1); spa(3);
		cout << " PRESS ANY KEY AND ENTER TO LOGIN AGAIN. ";
		cin >> ka;
		system("cls");
		LoginStaff();
	}
	else
	{
		brk(1); spa(4);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

}

void Admin_Staff()
{

	system("cls");
	int option = 0;
	int chooseOneFromMenu = 0;
	char exitSurity;
	Label2:
	while (option != 1)
	{
		brk(1); spa(5);
		cout << "Please choose your choice" << endl << endl;
		brk(1); spa(5);
		cout << "1. Add staff" << endl;
		brk(1); spa(5);
		cout << "2. Modify staff" << endl;
		brk(1); spa(5);
		cout << "3. Delete staff" << endl;
		brk(1); spa(5);
		cout << "4. View staff" << endl;
		brk(1); spa(5);
		cout << "5. Back" << endl;
		brk(1); spa(5);

		cin >> chooseOneFromMenu;

		while (!cin)
		{
			cout << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}

		if (chooseOneFromMenu == 1)
		{
			system("cls");
			addStaff();
			option = 1;
		}
		else if (chooseOneFromMenu == 2)
		{
			system("cls");
			modifyStaff();
			option = 1;
		}
		else if (chooseOneFromMenu == 3)
		{
			system("cls");
			deleteStaff();
			option = 1;
		}
		else if (chooseOneFromMenu == 4)
		{
			system("cls");
			viewStaff();
			option = 1;
		}
		else if (chooseOneFromMenu == 5)
		{
			system("cls");
			AdminMenu();
			option = 1;
		}
		else
		{
			system("cls");
			brk(1); spa(5);
			cout << "INVALID KEY!. PLEASE ENTER FROM 1 TO 5. ";
			Sleep(1000);
			option = 0;
			system("cls");
			goto Label2;
		}
	}
}

void modifyStaff()
{

	system("cls");

	// Variables
	string staffid = "";
	string fname = "";
	string lname = "";
	string address = "";
	string email = "";
	string pass_staff = "";
	string age = "";
	string phoneNo = "";
	string item[5000];

	char choose;
	int Id;
	bool HaveException = false;
	bool NotInDatabase = false;
	int indexForId = 0;


	string snstaffid = "";
	string snfname = "";
	string snlname = "";
	string snaddress = "";
	string snemail = "";
	string snpass_staff = "";
	string snage = "";
	string snphoneNo = "";




	qstate = mysql_query(conn, "select Staff_ID, Password, FName, LName from staff");
	if (!qstate)
	{
		res = mysql_store_result(conn);
		brk(1); spa(5);
		cout << "Staffs In Database:" << endl;
		brk(1); spa(5);
		cout << "------------------------" << endl;
		cout << endl;
		brk(1); spa(5);
		cout << "| ID\t| Name\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{
		    spa(5);
			cout << "| " << row[0] << "\t" << "| " << row[2] << " " << row[3] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}
	}
	else
	{
		brk(1); spa(5);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	try
	{
		cout << endl;
		brk(1); spa(5);
		cout << "Enter Staff ID: ";
		cin >> staffid;
		cout << endl;
	}
	catch (exception e)
	{
		brk(1); spa(5);
		cout << "Please Enter a valid NUMBER." << endl;
		HaveException = true;
	}

	if (HaveException == false)
	{
		stringstream streamid;
		string strid;
		streamid << staffid;
		streamid >> strid;

		for (int i = 0; i < indexForId; i++)
		{
			if (strid != item[i])
			{
				NotInDatabase = true;
			}
			else
			{
				NotInDatabase = false;
				break;
			}
		}

		if (NotInDatabase == false)
		{
			string findbyid_query = "select * from staff where Staff_ID = '" + strid + "'";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);

			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;
				system("cls");
				while ((row = mysql_fetch_row(res)))
				{
					brk(3); spa(5);
					cout << "Current Staff Information";
					brk(3); spa(5);
					cout << "Staff ID: " << row[0];
					brk(2); spa(5);
					cout << "Staff Password: " << row[1];
					brk(2); spa(5);
					cout << "Staff Name: " << row[2] << " " << row[3];
					brk(2); spa(5);
					cout << "Age: " << row[4];
					brk(2); spa(5);
					cout << "Address: " << row[5];
					brk(2); spa(5);
					cout << "Email: " << row[6];
					brk(2); spa(5);
					cout << "Phone Number: " << row[7]; 
					

					snstaffid = row[0];
					snpass_staff = row[1];
					snfname = row[2];
					snlname = row[3];
					snage = row[4];
					snaddress = row[5];
					snemail = row[6];
					snphoneNo = row[7];

				}
			}
			else
			{
				brk(2); spa(5);
				cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
			}
			brk(3); spa(5);
			cout << "New Staff Information";
			cin.ignore(1, '\n');
			brk(3); spa(5);
			cout << "Enter First Name (xN to not change): ";
			getline(cin, fname);
			if (fname == "xN")
			{
				fname = snfname;
			}
			brk(1); spa(5);
			cout << "Enter Last Name (xN to not change): ";
			getline(cin, lname);
			if (lname == "xN")
			{
				lname = snlname;
			}
			brk(1); spa(5);
			cout << "Enter Age (xN to not change): ";
			getline(cin, age);
			if (age == "xN")
			{
				age = snage;
			}
			brk(1); spa(5);
			cout << "Enter Address (xN to not change): ";
			getline(cin, address);
			if (address == "xN")
			{
				address = snaddress;
			}
			brk(1); spa(5);
			cout << "Enter Email (xN to not change): ";
			getline(cin, email);
			if (email == "xN")
			{
				email = snemail;
			}
			brk(1); spa(5);
			cout << "Enter Phone Number (xN to not change): ";
			getline(cin, phoneNo);
			if (phoneNo == "xN")
			{
				phoneNo = snphoneNo;
			}
			brk(1); spa(5);
			cout << "Enter Password (xN to not change): ";
			getline(cin, pass_staff);
			if (pass_staff == "xN")
			{
				pass_staff = snpass_staff;
			}

			string update_query = "update staff set FName = '" + fname + "', LName = '" + lname + "', Age = '" + age + "', Address = '" + address + "' , Password = '" + pass_staff + "', Email = '" + email + "', PhoneNumber = '" + phoneNo + "' where Staff_ID ='" + strid + "'";
			const char* qu = update_query.c_str();
			qstate = mysql_query(conn, qu);

			if (!qstate)
			{
				system("cls");
				brk(3); spa(5);
				cout << "Staff Updated Successfully In Database!" << endl;
			}
			else
			{
				system("cls");
				brk(3); spa(5);
				cout << "Failed To Update!" << mysql_errno(conn) << endl;
			}

		}
		else
		{
		system("cls");
			brk(1); spa(5);
			cout << "Staff does not exist in database." << endl;
			Sleep(1000);
			system("cls");
			modifyStaff();

		}
	}

Label5:
	int option;
	brk(3); spa(5);
	cout << "Press 'a' to Update Again or 'b' to go back : ";
	cin >> choose;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choose == 'b' || choose == 'B')
	{
		system("cls");
		Admin_Staff();;
		option = 1;
	}
	else if (choose == 'a' || choose == 'A')
	{
		system("cls");
		modifyStaff();
		option = 1;
	}
	else
	{
		brk(3); spa(5);
		cout << "Invalid key. Please enter again.";
		Sleep(1000);
		system("cls");
		goto Label5;
	}

}

void addStaff()
{
	
	string staffid = "";
	string fname = "";
	string lname = "";
	int age;
	string address = "";
	string email = "";
	string phoneNo ="";
	string pass_staff;

	char choose;
	// Variables End
	system("cls");
	brk(1); spa(4);
	cout << "Add New Staff Menu" << endl << endl;

	cin.ignore(1, '\n');
	brk(1); spa(4);
	cout << "Enter Staff ID: ";
	getline(cin, staffid);
	brk(1); spa(4);
	cout << "Enter First Name: ";
	getline(cin, fname);
	brk(1); spa(4);
	cout << "Last Name: ";
	getline(cin, lname);
	brk(1); spa(4);
	cout << "Enter address: ";
	getline(cin, address);
	brk(1); spa(4);
	cout << "Enter email: ";
	getline(cin, email);
	brk(1); spa(4);
	cout << "Enter age: ";
	cin >> age;
	brk(1); spa(4);
	cout << "Enter Phone Number: ";
	cin >> phoneNo;
	brk(1); spa(4);
	cout << "Enter password: ";
	cin >> pass_staff;


	stringstream streamage, streamphono;
	string sage;
	streamage << age;
	streamage >> sage;

	


	string insert_query = "insert into staff (Staff_ID, Password, FName, LName, Age, Address, Email, PhoneNumber) values ('" + staffid + "','" + pass_staff + "','" + fname + "','" + lname + "','" + sage + "','" + address + "','" + email + "','" + phoneNo + "')";


	const char* q = insert_query.c_str(); 

	qstate = mysql_query(conn, q);

	if (!qstate)
	{
		brk(3); spa(4);
		cout  << "Staff has been successfully added in database.";
	}
	else
	{
		brk(3); spa(4);
		cout << "Query Execution Problem!" << mysql_errno(conn);
	}

	
Label4:
	int option;
	brk(2); spa(4);
	cout << "Press 'a' to Insert Again or 'b' to go back : ";
	Sleep(1000);
	cin >> choose;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choose == 'b' || choose == 'B')
	{
		system("cls");
		Admin_Staff();;
		option = 1;
	}
	else if (choose == 'a' || choose == 'A')
	{
		system("cls");
		addStaff();
		option = 1;
	}
	else
	{
		brk(3); spa(4);
		cout << "Invalid key. Please enter again.";
		system("cls");
		goto Label4;
	}

}

void Admin_Client()
{
	int option;
	Label8:
	system("cls");
	// Variables
	int chooseOneFromMenu = 0;
	char exitSurity;
	
	brk(1); spa(5);
	cout << "Please choose your choice" << endl << endl;
	brk(1); spa(5);
	cout << "1. Add client" << endl;
	brk(1); spa(5);
	cout << "2. Modify client" << endl;
	brk(1); spa(5);
	cout << "3. Delete client" << endl;
	brk(1); spa(5);
	cout << "4. View client" << endl;
	brk(1); spa(5);
	cout << "5. Back" << endl;
	brk(1); spa(5);

	cin >> chooseOneFromMenu;

	while (!cin)
	{
		cout << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (chooseOneFromMenu == 1)
	{
		system("cls");
		addClient();
		option = 1;
	}
	else if (chooseOneFromMenu == 2)
	{
		system("cls");
		modifyClient();
		option = 1;
	}
	else if (chooseOneFromMenu == 3)
	{
		system("cls");
		deleteClient();
		option = 1;
	}
	else if (chooseOneFromMenu == 4)
	{
		system("cls");
		viewClient();
		option = 1;
	}
	else if (chooseOneFromMenu == 5)
	{
		system("cls");
		AdminMenu();
		option = 1;
	}
	else
	{
		system("cls");
		brk(1); spa(5);
		cout << "INVALID KEY!. PLEASE ENTER FROM 1 TO 5. ";
		Sleep(1000);
		option = 0;
		system("cls");
		goto Label8;
	}
}

void deleteStaff()
{

	system("cls");
	char choose;
	bool HaveException = false;
	bool NotInDatabase = false;
	int indexForId = 0;
	string item[5000];
	string staffid;

	qstate = mysql_query(conn, "select Staff_ID, Password, FName, LName from staff");
	if (!qstate)
	{
		res = mysql_store_result(conn);
		brk(1); spa(5);
		cout << "Staffs In Database:" << endl;
		 spa(5);
		cout << "------------------------" << endl;
		cout << endl;
		spa(5);
		cout << "| ID\t| Name\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{
			spa(5);
			cout << "| " << row[0] << "\t" << "| " << row[2] << " " << row[3] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}
	}
	else
	{
		brk(1); spa(5);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	try
	{
		cout << endl;
		brk(1); spa(5);
		cout << "Enter Staff ID: ";
		cin >> staffid;
		cout << endl;
	}
	catch (exception e)
	{
		brk(1); spa(5);
		cout << "Please Enter a valid NUMBER." << endl;
		HaveException = true;
	}

	if (HaveException == false)
	{
		stringstream streamid;
		string strid;
		streamid << staffid;
		streamid >> strid;

		for (int i = 0; i < indexForId; i++)
		{
			if (strid != item[i])
			{
				NotInDatabase = true;
			}
			else
			{
				NotInDatabase = false;
				break;
			}
		}
		if (NotInDatabase == false)
		{
			string delete_query = "delete from staff where Staff_ID = '" + strid + "'";
			const char* qd = delete_query.c_str();
			qstate = mysql_query(conn, qd);

			if (!qstate)
			{
				system("cls");
				brk(1); spa(5);
				cout << "Successfully Deleted From Database." << endl;
			}
			else
			{
				brk(1); spa(5);
				cout << "Failed To Delete!" << mysql_errno(conn) << endl;
			}

		}
		else
		{
			system("cls");
			brk(1); spa(5);
			cout << "Staff does not exist in database." << endl;
			Sleep(1000);
			system("cls");
			deleteStaff();
		}
	}

	// Exit Code
Label5:
	int option;
	brk(2); spa(4);
	cout << "Press 'd' to Delete Again or 'b' to go back : ";
	cin >> choose;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choose == 'b' || choose == 'B')
	{
		system("cls");
		Admin_Staff();;
		option = 1;
	}
	else if (choose == 'd' || choose == 'D')
	{
		system("cls");
		deleteStaff();
		option = 1;
	}
	else
	{
		brk(3); spa(4);
		cout << "Invalid key. Please enter again.";
		system("cls");
		goto Label5;
	}

}

void viewStaff()
{
	system("cls");
	string item[5000];
	int indexForId = 0;
	char choose;
	qstate = mysql_query(conn, "select Staff_ID, Password, FName, LName from staff");
	if (!qstate)
	{
		res = mysql_store_result(conn);
		brk(1); spa(5);
		cout << "Staffs In Database:" << endl;
		brk(1); spa(5);
		cout << "------------------------" << endl;
		brk(1); spa(5);
		cout << "| ID\t| Name\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{
			spa(5);
			cout << "| " << row[0] << "\t" << "| " << row[2] << " " << row[3] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}
	}
	else
	{
		brk(1); spa(5);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

ExitMenu:
	brk(2); spa(5);
	cout << "Press any other key and Enter to Exit: ";
	cin >> choose;
	
	Admin_Staff();
}

void addClient()
{
	// Initial Load
	system("cls");
	// Initial Load End

	// Variables
	string clientid = "";
	string fname = "";
	string lname = "";
	int age;
	string address = "";
	string email = "";
	string phoneNo = "";


	char choose;
	// Variables End

	brk(1); spa(4);
	cout << "Add New Client Menu" << endl << endl;

	cin.ignore(1, '\n');
	brk(1); spa(4);
	cout << "Enter Client ID: ";
	getline(cin, clientid);
	brk(1); spa(4);
	cout << "Enter First Name: ";
	getline(cin, fname);
	brk(1); spa(4);
	cout << "Last Name: ";
	getline(cin, lname);
	brk(1); spa(4);
	cout << "Enter address: ";
	getline(cin, address);
	brk(1); spa(4);
	cout << "Enter email: ";
	getline(cin, email);
	brk(1); spa(4);
	cout << "Enter age: ";
	cin >> age;
	brk(1); spa(4);
	cout << "Enter Phone Number: ";
	cin >> phoneNo;



	stringstream streamage, streamphono;
	string sage;
	streamage << age;
	streamage >> sage;
	


	string insert_query = "insert into client (Client_ID, FName, LName, Age, Address, Email, PhoneNumber) values ('" + clientid + "','" + fname + "','" + lname + "','" + sage + "','" + address + "','" + email + "','" + phoneNo + "')";


	const char* q = insert_query.c_str(); // c_str converts string to constant char 

	qstate = mysql_query(conn, q);

	if (!qstate)
	{
		brk(3); spa(4);
		cout << "Client has been successfully added in database." << endl;
	}
	else
	{
		brk(3); spa(4);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	// Exit Code
Label5:
	int option;
	brk(3); spa(4);
	cout << "Press 'a' to Insert Again or 'b' to go back : ";
	cin >> choose;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choose == 'b' || choose == 'B')
	{
		system("cls");
		Admin_Client();
		option = 1;
	}
	else if (choose == 'a' || choose == 'A')
	{
		system("cls");
		addClient();
		option = 1;
	}
	else
	{
		brk(3); spa(4);
		cout << "Invalid key. Please enter again.";
		system("cls");
		goto Label5;
	}

}

void modifyClient()
{
	system("cls");

	// Variables
	string clientid = "";
	string fname = "";
	string lname = "";
	string address = "";
	string email = "";
	string age = "";
	string phoneNo = "";
	string item[5000];

	char choose;
	int Id;
	bool HaveException = false;
	bool NotInDatabase = false;
	int indexForId = 0;

	// Store Variables
	string snstaffid = "";
	string snfname = "";
	string snlname = "";
	string snaddress = "";
	string snemail = "";
	string snage = "";
	string snphoneNo = "";


	// Variables End

	qstate = mysql_query(conn, "select Client_ID, FName, LName from client");
	if (!qstate)
	{
		brk(1); spa(5);
		res = mysql_store_result(conn);
		system("cls");
		cout << "Clients In Database:" << endl;
		brk(1); spa(5);
		cout << "------------------------" << endl;
		cout << endl;
	    spa(5);
		cout << "| ID\t| Name\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{
			spa(5);
			cout << "| " << row[0] << "\t" << "| " << row[1] << " " << row[2] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}
	}
	else
	{
		brk(1); spa(5);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	try
	{
		cout << endl;
		brk(1); spa(5);
		cout << "Enter Client ID: ";
		cin >> clientid;
		cout << endl;
	}
	catch (exception e)
	{
		brk(1); spa(5);
		cout << "Please Enter a valid NUMBER." << endl;
		HaveException = true;
		goto Label6;
	}

	if (HaveException == false)
	{
		stringstream streamid;
		string strid;
		streamid << clientid;
		streamid >> strid;

		for (int i = 0; i < indexForId; i++)
		{
			if (strid != item[i])
			{
				NotInDatabase = true;
			}
			else
			{
				NotInDatabase = false;
				break;
			}
		}

		if (NotInDatabase == false)
		{
			string findbyid_query = "select * from client where Client_ID = '" + strid + "'";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);

			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;
				while ((row = mysql_fetch_row(res)))
				{
					brk(2); spa(5);
					cout << "Current Client Information";
					brk(3); spa(5);
					cout << "Client ID: " << row[0]<<endl;
					brk(1); spa(5);
					cout << "Client Name: " << row[1] << " " << row[2]<<endl;
					brk(1); spa(5);
					cout << "Age: " << row[3]<<endl;
					brk(1); spa(5);
					cout << "Address: " << row[4]<<endl;
					brk(1); spa(5);
					cout << "Email: " << row[5]<<endl;
					brk(1); spa(5);
					cout << "Phone Number: " << row[6]<<endl;

					snstaffid = row[0];
					snfname = row[1];
					snlname = row[2];
					snage = row[3];
					snaddress = row[4];
					snemail = row[5];
					snphoneNo = row[6];

				}
			}
			else
			{
				brk(2); spa(5);
				cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
			}
			brk(3); spa(5);
			cout << "New Client Information";
			cin.ignore(1, '\n');
			brk(3); spa(5);
			cout << "Enter First Name (xN to not change): ";
			getline(cin, fname);
			if (fname == "xN")
			{
				fname = snfname;
			}
			brk(1); spa(5);
			cout << "Enter Last Name (xN to not change): ";
			getline(cin, lname);
			if (lname == "xN")
			{
				lname = snlname;
			}
			brk(1); spa(5);
			cout << "Enter Age (xN to not change): ";
			getline(cin, age);
			if (age == "xN")
			{
				age = snage;
			}
			brk(1); spa(5);
			cout << "Enter Address (xN to not change): ";
			getline(cin, address);
			if (address == "xN")
			{
				address = snaddress;
			}
			brk(1); spa(5);
			cout << "Enter Email (xN to not change): ";
			getline(cin, email);
			if (email == "xN")
			{
				email = snemail;
			}
			brk(1); spa(5);
			cout << "Enter Phone Number (xN to not change): ";
			getline(cin, phoneNo);
			if (phoneNo == "xN")
			{
				phoneNo = snphoneNo;
			}

			string update_query = "update client set FName = '" + fname + "', LName = '" + lname + "', Age = '" + age + "', Address = '" + address + "', Email = '" + email + "', PhoneNumber = '" + phoneNo + "' where Client_ID ='" + strid + "'";
			const char* qu = update_query.c_str();
			qstate = mysql_query(conn, qu);

			if (!qstate)
			{
				system("cls");
				brk(3); spa(5);
				cout << "*Client Updated Successfully In Database!" << endl;
			}
			else
			{
				system("cls");
				brk(3); spa(5);
				cout << "Failed To Update!" << mysql_errno(conn) << endl;
			}

		}
		else
		{
		       brk(1); spa(5);
			cout << "Client does not exist in database." << endl;
			Sleep(1000);
			system("cls");
			modifyClient();

		}
	}

Label6:
	int option;
	brk(3); spa(5);
	cout << "Press 'a' to Update Again or 'b' to go back : ";
	cin >> choose;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choose == 'b' || choose == 'B')
	{
		system("cls");
		Admin_Client();;
		option = 1;
	}
	else if (choose == 'a' || choose == 'A')
	{
		system("cls");
		modifyClient();
		option = 1;
	}
	else
	{
		brk(3); spa(5);
		cout << "Invalid key. Please enter again.";
		Sleep(1000);
		system("cls");
		goto Label6;
	}
}

void deleteClient()
{
	system("cls");
	char choose;
	bool HaveException = false;
	bool NotInDatabase = false;
	int indexForId = 0;
	string item[5000];
	string clientid;

	qstate = mysql_query(conn, "select Client_ID, FName, LName from client");
	if (!qstate)
	{
		res = mysql_store_result(conn);
		brk(1); spa(5);
		cout << "Clients In Database:" << endl;
	    spa(5);
		cout << "------------------------" << endl;
		cout << endl;
		spa(5);
		cout << "| ID\t| Name\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{
			spa(5);
			cout << "| " << row[0] << "\t" << "| " << row[1] << " " << row[2] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}
	}
	else
	{
		brk(1); spa(5);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	try
	{
		cout << endl;
		brk(1); spa(5);
		cout << "Enter Client ID: ";
		cin >> clientid;
		cout << endl;
	}
	catch (exception e)
	{
		brk(1); spa(5);
		cout << "Please Enter a valid NUMBER." << endl;
		HaveException = true;
		goto Label7;
	}

	if (HaveException == false)
	{
		stringstream streamid;
		string strid;
		streamid << clientid;
		streamid >> strid;

		for (int i = 0; i < indexForId; i++)
		{
			if (strid != item[i])
			{
				NotInDatabase = true;
			}
			else
			{
				NotInDatabase = false;
				break;
			}
		}
		if (NotInDatabase == false)
		{
			string delete_query = "delete from client where Client_ID = '" + strid + "'";
			const char* qd = delete_query.c_str();
			qstate = mysql_query(conn, qd);

			if (!qstate)
			{
				brk(1); spa(5);
				cout << "Successfully Deleted From Database." << endl;
			}
			else
			{
				brk(1); spa(5);
				cout << "Failed To Delete!" << mysql_errno(conn) << endl;
			}

		}
		else
		{
			brk(1); spa(5);
			cout << "Client does not exist in database." << endl;
			Sleep(1000);
			system("cls");
			deleteClient();
		}
	}

	// Exit Code
Label7:
	int option;
	brk(2); spa(4);
	cout << "Press 'd' to Delete Again or 'b' to go back : ";
	cin >> choose;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choose == 'b' || choose == 'B')
	{
		system("cls");
		Admin_Client();;
		option = 1;
	}
	else if (choose == 'd' || choose == 'D')
	{
		system("cls");
		deleteClient();
		option = 1;
	}
	
	else
	{
	brk(3); spa(5);
	cout << "Invalid key. Please enter again.";
	Sleep(1000);
	system("cls");
	goto Label7;
	}
}

void viewClient()
{
	system("cls");
	string item[5000];
	int indexForId = 0;
	char choose;
	qstate = mysql_query(conn, "select Client_ID, FName, LName from client");
	if (!qstate)
	{
		res = mysql_store_result(conn);
		brk(1); spa(5);
		cout << "Clients In Database:" << endl;
		brk(1); spa(5);
		cout << "------------------------" << endl;
		brk(1); spa(5);
		cout << "| ID\t| Name\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{
			spa(5);
			cout << "| " << row[0] << "\t" << "| " << row[1] << " " << row[2] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}
		
	}
	else
	{
		brk(1); spa(5);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

ExitMenu:
	brk(2); spa(5);
	cout << "Press any other key to Exit: ";
	cin >> choose;
		cout << endl;
		system("cls");
		Admin_Client();

}

void loancalc()
{
	int option;
	Label16:
	system("cls");
	// Variables
	int chooseOneFromMenu = 0;
	char exitSurity;
	// Variables End
	brk(1); spa(5);
	cout << "Calucluation Menus" << endl;
	brk(2); spa(5);
	cout << "1.add calculation " << endl;
	brk(1); spa(5);
	cout << "2.update calculation " << endl;
	brk(1); spa(5);
	cout << "3.delete calculation " << endl;
	brk(1); spa(5);
	cout << "4.view calculation " << endl;
	brk(1); spa(5);
	cout << "5.Back " << endl;

	brk(1); spa(5);
	cin >> chooseOneFromMenu;

	while (!cin)
	{
		cout << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (chooseOneFromMenu == 1)
	{
		system("cls");
		addCalc();
		option = 1;
	}
	else if (chooseOneFromMenu == 2)
	{
		system("cls");
		modifyCalc();
		option = 1;
	}
	else if (chooseOneFromMenu == 3)
	{
		system("cls");
		deleteCalc();
		option = 1;
	}
	else if (chooseOneFromMenu == 4)
	{
		system("cls");
		viewCalc_Staff();
		option = 1;
	}
	else if (chooseOneFromMenu == 5)
	{
		system("cls");
		StaffMenu();
		option = 1;
	}
	else
	{
		system("cls");
		brk(1); spa(5);
		cout << "INVALID KEY!. PLEASE ENTER FROM 1 TO 5. ";
		Sleep(1000);
		option = 0;
		system("cls");
		goto Label16;
	}

}

void addCalc()
{
	string amountid = "";
	string clientid = "";
	string housetype = "";
	double loanamount = 0;
	double interest_rate = 0;
	int loanperiod = 0;
	double down1 = 0.0;
	double down2=0.0;
	double total_loan_amount = 0;
	double monthly_repayment = 0;
	double monthly_interest_rate = 0;
	int monthly_term = 0;
	int indexForId = 0;
	string item[5000];
	char choose;
	int Id;
	bool HaveException = false;
	bool NotInDatabase = false;


	cin.ignore(1, '\n');
	qstate = mysql_query(conn, "select Client_ID, FName, LName from client");
	if (!qstate)
	{
		brk(1); spa(5);
		res = mysql_store_result(conn);
		cout << "Clients In Database:" << endl;
		brk(1); spa(5);
		cout << "------------------------" << endl;
		cout << endl;
		spa(5);
		cout << "| ID\t| Name\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{
			spa(5);
			cout << "| " << row[0] << "\t" << "| " << row[1] << " " << row[2] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}
	}
	else
	{
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	try
	{
		brk(1); spa(5);
		cout << "Enter Client ID: ";
		cin >> clientid;
		cout << endl;
	}
	catch (exception e)
	{
		cout << "Please Enter a valid NUMBER." << endl;
		HaveException = true;
	}

	if (HaveException == false)
	{
		stringstream streamid;
		string strid;
		streamid << clientid;
		streamid >> strid;

		for (int i = 0; i < indexForId; i++)
		{
			if (strid != item[i])
			{
				NotInDatabase = true;
			}
			else
			{
				NotInDatabase = false;
				break;
			}
		}

		if (NotInDatabase == false)
		{
			string findbyid_query = "select * from client where Client_ID = '" + strid + "'";
			const char* qi = findbyid_query.c_str();

		}
		else
		{
			brk(2); spa(5);
			cout << "Client does not exist in database." << endl;
			Sleep(1000);
			system("cls");
			addCalc();

		}
	}
	cin.ignore(1, '\n');
	brk(1); spa(5);
	cout << "Enter Property Type: ";
	getline(cin, housetype);
	brk(1); spa(5);
	cout << "Enter Property Price(RM): ";
	cin >> loanamount;
	brk(1); spa(5);
	cout << "Enter Interest Rate(%): ";
	cin >> interest_rate;
	brk(1); spa(5);
	cout << "Down Payment(%): ";
	cin >> down1;
	brk(1); spa(5);
	cout << "Loan Period(Years): ";
	cin >> loanperiod;
	cout << fixed << showpoint;
	monthly_interest_rate = (interest_rate/100) / 12;
	down2 = loanamount*(down1 / 100);
	total_loan_amount = loanamount - down2;
	monthly_term = loanperiod * 12;
	brk(1); spa(5);
	cout << "Total loan amount: " <<setprecision(2)<< total_loan_amount;
	monthly_repayment = total_loan_amount *( monthly_interest_rate / (1 - pow(1 + monthly_interest_rate, -monthly_term)));
	brk(1); spa(5);
	cout << "Monthly Repayment: " << monthly_repayment;


	string insert_query = "insert into amount (Client_ID,House_type,Amount,Interest_rate,Loan_Period,Down_payment,Total_loan_amount,Monthly_repayment) values ('" + clientid + "','" + housetype + "','" + to_string(loanamount) + "','" + to_string(interest_rate) + "','" + to_string(loanperiod) + "','" + to_string(down1) + "','" + to_string(total_loan_amount) + "','" + to_string(monthly_repayment) + "')";

	const char* q = insert_query.c_str();
	qstate = mysql_query(conn, q);

	if (!qstate)
	{
		brk(3); spa(4);
		cout << "Staff has been successfully added in database.";
	}
	else
	{
		brk(3); spa(4);
		cout << "Query Execution Problem!" << mysql_errno(conn);
	}

	// Exit Code
Label12:
	int option;
	brk(2); spa(4);
	cout << "Press 'a' to Insert Again or 'b' to go back : ";
	cin >> choose;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choose == 'b' || choose == 'B')
	{
		system("cls");
		loancalc();
		option = 1;
	}
	else if (choose == 'a' || choose == 'A')
	{
		system("cls");
		addCalc();
		option = 1;
	}
	else
	{
		brk(3); spa(4);
		cout << "Invalid key. Please enter again.";
		system("cls");
		goto Label12;
	}
}

void modifyCalc()
{
	system("cls");

	// Variables
	string amountid = "";
	string clientid = "";
	string housetype = "";
	string amount = "";
	string interest_rate = "";
	string loan_period = "";
	string down_payment = "";
	string total_loan_amount = "";
	string monthly_repayment = "";
	string item[5000];

	char choose;
	int Id;
	bool HaveException = false;
	bool NotInDatabase = false;
	int indexForId = 0;

	// Store Variables
	string snamtid = "";
	string snclientid = "";
	string snht = "";
	string snamount = "";
	string sir = "";
	string slp = "";
	string sdp = "";
	string stla = "";
	string smr = "";



	qstate = mysql_query(conn, "select Amount_ID, Client_ID from amount");
	if (!qstate)
	{
		res = mysql_store_result(conn);
		brk(1); spa(5);
		cout << "Clalculations In Database:" << endl;
		brk(1); spa(5);
		cout << "------------------------" << endl;
		brk(1); spa(5);
		cout << "| Bill No | Client ID\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{
			brk(1); spa(5);
			cout << "|  " << row[0] << " | " << row[1] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}
	}
	else
	{
		brk(2); spa(5);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	try
	{
		brk(1); spa(5);
		cout << "Enter Bill ID: ";
		cin >> amountid;
		cout << endl;
	}
	catch (exception e)
	{
		brk(2); spa(5);
		cout << "Please Enter a valid NUMBER." << endl;
		HaveException = true;
		goto Label14;
	}

	if (HaveException == false)
	{
		stringstream streamid;
		string strid;
		streamid << amountid;
		streamid >> strid;

		for (int i = 0; i < indexForId; i++)
		{
			if (strid != item[i])
			{
				NotInDatabase = true;
			}
			else
			{
				NotInDatabase = false;
				break;
			}
		}

		if (NotInDatabase == false)
		{
			string findbyid_query = "select * from amount where Amount_ID = '" + strid + "'";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);

			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;
				while ((row = mysql_fetch_row(res)))
				{
					brk(1); spa(5);
					cout << "Bill ID: " << row[0]<<endl;
					brk(1); spa(5);
					cout << "Client ID: " << row[1]<<endl;
					brk(1); spa(5);
					cout << "Property Type: " << row[2]<<endl;
					brk(1); spa(5);
					cout << "Property Price: " << row[3]<<endl;
					brk(1); spa(5);
					cout << "Interest Rate: " << row[4]<<endl;
					brk(1); spa(5);
					cout << "Loan Period: " << row[5]<<endl;
					brk(1); spa(5);
					cout << "Down Payment: " << row[6]<<endl;
					brk(1); spa(5);
					cout << "Total Loan Amount: " << row[7]<<endl;
					brk(1); spa(5);
					cout << "Monthly Repayment: " << row[8]<<endl;

					snamtid = row[0];
					snclientid = row[1];
					snht = row[2];
					snamount = row[3];
					sir = row[4];
					slp = row[5];
					sdp = row[6];
					stla = row[7];
					smr = row[8];

				}
			}
			else
			{
				brk(3); spa(5);
				cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
			}
			cout << endl;
			cin.ignore(1, '\n');
			brk(1); spa(5);
			cout << "Enter Property Type (xN to not change): ";
			getline(cin, housetype );
			if (housetype== "xN")
			{
				housetype = snht;
			}
			brk(1); spa(5);
			cout << "Enter Property Price (xN to not change): ";
			getline(cin, amount);
			if (amount == "xN")
			{
				amount = snamount;
			}
			brk(1); spa(5);
			cout << "Enter Interest Rate (xN to not change): ";
			getline(cin, interest_rate);
			if (interest_rate == "xN")
			{
				interest_rate = sir;
			}
			brk(1); spa(5);
			cout << "Enter Loan Period (xN to not change): ";
			getline(cin, loan_period);
			if (loan_period == "xN")
			{
				loan_period = slp;
			}
			brk(1); spa(5);
			cout << "Enter Down Payment(xN to not change): ";
			getline(cin, down_payment);
			if (down_payment == "xN")
			{
				down_payment = sdp;
			}
			cout << fixed << showpoint;
			double amt = stod(amount);
			double ir = stod(interest_rate);
			int lp= stoi(loan_period);
			double dp = stod(down_payment);
			double monthly_interest_rate = (ir / 100) / 12;
			double down2 = amt * (dp / 100);
			double total_loan_amount = amt - down2;
			int monthly_term = lp * 12;
			double monthly_repayment = total_loan_amount * (monthly_interest_rate / (1 - pow(1 + monthly_interest_rate, -monthly_term)));
			brk(1); spa(5);
			cout << "Total loan amount: " <<setprecision(2)<< total_loan_amount;
			brk(1); spa(5);
			cout << "Monthly Repayment: " << monthly_repayment;
		

			string update_query = "update amount set House_type = '" + housetype + "', Amount = '" + amount + "', Interest_rate = '" + interest_rate + "', Loan_Period = '" + loan_period + "' , Down_payment = '" + down_payment + "', Total_loan_amount = '" + to_string(total_loan_amount) + "', Monthly_repayment = '" + to_string(monthly_repayment) + "' where Amount_ID ='" + amountid + "'";
			const char* qu = update_query.c_str();
			qstate = mysql_query(conn, qu);

			if (!qstate)
			{
				brk(3); spa(5);
				cout << "*Amount Updated Successfully In Database!" << endl;
			}
			else
			{
				brk(3); spa(5);
				cout << "Failed To Update!" << mysql_errno(conn) << endl;
			}

		}
		else
		{
		brk(3); spa(5);
			cout << "Calculation does not exist in database." << endl;
			Sleep(1000);
			system("cls");
			modifyCalc();

		}
	}

Label14:
	int option;
	brk(3); spa(5);
	cout << "Press 'a' to Update Again or 'b' to go back : ";
	cin >> choose;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choose == 'b' || choose == 'B')
	{
		system("cls");
		loancalc();;
		option = 1;
	}
	else if (choose == 'a' || choose == 'A')
	{
		system("cls");
		modifyCalc();
		option = 1;
	}
	else
	{
		brk(3); spa(5);
		cout << "Invalid key. Please enter again.";
		Sleep(1000);
		system("cls");
		goto Label14;
	}

}

void deleteCalc()
{
	system("cls");
	string amountid = "";
	string clientid = "";
	string housetype = "";
	string amount = "";
	string interest_rate = "";
	string loan_period = "";
	string down_payment = "";
	string total_loan_amount = "";
	string monthly_repayment = "";
	string item[5000];

	char choose;
	int Id;
	bool HaveException = false;
	bool NotInDatabase = false;
	int indexForId = 0;

	// Store Variables
	string snamtid = "";
	string snclientid = "";
	string snht = "";
	string snamount = "";
	string sir = "";
	string slp = "";
	string sdp = "";
	string stla = "";
	string smr = "";


	
	qstate = mysql_query(conn, "select Amount_ID, Client_ID from amount");
	if (!qstate)
	{
		res = mysql_store_result(conn);
		brk(1); spa(5);
		cout << "Clalculations In Database:" << endl;
		brk(1); spa(5);
		cout << "------------------------" << endl;
		brk(1); spa(5);
		cout << "| Bill No | Client ID\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{
			brk(1); spa(5);
			cout << "|  " << row[0] << " | " << row[1] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}
	}
	else
	{
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	try
	{
		brk(1); spa(5);
		cout << "Enter Bill No: ";
		cin >> amountid;
		cout << endl;
	}
	catch (exception e)
	{
		cout << "Please Enter a valid NUMBER." << endl;
		HaveException = true;
		goto Label15;
	}

	if (HaveException == false)
	{
		stringstream streamid;
		string strid;
		streamid << amountid;
		streamid >> strid;

		for (int i = 0; i < indexForId; i++)
		{
			if (strid != item[i])
			{
				NotInDatabase = true;
			}
			else
			{
				NotInDatabase = false;
				break;
			}
		}
		if (NotInDatabase == false)
		{
			string delete_query = "delete from amount where Amount_ID = '" + strid + "'";
			const char* qd = delete_query.c_str();
			qstate = mysql_query(conn, qd);

			if (!qstate)
			{
				system("cls");
				brk(1); spa(5);
				cout << "Successfully Deleted From Database." << endl;
			}
			else
			{
				brk(1); spa(5);
				cout << "Failed To Delete!" << mysql_errno(conn) << endl;
			}

		}
		else
		{
			system("cls");
			brk(1); spa(5);
			cout << "Amount does not exist in database." << endl;
			Sleep(1000);
			system("cls");
			deleteCalc();
		}
	}

	// Exit Code
Label15:
	int option;
	brk(2); spa(4);
	cout << "Press 'd' to Delete Again or 'b' to go back : ";
	cin >> choose;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choose == 'b' || choose == 'B')
	{
		system("cls");
		loancalc();
		option = 1;
	}
	else if (choose == 'd' || choose == 'D')
	{
		system("cls");
		deleteCalc();
		option = 1;
	}
	else
	{
		brk(3); spa(4);
		cout << "Invalid key. Please enter again.";
		system("cls");
		goto Label15;
	}
}

void StaffMenu()
{
	// Variables
	int choose = 0;
	int option = 0;
	char exitSurity;
	// Variables End
	brk(1); spa(4);
Label10:
	brk(1); spa(4);
	cout << "Staff Menus" << endl;
	brk(1); spa(4);
	cout << "1. CLIENTS" << endl;
	brk(1); spa(4);
	cout << "2. CALCULATION" << endl;
	brk(1); spa(4);
	cout << "3. View Amortization" << endl;
	brk(1); spa(4);
	cout << "4. Exit " << endl;
	brk(1); spa(4);
	cin >> choose;
	system("cls");

	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choose == 1)
	{
		system("cls");
		Staff_Client();
		option = 1;
	}
	else if (choose == 2)
	{
		system("cls");
		loancalc();
		option = 1;
	}
	else if (choose == 3)
	{
		system("cls");
		report_Staff();
		option = 1;
	}
	else if (choose == 4)
	{
		system("cls");
	ExitProgram:
		brk(1); spa(5);
		cout << "Program terminating. Are you sure? (y/N): ";
		cin >> exitSurity;
		if (exitSurity == 'y' || exitSurity == 'Y')
		{
			exit(0);
		}
		else if (exitSurity == 'n' || exitSurity == 'N')
		{
			system("cls");
			StaffMenu();
			option = 1;
		}
		else {
			system("cls");
			brk(1); spa(5);
			cout << "Next time choose after read the corresponding line." << endl;
			goto ExitProgram;
		}
	}

	else
	{
		system("cls");
		brk(1); spa(5);
		cout << "INVALID KEY!. PLEASE SELECT FROM 1 TO 4. ";
		Sleep(1000);
		option = 0;
		system("cls");
		goto Label10;
	}

}

void Staff_Client()
{
	int option;
Label9:
	system("cls");
	// Variables
	int chooseOneFromMenu = 0;
	char exitSurity;
	// Variables End
	brk(1); spa(5);
	cout << "Please choose your choice" << endl << endl;
	brk(1); spa(5);
	cout << "1. Add client" << endl;
	brk(1); spa(5);
	cout << "2. Modify client" << endl;
	brk(1); spa(5);
	cout << "3. Delete client" << endl;
	brk(1); spa(5);
	cout << "4. View client" << endl;
	brk(1); spa(5);
	cout << "5. Back" << endl;
	brk(1); spa(5);

	cin >> chooseOneFromMenu;

	while (!cin)
	{
		cout << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (chooseOneFromMenu == 1)
	{
		system("cls");
		addClient_Staff();
		option = 1;
	}
	else if (chooseOneFromMenu == 2)
	{
		system("cls");
		modifyClient_Staff();
		option = 1;
	}
	else if (chooseOneFromMenu == 3)
	{
		system("cls");
		deleteClient_Staff();
		option = 1;
	}
	else if (chooseOneFromMenu == 4)
	{
		system("cls");
		viewClient_Staff();
		option = 1;
	}
	else if (chooseOneFromMenu == 5)
	{
		system("cls");
		StaffMenu();
		option = 1;
	}
	else
	{
		system("cls");
		brk(1); spa(5);
		cout << "INVALID KEY!. PLEASE ENTER FROM 1 TO 5. ";
		Sleep(1000);
		option = 0;
		system("cls");
		goto Label9;
	}
}

void viewCalc()
{
	system("cls");

	// Variables
	string amountid = "";
	string clientid = "";
	string housetype = "";
	string amount = "";
	string interest_rate = "";
	string loan_period = "";
	string down_payment = "";
	string total_loan_amount = "";
	string monthly_repayment = "";
	string item[5000];

	char choose;
	int Id;
	bool HaveException = false;
	bool NotInDatabase = false;
	int indexForId = 0;

	// Store Variables
	string snamtid = "";
	string snclientid = "";
	string snht = "";
	string snamount = "";
	string sir = "";
	string slp = "";
	string sdp = "";
	string stla = "";
	string smr = "";



	qstate = mysql_query(conn, "select Amount_ID, Client_ID from amount");
	if (!qstate)
	{
		res = mysql_store_result(conn);
		brk(1); spa(5);
		cout << "Clalculations In Database:" << endl;
		brk(1); spa(5);
		cout << "------------------------" << endl;
		brk(1); spa(5);
		cout << "| Bill No | Client ID\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{
		     spa(5);
			cout << "|  " << row[0] <<  " | " << row[1] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}
	}
	else
	{
		brk(1); spa(5);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	try
	{
		brk(1); spa(5);
		cout << "Enter Bill No: ";
		cin >> amountid;
		cout << endl;
	}
	catch (exception e)
	{
		brk(1); spa(5);
		cout << "Please Enter a valid NUMBER." << endl;
		HaveException = true;
		goto ExitMenu;
	}

	if (HaveException == false)
	{
		stringstream streamid;
		string strid;
		streamid << amountid;
		streamid >> strid;

		for (int i = 0; i < indexForId; i++)
		{
			if (strid != item[i])
			{
				NotInDatabase = true;
			}
			else
			{
				NotInDatabase = false;
				break;
			}
		}

		if (NotInDatabase == false)
		{
			string findbyid_query = "select * from amount where Amount_ID = '" + strid + "'";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);

			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;
				while ((row = mysql_fetch_row(res)))
				{
					brk(1); spa(5);
					cout << "Bill No: " << row[0] << endl;
					brk(1); spa(5);
					cout << "Client ID: " << row[1] << endl;
					brk(1); spa(5);
					cout << "Property Type: " << row[2] << endl;
					brk(1); spa(5);
					cout << "Property Price: " << row[3] << endl;
					brk(1); spa(5);
					cout << "Interest Rate: " << row[4] << endl;
					brk(1); spa(5);
					cout << "Loan Period: " << row[5] << endl;
					brk(1); spa(5);
					cout << "Down Payment: " << row[6] << endl;
					brk(1); spa(5);
					cout << "Total Loan Amount: " << row[7] << endl;
					brk(1); spa(5);
					cout << "Monthly Repayment: " << row[8] << endl;

					snamtid = row[0];
					snclientid = row[1];
					snht = row[2];
					snamount = row[3];
					sir = row[4];
					slp = row[5];
					sdp = row[6];
					stla = row[7];
					smr = row[8];

				}
			}
		}
		else
		{
			brk(3); spa(5);
			cout << "Calculation does not exist in database." << endl;
			Sleep(1000);
			system("cls");
			viewCalc();
		}

	}
ExitMenu:
	brk(2); spa(5);
	cout << "Press any other key to Exit: ";
	cin >> choose;
	cout << endl;
	system("cls");
	AdminMenu();
}
	
void report()
{
	system("cls");

	// Variables
	string amountid = "";
	string clientid = "";
	string item[5000];

	char choose;
	int Id;
	bool HaveException = false;
	bool NotInDatabase = false;
	int indexForId = 0;
	int l = 0;

	// Store Variables
	string snamtid = "";
	string snclientid = "";
	string snht = "";
	string snamount = "";
	string sir = "";
	string slp = "";
	string sdp = "";
	string stla = "";
	string smr = "";



	qstate = mysql_query(conn, "select Amount_ID, Client_ID from amount");
	if (!qstate)
	{
		res = mysql_store_result(conn);
		brk(1); spa(5);
		cout << "Clalculations In Database:" << endl;
		brk(1); spa(5);
		cout << "------------------------" << endl;
		brk(1); spa(5);
		cout << "| Bill No | Client ID\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{ spa(5);
			cout << "|  " << row[0] << " | " << row[1] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}
	}
	else
	{
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	try
	{
		brk(1); spa(5);
		cout << "Enter Bill No: ";
		cin >> amountid;
		cout << endl;
	}
	catch (exception e)
	{
		cout << "Please Enter a valid NUMBER." << endl;
		HaveException = true;
	}

	if (HaveException == false)
	{
		stringstream streamid;
		string strid;
		streamid << amountid;
		streamid >> strid;

		for (int i = 0; i < indexForId; i++)
		{
			if (strid != item[i])
			{
				NotInDatabase = true;
			}
			else
			{
				NotInDatabase = false;
				break;
			}
		}

		if (NotInDatabase == false)
		{
			string findbyid_query = "select * from amount where Amount_ID = '" + strid + "'";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);

			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;
				while ((row = mysql_fetch_row(res)))
				{
					brk(1); spa(5);
					cout << "Bill No: " << row[0] << endl;
					brk(1); spa(5);
					cout << "Client ID: " << row[1] << endl;
					brk(1); spa(5);
					cout << "Property Type: " << row[2] << endl;
					brk(1); spa(5);
					cout << "Property Price: " << row[3] << endl;
					brk(1); spa(5);
					cout << "Interest Rate: " << row[4] << endl;
					brk(1); spa(5);
					cout << "Loan Period: " << row[5] << endl;
					brk(1); spa(5);
					cout << "Down Payment: " << row[6] << endl;
					brk(1); spa(5);
					cout << "Total Loan Amount: " << row[7] << endl;
					brk(1); spa(5);
					cout << "Monthly Repayment: " << row[8] << endl;

					snamtid = row[0];
					snclientid = row[1];
					snht = row[2];
					snamount = row[3];
					sir = row[4];
					slp = row[5];
					sdp = row[6];
					stla = row[7];
					smr = row[8];
				}
				cout << fixed << showpoint;
				double amount = stod(snamount);
				int loan_period = stoi(slp);
				double interest_rate = stod(sir);
				double monthly_repayment = stod(smr);
				double down_payment = stod(sdp);
				double total_interest_paid = 0;
				double total_principle_paid = 0;
				int j = 0;
				brk(2); spa(5);
				cout << "\t Amortized Payment Schedule" << endl;
				brk(1); spa(4);
				cout << setw(6) << left << "Month\t" << setw(12) << left << "Interest Paid\t" << setw(14) << right << "Principal Paid\t" << setw(12) << right << "Remaining Balance\t" << endl;
				for (int i = 1; i <= (loan_period * 12); i++)
				{
					double down2 = amount * (down_payment / 100);
					double mir = (interest_rate / 100) / 12;
					double interest_paid = (amount - down2) * mir;
					double principle_paid = monthly_repayment - interest_paid;
					if (i == 1)
					{
						amount = amount - principle_paid - down2;
						total_interest_paid = total_interest_paid + interest_paid;
						total_principle_paid = total_principle_paid + principle_paid;
						brk(1); spa(5);
						cout << setw(6) << left << i << setw(12) << left << setprecision(2) << interest_paid << setw(4) << right << setprecision(2) << principle_paid << setw(14) << right << setprecision(2) << amount << endl;
						j = j + 1;
					}
					else if (i == loan_period * 12)
					{
						double amount1 = amount;
						interest_paid = amount * mir;
						amount = 0;
						total_interest_paid = total_interest_paid + interest_paid;
						total_principle_paid = total_principle_paid + principle_paid;
						spa(5);
						cout << setw(6) << left << i << setw(12) << left << setprecision(2) << interest_paid << setw(4) << right << setprecision(2) << amount1 << setw(14) << right << setprecision(2) << amount << endl;
						 spa(5);
						cout << "Total Interest Paid: " << total_interest_paid << endl;
						 spa(5);
						cout << "Total Principle Paid: " << total_principle_paid << endl;
						 spa(5);
						cout << "Total Amount Should Be Paid for Last Year" << ": " << total_interest_paid + total_principle_paid << endl;
					}
					else
					{
						string k;
						double interest_paid = amount * mir;
						double principle_paid = monthly_repayment - interest_paid;
						amount = amount - principle_paid;
						total_interest_paid = total_interest_paid + interest_paid;
						total_principle_paid = total_principle_paid + principle_paid;
						spa(5);
						cout << setw(6) << left << i << setw(12) << left << setprecision(2) << interest_paid << setw(4) << right << setprecision(2) << principle_paid << setw(14) << right << setprecision(2) << amount << endl;
						j = j + 1;
						if (j == 12)
						{
							l = l + 1;
							brk(1); spa(5);
							cout << "Total Interest Paid: " << total_interest_paid << endl;
						    spa(5);
							cout << "Total Principle Paid: " << total_principle_paid << endl;
						    spa(5);
							cout << "Total Amount Should Be Paid for Year " << l << ": " << total_interest_paid + total_principle_paid << endl;
							total_interest_paid = 0;
							total_principle_paid = 0;
							brk(1); spa(5);
							cout << "Press any key to continue or b exit";
							cin >> k;
							if (k == "B" || k == "b")
							{
								system("cls");
								AdminMenu();
							}
							cout << endl;
							j = 0;
						}
					}

				}

			}
		}
			else
			{
				brk(3); spa(5);
				cout << "Calculation does not exist in database." << endl;
				Sleep(1000);
				system("cls");
				report();
			}

	ExitMenu:
		brk(2); spa(5);
		cout << "Press any other key to Exit: ";
		cin >> choose;
		cout << endl;
		system("cls");
		AdminMenu();
	}

	
}

void spa(int tab) {

	for (int i = 0; i < tab; i++) {
		cout << "\t";
	}

}

void brk(int line) {
	for (int i = 0; i < line; i++) {
		cout << "\n";
	}
}

void addClient_Staff()
{
	// Initial Load
	system("cls");
	// Initial Load End

	// Variables
	string clientid = "";
	string fname = "";
	string lname = "";
	int age;
	string address = "";
	string email = "";
	string phoneNo = "";


	char choose;
	// Variables End

	brk(1); spa(4);
	cout << "Add New Client Menu" << endl << endl;

	cin.ignore(1, '\n');
	brk(1); spa(4);
	cout << "Enter Client ID: ";
	getline(cin, clientid);
	brk(1); spa(4);
	cout << "Enter First Name: ";
	getline(cin, fname);
	brk(1); spa(4);
	cout << "Last Name: ";
	getline(cin, lname);
	brk(1); spa(4);
	cout << "Enter address: ";
	getline(cin, address);
	brk(1); spa(4);
	cout << "Enter email: ";
	getline(cin, email);
	brk(1); spa(4);
	cout << "Enter age: ";
	cin >> age;
	brk(1); spa(4);
	cout << "Enter Phone Number: ";
	cin >> phoneNo;



	stringstream streamage, streamphono;
	string sage;
	streamage << age;
	streamage >> sage;



	string insert_query = "insert into client (Client_ID, FName, LName, Age, Address, Email, PhoneNumber) values ('" + clientid + "','" + fname + "','" + lname + "','" + sage + "','" + address + "','" + email + "','" + phoneNo + "')";


	const char* q = insert_query.c_str(); // c_str converts string to constant char 

	qstate = mysql_query(conn, q);

	if (!qstate)
	{
		brk(3); spa(4);
		cout << "Client has been successfully added in database." << endl;
	}
	else
	{
		brk(3); spa(4);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	// Exit Code
Label5:
	int option;
	brk(3); spa(4);
	cout << "Press 'a' to Insert Again or 'b' to go back : ";
	cin >> choose;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choose == 'b' || choose == 'B')
	{
		system("cls");
		Staff_Client();
		option = 1;
	}
	else if (choose == 'a' || choose == 'A')
	{
		system("cls");
		addClient_Staff();
		option = 1;
	}
	else
	{
		brk(3); spa(4);
		cout << "Invalid key. Please enter again.";
		system("cls");
		goto Label5;
	}

}

void modifyClient_Staff()
{
	system("cls");

	// Variables
	string clientid = "";
	string fname = "";
	string lname = "";
	string address = "";
	string email = "";
	string age = "";
	string phoneNo = "";
	string item[5000];

	char choose;
	int Id;
	bool HaveException = false;
	bool NotInDatabase = false;
	int indexForId = 0;

	// Store Variables
	string snstaffid = "";
	string snfname = "";
	string snlname = "";
	string snaddress = "";
	string snemail = "";
	string snage = "";
	string snphoneNo = "";


	// Variables End

	qstate = mysql_query(conn, "select Client_ID, FName, LName from client");
	if (!qstate)
	{
		brk(1); spa(5);
		res = mysql_store_result(conn);
		system("cls");
		cout << "Clients In Database:" << endl;
		brk(1); spa(5);
		cout << "------------------------" << endl;
		cout << endl;
		spa(5);
		cout << "| ID\t| Name\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{
			spa(5);
			cout << "| " << row[0] << "\t" << "| " << row[1] << " " << row[2] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}
	}
	else
	{
		brk(1); spa(5);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	try
	{
		cout << endl;
		brk(1); spa(5);
		cout << "Enter Client ID: ";
		cin >> clientid;
		cout << endl;
	}
	catch (exception e)
	{
		brk(1); spa(5);
		cout << "Please Enter a valid NUMBER." << endl;
		HaveException = true;
		goto Label11;
	}

	if (HaveException == false)
	{
		stringstream streamid;
		string strid;
		streamid << clientid;
		streamid >> strid;

		for (int i = 0; i < indexForId; i++)
		{
			if (strid != item[i])
			{
				NotInDatabase = true;
			}
			else
			{
				NotInDatabase = false;
				break;
			}
		}

		if (NotInDatabase == false)
		{
			string findbyid_query = "select * from client where Client_ID = '" + strid + "'";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);

			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;
				while ((row = mysql_fetch_row(res)))
				{
					brk(2); spa(5);
					cout << "Current Client Information";
					brk(3); spa(5);
					cout << "Client ID: " << row[0] << endl;
					brk(1); spa(5);
					cout << "Client Name: " << row[1] << " " << row[2] << endl;
					brk(1); spa(5);
					cout << "Age: " << row[3] << endl;
					brk(1); spa(5);
					cout << "Address: " << row[4] << endl;
					brk(1); spa(5);
					cout << "Email: " << row[5] << endl;
					brk(1); spa(5);
					cout << "Phone Number: " << row[6] << endl;

					snstaffid = row[0];
					snfname = row[1];
					snlname = row[2];
					snage = row[3];
					snaddress = row[4];
					snemail = row[5];
					snphoneNo = row[6];

				}
			}
			else
			{
				brk(2); spa(5);
				cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
			}
			brk(3); spa(5);
			cout << "New Client Information";
			cin.ignore(1, '\n');
			brk(3); spa(5);
			cout << "Enter First Name (xN to not change): ";
			getline(cin, fname);
			if (fname == "xN")
			{
				fname = snfname;
			}
			brk(1); spa(5);
			cout << "Enter Last Name (xN to not change): ";
			getline(cin, lname);
			if (lname == "xN")
			{
				lname = snlname;
			}
			brk(1); spa(5);
			cout << "Enter Age (xN to not change): ";
			getline(cin, age);
			if (age == "xN")
			{
				age = snage;
			}
			brk(1); spa(5);
			cout << "Enter Address (xN to not change): ";
			getline(cin, address);
			if (address == "xN")
			{
				address = snaddress;
			}
			brk(1); spa(5);
			cout << "Enter Email (xN to not change): ";
			getline(cin, email);
			if (email == "xN")
			{
				email = snemail;
			}
			brk(1); spa(5);
			cout << "Enter Phone Number (xN to not change): ";
			getline(cin, phoneNo);
			if (phoneNo == "xN")
			{
				phoneNo = snphoneNo;
			}

			string update_query = "update client set FName = '" + fname + "', LName = '" + lname + "', Age = '" + age + "', Address = '" + address + "', Email = '" + email + "', PhoneNumber = '" + phoneNo + "' where Client_ID ='" + strid + "'";
			const char* qu = update_query.c_str();
			qstate = mysql_query(conn, qu);

			if (!qstate)
			{
				system("cls");
				brk(3); spa(5);
				cout << "*Client Updated Successfully In Database!" << endl;
			}
			else
			{
				system("cls");
				brk(3); spa(5);
				cout << "Failed To Update!" << mysql_errno(conn) << endl;
			}

		}
		else
		{
			brk(1); spa(5);
			cout << "Client does not exist in database." << endl;
			Sleep(1000);
			system("cls");
			modifyClient_Staff();

		}
	}

Label11:
	int option;
	brk(3); spa(5);
	cout << "Press 'a' to Update Again or 'b' to go back : ";
	cin >> choose;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choose == 'b' || choose == 'B')
	{
		system("cls");
		Staff_Client();
		option = 1;
	}
	else if (choose == 'a' || choose == 'A')
	{
		system("cls");
		modifyClient_Staff();
		option = 1;
	}
	else
	{
		brk(3); spa(5);
		cout << "Invalid key. Please enter again.";
		Sleep(1000);
		system("cls");
		goto Label11;
	}
}

void deleteClient_Staff()
{
	system("cls");
	char choose;
	bool HaveException = false;
	bool NotInDatabase = false;
	int indexForId = 0;
	string item[5000];
	string clientid;

	qstate = mysql_query(conn, "select Client_ID, FName, LName from client");
	if (!qstate)
	{
		res = mysql_store_result(conn);
		brk(1); spa(5);
		cout << "Clients In Database:" << endl;
		spa(5);
		cout << "------------------------" << endl;
		cout << endl;
		spa(5);
		cout << "| ID\t| Name\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{
			spa(5);
			cout << "| " << row[0] << "\t" << "| " << row[1] << " " << row[2] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}
	}
	else
	{
		brk(1); spa(5);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	try
	{
		cout << endl;
		brk(1); spa(5);
		cout << "Enter Client ID: ";
		cin >> clientid;
		cout << endl;
	}
	catch (exception e)
	{
		brk(1); spa(5);
		cout << "Please Enter a valid NUMBER." << endl;
		HaveException = true;
		goto Label12;
	}

	if (HaveException == false)
	{
		stringstream streamid;
		string strid;
		streamid << clientid;
		streamid >> strid;

		for (int i = 0; i < indexForId; i++)
		{
			if (strid != item[i])
			{
				NotInDatabase = true;
			}
			else
			{
				NotInDatabase = false;
				break;
			}
		}
		if (NotInDatabase == false)
		{
			string delete_query = "delete from client where Client_ID = '" + strid + "'";
			const char* qd = delete_query.c_str();
			qstate = mysql_query(conn, qd);

			if (!qstate)
			{
				brk(1); spa(5);
				cout << "Successfully Deleted From Database." << endl;
			}
			else
			{
				brk(1); spa(5);
				cout << "Failed To Delete!" << mysql_errno(conn) << endl;
			}

		}
		else
		{
			brk(1); spa(5);
			cout << "Client does not exist in database." << endl;
			Sleep(1000);
			system("cls");
			deleteClient_Staff();
		}
	}

	// Exit Code
Label12:
	int option;
	brk(2); spa(4);
	cout << "Press 'd' to Delete Again or 'b' to go back : ";
	cin >> choose;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choose == 'b' || choose == 'B')
	{
		system("cls");
		Staff_Client();;
		option = 1;
	}
	else if (choose == 'd' || choose == 'D')
	{
		system("cls");
		deleteClient_Staff();
		option = 1;
	}

	else
	{
		brk(3); spa(5);
		cout << "Invalid key. Please enter again.";
		Sleep(1000);
		system("cls");
		goto Label12;
	}
}

void viewClient_Staff()
{
	system("cls");
	string item[5000];
	int indexForId = 0;
	char choose;
	qstate = mysql_query(conn, "select Client_ID, FName, LName from client");
	if (!qstate)
	{
		res = mysql_store_result(conn);
		brk(1); spa(5);
		cout << "Clients In Database:" << endl;
		brk(1); spa(5);
		cout << "------------------------" << endl;
		brk(1); spa(5);
		cout << "| ID\t| Name\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{
			spa(5);
			cout << "| " << row[0] << "\t" << "| " << row[1] << " " << row[2] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}

	}
	else
	{
		brk(1); spa(5);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

ExitMenu:
	brk(2); spa(5);
	cout << "Press any other key to Exit: ";
	cin >> choose;
	cout << endl;
	system("cls");
	Staff_Client();

}

void viewCalc_Staff()
{
	system("cls");

	// Variables
	string amountid = "";
	string clientid = "";
	string housetype = "";
	string amount = "";
	string interest_rate = "";
	string loan_period = "";
	string down_payment = "";
	string total_loan_amount = "";
	string monthly_repayment = "";
	string item[5000];

	char choose;
	int Id;
	bool HaveException = false;
	bool NotInDatabase = false;
	int indexForId = 0;

	// Store Variables
	string snamtid = "";
	string snclientid = "";
	string snht = "";
	string snamount = "";
	string sir = "";
	string slp = "";
	string sdp = "";
	string stla = "";
	string smr = "";



	qstate = mysql_query(conn, "select Amount_ID, Client_ID from amount");
	if (!qstate)
	{
		res = mysql_store_result(conn);
		brk(1); spa(5);
		cout << "Clalculations In Database:" << endl;
		brk(1); spa(5);
		cout << "------------------------" << endl;
		brk(1); spa(5);
		cout << "| Bill No | Client ID\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{
			spa(5);
			cout << "|  " << row[0] << " | " << row[1] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}
	}
	else
	{
		brk(1); spa(5);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	try
	{
		brk(1); spa(5);
		cout << "Enter Bill No: ";
		cin >> amountid;
		cout << endl;
	}
	catch (exception e)
	{
		brk(1); spa(5);
		cout << "Please Enter a valid NUMBER." << endl;
		HaveException = true;
		goto ExitMenu;
	}

	if (HaveException == false)
	{
		stringstream streamid;
		string strid;
		streamid << amountid;
		streamid >> strid;

		for (int i = 0; i < indexForId; i++)
		{
			if (strid != item[i])
			{
				NotInDatabase = true;
			}
			else
			{
				NotInDatabase = false;
				break;
			}
		}

		if (NotInDatabase == false)
		{
			string findbyid_query = "select * from amount where Amount_ID = '" + strid + "'";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);

			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;
				while ((row = mysql_fetch_row(res)))
				{
					brk(1); spa(5);
					cout << "Bill No: " << row[0] << endl;
					brk(1); spa(5);
					cout << "Client ID: " << row[1] << endl;
					brk(1); spa(5);
					cout << "Property Type: " << row[2] << endl;
					brk(1); spa(5);
					cout << "Property Price: " << row[3] << endl;
					brk(1); spa(5);
					cout << "Interest Rate: " << row[4] << endl;
					brk(1); spa(5);
					cout << "Loan Period: " << row[5] << endl;
					brk(1); spa(5);
					cout << "Down Payment: " << row[6] << endl;
					brk(1); spa(5);
					cout << "Total Loan Amount: " << row[7] << endl;
					brk(1); spa(5);
					cout << "Monthly Repayment: " << row[8] << endl;

					snamtid = row[0];
					snclientid = row[1];
					snht = row[2];
					snamount = row[3];
					sir = row[4];
					slp = row[5];
					sdp = row[6];
					stla = row[7];
					smr = row[8];

				}
			}
		}
		else
		{
			brk(3); spa(5);
			cout << "Calculation does not exist in database." << endl;
			Sleep(1000);
			system("cls");
			viewCalc_Staff();
		}

	}
ExitMenu:
	brk(2); spa(5);
	cout << "Press any other key to Exit: ";
	cin >> choose;
	cout << endl;
	system("cls");
	loancalc();
}

void report_Staff()
{
	system("cls");

	// Variables
	string amountid = "";
	string clientid = "";
	string item[5000];

	char choose;
	int Id;
	bool HaveException = false;
	bool NotInDatabase = false;
	int indexForId = 0;
	int l = 0;

	// Store Variables
	string snamtid = "";
	string snclientid = "";
	string snht = "";
	string snamount = "";
	string sir = "";
	string slp = "";
	string sdp = "";
	string stla = "";
	string smr = "";



	qstate = mysql_query(conn, "select Amount_ID, Client_ID from amount");
	if (!qstate)
	{
		res = mysql_store_result(conn);
		brk(1); spa(5);
		cout << "Clalculations In Database:" << endl;
		brk(1); spa(5);
		cout << "------------------------" << endl;
		brk(1); spa(5);
		cout << "| Bill No | Client ID\n" << endl;

		while ((row = mysql_fetch_row(res)))
		{
			spa(5);
			cout << "|  " << row[0] << " | " << row[1] << endl;
			item[indexForId] = row[0];
			indexForId++;
		}
	}
	else
	{
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	try
	{
		brk(1); spa(5);
		cout << "Enter Bill No: ";
		cin >> amountid;
		cout << endl;
	}
	catch (exception e)
	{
		cout << "Please Enter a valid NUMBER." << endl;
		HaveException = true;
	}

	if (HaveException == false)
	{
		stringstream streamid;
		string strid;
		streamid << amountid;
		streamid >> strid;

		for (int i = 0; i < indexForId; i++)
		{
			if (strid != item[i])
			{
				NotInDatabase = true;
			}
			else
			{
				NotInDatabase = false;
				break;
			}
		}

		if (NotInDatabase == false)
		{
			string findbyid_query = "select * from amount where Amount_ID = '" + strid + "'";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);

			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;
				while ((row = mysql_fetch_row(res)))
				{
					brk(1); spa(5);
					cout << "Bill No: " << row[0] << endl;
					brk(1); spa(5);
					cout << "Client ID: " << row[1] << endl;
					brk(1); spa(5);
					cout << "Property Type: " << row[2] << endl;
					brk(1); spa(5);
					cout << "Property Price: " << row[3] << endl;
					brk(1); spa(5);
					cout << "Interest Rate: " << row[4] << endl;
					brk(1); spa(5);
					cout << "Loan Period: " << row[5] << endl;
					brk(1); spa(5);
					cout << "Down Payment: " << row[6] << endl;
					brk(1); spa(5);
					cout << "Total Loan Amount: " << row[7] << endl;
					brk(1); spa(5);
					cout << "Monthly Repayment: " << row[8] << endl;

					snamtid = row[0];
					snclientid = row[1];
					snht = row[2];
					snamount = row[3];
					sir = row[4];
					slp = row[5];
					sdp = row[6];
					stla = row[7];
					smr = row[8];
				}
				cout << fixed << showpoint;
				double amount = stod(snamount);
				int loan_period = stoi(slp);
				double interest_rate = stod(sir);
				double monthly_repayment = stod(smr);
				double down_payment = stod(sdp);
				double total_interest_paid = 0;
				double total_principle_paid = 0;
				int j = 0;
				brk(2); spa(5);
				cout << "\t Amortized Payment Schedule" << endl;
				brk(1); spa(4);
				cout << setw(6) << left << "Month\t" << setw(12) << left << "Interest Paid\t" << setw(14) << right << "Principal Paid\t" << setw(12) << right << "Remaining Balance\t" << endl;
				for (int i = 1; i <= (loan_period * 12); i++)
				{
					double down2 = amount * (down_payment / 100);
					double mir = (interest_rate / 100) / 12;
					double interest_paid = (amount - down2) * mir;
					double principle_paid = monthly_repayment - interest_paid;
					if (i == 1)
					{
						amount = amount - principle_paid - down2;
						total_interest_paid = total_interest_paid + interest_paid;
						total_principle_paid = total_principle_paid + principle_paid;
						brk(1); spa(5);
						cout << setw(6) << left << i << setw(12) << left << setprecision(2) << interest_paid << setw(4) << right << setprecision(2) << principle_paid << setw(14) << right << setprecision(2) << amount << endl;
						j = j + 1;
					}
					else if (i == loan_period * 12)
					{
						double amount1 = amount;
						interest_paid = amount * mir;
						amount = 0;
						total_interest_paid = total_interest_paid + interest_paid;
						total_principle_paid = total_principle_paid + principle_paid;
						spa(5);
						cout << setw(6) << left << i << setw(12) << left << setprecision(2) << interest_paid << setw(4) << right << setprecision(2) << amount1 << setw(14) << right << setprecision(2) << amount << endl;
						spa(5);
						cout << "Total Interest Paid: " << total_interest_paid << endl;
						spa(5);
						cout << "Total Principle Paid: " << total_principle_paid << endl;
						spa(5);
						cout << "Total Amount Should Be Paid for Last Year" << ": " << total_interest_paid + total_principle_paid << endl;
					}
					else
					{
						string k;
						double interest_paid = amount * mir;
						double principle_paid = monthly_repayment - interest_paid;
						amount = amount - principle_paid;
						total_interest_paid = total_interest_paid + interest_paid;
						total_principle_paid = total_principle_paid + principle_paid;
						spa(5);
						cout << setw(6) << left << i << setw(12) << left << setprecision(2) << interest_paid << setw(4) << right << setprecision(2) << principle_paid << setw(14) << right << setprecision(2) << amount << endl;
						j = j + 1;
						if (j == 12)
						{
							l = l + 1;
							brk(1); spa(5);
							cout << "Total Interest Paid: " << total_interest_paid << endl;
							spa(5);
							cout << "Total Principle Paid: " << total_principle_paid << endl;
							spa(5);
							cout << "Total Amount Should Be Paid for Year " << l << ": " << total_interest_paid + total_principle_paid << endl;
							total_interest_paid = 0;
							total_principle_paid = 0;
							brk(1); spa(5);
							cout << "Press any key to continue or b exit";
							cin >> k;
							if (k == "B" || k == "b")
							{
								system("cls");
								StaffMenu();
							}
							cout << endl;
							j = 0;
						}
					}

				}

			}
		}
		else
		{
			brk(3); spa(5);
			cout << "Calculation does not exist in database." << endl;
			Sleep(1000);
			system("cls");
			report_Staff();
		}

	ExitMenu:
		brk(2); spa(5);
		cout << "Press any other key to Exit: ";
		cin >> choose;
		cout << endl;
		system("cls");
		StaffMenu();
	}


}

