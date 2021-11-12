//Author: Pankaj Yadav
#include <iostream>
#include <string.h>
using namespace std;
class String{
	char *name;
public:
	String() : name(nullptr) {} 	//default constructor will hold nullptr
	String(const char *sp)
	{
		name = new char[strlen(sp) + 1];
		strcpy(name,sp);
	}	
	String(const String &sp)
	{ 
		name = new char[strlen(sp.name) + 1];	// mem allocation using new 	
		strcpy(name,sp.name);
	}
	~String()	//destructor..... to free the block assigned thru parameterised constructor
	{
		delete name;
	}	
	char* read()				//accessor for string class
	{
		return name;
	}
	void write(const char *sp)		// mutator for string class
	{
		name = new char[strlen(sp) + 1];
		strcpy(name, sp);
	}
};

int main()
{
	String s("Bjarne Stroustrup is the creator of C++");
	cout << "Using parameterised constructor for String s \n\t\t" << s.read() <<endl;
	//   double free can't do this s1=s;	//	re=initialization can't do this s1(s)	
	String s1(s);
	cout << "copy constructor is used for s1 \n\t\t" << s1.read() <<endl;
	char str[]="Hello, Welcome to the post match presentation party for today's match played between India and Pakistan";
	//str is string I wish to write in String class object
	String s2;
	s2.write(str);		//writing to the s2 using String write funtion
	cout << "Wrote const char string pool to String s2 and now s2 is :  \n\t" << s2.read() <<endl;
	char str1[20];
	return 0;
}




