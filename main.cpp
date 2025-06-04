#include <iostream>
#include "head.hpp"

int main(){
	String c;
	const char* str = "Hello world";
	String s(str);
	std::cout << s.Length() << std::endl;
	const char* tmp = s.C_string();
	std::cout << tmp << std::endl;
	s.print();
	return 0;
}
