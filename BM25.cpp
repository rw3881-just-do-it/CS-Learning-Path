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

//transverse using one stack
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        stack<TreeNode*> stack1, stack2;
        stack1.push(root);
        
        // stack1: processes nodes (Root -> Right -> Left)
        while (!stack1.empty()) {
            TreeNode* node = stack1.top();
            stack1.pop();
            stack2.push(node);
            
            // Push left first, then right? No - left first then right!
            // Since stack1 is LIFO, we push left first, then right
            if (node->left) {
                stack1.push(node->left);
            }
            if (node->right) {
                stack1.push(node->right);
            }
            // This gives: Root (popped), then right pushed, then left pushed
            // So stack1 pops: Root, then left, then right? Let me trace carefully
        }
        
        // stack2 now has nodes in Root->Right->Left order
        // Popping gives Left->Right->Root (postorder)
        while (!stack2.empty()) {
            result.push_back(stack2.top()->val);
            stack2.pop();
        }
        
        return result;
    }

//tranverse using one stack
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr;
        
        while (!st.empty() || current != nullptr) {
            // Traverse to the leftmost node
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            
            // Peek at the top node
            TreeNode* node = st.top();
            
            // If right child exists and hasn't been visited
            if (node->right != nullptr && node->right != lastVisited) {
                // Process right subtree
                current = node->right;
            } else {
                // No right child or right already visited
                // Visit the node
                result.push_back(node->val);
                lastVisited = st.top();
                st.pop();
                // current remains nullptr to process next stack item
            }
        }
        
        return result;
    }