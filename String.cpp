#include <iostream>
#include <cstddef>
#include "head.hpp"

String::String() : size_(0){}
String::String(const char* str){
	const char* tmp = str;
	while(*tmp){
		++size_;
		++tmp;
	}
	data_ = new char[size_+1];
	for(size_t i = 0; i < size_; ++i){
		data_[i] = str[i];
	}
	data_[size_] = '\0';
}

String::~String(){
	size_ = 0;
	delete[]  data_;
}

size_t String::Length() const{
	return size_;
}

const char* String::C_string() const {
	return data_;
}

void String::print() const{
	std::cout << data_ << std::endl;
}
