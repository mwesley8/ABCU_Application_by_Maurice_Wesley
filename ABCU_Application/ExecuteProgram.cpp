//============================================================================
// Name        : ABCU BST Execute Program cpp
// Author      : Maurice Wesley
// Version     : 5.0
// Copyright   : Copyright © 2022 SNHU COCE
// Description : Code to execute program
//============================================================================

#include "ExecuteProgram.h"

using namespace std;

// Define Node default constructor
Node::Node() {
	left = nullptr;
	right = nullptr;
}

// Define Node custom constructor
Node::Node(Curriculum t_courses) {
	this->curriculum = t_courses;
	left = nullptr;
	right = nullptr;
}

// Define Prerequisites default constructor
Prerequisites::Prerequisites() {};

// Define Prerequisite custom constructor
Prerequisites::Prerequisites(std::string t_aClass) {
	this->m_Class = t_aClass;
}

// Define Execute Program default constructor
ExecuteProgram::ExecuteProgram() {}

// Define Execute Program custom constructor
ExecuteProgram::ExecuteProgram(Prerequisites t_aClass) {
	this->aCourse = t_aClass;
}

// Define destructor
ExecuteProgram::~ExecuteProgram() {
	delete root;
}

// Function to output menu to user
void ExecuteProgram::printMenu() {
	// Method defintion to output menu to user
	cout << setw(64) << right << "COURSE PLANNER" << endl;
	cout << setw(42) << " " << string(29, '*') << endl;
	cout << "" << endl;
	cout << setw(42) << " " << "** 1: Load Data Structure  ** " << endl;
	cout << "" << endl;
	cout << setw(42) << " " << string(29, '*') << endl;
	cout << "" << endl;
	cout << setw(42) << " " << "** 2: Print Course List    **" << endl;
	cout << "" << endl;
	cout << setw(42) << " " << string(29, '*') << endl;
	cout << "" << endl;
	cout << setw(42) << " " << "** 3: Print Course         **" << endl;
	cout << "" << endl;
	cout << setw(42) << " " << string(29, '*') << endl;
	cout << "" << endl;
	cout << setw(42) << " " << "** 9: Exit                 **" << endl;
	cout << "" << endl;
	cout << setw(42) << " " << string(29, '*') << endl;
}

// Function to check user selection
int ExecuteProgram::checkNum() {
	// Function to check user selection
	string userInput{};                                                // Declare/initialize local variables
	int userNum{};
	printf("\n\n\n");
	// Loop to check user input
	while (true) {
		printMenu();                                                   // Function call to print menu
		printf("\n\n");
		cout << "Please enter your selection:" << endl;                // Output to user
		regex selection("[1-3]");                                      // Regex classification
		getline(cin, userInput, '\n');                                 // Get user input
		// Condition to check user input
		if (regex_match(userInput, selection) || userInput == "9") {
			userNum = stoi(userInput);                                 // Parse integer from a string
			break;
		}
		// Condition when previous condition false
		else {
			// Output to user
			system("color 46");                                         // Change console color
			cout << "\nPlease enter a valid option. \n" << endl;        // Output to user
			system("pause");
			cin.clear();
			system("cls");
			system("color 1C");
		}
	}
	return userNum; // return user input
}

//Fuction to validate prerequisites
bool ExecuteProgram::validateClass(vector<ExecuteProgram>& classList, string aClass) {
	// Function to validate prerequisites using binary search
	int low = 0;                                                         // Initialize local variables
	int high = classList.size() - 1;

	while (low <= high) {                                                // Loop while low is less than or equal to high
		int mid = (low + high) / 2;                                      // Initialize scope variable
		if (classList.at(mid).aCourse.m_Class == aClass) {               // Check for match
			return true;                                                 // Exit when true
		}
		else if (classList.at(mid).aCourse.m_Class < aClass) {           // Check if mid less than search variable
			low = mid + 1;                                               // Reassign low
		}
		else {                                                           // Reassign high when previouis condition false
			high = mid - 1;
		}
	}
	return false;                                                        // Return false when a match is not found
}

