
/**
*
* Author: Devin Hunter
* H6 Inc. Project
* Made with Open Graphics Library: A software interface to graphics hardware. OpenGL consists of over 250 different function calls which can be used to draw complex two and three-dimensional scenes.
*
*/

#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string> // Including this header file from the C++ standard library enables me to use the getline() function.
#include <vector>

using namespace std;


class Coordinates {
private:
	string x, y;
};


class CsvReader {
public:
	void readFile();

private:
	string line;
	GLfloat tempFloat;
	//void storeCoordinates(Coordinates myCoordinates, vector<GLfloat> myVect);
	vector<string> tempStringStorage;
	vector<GLfloat> tempFloatStorage;
	vector<Coordinates> csvCoordinates;
};

