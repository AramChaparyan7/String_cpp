#ifndef STRING
#define STRING
#include <cstddef>

class String{
private:
	size_t size_;
	char* data_;
public:
	String();
	String(const char*);
	~String();
	size_t Length() const;
	const char* C_string() const;
	void print() const;
};

#endif
