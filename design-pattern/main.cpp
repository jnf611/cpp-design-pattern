#include <iostream>
#include "Singleton.hpp"

using namespace std;

static void test_singleton()
{
	// Self tried implementation
	cout << "Self tried implementation:" << endl;

	cout << "Singleton::Instance():" << endl;
	Singleton::Instance();
	cout << "Reference to singleton:" << endl;
	Singleton& rs = Singleton::Instance();
	cout << (void*)&Singleton::Instance() << endl;
	cout << (void*)&rs << endl;


	cout << "Trying to create a derived singleton:" << endl;
	cout << DerivedSingleton::Instance().to_string() << endl;
	cout << "Inheritance has failed as new is called in Singleton constructor" << endl;
	cout << "A solution could be to create a public virtual init function that"
			" performs the new, instead of the Instance() but this also adds an api" << endl;

	cout << "Destructor is not called automatically, it should be done manually:" << endl
		<< "this requires adding an api that should be called the right place" << endl;
	rs.clear();

	// Meyer implementation
	cout << endl << endl;
	cout << "Meyer's singleton implementation:" << endl;
	cout << (void*)&Meyers::Instance() << endl;
	cout << "Reference to Meyers implementation" << endl;
	Meyers& rm = Meyers::Instance();
	cout << (void*)&rm << endl;
}

int main()
{
	test_singleton();

	return 0;
}

