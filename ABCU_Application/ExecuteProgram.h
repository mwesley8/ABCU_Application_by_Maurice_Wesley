#ifndef EXECUTEPROGRAM_H
#define EXECUTEPROGRAM_H
//============================================================================
// Name        : ABCU BST Execute Program Header
// Author      : Maurice Wesley
// Version     : 5.0
// Copyright   : Copyright © 2022 SNHU COCE
// Description : Header for Execute Program cpp
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <regex>
#include <sstream>
#include <vector>
#include <regex>

struct Curriculum {
	// Declare member variables
	std::string m_ID;
	std::string m_Course;
	std::vector<std::string> m_requirements;
};
struct Node {
	// Declare member variables
	Curriculum curriculum;
	Node* left;
	Node* right;

	// Declare constructors
	Node();
	Node(Curriculum t_courses);
};
struct Prerequisites {
	// Declare member variables
	std::string m_Class;

	// Declare constructors
	Prerequisites();
	Prerequisites(std::string t_aClass);
};

// Class declarations
class ExecuteProgram {

public:
	// Declare member object
	Prerequisites aCourse;
	Node* root = nullptr;

	// Delare member functions

	// Function to search for match in data structgure
	Curriculum search(std::string t_courseID);
	
	// Functio to insert Node into data structure
	Node* insertNode(Node*& root, Node* newNode);

	// Declare vector to hold list of classes
	std::vector <ExecuteProgram> classList;
	
	// Declare default constructor
	ExecuteProgram();

	// Declare custom constructor
	ExecuteProgram(Prerequisites t_aClass);

	// Declare destructor
	virtual ~ExecuteProgram();
	
	// Function to run the application 
	void runProgram();

	// Function to output menu to user
	void printMenu();

	// Function to check user selection
	int checkNum();
	
	// Function to validate class input from user
	std::string CheckClass();

	// Functino to validate file input from user
	std::string CheckFile();

	// Function to capitalize the first four letter of user input
	std::string stringToUpper(std::string t_input);

	// Function to read file from user input
	void readFile(std::string t_address);
	
	// Function to print courses in alphnumeric order
	void inOrderPrint(Node* root);

	// Function to print course data to user
	void PrintClass(Curriculum& t_curr);

	//Fuction to validate prerequisites
	bool validateClass(std::vector<ExecuteProgram>& classList, std::string t_aClass);
	
	// Function to partition vector of class
	void quickSortClassList(std::vector<ExecuteProgram>& classList, int t_begin, int t_end);
	
	// Function to partition vector of prerequisites
	void quickSortPrerequisites(Node* t_curr, int t_begin, int t_end);
    
	// Function to sort class partition
	int partitionClassList(std::vector<ExecuteProgram>& t_classList, int t_begin, int t_end);
	
	// Function to sort prerequisites partition
	int partitionPrerequisites(Node* t_curr, int t_begin, int t_end);
};
#endif
