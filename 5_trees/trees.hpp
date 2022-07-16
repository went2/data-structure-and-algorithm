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
int findMinRe(BstNode* root);
int findMaxRe(BstNode* root);
int findHeight(BstNode* root);

// 工具函数
BstNode* GetNewNode(int data);

// 递归方式插入节点，写起来优雅，理解需要花时间
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

int findMinRe(BstNode* root) {
    // 写递归先写终止条件
    if(root == NULL) {
        cout << "Error: empty tree.\n";
        return -1;
    }
    else if(root->left == NULL) {
        return root->data;
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
