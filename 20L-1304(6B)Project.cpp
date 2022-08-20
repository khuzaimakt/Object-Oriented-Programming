#include"project.h"
#include"Employee.h"

Project::Project(string name, int budget, int duration)
{
	this->name = name;
	this->duration = duration;
	this->budget = budget;
	employeecount = 0;
	Emp = new Employee*[3];
	for (int i = 0; i < 3; i++)
	{
		Emp[i] = nullptr;
	}
	
}



Project::Project(const Project& P)
{
	this->name = P.name;

	this->duration = P.duration;

	this->budget = P.budget;

	this->employeecount = P.employeecount;

	for (int i = 0; i < employeecount; i++)
	{
		Emp[i] = P.Emp[i];
	}
}


void Project::setBudget(int bud)
{
	this->budget = bud;
}


ostream& operator<<(ostream& osObject, const Project& P)
{
	osObject << "Project Name: " << P.name << "," << "Project Budget: " << P.budget << "," << "Project duration: " << P.duration<< " weeks" << endl
		<< "No. of employess: " << P.employeecount << endl << endl;
	return osObject;
}

bool Project::operator==(const Project& P)
{
	if ((name == P.name) && (budget == P.budget) && (duration == P.duration))
	{
		return true;
	}
	else
		return false;
}

const Project& Project:: operator=(const Project& other)
{
	this->name = other.name;

	this->duration = other.duration;

	this->budget = other.budget;

	this->employeecount = other.employeecount;

	for (int i = 0; i < employeecount; i++)
	{
		Emp[i] = other.Emp[i];
	}

	return *this;
}

void Project::addemployee(Employee* E)
{
	if (Emp[employeecount] == nullptr)
	{
		this->Emp[employeecount] = E;
		employeecount++;
		cout << "Employee added to Project" << endl << endl;;
	}
}

Employee** Project::getemployee()
{
	return Emp;
}

void Project::printEmployees()
{
	for (int i = 0; i < 3; i++)
	{
		if (Emp[i] != nullptr)
			cout << Emp[i]->emp_name << " "  << endl;
	}
	cout << endl;
}


void Project::removeemployee(Employee* E)
{
	for (int i = 0; i < employeecount; i++)
	{
		if (Emp[i] == E)
		{
			Emp[i] = nullptr;
			employeecount--;
			cout << "Employee removed from project " << endl << endl;
		}
	}
}


Project::~Project()
{
	
	delete[]Emp;
}


