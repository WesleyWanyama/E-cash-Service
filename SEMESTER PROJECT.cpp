/*NAME: WESLEY WANYAMA
ADM NO: 136895
SEMESTER PROJECT
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	int option;
	string username, password, un, pw;
	string adminpw, adminun,str,ptr;
	int withdraw;
	float balance, deposit;
	ifstream fin;
	ofstream fout;
	ifstream inadmin;
	ofstream outadmin;
	ofstream adminpass;
	string newPw;
	cout<<"*****WELCOME TO BBIT2020 E-CASH SERVICES****\n";
	cout<<"1. Normal User Login\n2. Administrator Login\n"<<endl;
	cout<<"Choose an option to proceed: ";
	cin>> option;
	switch(option)
	{
		case 1:
			system("cls");
			fin.open("usersDB.txt");
			fin>>username;
			fin>>password;
			fin>>balance;
			cout<<"Welcome to the Normal User Login page:\n\n";
			cout<<"Enter Username: ";
			cin>>un;
			cout<<"Enter Password: ";
			cin>>pw;
			while(un!=username || pw!=password)
			{
				system("cls");
				cout<<"Wrong username or password. Re-enter\n";
				cout<<"Enter Username: ";
			    cin>>un;
			    cout<<"Enter Password: ";
			    cin>>pw;
			}
			if(un == username && pw == password)
			{
				system("cls");
				cout<<"Welcome "<<username<<endl;
				int num;
				cout<<"1. Withdraw cash\n";
				cout<<"2. Check balance\n";
				cout<<"3. Reset your password\n\n";
				cout<<"Enter option to proceed: ";
				cin>>num;
				switch(num)
				{
					case 1:
						system("cls");
						cout<<"Enter the amount you want to withdraw: ";
						cin>>withdraw;
						if(balance>withdraw)
						{
							fout.open("tempt.txt");
							balance = balance-withdraw;
							cout<<"Withdraw successful new balance is: "<<balance<<endl;
							fout<<username<<endl;
							fout<<password<<endl;
							fout<<balance<<endl;
							fin.close();
							fout.close();
							remove("usersDB.txt");
							rename("tempt.txt", "usersDB.txt");
						}
						else
						{
							cout<<"Failed to withdraw due to insufficient balance. Your balance is: "<<balance<<endl;
						}
						break;
					case 2:
						system("cls");
						cout<<"Your balance is: "<<balance;
						break;
					case 3:
						system("cls");
						fout.open("newpass.txt");
						cout<<"Enter new password: ";
						cin>>password;
						cout<<"Your new password is: "<<password<<" Please confirm!!";
						fout<<username<<endl;
						fout<<password<<endl;
						fout<<balance<<endl;
						fin.close();
						fout.close();
						remove("usersDB.txt");
						rename("newpass.txt", "usersDB.txt");
						break;
					default:
						cout<<"!!INVALID INPUT!!";
				}
			}
			break;
		case 2:
			system("cls");
			inadmin.open("admin.txt");
			getline(inadmin, str);
			getline(inadmin, ptr);
			cout<<"Welcome to the Registration and Deposit page\n";
			cout<<"Enter administrator username and password.\n";
			cout<<"Enter username: ";
			cin>>adminun;
			cout<<"Enter password: ";
			cin>>adminpw;
			while(adminun!=str || adminpw!=ptr)
			{
				system("cls");
				cout<<"Wrong username or password. Re-enter\n";
				cout<<"Enter username: ";
			    cin>>adminun;
			    cout<<"Enter password: ";
			    cin>>adminpw;
			}
			if(adminun == str && adminpw == ptr)
			{
				system("cls");
				int mun;
				outadmin.open("usersDB.txt", ios::app);
				cout<<"Welcome admin \n";
				cout<<"1. Deposit money for client\n";
				cout<<"2. Register new client\n";
				cout<<"3. Reset your password\n";
				cout<<"Enter option to proceed: ";
				cin>>mun;
				switch(mun)
				{
				    case 1:
					   system("cls");
					   cout<<"Enter amount to deposit: ";
					   cin>>deposit;
					   if(deposit>0)
					   {
					   balance = balance + deposit;
					   outadmin<<balance;
					   cout<<"Deposit successful. New account balance for client is "<<balance;	
				       }
				       else
				       {
				    	cout<<"Cannot deposit a negative value";
					   }
					   break;
					case 2:
						system("cls");
						int age;
						int idNum;
						cout<<"Enter username for the new client: ";
						cin>>username;
						cout<<"Enter age: ";
						cin>>age;
						if(age>=18)
						{
						cout<<"Enter id number: ";
						cin>>idNum;
						cout<<"Enter new password: ";
						cin>>password;
						outadmin<<username<<endl;
						outadmin<<password<<endl;
						cout<<"Registration successful";
					    }
					    else
					    {
					    	cout<<"Client must be above 18 to register";
						}
						break;
					case 3:
						system("cls");
						adminpass.open("newadm.txt");
						cout<<"Enter your new password: ";
						cin>>adminpw;
						cout<<"The new admin password is "<<adminpw<<" Please confirm";
						adminpass<<adminun<<endl;
						adminpass<<adminpw;
						inadmin.close();
						outadmin.close();
						adminpass.close();
						remove("admin.txt");
						rename("newadm.txt", "admin.txt");
						break;
					default:
						cout<<"!!INVALID INPUT!!";
				}
			}
			else
			{
				cout<<"!!Invalid username or password!!";
			}
		    break;
		 default:
			cout<<"!!INVALID INPUT!!";
	}
	return 0;
}









