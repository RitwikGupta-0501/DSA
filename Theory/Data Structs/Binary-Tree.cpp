#include <iostream>

using namespace std;

class TreeNode {
    public:
        TreeNode* parent;
        TreeNode* right;
        TreeNode* left;
        int data;

        TreeNode(int value) {
            this->parent = nullptr;
            this->left = nullptr;
            this->right = nullptr;
            this->data = value;
        }
};

class Tree {
    private:
        TreeNode* root;
    
    public:
        Tree() {
            this->root = nullptr;
        }
};