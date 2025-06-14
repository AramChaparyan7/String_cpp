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
	String(const String&);
	String(String &&);
	String& operator= (String&&);
	String& operator= (const String&);
	String operator+ (const String&);
	String operator+ (const char*);
	friend String operator+ (const char&, const String&);
	friend std::ostream& operator<< (std::ostream&, const String&);
	friend std::istream& operator>> (std::istream&, String&);
	char& operator[] (size_t index);
	const char& operator[] (size_t index) const;
	~String();
	size_t Length() const;
	const char* C_string() const;
	void print() const;
};

#endif
