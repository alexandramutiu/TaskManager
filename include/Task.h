#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>

using namespace std;

class Task {
private:
	string title;
	string description;
	string dueDate;
	bool completed;

public:

	Task(const string& t, const string& d, const string& date);

	void markCompleted();
	void display() const;
	//Getters
	bool isCompleted() const;
	string getTitle() const;
	string getDescription() const;
	string getDueDate() const;
	//File saving and loading

	string serialize() const;
	static Task deserialize(const string& line);
};

#endif
