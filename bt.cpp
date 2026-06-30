#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int main() {

    // Creating nodes
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* buildTree() {
    int val;
    cin >> val;

    if (val == -1)
        return nullptr;

    Node* root = new Node(val);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int main() {

    cout << "Enter tree in preorder (-1 for NULL):\n";

    Node* root = buildTree();

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* buildTree() {
    int val;
    cout << "Enter root value (-1 for NULL): ";
    cin >> val;

    if (val == -1)
        return nullptr;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int leftData, rightData;

        cout << "Enter left child of " << curr->data << " (-1 for NULL): ";
        cin >> leftData;

        if (leftData != -1) {
            curr->left = new Node(leftData);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->data << " (-1 for NULL): ";
        cin >> rightData;

        if (rightData != -1) {
            curr->right = new Node(rightData);
            q.push(curr->right);
        }
    }

    return root;
}

int main() {
    Node* root = buildTree();

    cout << "Binary tree created successfully!\n";

    return 0;
}
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
//iterative inorder

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        stack<pair<TreeNode*, bool>> st;

        if (root)
            st.push({root, false});

        while (!st.empty()) {

            auto [node, vis] = st.top();
            st.pop();

            if (node == NULL)
                continue;

            if (vis) {
                ans.push_back(node->val);
            } else {
                if (node->right)
                    st.push({node->right, false});

                st.push({node, true});

                if (node->left)
                    st.push({node->left, false});
            }
        }

        return ans;
    }
};

Morris inorder traversal

root ke left child ke right me tab tak jao jab tak possible ho then root aur left child ka connection break kar do
    and now leftchild will become curr root 
agar left child nahi h to print kar do aur curr ko right me bhej do
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

