#include <iostream>
#include <GLFW/glfw3.h>

class Vec3f {
public:
	float x, y, z;
};

class MyClass
{
public:
	MyClass();
	~MyClass();

private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int main() {
	std::cout << "Hello my program.";
	GLFWwindow *window = nullptr;
	if (!glfwInit()) {
		glfwTerminate();
		return -1;
	}
	window = glfwCreateWindow(640, 480, "My Game", nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	float t1 = 0.0f;
	float t2 = 0.0f;
	float t3 = 0.0f;
	float t4 = 0.0f;
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		t1 += 0.01f;
		t2 += 0.02f;
		t3 += 0.03f;
		t4 += 0.04f;
		glPushMatrix();
			glRotatef(t1, 0, 0, 1);
			glBegin(GL_TRIANGLES);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0f, 0.8f, 0.0f);
				glVertex3f(0.8f, 1.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 0.0f);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glRotatef(t2, 0, 0, 1);
			glBegin(GL_TRIANGLES);
				glColor3f(0.0f, 1.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(-0.6f, -0.8f, 0.0f);
				glVertex3f(-0.8f, -0.6f, 0.0f);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glRotatef(t3, 0, 0, 1);
			glBegin(GL_TRIANGLES);
				glColor3f(0.0f, 0.0f, 1.0f);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(-0.4f, 0.6f, 0.0f);
				glVertex3f(-0.6f, 0.4f, 0.0f);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glRotatef(t4, 0, 0, 1);
			glBegin(GL_TRIANGLES);
				glColor3f(0.5f, 0.5f, 0.5f);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(0.2f, -0.4f, 0.0f);
				glVertex3f(0.4f, -0.2f, 0.0f);
			glEnd();
		glPopMatrix();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	getchar();
	return 0;
}