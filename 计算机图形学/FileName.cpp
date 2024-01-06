#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
//#pragma comment(lib, "glfw3.lib")
using namespace std;
void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
	glfwInit();
	// 声明版本与核心
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // 主版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // 次版本号
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// 可以了解到当前使用的版本
	int Major, Minor, Rev;
	glfwGetVersion(&Major, &Minor, &Rev);
	cout << "GLFW " << Major << ", " << Minor << ", " << Rev << "initialized\n";

	/*
	第一个参数是宽，第二个参数是高，第三个参数是标题，最后两个可以暂时忽略
	返回一个GLFWwindow对象
	*/
	GLFWwindow* window = glfwCreateWindow(800, 600, "window", NULL, NULL);
	if (window == NULL) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	/*
	初始化GLAD，给GLAD传入用来加载系统相关的OpenGL函数指针地址的函数
	GLFW给我们的是glfwGetProAddress,它根据我们编译的系统定义了正确的函数
	*/
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	/*
	// 渲染
	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	*/
	
	// 渲染循环
	while (!glfwWindowShouldClose(window)) {
		// 输入
		processInput(window);
		glClearColor(0.0f, 0.34f, 0.57f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// 渲染指令
		// 。。。
		// 检查并调用事件，交换缓冲
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	// 释放资源
	glfwTerminate();
		
	
	return 0;
}

/*
帧缓冲大小函数需要一个GLFWwindow作为他的第一个参数，以及两个整数表示新窗口的新维度，每当窗口改变大小，GLFW会调用这个函数并填入相应的参数供你处理
*/
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	/*
	前两个参数控制窗口左下角的位置，第三个和第四个控制渲染窗口的宽度和高度
	*/
	glViewport(0, 0, 800, 600);
}

/*
相应键盘输入事件
*/
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}