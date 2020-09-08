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


int main(){
	
	ifstream input_File;
	ifstream output_File;
	
	string input_File_Name = "hw1.txt";
	string output_File_Name = "hw2.txt";
	
	cout << "Program to keep a list of accounts using a linked list." << endl;
	
	while(1){
		cout << "Input filename:";
		cin >> input_File_Name;
		input_File.open(input_File_Name, fstream::in);
		if(!input_File.is_open()){
			cout <<  "ERROR: file " << input_File_Name << " can not be opened!\n";
		}
		else{
			break;
		}
	}


	account_List* first_Account = new account_List(); 
	bool is_First_Account = true;
	
	while(!input_File.eof()){
		account_List* next_Account = new account_List(); 
		account_List* dummy_Account_1 = first_Account;
		account_List* dummy_Account_2;
		
		if(is_First_Account == true){
			
			input_File >> first_Account->last_Name;
			input_File >> first_Account->first_Name;
			input_File >> first_Account->account_Number;
			input_File >> first_Account->account_Balance;
			is_First_Account = false;
		}
		else{
			while(dummy_Account_1 != NULL){
				dummy_Account_2 = dummy_Account_1;
				dummy_Account_1 = dummy_Account_1->next;
			}
			
			input_File >> next_Account->last_Name;
			input_File >> next_Account->first_Name;
			input_File >> next_Account->account_Number;
			input_File >> next_Account->account_Balance;
			dummy_Account_2->next = next_Account;

		}
	}
	input_File.close();
	

	cout << endl << "Enter option:" << endl;
	cout << "\t(0) Write output file and exit" << endl;
	cout << "\t(1) Print the list" << endl;
	cout << "\t(2) Add new account at head of the list" << endl;
	cout << "\t(3) Calculate and display average balance" << endl;
	cout << "\t\tChoice ?";
	
	int choice = 4;
	while(1){
		cin >> choice;
		if(choice == 0){
			cout << "Writing output file " << output_File_Name;
			print_Account_List(first_Account);
			break;
		}
		else if(choice == 1){
			print_Account_List(first_Account);
		}
		else if(choice == 2){
			first_Account = add_New_Account(first_Account);
		}
		else if(choice == 3){
			average_Balance(first_Account);
		}
		cout << endl << "\tChoice ?";
	}
	
	
	
	
	//cout << last_Name;
	
	return 0;
}





