#include "mystring.h"


/************************************** Constructors **************************************************/

String::String():_str(NULL), _size(0)	//default constructor
{

}

String::String(const char* ch)
{
	_size = strlen(ch) + 1;
	_str = new char[_size];
	strcpy_s(_str, _size, ch);
}

String::String(const String& ob)
{

	_size = ob._size;
	_str = new char[_size];
	memcpy(_str, ob._str, _size);
}



/************************************** Member Functions & Operators *******************************************/


String& String::operator+=(const String& ob)
{
	size_t _tempSize = ob._size + _size -1;
	char* _tempStr = new char[_tempSize];

	memcpy(_tempStr, _str, _size);
	memcpy(_tempStr + _size - 1, ob._str, ob._size);

	delete[] _str;

	_str = _tempStr;
	_size = _tempSize;

	return *this;
}

String& String::operator=(const String& ob)
{
	if (this != &ob)	//avoid self refrence
	{
		delete[] _str;

		_size = ob._size;
		_str = new char[_size];
		memcpy(_str, ob._str, _size);
	}
	return *this;
}

char& String::operator[](int index)
{
	if (index < 0 || index > _size - 1)
	{
		//throw exception here
	}

	return _str[index];
}


int String::length() const
{
	if (_size)
		return _size - 1;
	else
		_size;
}


String::~String()
{
	delete[] _str;
}


/************************************** Friend Functions ******************************************************/

String& operator+(const String& ob1, const String& ob2)
{
	size_t _tempSize = ob1._size + ob2._size - 1;
	char* _tempStr = new char[_tempSize];

	memcpy(_tempStr, ob1._str, ob1._size);
	memcpy(_tempStr + ob1._size - 1, ob2._str, ob2._size);


	String* _temp = new String(_tempStr);

	return *_temp;
}


std::ostream& operator<<(std::ostream& os, const String& ob)
{
	for (int i = 0; i < ob._size; ++i)
		os.put(ob._str[i]);
	return os;
}


