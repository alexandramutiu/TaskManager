#include "TaskManager.h"
#include <iostream>

void showMenu()
{
    cout << "\n=== Task Manager CLI ===\n";
    cout << "1. Add Task\n";
    cout << "2. List All Tasks\n";
    cout << "3. List Completed Tasks\n";
    cout << "4. List Pending Tasks\n";
    cout << "5. Complete a Task\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

int main()
{
    TaskManager manager;
    manager.loadFromFile("data/tasks.txt");
    int choice;
    do
    {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1: {
            string title, desc, due;
            cout << "Title: ";
            getline(cin, title);
            cout << "Description: ";
            getline(cin, desc);
            cout << "Due Date (YYYY-MM-DD): ";
            getline(cin, due);
            manager.addTask(Task(title, desc, due));
            break;
        }
        case 2:
            manager.listTasks();
            break;
        case 3:
            manager.listTasks(true);
            break;
        case 4:
            manager.listTasks(false);
            break;
        case 5: {
            std::cout << "Pending Tasks:\n";
            manager.listTasks(false); // list only pending
            int num;
            std::cout << "Enter task number to complete: ";
            std::cin >> num;
            std::cin.ignore();
            manager.completeTask(num); // use filtered index
            break;
        }
        case 6:
            manager.saveToFile("data/tasks.txt");
            cout << "Tasks saved. Goodbye!\n";
            break;
        default:
            cout << "Invalid option.\n";
        }
    } while (choice != 6);
    return 0;
}
