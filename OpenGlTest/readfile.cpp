
/**
*
* Author: Devin Hunter
* H6 Inc. Project
* Made with Open Graphics Library: A software interface to graphics hardware. OpenGL consists of over 250 different function calls which can be used to draw complex two and three-dimensional scenes.
*
*/

#include "readfile.h"
#include <iostream> // Including this header file from the C++ standard library declares a set of functions for standard input/output.
#include <fstream> // Including this header file from the C++ standard library grants my program the capabilities to create, write information to, and read information from files.

using namespace std;

void CsvReader::readFile() {
	ifstream csvFile;               // This is my input file stream.
	csvFile.open("pentagon.csv");
	if (!csvFile.is_open()) {
		cout << "Could not open the csv file." << endl;
	}

	while (csvFile.good()) {
		getline(csvFile, line, ',');   // Here I read each comma seperated value and store each in string "line".
		tempStringStorage.push_back(line);   // Here I store all values gathered from the csv file in a vector.
	}

	cout << tempStringStorage.at(2) << endl;

	for (int i = 0; i < tempStringStorage.size(); i++) {
		string token = tempStringStorage.at(i);
	}

	//for (int i = 0; i < tempStringStorage.size() / 2; i++) {
		//Coordinates newCoordinates;
		//storeCoordinates(newCoordinates, tempFloatStorage);
	//}

	csvFile.close();
}

//void CsvReader::storeCoordinates(Coordinates myCoordinates, vector<GLfloat> myVect) {
	//for (int i = 0; i < myVect.size(); i += 2) {
		//cout << myVect.begin()[i] << endl;
	//}
//}