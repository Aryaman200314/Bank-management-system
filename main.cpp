#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class bank 
{
	private:
		int pin;
		string phone;
		string id;
		string pass;
		string name;
		string FName;
		string address;
		float balance;
		
	public:
		void menu();
		void bank_management();
		void atm_management();
		void new_user();
		void already_user();
		void deposite();
		void withdraw();
		void transfer_amount();
};
	void bank::menu() 
	{
		p:
		system("cls");
		int choice;
		char ch;
		string pin;
		string pass;
		string email;
		cout<<"\t\t\t\tControl Panel"<<endl;
		cout<<"1. Bank Management"<<endl;
		cout<<"2. Atm Management"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"Enter your choice: ";
		
		cin>>choice;
		switch(choice) {
			case 1:
				system("cls");
				cout<<"\t\t\t\tBank Mangement console."<<endl;
				cout<<"Login account"<<endl;
				cout<<"Enter your email: ";
				cin>>email;
				cout<<endl;
				cout<<"Enter your five digit pin code: ";
				for(int i = 1 ; i <= 5 ;i++)
				{
					ch = getch();
					pin = pin + ch;
					cout<<"*";
				}
				cout<<endl;
				cout<<"Enter password: ";
				for(int i = 1 ; i <= 5 ; i++ ) 
				{
					ch = getch();
					pass = pass + ch;
					cout<<"*";
				}
				cout<<endl;
				if(email == "200314arya@gmail.com" && pin == "12345" && pass == "12345")
				{
					bank_management();
				}
				else {
					cout<<"\t\t\t\t\tPlease enter right credentails!";
				}
				break;
				
			case 2:
				atm_management();
				break;
				
			case 3:
				exit(0);
				
			default:
			cout<<"Invalid value please try again!";		
		}
		getch();
		goto p;
	}
	
	void bank::bank_management() {
		system("cls");
		int choice;
		cout<<"\t\t\t\t Bank Management"<<endl;
		cout<<"1. New User"<<endl;
		cout<<"2. ALready user"<<endl;
		cout<<"3. Deposite option"<<endl;
		cout<<"4. Withdraw option"<<endl;
		cout<<"5. Transfer option"<<endl;
		cout<<"6. Payment option"<<endl;
		cout<<"7. Search user record"<<endl;
		cout<<"8. Edit user record"<<endl;
		cout<<"9. Delete user Record"<<endl;
		cout<<"10. show all records"<<endl;
		cout<<"11. Payment all records"<<endl;
		cout<<"12. Go Back"<<endl;
		
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice) {
			case 1:
				new_user();
				break;
			case 2:
				already_user();
				break;
			case 3:
				deposite();
				break;
			case 4:
				withdraw();
				break;
			case 5:
				transfer_amount();
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;
			case 12:
				menu();
			default:
				cout<<"Invalid choice Please enter valid input!";
		}
		
	}
	
	void bank::atm_management() {
		p:
		system("cls");
		int choice;
		cout<<"\t\t\t\tAtm management system";
		cout<<endl;
		cout<<"1. User login and check balance"<<endl;
		cout<<"2. Withdraw Amount"<<endl;
		cout<<"3. Account details"<<endl;
		cout<<"4. Go Back"<<endl;
		cout<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				menu();
			default:
				cout<<"Invalid input please enter valid choice";
		}
		getch();
		goto p;
	}
	
	void bank::new_user() {
		p:
		system("cls");
		fstream file;
		int p;
		string n, f, pa, a, ph, i;
		float bl;
		cout<<"\t\t\t\t Add New User"<<endl;
		cout<<"Unique User ID: ";
		cin>>id;
		cout<<endl;
		cout<<"Name: ";
		cin>>name;
		cout<<endl;
		cout<<"Enter father name: ";
		cin>>FName;
		cout<<endl;
		cout<<"Enter your address: ";
		cin>>address;
		cout<<endl;
		cout<<"Enter 5 digit pin code: ";
		cin>>pin;
		cout<<endl;
		cout<<"Enter Password: ";
		cin>>pass;
		cout<<endl;
		cout<<"Enter Phone number: ";
		cin>>phone;
		cout<<endl;
		cout<<"Enter current balance: ";
		cin>>balance;
		file.open("bank.txt", ios::in);
		if(!file) {
			file.open("bank.txt", ios::app|ios::out); //file handling and stroing data into the file.
			file<<" "<<id<<" "<<name<<" "<<FName<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<endl;
			file.close();
		}
		else {
			file>>i>>n>>f>>a>>p>>pa>>ph>>bl;
			while(!file.eof()) {
				if(i == id){
					cout<<"\t\t\t\t User ID already exists please make an unique id";
					getch();
					goto p;
				}
				file>>i>>n>>f>>a>>p>>pa>>ph>>bl;
			}
			file.close();
			file.open("bank.txt", ios::app|ios::out); 
			file<<" "<<id<<" "<<name<<" "<<FName<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<endl;
			file.close();
		}
		cout<<"\t\t\t\t New user added successfully!";
	}
	
	void bank::already_user() {
		system("cls");
		fstream file;
		string Test_id;
		int found = 0;
		cout<<"\t\t\t\t Already user account details"<<endl;
		file.open("bank.txt", ios::in);
		if(!file) {
			cout<<"\t\t\t\t File opening error"<<endl;
		}
		else {
			cout<<"Enter user ID: ";
			cin>>Test_id;
			file>>id>>name>>FName>>address>>pin>>pass>>phone>>balance;
			while(!file.eof()) {
				if(Test_id == id) {
					system("cls");
					cout<<"\t\t\t\t User account Details"<<endl;
					cout<<"User ID: "<<id<<endl;
					cout<<"Pin Code: "<<pin<<endl;
					cout<<"Password: "<<pass<<endl;
					cout<<"Balance: "<<balance<<endl;
					found++;
				}
				file>>id>>name>>FName>>address>>pin>>pass>>phone>>balance;
			}
			file.close();
			if(found == 0) {
				cout<<"User ID did'nt exist!";
			}
		}
	}
	
	void bank::withdraw() {
		fstream file;
		fstream fileUpdated;
		string Test_id;
		float with;
		int found = 0;
		system("cls");
		cout<<"\t\t\t\t Money withdraw portal"<<endl;
		cout<<endl;
		file.open("bank.txt", ios::in);
		if(!file) {
			cout<<"\t\t\t\t File opening error"<<endl;
		}
		else {
			cout<<"\t\t\t\t Please enter user details"<<endl;
			cout<<"Enter user ID: ";
			cin>>Test_id;
			fileUpdated.open("bank1.txt",ios::app|ios::out);
			file>>id>>name>>FName>>address>>pin>>pass>>phone>>balance;
			while(!file.eof()) {
				if(Test_id == id) {
					system("cls");
					cout<<"\t\t\t\t User account Details for withdrawal"<<endl;
					cout<<"Enter amount: ";
					cin>>with;
					if(with <= balance) {
					balance = balance - with;
					fileUpdated<<" "<<id<<" "<<name<<" "<<FName<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<endl;
					found++;
					
					cout<<"\t\t\t\t Amout deducted: "<<with<<endl;
				}
				else {
					fileUpdated<<" "<<id<<" "<<name<<" "<<FName<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<endl;
					cout<<" \t\t\t Your current balance is less that the withdrawal amount"<<endl;
					cout<<"Your current balance is:"<<balance<<endl;
				}
				found++;
				}
				else {
					fileUpdated<<" "<<id<<" "<<name<<" "<<FName<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<endl;
				}
				file>>id>>name>>FName>>address>>pin>>pass>>phone>>balance;
			}
			file.close();
			fileUpdated.close();
			remove("bank.txt");
			rename("bank1.txt", "bank.txt");
			if(found == 0) {
				cout<<"User ID did'nt exist!";
			}
		}
	}
	
	void bank::deposite() {
		fstream file;
		fstream fileUpdated;
		string Test_id;
		float dep;
		int found = 0;
		system("cls");
		cout<<"\t\t\t\t Money deposite portal"<<endl;
		cout<<endl;
		file.open("bank.txt", ios::in);
		if(!file) {
			cout<<"\t\t\t\t File opening error"<<endl;
		}
		else {
			cout<<"\t\t\t\t Please enter user details"<<endl;
			cout<<"Enter user ID: ";
			cin>>Test_id;
			fileUpdated.open("bank1.txt",ios::app|ios::out);
		
			file>>id>>name>>FName>>address>>pin>>pass>>phone>>balance;
			while(!file.eof()) {
				if(Test_id == id) {
					system("cls");
					cout<<"\t\t\t\t User account Details"<<endl;
					cout<<"Enter amount: ";
					cin>>dep;
					balance = balance + dep;
					fileUpdated<<" "<<id<<" "<<name<<" "<<FName<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<endl;
					found++;
					
					cout<<"\t\t\t\t Amout added: "<<dep<<endl;
				}
				else {
					fileUpdated<<" "<<id<<" "<<name<<" "<<FName<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<endl;
				}
				file>>id>>name>>FName>>address>>pin>>pass>>phone>>balance;
			}
			file.close();
			fileUpdated.close();
			remove("bank.txt");
			rename("bank1.txt", "bank.txt");
			if(found == 0) {
				cout<<"User ID did'nt exist!";
			}
		}
	}
	
	void bank::transfer_amount() {
		fstream file, file1;
		string Sender_ID;
		string Receiver_ID;
		system("cls");
		cout<<"\t\t\t\t Transfer amount portal"<<endl;
		file.open("bank.txt", ios::in);
		if(!file) {
			cout<<"File opening error";
		}
		else {
			
			cout<<"Enter sender User ID: ";
			cin>>Sender_ID;
			cout<<"Enter receiver User ID: ";
			cin>>Receiver_ID;
			file1.open("bank1.txt",ios::app|ios::out);
			file>>id>>name>>FName>>address>>pin>>pass>>phone>>balance;
			while(!file.eof()) {
				if(Sender_ID == id) {
					balance = balance - 	
				}
				else if(Receiver_ID == id) {
					
				}
				else {
					
				}
				file>>id>>name>>FName>>address>>pin>>pass>>phone>>balance;
			}
		}
	}
	
main() {
	bank obj;
	obj.menu();
}
