
/**
*
* Author: Devin Hunter
* H6 Inc. Project
* Made with Open Graphics Library: A software interface to graphics hardware. OpenGL consists of over 250 different function calls which can be used to draw complex two and three-dimensional scenes.
*
*/

#include "program.h";
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

using namespace std;

void Program::runProgram() { // Runs the program.
	mainMenu();
	//runOpenGL();
}

void Program::mainMenu() {

	cout << endl;
	cout << "Welcome to the main menu." << endl;
	cout << endl;

	cout << "1. Create shape" << endl;
	cout << "2. Pull data from CSV file" << endl;
	cout << "3. View current shape" << endl;
	cout << "4. Erase current shape" << endl;
	cout << "5. Quit program" << endl;
	cout << endl;
	cout << "Please select an option: ";
	cin >> menuSelection;
	cout << endl;

	if (menuSelection == 1) {
		menuSelection = 0;
		cout << "Would you like to create a shape with pre-defined vertices or create your own shape?" << endl;
		cout << endl;

		cout << "1. Choose a pre-defined shape" << endl;
		cout << "2. Create my own shape" << endl;
		cout << endl;
		cout << "Please select an option: ";
		cin >> menuSelection;
		cout << endl;

		if (menuSelection == 1) {                                                 
			menuSelection = 0;
			cout << "Please choose a pre-defined shape" << endl;
			cout << endl;

			cout << "1. Single line" << endl;
			cout << "2. Triangle" << endl;
			cout << "3. Square" << endl;
			cout << "4. Pentagon" << endl;
			cout << "5. Hexagon" << endl;

			cout << endl;
			cout << "Please select an option: ";
			cin >> menuSelection;
			cout << endl;

			if (menuSelection == 1) {    //FIXME - have this produce different shapes   
				numVertices = 2;
			
				GLfloat xFloat1 = -0.5;
				shapeVertices.push_back(xFloat1);
				GLfloat yFloat1 = -0.5;
				shapeVertices.push_back(yFloat1);
				GLfloat xFloat2 = 0.5;
				shapeVertices.push_back(xFloat2);
				GLfloat yFloat2 = 0.5;
				shapeVertices.push_back(yFloat2);		

				cout << "You've created a single line" << endl;
				cout << endl;

				runOpenGL(shapeVertices, numVertices);
			}
			else if (menuSelection == 2) {
				numVertices = 3;
				cout << "You've created a triangle" << endl;
				cout << endl;
			}
			else if (menuSelection == 3) {
				numVertices = 4;
				cout << "You've created a square" << endl;
				cout << endl;
			}
			else if (menuSelection == 4) {
				numVertices = 5;
				cout << "You've created a pentagon" << endl;
				cout << endl;
			}
			else if (menuSelection == 5) {
				numVertices = 6;
				cout << "You've created a hexagon" << endl;
				cout << endl;
			}
			else {
				cout << "Please enter a valid option." << endl;
				mainMenu();
			}

		}                                                 
		else if (menuSelection == 2) {                                                         //FIXME - have this produce shapes based on user input
			cout << "How many vertices would you like your shape to have: ";
			cin >> numVertices;
			cout << endl;
			cout << "All vertices must be within the range of -1.0 to 1.0. All vertices must be in the following format: -#.# or #.#" << endl;
			cout << endl;
			for (int i = 0; i < numVertices; i++) {
				cout << "Please enter your x value: ";
				cin >> xValue;
				cout << "Please enter you y value: ";
				cin >> yValue;
				cout << endl;
				cout << "Your vertex is: (" << xValue << ", " << yValue << ")" << endl;
				cout << endl;
			}
			cout << "Creating a shape with " << numVertices << " vertices." << endl;
			cout << endl;
			//runOpenGL();
		}
		else {
			cout << "Please enter a valid option." << endl;
			mainMenu();
		}
	}
	else if (menuSelection == 2) {
		// FIXME implement viewing of current shape.
		cout << "This path has not been implemented yet. Please select another option";
		cout << endl;
		mainMenu();
	}
	else if (menuSelection == 3) {
		// FIXME implement erasure of shape.
		cout << "This path has not been implemented yet. Please select another option";
		cout << endl;
		mainMenu();
	}
	else if (menuSelection == 4) {
		// FIXME implement viewing of current shape.
		cout << "This path has not been implemented yet. Please select another option";
		cout << endl;
		mainMenu();
	}
	else if (menuSelection == 5) {
		cout << "You have exit the menu." << endl;
		cout << endl;
	}
	else {
		cout << "Please enter a valid option." << endl;
		mainMenu();
	}
}

bool Program::CompileStatus(GLuint shader) // I use this function within runOpenGL() to check for compile errors.
{
	GLint status = GL_TRUE;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint logLen;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);
		vector < char > log(logLen);
		GLsizei written;
		(shader, logLen, &written, log.data());
		cout << "compile error:" << endl << log.data() << endl;
	}
	return status != GL_FALSE;
}

