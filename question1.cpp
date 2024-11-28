// Your Name: Sophie
// Student ID: 1123504
// Date of Submission: 28-Nov-2024

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition of a binary tree node
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to build a binary tree from level-order input
TreeNode* buildTree(const vector<int>& levelOrder) {
    if (levelOrder.empty() || levelOrder[0] == -1) {
        return nullptr;
    }

    // Create the root node
    TreeNode* root = new TreeNode(levelOrder[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    // Using a queue to construct the binary tree iteratively
    while (i < levelOrder.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Assign left child
        if (levelOrder[i] != -1) {
            current->left = new TreeNode(levelOrder[i]);
            q.push(current->left);
        }
        i++;

        // Assign right child
        if (i < levelOrder.size() && levelOrder[i] != -1) {
            current->right = new TreeNode(levelOrder[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Helper function to calculate height and diameter in a single traversal
pair<int, int> heightAndDiameter(TreeNode* root) {
    if (!root) {
        return {0, 0}; // height, diameter
    }

    // Recursively calculate for left and right subtrees
    pair<int, int> left = heightAndDiameter(root->left);
    pair<int, int> right = heightAndDiameter(root->right);

    // Height of the current node
    int currentHeight = 1 + max(left.first, right.first);

    // Diameter at the current node
    int currentDiameter = left.first + right.first;

    // Overall diameter
    int overallDiameter = max(currentDiameter, max(left.second, right.second));

    return {currentHeight, overallDiameter};
}

// Function to calculate the diameter of the binary tree
int diameterOfBinaryTree(TreeNode* root) {
    return heightAndDiameter(root).second;
}

int main() {
    // Input: Level-order traversal of the binary tree
    vector<int> levelOrder = {1, 2, 3, 4, -1, 5, 6, -1, -1, -1, -1, 7, 8}; // Replace with your own test case

    // Build the binary tree
    TreeNode* root = buildTree(levelOrder);

    // Calculate the diameter
    int diameter = diameterOfBinaryTree(root);

    // Output: Diameter of the binary tree
    cout << diameter << endl;

    return 0;
}
