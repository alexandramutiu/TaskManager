#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TaskManager {
private:
	vector<Task> tasks;

public:
	void addTask(const Task& task);
	void listTasks();
	void listTasks(bool completed);
	void completeTask(int index);
	void saveToFile(const string& filename);
	void loadFromFile(const string& filename);
	int getTaskCount();
};

#endif //TASKMANAGER_H
