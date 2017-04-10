/*
	ca-hello-file.cpp
	Write "Hello, world!" to a file
*/

#include <fstream>

int main()
{
	std::ofstream fileStream;
	fileStream.open("hello.txt", std::ios::out | std::ios::app);
	fileStream << "Hello, world!" << std::endl;
	fileStream.close();
	return 0;
}