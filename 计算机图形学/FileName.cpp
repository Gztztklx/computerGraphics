#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
//#pragma comment(lib, "glfw3.lib")
using namespace std;
void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
	glfwInit();
	// �����汾�����
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // ���汾��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // �ΰ汾��
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// �����˽⵽��ǰʹ�õİ汾
	int Major, Minor, Rev;
	glfwGetVersion(&Major, &Minor, &Rev);
	cout << "GLFW " << Major << ", " << Minor << ", " << Rev << "initialized\n";

	/*
	��һ�������ǿ��ڶ��������Ǹߣ������������Ǳ��⣬�������������ʱ����
	����һ��GLFWwindow����
	*/
	GLFWwindow* window = glfwCreateWindow(800, 600, "window", NULL, NULL);
	if (window == NULL) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	/*
	��ʼ��GLAD����GLAD������������ϵͳ��ص�OpenGL����ָ���ַ�ĺ���
	GLFW�����ǵ���glfwGetProAddress,���������Ǳ����ϵͳ��������ȷ�ĺ���
	*/
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	/*
	// ��Ⱦ
	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	*/
	
	// ��Ⱦѭ��
	while (!glfwWindowShouldClose(window)) {
		// ����
		processInput(window);
		glClearColor(0.0f, 0.34f, 0.57f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// ��Ⱦָ��
		// ������
		// ��鲢�����¼�����������
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	// �ͷ���Դ
	glfwTerminate();
		
	
	return 0;
}

/*
֡�����С������Ҫһ��GLFWwindow��Ϊ���ĵ�һ���������Լ�����������ʾ�´��ڵ���ά�ȣ�ÿ�����ڸı��С��GLFW��������������������Ӧ�Ĳ������㴦��
*/
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	/*
	ǰ�����������ƴ������½ǵ�λ�ã��������͵��ĸ�������Ⱦ���ڵĿ�Ⱥ͸߶�
	*/
	glViewport(0, 0, 800, 600);
}

/*
��Ӧ���������¼�
*/
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}