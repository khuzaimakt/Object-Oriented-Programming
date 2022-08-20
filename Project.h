#include <iostream>
#include <string>
using namespace std;

#ifndef PROJECT_H
#define PROJECT_H
class Project
{
	string name;
	int budget;
	int duration; //estimate duration of project in weeks

public:
	Project(string name, int budget, int duration);
	// an overloaded constructor
	Project(const Project&);
	//copy constructor
	
	friend ostream& operator<<(ostream& osObject, const Project&);
	void setBudget(int);
	bool operator==(const Project&);
	

};
#endif