// Functino to validate file input from user with return type string
string ExecuteProgram::CheckFile() {
	// Function to check user input of file
	string extension;                                                    // Initialize local variables
	regex file("[a-zA-z]*\.txt");
	
	while (true) {
		system("cls");
		cout << "\nPlease enter the file extension:\n" << endl;          // Output to user
		getline(cin, extension, '\n');                                   // Assign local variable to user input
		
		if (regex_match(extension, file)) {                              // Check user input
			cout << "\n\nThank You!!\n" << endl;                         // Output to user when true
			return extension;                                            // Return user input
		}
		else {
			system("color 46");
			cout << "\nYou have entered an invalid file extension.\n" << endl; // Output for invlaid input
			cout << "Please enter a valid file extension" << endl;
			system("pause");
			system("color 1C");
		}
	}
}

// Function to sort partitioned classlist vector with return type int
int ExecuteProgram::partitionClassList(vector<ExecuteProgram>& t_classList, int t_begin, int t_end) {
	/* Partition the vector of into two parts, low and high */

	// Initialize local variables
	int low = t_begin;
	int high = t_end;
	int mid = (low + high) / 2;
	string pivot = classList[mid].aCourse.m_Class;
	int count = 0;

	// Count how many elements less than the current pivot
	for (int i = low; i <= high; i++) {
		if (t_classList[i].aCourse.m_Class.compare(pivot) < 0 && i != mid)
			count++;
	}
	// Giving pivot element its correct position
	int pivotIndex = low + count;
	swap(t_classList[pivotIndex].aCourse.m_Class, t_classList[mid].aCourse.m_Class);

	// Execute loop while condition true
	while (low < pivotIndex && high > pivotIndex) {

		// Compare current element to middle element
		while (t_classList[low].aCourse.m_Class.compare(pivot) < 0) {
			low++;
		}
		// Compare element to middle element
		while (t_classList[high].aCourse.m_Class.compare(pivot) >= 0) {
			high--;
		}
		// Swap elements when condition is true
		if (low < pivotIndex && high > pivotIndex) {
			swap(t_classList[low].aCourse.m_Class, t_classList[high].aCourse.m_Class);
			low++;
			high--;
		}
	}
	return pivotIndex;
}

// Function to partition class list vector with return type void
void ExecuteProgram::quickSortClassList(vector <ExecuteProgram>& t_classList, int t_begin, int t_end) {

	// Base Case
	if (t_begin >= t_end) {
		return;
	}
	// Parititioning the array
	int mid = partitionClassList(classList, t_begin, t_end);

	// Sorting the left part
	quickSortClassList(t_classList, t_begin, mid - 1);

	// Sorting the right part
	quickSortClassList(t_classList, mid + 1, t_end);
}

// Function to sort partitioned prerequisite vector with return type int
int ExecuteProgram::partitionPrerequisites(Node* t_curr, int begin, int end) {
	/* Partition the vector of prerequisites into two parts, low and high */

	// Initialize local variables
	int low = begin;
	int high = end;
	int mid = (low + high) / 2;
	string pivot = t_curr->curriculum.m_requirements[mid];
	int count = 0;

	// Count how many elements less than the current pivot
	for (int i = low; i <= high; i++) {
		if (t_curr->curriculum.m_requirements[i].compare(pivot) < 0 && i != mid)
			count++;
	}
	// Giving pivot element its correct position
	int pivotIndex = low + count;
	swap(t_curr->curriculum.m_requirements[pivotIndex], t_curr->curriculum.m_requirements[mid]);

	// Execute loop while condition true
	while (low < pivotIndex && high > pivotIndex) {

		// Compare current element to middle element
		while (t_curr->curriculum.m_requirements[low].compare(pivot) < 0) {
			low++;
		}
		// Compare element to middle element
		while (t_curr->curriculum.m_requirements[high].compare(pivot) >= 0) {
			high--;
		}
		// Swap elements when condition is true
		if (low < pivotIndex && high > pivotIndex) {
			swap(t_curr->curriculum.m_requirements[low], t_curr->curriculum.m_requirements[high]);
			low++;
			high--;
		}
	}
	return pivotIndex;
}

// Function to partition prerequisite vector with return type void
void ExecuteProgram::quickSortPrerequisites(Node* t_curr, int t_begin, int t_end) {

	// Base Case
	if (t_begin >= t_end) {
		return;
	}
	// Parititioning the array
	int mid = partitionPrerequisites(t_curr, t_begin, t_end);

	// Sorting the left part
	quickSortPrerequisites(t_curr, t_begin, mid - 1);

	// Sorting the right part
	quickSortPrerequisites(t_curr, mid + 1, t_end);
}

