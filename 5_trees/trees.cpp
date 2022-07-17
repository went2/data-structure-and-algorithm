//
//  trees.cpp
//  
//
//  Created by WenTommy on 2022/7/14.
//

#include "trees.hpp"
#include <iostream>
using namespace std;

BstNode* Insert(BstNode* root, int data);
bool Search(BstNode* root, int data);
int findMin(BstNode* root);
int findMax(BstNode* root);
BstNode* findMinRe(BstNode* root);
int findMaxRe(BstNode* root);
int findHeight(BstNode* root);
void levelOrder(BstNode* root);
void preOrder(BstNode* root);
void inOrder(BstNode* root);
bool isBST(BstNode* root);

int main() {
    BstNode* root = NULL; // create a empty tree
    root = Insert(root, 25);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 14);
    root = Insert(root, 15);
    root = Insert(root, 34);
    
    inOrder(root);
    cout<<"\n";
    deleteNode(root, 15);
    inOrder(root);
    
    cout<<"\nroot pointer"<< root << std::endl;
    
    return 0;
}
