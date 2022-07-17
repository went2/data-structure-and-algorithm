//
//  trees.hpp
//  
//
//  Created by WenTommy on 2022/7/14.
//

#ifndef trees_hpp
#define trees_hpp

#include <stdio.h>
#include <stdlib.h>
#include <queue>

#endif /* trees_hpp */

#include <iostream>
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* Insert(BstNode* root, int data);
bool Search(BstNode* root, int data);

int findMin(BstNode* root);
int findMax(BstNode* root);
BstNode* findMinRe(BstNode* root);
int findMaxRe(BstNode* root);
int findHeight(BstNode* root);

// 广度优先遍历
void levelOrder(BstNode* root);

// 深度优先遍历
void preOrder(BstNode* root);
void inOrder(BstNode* root);

// 检测一个二分树是否是二分查找树
bool isBST(BstNode* root);

// 从二分查找树中删除一个节点
BstNode* deleteNode(BstNode* root, int value);

// 工具函数
BstNode* GetNewNode(int data);
bool isBstUtil(BstNode* root, int minValue, int maxValue);

// 在树中插入节点的意思，需要从树的根节点开始，通过不断比较，将一个新节点添加为父节点的左节点或右节点
// 递归即实现沿着树层层向下查找
BstNode* Insert(BstNode* root, int data) {
    if(root == NULL) {
        root = GetNewNode(data);
    } else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(BstNode* root, int data) {
    if(root == NULL) return false;
    else if (data == root->data) return true;
    else if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

BstNode* GetNewNode(int data) {
    BstNode* temp = (BstNode*)malloc(sizeof(BstNode));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int findMin(BstNode* root) {
    // 按值传递，root 是本地变量
    if(root == NULL) {
        cout << "Error: empty tree.\n";
        return -1;
    }

    while(root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int findMax(BstNode* root) {
    if(root == NULL) {
        cout << "Error: empty tree.\n";
        return -1;
    }

    while(root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

BstNode* findMinRe(BstNode* root) {
    // 写递归先写终止条件
    if(root == NULL) {
        cout << "Error: empty tree.\n";
        return NULL;
    }
    else if(root->left == NULL) {
        return root;
    }
    return findMinRe(root->left);
}

int findMaxRe(BstNode* root) {
    if(root == NULL) {
        cout << "Error: empty tree.\n";
        return -1;
    }
    else if(root->right == NULL) {
        return root->data;
    }
    return findMaxRe(root->right);
}

int findHeight(BstNode* root) {
    // 节点高度指它到最远叶子节点经过的路径
    // 算法: H(root) = max( H(root->left), H(root->right) ) + 1
    
    if(root == NULL) {
        return -1;
    }
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void levelOrder(BstNode* root) {
    if(root == NULL) {
        return;
    }
    queue<BstNode*> Q;
    Q.push(root);
    
    while(!Q.empty()) {
        BstNode* temp = Q.front();
        
        // 遍历到节点并操作
        cout << temp->data << " ";
        
        // 执行下一次遍历前的设置
        if(temp->left != NULL) Q.push(temp->left);
        if(temp->right != NULL) Q.push(temp->right);
        Q.pop();
    }
}

void preOrder(BstNode* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    if(root->left != NULL) preOrder(root->left);
    if(root->right != NULL) preOrder(root->right);
}

void inOrder(BstNode* root) {
    if(root == NULL) {
        return;
    }
    
    if(root->left != NULL) inOrder(root->left);
    cout << root->data << " ";
    if(root->right != NULL) inOrder(root->right);
}

bool isBST(BstNode* root) {
    return isBstUtil(root, INT_MIN, INT_MAX);
}


bool isBstUtil(BstNode* root, int minValue, int maxValue) {
    if(root == NULL) return true;
    
    // 每个节点的值要在一个范围内
    // 对于左节点，设置其最大值为当前值，对于右节点，设置其最小值为当前值
    if(root->data > minValue && root->data < maxValue
       && isBstUtil(root->left, minValue, root->data)
       && isBstUtil(root->right, root->data, maxValue))
        return true;
    else return false;
}

BstNode* deleteNode(BstNode* root, int value) {
    if(root == NULL) return root;
    else if(value < root->data)
        root->left = deleteNode(root->left, value);
    else if(value > root->data)
        root->right = deleteNode(root->right, value);
    else { // 已找到该节点，准备删除
        // no child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        // 1 child
        else if(root->left == NULL) {
            BstNode* temp = root;
            root = temp->right;
            delete temp;
        }
        else if(root->right == NULL) {
            BstNode* temp = root;
            root = temp->left;
            delete temp;
        }
        // 2 children
        else {
            BstNode* temp = findMinRe(root->right);
            root->data = temp->data;
            // 删除右边子树的最小值的节点，该节点无左树
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}


