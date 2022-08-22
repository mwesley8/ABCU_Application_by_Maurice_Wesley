//============================================================================
// Name        : ABCU BST Main cpp
// Author      : Maurice Wesley
// Version     : 5.0
// Copyright   : Copyright © 2022 SNHU COCE
// Description : The one and only main
//============================================================================

#include "ExecuteProgram.h"

using namespace std;

int main() {
	// Initialize pointer with object type ExecuteProgram
	auto start = make_shared<ExecuteProgram>();
	
	// Fuction to call to run application
	start->runProgram();

	return 0;
}