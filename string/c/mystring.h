#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include <iostream>

typedef class String
{
	char* _str;
	size_t _size;
public:
	String();
	String(const char* ch);
	String(const String& ob);
	String& operator=(const String& ob);
	String& operator+=(const String& ob);
	char& operator[](int index);
	friend String& operator+(const String& ob1, const String& ob2);
	friend std::ostream& operator<<(std::ostream&, const String& ob);
	int length() const;
	~String();
}mystring;



#endif // !__MYSTRING_H__