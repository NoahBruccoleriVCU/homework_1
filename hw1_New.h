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

class account_List {
	public:
	string last_Name;
	string first_Name;
	int account_Number;
	double account_Balance;
	account_List* next;
};


void print_Account_List(account_List*);

void average_Balance(account_List*);

account_List* add_New_Account(account_List*);