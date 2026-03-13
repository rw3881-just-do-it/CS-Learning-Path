
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//recursive approach
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    preorderHelper(root, result);
    return result;
}

void preorderHelper(TreeNode* node, vector<int>& result) {
    if (node == nullptr) return;
    
    // Visit root first (preorder: root -> left -> right)
    result.push_back(node->val);
    preorderHelper(node->left, result);
    preorderHelper(node->right, result);
}

//iterative using stack
vector<int> SecondpreorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) return result;
    
    stack<TreeNode*> nodeStack;
    nodeStack.push(root);
    
    while (!nodeStack.empty()) {
        TreeNode* current = nodeStack.top();
        nodeStack.pop();
        
        // Visit the node
        result.push_back(current->val);
        
        // Push right child first so that left is processed first (LIFO)
        if (current->right) {
            nodeStack.push(current->right);
        }
        if (current->left) {
            nodeStack.push(current->left);
        }
    }
    
    return result;
}


//Morris Traversal with Space Optimized
vector<int> ThirdpreorderTraversal(TreeNode* root) {
    vector<int> result;
    TreeNode* current = root;
    
    while (current != nullptr) {
        if (current->left == nullptr) {
            // If no left child, visit current and go right
            result.push_back(current->val);
            current = current->right;
        } else {
            // Find the inorder predecessor
            TreeNode* predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            
            if (predecessor->right == nullptr) {
                // Create thread and visit current node
                predecessor->right = current;
                result.push_back(current->val);
                current = current->left;
            } else {
                // Remove thread and go right
                predecessor->right = nullptr;
                current = current->right;
            }
        }
    }
    
    return result;
}

int main(){

}