#include "Task.h"
#include <sstream>

using namespace std;

//Implementing the constructor

Task::Task(const string& t, const string& d, const string& date)
	: title(t), description(d), dueDate(date), completed(false){}


//Mark a task as completed

void Task::markCompleted()
{
	completed = true;
}

void Task::display() const
{
	cout << "[" << (completed ? "X" : " ") << "] " << title
		<< " (Due: " << dueDate << ")" << endl;
	cout << "  " << description << endl;
}

bool Task::isCompleted() const { return completed;}
string Task::getTitle() const { return title; }
string Task::getDescription() const { return description; }
string Task::getDueDate() const { return dueDate; }

string Task::serialize() const{
	ostringstream oss;
	oss << title << "|" << dueDate << "|" << completed;
	return oss.str();
}

Task Task::deserialize(const string& line)
{
	istringstream iss(line);
	string t, d, date, compStr;
	getline(iss, t, '|');
	getline(iss, d, '|');
	getline(iss, date, '|');
	getline(iss, compStr, '|');
	Task task(t, d, date);
	task.completed = (compStr == "1" || compStr == "true");
	return task;
}
