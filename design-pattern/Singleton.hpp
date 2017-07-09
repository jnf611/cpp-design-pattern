#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <string>

/**
 * @brief Singleton
 * Self implementation: with many drawbacks
 */
class Singleton
{
public:
	static Singleton& Instance();
	std::string to_string();
	void clear();

protected:
	Singleton();
	virtual ~Singleton();

private:
	static Singleton* m_instance;
	int m_id;
};

class DerivedSingleton : public Singleton
{
public:
	DerivedSingleton();
	std::string to_string();

public:
	int m_value;
};

class Meyers
{
public:
	static Meyers& Instance();
};

#endif // SINGLETON_HPP
