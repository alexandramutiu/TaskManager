#include "TaskManager.h"
#include <fstream>
#include <iostream>

using namespace std;

void TaskManager::addTask(const Task& task)
{
	tasks.push_back(task);
}

void TaskManager::listTasks()
{
	if (tasks.empty()) {
		cout << "No tasks available!" << endl;
		return;
	}

	for (size_t i = 0; i < tasks.size(); ++i)
	{
		cout << i + 1 << ". ";
		tasks[i].display();
	}
}

void TaskManager::listTasks(bool completedFilter)  {
	int num = 1;
	bool found = false;
	for (const auto& task : tasks) {
		if (task.isCompleted() == completedFilter) {
			std::cout << num << ". ";
			task.display();
			num++;
			found = true;
		}
	}
	if (!found)
		std::cout << "No matching tasks found." << std::endl;
}

void TaskManager::completeTask(int filteredIndex) {
	// filteredIndex = 1..N in the filtered pending list
	int count = 0;
	for (auto& task : tasks) {
		if (!task.isCompleted()) { // only pending tasks
			count++;
			if (count == filteredIndex) {
				task.markCompleted();
				std::cout << "Task marked as completed!" << std::endl;
				return;
			}
		}
	}
	std::cout << "Invalid task number." << std::endl;
}

void TaskManager::saveToFile(const string& filename) {
	std::ofstream outFile(filename);
	for (const auto& task : tasks) {
		outFile << task.serialize() << endl;
	}
}

void TaskManager::loadFromFile(const string& filename)
{
	ifstream inFile(filename);
	if (inFile)
		return;
	tasks.clear();
	string line;
	while (getline(inFile, line)) {
		tasks.push_back(Task::deserialize(line));
	}
}

int TaskManager::getTaskCount()
{
	return static_cast<int>(tasks.size());
}
