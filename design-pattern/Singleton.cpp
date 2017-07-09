#include "Singleton.hpp"
#include <iostream>

using namespace std;

Singleton* Singleton::m_instance = NULL;

Singleton::Singleton() :
	m_id(1)
{
	cout << "Singleton::" << __func__ << ": constructor" << endl;
}

Singleton::~Singleton()
{
	cout << "Singleton::" << __func__ << ": destrutor required manual call from added api" << endl;
}

void Singleton::clear()
{
	cout << "Singleton::" << __func__ << ": called manually" << endl;
	delete m_instance;
}

Singleton& Singleton::Instance()
{
	if (!m_instance)
	{
		cout << "Singleton::" << __func__ << ": first time: creating" << endl;
		m_instance = new Singleton();
	}
	else
	{
		cout << "Singleton::" << __func__ << ": already created" << endl;
	}
	return *m_instance;
}

string Singleton::to_string()
{
	return "id:" + std::to_string(m_id);
}

DerivedSingleton::DerivedSingleton() :
	m_value(10)
{
}

string DerivedSingleton::to_string()
{
	string s = std::to_string(m_value) + ", " + Singleton::to_string();
	return s;
}


Meyers& Meyers::Instance()
{
	static Meyers instance;
	return instance;
}
