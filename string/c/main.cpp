#include <iostream>
#include "mystring.h"

using namespace std;


int main()
{

	mystring s1;
	s1 = "vivek";

	mystring s2 = s1;
	mystring s3("yadav");

	mystring s4 = s2 + " " + s3;
	s2[4] = 'l';

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	return 0;
}