#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
	string name;
public:    
	Person(const string& name) : name(name) {}
	virtual void who()
	{
		cout << "My name is " << name << "\tI'm - Person " << endl;
	}
};

class Engineer : public Person
{
public:
	Engineer(const string& name) : Person(name) {}
	void who() override
	{
		cout << "My name is " << name << "\tI'm - Engineer" << endl;
	}
};

class Worker : public Person
{
public:
	Worker(const string& name) : Person(name) {}
	void who() override
	{
		cout << "My name is " << name << "\tI'm - Worker" << endl;
	}
};

class Manager : public Person
{
public:
	Manager(const string& name) : Person(name) {}
	void who() override
	{
		cout << "My name is " << name << "\tI'm - Manager" << endl;
	}
};

class TopManager : public Person
{
public:
	TopManager(const string& name) : Person(name) {}
	void who() override
	{
		cout << "My name is " << name << "\tI'm - Top manager" << endl;
	}
};

class Plumber : public Person
{
public:
	Plumber(const string& name) : Person(name) {}
	void who() override
	{
		cout << "My name is " << name << "\tI'm - Plumber" << endl;
	}
};

int main()
{
	Person person{"Yurij"};
	person.who();

	Plumber plumber{"Uladzimir"};
	plumber.who();

	Engineer engineer{"Nikita"};
	engineer.who();

	Worker worker{"Andrey"};
	worker.who();

	Manager manager{"Mikita"};
	manager.who();

	TopManager topmanager{"Mikhail"};
	topmanager.who();
}