void Program::runOpenGL(vector<GLfloat> myVertices, int numVerts) {

	const char* vertexShaderSource = "#version 330 core\n" // Source code for the vertex shader written in OpenGL Shading Language.
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	const char* fragmentShaderSource = "#version 330 core\n" // Source code for the fragment shader written in OpenGL Shading Language.
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"    FragColor = vec4(0.8f, 0.3f, 0.2f, 1.0f);\n"
		"}\n\0";


	glfwInit(); // glfw is an OpelGL library. We need to use it's functions for this project. Here I am initializing it so that I can use it's functions in my program.

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // glfw does not know which version of OpenGL we are using, so we have to tell it here.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // An OpenGL profile is a package of functions. Here I am telling glfw I want to use the core package which contains all modern OpenGL functions.

		GLfloat vertices[] = // This is an array of the coordinates for the vertices. OpenGL uses it's own type of float called "GLfloat". In OpenGL everything is in a 3D space and if we want a 2D shape, we must transnform all 3D coordinates to 2D pixels. OpenGL only
							 // processes 3D coordinates if they're in a specific range between -1.0 and 1.0. All coordinates within this range will show up visible on the screen and all cooridinates outside this range will not. Each vertice has coordinates x, y, and z.
							 // Notice that the z parameter for each coordinate below is 0.0f. This way the depth of the shape remains the same making it look like it is 2D rather than 3D. 
		{
			myVertices.at(0), myVertices.at(1), 0.0,
			myVertices.at(2), myVertices.at(3), 0.0

			//-0.5f, -0.5f, 0.0f,
			//0.5f, 0.5f, 0.0f

			// Below is some commented out code which made up the the vertices for a triangle
			//-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
			//0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
			//0.0f, 0.5f * float(sqrt(3)) / 3, 0.0f

			//-0.4f, -0.5f, 0.0f,
			//0.4f, -0.5f, 0.0f,
			//0.6f, 0.1f, 0.0f,
			//0.0f, 0.6f, 0.0f,
			//-0.6f, 0.1f, 0.0f
		};


	GLFWwindow* window = glfwCreateWindow(800, 800, "H6-Project", NULL, NULL); // Here I name my window "window" and use the create-a-window function: glfwCreateWindow(width, height, name of window, whether we want it full screen or not, unimportant parameter)

	if (window == NULL) // This "if" statement produces an error and terminates glfw if the window fails to open.
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		//return -1;
	}

	glfwMakeContextCurrent(window); // glfw is really dumb, so here I have to tell it that since I've created the window, I'd also like to use it. 

	gladLoadGL(); // Here we load GLAD so it configures OpenGL.

	glViewport(0, 0, 800, 800); // This sets the viewport: glViewport(x, y, width, height) x and y specify the lower left hand corner of the viewport rectangle, in pixels. The inital value is (0, 0).
								// width and height specify the width and height of the viewport. When a GL context is first attached to a window, width and height are set to the dimensions of that window.

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); // GLuint is the OpenGl version of an unsigned integer (aka a positive integer). In order for OpenGL to use the vertex shader it has to dynamically compile it at run-time from the source code. This is because
															// the GPU does not understand the source code, so we have to compile it into machine code. Same goes for the fragment shader. Here we are compiling the shaders. For more info (learnopengl/Getting-started/Hello-Triangle).

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	CompileStatus(vertexShader);


	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);


	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	CompileStatus(vertexShader);

	GLuint shaderProgram = glCreateProgram();  // In order to use our shaders, we need to wrap them up into something called a shader program.
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	GLuint VAO, VBO; // Sending info from the CPU to the GPU is slow, so we send it in big packages called buffers. VBO = Vertex Buffer Object. We're creating this object to store our vertex data. 

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO); // Here we are generating 1 buffer object and pointing it to the VBO reference.

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO); // Binding in OpenGL is when we make a certain object the current object so that when you modify that type of object, it modifies the current object. Here we are using GL_ARRAY_BUFFER because that is the type we need to use
										// for the vertex buffer due to the vertex buffer being an array of vertices. There are lots of other types of buffers you can use.
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Here we are actually storing our vertices in the VBO. GL_ARRAY_BUFFER is the type of buffer, sizeof(vertices) is the size of the data, vertices specifies the use of the data,
																			   // GL_STATIC means that the vertices will be modified once and used many times and _DRAW means that the vertices will be modified and used to draw an image on the screen.
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // This specifies the color values of the background: glClearColor(red, green, blue, alpha). alpha is the transparency of the color, 1 is opaque, 0 is completely transparent.
	glClear(GL_COLOR_BUFFER_BIT); // This cleans the back buffer and assigns the new color to it.
	glfwSwapBuffers(window); // This swaps the back buffer with the front buffer.

	while (!glfwWindowShouldClose(window)) // This while loop only ends if the window closes.
	{
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		//glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_LINE_LOOP, 0, numVertices); // glDrawArrays(type of primitive to use, starting index of the vertices, amount of vertices we want to draw); <-- change the third parameter to create shapes with different amounts of vertices
		glfwSwapBuffers(window);

		glfwPollEvents(); // Once again, glfw is dumb, so here we have to tell it to process events such as resizing, window closing, etc. or it'll be unresponsive.
	}

	glDeleteVertexArrays(1, &VAO); // Here we're deleting what we don't need.
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	glfwDestroyWindow(window); // Here I am terminating the window because we're done with it.

	glfwTerminate(); // Here I am terminating glfw because we're done using it.

}