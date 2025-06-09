#include <iostream>
#include <cstddef>
#include "head.hpp"

String::String() : size_(0), data_(nullptr){}

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

String::String(const String& other){
	size_ = other.size_;
	data_ = new char[size_+1];
	for(int i = 0; i < size_+1; ++i){
		data_[i] = other.data_[i];
	}
}

String::String(String && other){
	size_ = other.size_;
	data_ = other.data_;
	other.data_ = nullptr;
}

String& String::operator= (String&& other){
	if(this == &other){
		return *this;
	}
	delete[] data_;
	size_ = other.size_;
	data_ = other.data_;
	other.data_ = nullptr;
	return *this;
}

String& String::operator= (const String& other){
	if(this == &other){
		return *this;
	}
	size_ = other.size_;
	data_ = new char[size_+1];
	for(int i = 0; i < size_+1; ++i){
		data_[i] = other.data_[i];
	}
	return *this;
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
