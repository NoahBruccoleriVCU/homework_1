//*********************************************************************************
// Program #: Homework 1
//
// Programmer: Noah Bruccoleri
//
// Due Date: 2020.Sep.08
//
// EGRE 347, Fall 2020       Instructor: Robert Klenke
//
// Pledge: I have neither given nor received unauthorized aid on this program.
//
// Description: [Insert a brief paragraph describing the program]
//
// Input: [Insert a brief description of user inputs, or "None" if  
//         there is no user input]
//
// Output: [Insert a brief description of the program output]
//
//*********************************************************************************

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> 
using namespace std;

#include "hw1_New.h"

account_List* add_New_Account(account_List* first_Account){
	
	account_List* dummy_Account = first_Account;
	first_Account = new account_List(); 
	
	cout << "Enter new member's last name ?";
	cin >> first_Account->last_Name;
	cout << "Enter new member's first name ?";
	cin >> first_Account->first_Name;
	cout << "Enter new member's account number ?";
	cin >> first_Account->account_Number;
	cout << "Enter new member's balance ?";
	cin >> first_Account->account_Balance;
	
	first_Account->next = dummy_Account;
	
	return first_Account;
}

void average_Balance(account_List* first_Account){

	double average_Balance = 0;
	int number_Of_Accounts = 0;
	account_List* dummy_Account = first_Account;
	while(dummy_Account != NULL){
		average_Balance = dummy_Account->account_Balance + average_Balance;
		++number_Of_Accounts;
		dummy_Account = dummy_Account->next;
	}
	
	cout << fixed << "There are " << number_Of_Accounts << " members with an average balance of " << average_Balance/number_Of_Accounts  << endl;
}

void print_Account_List(account_List* first_Account){
	
	cout << "Member List" << endl;
	cout << "Last name\tfirst name\taccount no.\tbalance" << endl;
	cout << "----------------------------------------------------------" << endl;
	
	account_List* dummy_Account = first_Account;
	while(dummy_Account != NULL){
		cout << dummy_Account->last_Name << "\t\t";
		cout << dummy_Account->first_Name << "\t\t";
		cout << dummy_Account->account_Number << "\t\t";
		cout << dummy_Account->account_Balance << endl;
		dummy_Account = dummy_Account->next;
	}
	
}


