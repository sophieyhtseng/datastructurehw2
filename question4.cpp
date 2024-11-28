// Your Name: Sophie
// Student ID: 1123504
// Date of Submission: 28-Nov-2024

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Structure to represent a task
struct Task {
    int profit;
    int deadline;

    // Constructor for Task
    Task(int p, int d) : profit(p), deadline(d) {}
};

// Comparator to sort tasks by profit in descending order
bool compareTasks(const Task& a, const Task& b) {
    return a.profit > b.profit;
}

int main() {
    int N;

    // Input: Number of tasks
    cout << "Enter the number of tasks: ";
    cin >> N;

    vector<Task> tasks;

    // Input: Profit and deadline for each task
    cout << "Enter profit and deadline for each task:" << endl;
    for (int i = 0; i < N; ++i) {
        int profit, deadline;
        cin >> profit >> deadline;
        tasks.emplace_back(profit, deadline);
    }

    // Step 1: Sort tasks by profit in descending order
    sort(tasks.begin(), tasks.end(), compareTasks);

    // Step 2: Initialize time slots and scheduled tasks
    int maxDeadline = 0;
    for (const Task& task : tasks) {
        maxDeadline = max(maxDeadline, task.deadline);
    }

    vector<int> timeSlots(maxDeadline, -1); // -1 indicates an empty slot
    vector<int> scheduledTasks;            // To store the profits of scheduled tasks
    int totalProfit = 0;

    // Step 3: Schedule tasks
    for (const Task& task : tasks) {
        // Find a free slot for the task before its deadline
        for (int slot = task.deadline - 1; slot >= 0; --slot) {
            if (timeSlots[slot] == -1) {
                // Schedule the task in this slot
                timeSlots[slot] = task.profit;
                scheduledTasks.push_back(task.profit);
                totalProfit += task.profit;
                break;
            }
        }
    }

    // Output: Maximum profit and scheduled tasks
    cout << "Maximum Profit: " << totalProfit << endl;
    cout << "Scheduled Tasks: [";
    for (size_t i = 0; i < scheduledTasks.size(); ++i) {
        cout << scheduledTasks[i];
        if (i != scheduledTasks.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
