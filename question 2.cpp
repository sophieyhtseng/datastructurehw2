// Your Name: Sophie        
// Student ID: 1123504
// Date of Submission: 28-Nov-2024

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

// Structure to represent a task
struct Task {
    string name;
    int priority;

    // Constructor for Task
    Task(string taskName, int taskPriority) : name(taskName), priority(taskPriority) {}

    // Overload < operator to create a max-heap
    bool operator<(const Task& other) const {
        return priority < other.priority; // Higher priority tasks come first
    }
};

int main() {
    priority_queue<Task> taskQueue; // Max-heap for tasks
    vector<Task> remainingTasks;   // To store remaining tasks
    int N;

    // Input: Number of operations
    cout << "Enter the number of operations: ";
    cin >> N;
    cin.ignore(); // Ignore newline character after reading N

    // Processing the commands
    for (int i = 0; i < N; ++i) {
        string command;
        cout << "Enter command (ADD task_name priority or GET): ";
        getline(cin, command);

        if (command.substr(0, 3) == "ADD") {
            // Parse ADD command
            size_t space1 = command.find(' ', 4);
            string taskName = command.substr(4, space1 - 4);
            int priority = stoi(command.substr(space1 + 1));
            taskQueue.push(Task(taskName, priority));
        } else if (command == "GET") {
            if (!taskQueue.empty()) {
                // Get the task with the highest priority
                Task topTask = taskQueue.top();
                taskQueue.pop();
                cout << topTask.name << endl;
            } else {
                cout << "No tasks available" << endl;
            }
        }
    }

    // Collect remaining tasks
    while (!taskQueue.empty()) {
        remainingTasks.push_back(taskQueue.top());
        taskQueue.pop();
    }

    // Print remaining tasks
    cout << "Remaining tasks: [";
    for (size_t i = 0; i < remainingTasks.size(); ++i) {
        cout << "('" << remainingTasks[i].name << "', " << remainingTasks[i].priority << ")";
        if (i != remainingTasks.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
