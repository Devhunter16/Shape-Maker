
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
#include <vector>

using namespace std;

class Program {
public:
	void runProgram();

private:
	int menuSelection, numVertices = 0;
	GLfloat xValue, yValue;
	bool CompileStatus(GLuint shader);
	vector<GLfloat> shapeVertices;
	void mainMenu();
	void runOpenGL(vector<GLfloat> myVertices, int numVerts);
};