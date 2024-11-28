// Your Name: Sophie
// Student ID: 1123504
// Date of Submission: 28-Nov-2024

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// Custom comparator for the min-heap
struct Compare {
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<0>(a) > get<0>(b); // Compare by value
    }
};

// Function to merge K sorted arrays
vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> minHeap;
    vector<int> result;

    // Initialize the heap with the first element of each array
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0}); // {value, array index, element index}
        }
    }

    // Process the heap
    while (!minHeap.empty()) {
        // Extract the smallest element
        auto [value, arrayIndex, elementIndex] = minHeap.top();
        minHeap.pop();
        result.push_back(value);

        // If there are more elements in the same array, add the next one to the heap
        if (elementIndex + 1 < arrays[arrayIndex].size()) {
            minHeap.push({arrays[arrayIndex][elementIndex + 1], arrayIndex, elementIndex + 1});
        }
    }

    return result;
}

int main() {
    int K;

    // Input: Number of sorted arrays
    cout << "Enter the number of sorted arrays: ";
    cin >> K;

    vector<vector<int>> arrays(K);

    // Input: K sorted arrays
    cout << "Enter each sorted array on a new line:" << endl;
    for (int i = 0; i < K; ++i) {
        int n;
        cout << "Enter size of array " << i + 1 << ": ";
        cin >> n;
        arrays[i].resize(n);
        cout << "Enter elements of array " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> arrays[i][j];
        }
    }

    // Merge the arrays
    vector<int> mergedArray = mergeKSortedArrays(arrays);

    // Output: Merged sorted array
    cout << "Merged Array: [";
    for (size_t i = 0; i < mergedArray.size(); ++i) {
        cout << mergedArray[i];
        if (i != mergedArray.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