// Function to read file from user input with return type void
void ExecuteProgram::readFile(string t_File) {
	// Declare Local variables
	ExecuteProgram t;
	string line;
	string line2;

	// Initialize local variables
	ifstream file{ t_File };
	regex delimiter(",");
	
	// Check if files is open
	if (file.is_open()) {

		// Loop until the end of the file
		while (getline(file, line)) {
			vector <string> token(sregex_token_iterator(line.begin(), line.end(), delimiter, -1), {});

			// Create object to store class
			ExecuteProgram t(token.at(0));

			// Push object into vector
			classList.push_back(t);
		}

		// Call quick sort
		quickSortClassList(classList, 0, classList.size() - 1);

		// Close file
		file.close();
	}
	else {
		// Output to user when file cannot be opened
		cout << "Cannot open file" << endl;
		return;
	}
	// Open file
	ifstream file1{ t_File };

	if (file1.is_open()) {

		// Loop until the end of the file
		while (getline(file1, line2)) {
			Node* newNode = new Node();
			vector <string> token1(sregex_token_iterator(line2.begin(), line2.end(), delimiter, -1), {});

			// Check for 2 or more elements in vector
			if (token1.size() > 1) {

				// Store course, course ID, and validate prerequisites before adding to node
				newNode->curriculum.m_ID = token1.at(0);
				newNode->curriculum.m_Course = token1.at(1);
				for (int i = 2; i < token1.size(); ++i) {
					if (validateClass(classList, token1.at(i))) {
						newNode->curriculum.m_requirements.push_back(token1.at(i));
					}
				}

				// Sort prerequisites
				quickSortPrerequisites(newNode, 0, newNode->curriculum.m_requirements.size() - 1);
				
				// Call function to insert node into data structure
				insertNode(root, newNode);
			}
			else {
				// Output when line contains less than two elements
				cout << "Invalid line" << endl;
			}
		}
		file1.close();
	}
	else{
		// Output when file cannot be opened
		cout << "Cannot open file" << endl;
	}
}

string ExecuteProgram::stringToUpper(string input) {
	// Function to captitalize the first four letter of user input
	for (int i = 0; i < 4; ++i) {
		input[i] = toupper(input[i]);
	}
	return input;
}

