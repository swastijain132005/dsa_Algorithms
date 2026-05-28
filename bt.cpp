Binary trees
PRE-ORDER
void helper(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        ans.push_back(root->val);      // Root
        helper(root->left, ans);       // Left
        helper(root->right, ans);      // Right
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
helper(root, ans);
        return ans;

Morris inorder traversal
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector<int> morrisInorder(Node* root) {
    vector<int> inorder;
    Node* curr = root;

    while (curr != NULL) {

        // Case 1: No left child
        if (curr->left == NULL) {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else {
            // Find inorder predecessor
            Node* prev = curr->left;

            while (prev->right != NULL && prev->right != curr) {
                prev = prev->right;
            }

            // Make thread
            if (prev->right == NULL) {
                prev->right = curr;     // create temporary link
                curr = curr->left;
            }
            // Remove thread
            else {
                prev->right = NULL;     // remove link
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return inorder;
}

