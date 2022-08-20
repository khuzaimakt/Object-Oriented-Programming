#include"project.h"

Project::Project(string name, int budget, int duration)
{
	this->name = name;
	this->duration = duration;
	this->budget = budget;
}


Project::Project(const Project &P)
{
	this->name = P.name;

	this->duration = P.duration; 

	this->budget = P.budget;
}


void Project::setBudget(int bud)
{
	this->budget = bud;   
} 

ostream& operator<<(ostream& osObject, const Project&P)
{
	osObject <<"Project Name: "<< P.name << "," << "Project Budget: "<<P.budget << "," <<"Project duration: "<< P.duration << endl;
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

