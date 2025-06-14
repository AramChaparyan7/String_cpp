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

String String::operator+ (const String& rhs){
	String tmp;
	tmp.size_ = rhs.size_ + this->size_;
	tmp.data_ = new char[tmp.size_ + 1];
	for(int i = 0; i < this->size_; ++i){
		tmp[i] = this->data_[i];
	}
	for(int i = 0; i < rhs.size_; ++i){
		tmp[this->size_ + i] = rhs[i];
	}
    tmp[tmp.size_] = '\0';	
	return tmp;
}

String String::operator+ (const char* rhs){
	return *this + String(rhs);
}

String operator+ (const char* lhs, const String& rhs){
	return String(lhs) + rhs;
}

std::ostream& operator<< (std::ostream& os, const String& str){
	os << str.data_;
	return os;
}

std::istream& operator>> (std::istream& is, String& str){
	is >> str.data_;
	return is;
}

char& String::operator[] (size_t index){
	return data_[index];
}

const char& String::operator[] (size_t index) const{
	return data_[index];
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
