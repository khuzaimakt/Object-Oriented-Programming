#include<iostream>
#include<string>

#include "Address.h"
#include "Project.h"
#include"Employee.h"
using namespace std;

Employee::Employee(string empname, const Address& Add):emp_name(empname),Add(Add)
{
	projectcount =0;
	Pro1 = nullptr;
	Pro2 = nullptr;
	
}

Employee::Employee(const Employee& Emp):Add(Emp.Add)
{
	Pro1 = Emp.Pro1;
	Pro2 = Emp.Pro2;
	
	this->projectcount = Emp.projectcount;
	this->emp_name = Emp.emp_name;
}

ostream& operator<<(ostream& osObject, const Employee& Emp)
{
	osObject << "Employee Name: " << Emp.emp_name << endl;
	osObject << "Employee Address: " << Emp.Add << endl;
	osObject << "Currently working On: ";
	cout << endl;
	if (Emp.Pro1 != nullptr)
	{
		osObject << *Emp.Pro1 << endl;
	}
	if (Emp.Pro2 != nullptr)
	{
		osObject << *Emp.Pro2 << endl << endl;
	}
	

	return osObject;
}

const Employee& Employee:: operator=(const Employee& other)
{
	emp_name = other.emp_name;
	Add = other.Add;
	projectcount = other.projectcount; 
	Pro1 = other.Pro1;
	Pro2 = other.Pro2;
	 
	return *this;
}


void Employee::addProject(Project *Proj)
{
	if (projectcount ==2)
	{
		cout << emp_name;
		cout << " already working on 2 projects " << endl << endl;;
		return;
	}

	else if ((Pro1==Proj) || (Pro2 ==Proj))
	{
		cout << "Project is already included in "<<emp_name << endl << endl;;
		return;
	}

	else if (projectcount < 2)
	{
		if (this->Pro1 == nullptr)
		{
			Pro1 = Proj;
			projectcount++;
			cout << "Project added succesfully" << endl << endl;

		}
		else if (this-> Pro2 == nullptr)
		{
			Pro2 =Proj;
			projectcount++;
			cout << "Project added succesfully" << endl << endl;;
		}
	}	
}

void Employee::removeProject(Project *P)
{
	if (Pro1 ==P)
	{
		Pro1 = nullptr;
		projectcount--;
		cout << "Project removed succesfully" << endl << endl;;
	}

	else if (Pro2 ==P)
	{
		Pro2 = nullptr;
		projectcount--;
		cout << "Project removed succesfully" << endl << endl;;
	}
	
}

 Employee::~Employee()
{
	 delete[] Pro1;
	 delete[] Pro2;
	
	 Pro1 = nullptr;
	 Pro2 = nullptr;
	
}


