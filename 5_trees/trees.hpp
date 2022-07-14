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

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* Insert(BstNode* root, int data);
bool Search(BstNode* root, int data);

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