Node* ExecuteProgram::insertNode(Node*& root, Node* newNode) {
	// Function to insert Node into data structure
	if (root == nullptr) {                                           // Check if current node is null pointer
		root = newNode;                                              // Assign current node when true
		return root;                                                 // Return node
	}
	else {
		if (newNode->curriculum.m_ID < root->curriculum.m_ID) {      // Check if new node less than current node
			root->left = insertNode(root->left, newNode);            // Recurse down left side of tree
		}
		else if (newNode->curriculum.m_ID > root->curriculum.m_ID) { // Check if new node greater than current node
			root->right = insertNode(root->right, newNode);          // Recurese down right side of tree
		}
		else {
			cout << "No duplicates allowed" << endl;                 // Output when duplicate found
			return root;                                             // Return node
		}
	}
	return root;                                                     // Return node
}
void ExecuteProgram::inOrderPrint(Node* root) {
	// Function to in order print courses
	if (root == nullptr) {
		return;
	}
	else {
		// Recurse down left side
		inOrderPrint(root->left);

		// Print course course ID and course
		cout << "\n" << root->curriculum.m_ID << ", " << root->curriculum.m_Course << endl;

		// Check if there are any prerequisites
		if (root->curriculum.m_requirements.empty()) {
			cout << "Prerequisites: None" << endl;
		}
		else{
			cout << "Prerequisites: ";

			// Loop through vector print prerequisites
			for (int i = 0; i < root->curriculum.m_requirements.size(); ++i) {
				if (i < root->curriculum.m_requirements.size() - 1) {
					cout << root->curriculum.m_requirements.at(i) << ", ";
				}
				else {
					cout << root->curriculum.m_requirements.at(i);
				}
			}
			cout << endl;
		}
		// Recurse down right side
		inOrderPrint(root->right);
	}
}
string ExecuteProgram::CheckClass() {
	// Function to validate class from user input
	
	// Declare or Initialize local variables
	string cls;
	regex test("[a-zA-Z0-9]+");

	// Loop while true
	while (true) {
		system("cls");                                                  // Clear console window
		cout << "\nEnter class:\n" << endl;                             // Output to user
		cin >> setw(7) >> cls;                                          // Assign variable to first 7 characters acquired
		cin.clear();                                                    // Clear input stream
		cin.ignore(INT_MAX, '\n');                                      // Ignore the rest
		if (regex_match(cls, test)) {                                   // Check for a match
			cls = stringToUpper(cls);                                   // Reassign variable 
			break;
		}
		else {
			system("color 46");
			cout << "\nYou have entered an invalid class." << endl;     // Output for invalid input
			cout << "\nPlease enter a valid class" << endl;
			system("pause");
			system("color 1C");
		}
	}
	return cls;                                                         // Return variable to function call
}
void ExecuteProgram::PrintClass(Curriculum& t_curr) {
	// Function to print course information

	// Check if node is empty
	if (!t_curr.m_ID.empty()) {

		// Output course and course ID to user
		cout << "\n" << t_curr.m_ID << ", " << t_curr.m_Course << endl;

		// Check for any prerequisites
		if (!t_curr.m_requirements.empty()) {
			cout << "Prerequisites: ";

			// Iterate through vector to print prerequisites
			for (int i = 0; i < t_curr.m_requirements.size(); ++i) {
				
				// Output formatting
				if (i < t_curr.m_requirements.size() - 1) {
					cout << t_curr.m_requirements.at(i) << ", ";
				}
				else {
					cout << t_curr.m_requirements.at(i);
				}
			}
			cout << "\n" << endl;
		}
		else {
			// Output when there are not any prerequisites
			cout << "Prerequisites: NONE\n" << endl;
		}
	}
	else {
		// Output when course could not be found
		cout << "\nCourse could not be found\n" << endl;
	}
}

Curriculum ExecuteProgram::search(string t_courseID) {
	// Function to search data structure for match

	// Initialize local varaibles
	Curriculum curriculum;
	Node* temp;

	if (root == nullptr) {                                     // Check is the root node is null pointer
		return curriculum;                                     // Return empty node
	}
	else {
		temp = root;                                           // Assign temp variable to root
		while (temp != nullptr) {
			if (temp->curriculum.m_ID == t_courseID) {         // Check for a match
				curriculum = temp->curriculum;                 // Return match
				break;
			}
			else if (t_courseID < temp->curriculum.m_ID) {     // Check if match is less than current node
				temp = temp->left;                             // Move to the left subtree
			}
			else {
				temp = temp->right;                            // Move to the right subtree
			}
		}
	}
	return curriculum;                                         // Return match
}

void ExecuteProgram::runProgram() {
	// Function to run ABCU application

	// Declare local variables
	auto rp = make_shared <ExecuteProgram>();
	Curriculum curr;
	int selection;

	while (true) {
		system("color 1C");                                    // Change the console color
		selection = checkNum();                                // Function call to retrieve user selection

		switch (selection) {                                   // Execution based on selection
		case 1:
			system("cls");                                     // Clear console window
			rp->readFile(rp->CheckFile());                     // Function call to check file input and read file
			system("pause");                                   // Pause application
			system("cls");                                     // Clear console window
			break;
		case 2:
			system("cls");                                     // Clear console window
			cout << "\nHere is a sample schedule:\n" << endl;  // Output to user
			rp->inOrderPrint(rp->root);                        // Print out courses in alphnumeric order
			cout << "" << endl;
			system("pause");                                   // Pause application 
			system("cls");                                     // Clear console window
			break;
		case 3:
			system("cls");
			curr = rp->search(rp->CheckClass());               // Assign variable to return value from function calls
			rp->PrintClass(curr);                              // Output course data to user
			system("pause");                                   // Pause application 
			system("cls");                                     // Clear console window
			break;
		case 9:
			system("cls");
			cout << "\nYou have chose to exit" << endl;                   // Output to user
			cout << "\nThank you for using the course planner\n" << endl; // Output to user
			exit(0);                                                      // End application
		}
	}
}