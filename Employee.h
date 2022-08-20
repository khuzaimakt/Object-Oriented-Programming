#include <iostream>
#include <string>
#include"address.h"


using namespace std;
class Project;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Employee
{
	string emp_name;
	Project* Pro1;
	Project* Pro2;

	Address Add;
	int projectcount;
	
	//add data address object
	//Add data members here to keep employees projects info

public:
	Employee(string, const Address& Add);
	//overloaded constructor
	Employee(const Employee&);
	//copy constructor
	friend ostream& operator<<(ostream& osObject, const Employee&);
	//overloaded insertion operator
	const Employee& operator=(const Employee& other);
	void addProject(Project* P);
	void removeProject(Project* P);
	bool operator==(const Employee&);
	string getname();
	

	//overloaded assignment operator
	// specify inputs and return types
	
	
	~Employee();

};
#endif

