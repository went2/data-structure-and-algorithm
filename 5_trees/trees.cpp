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
int findMinRe(BstNode* root);
int findMaxRe(BstNode* root);
int findHeight(BstNode* root);

int main() {
    BstNode* root = NULL; // create a empty tree
    root = Insert(root, 25);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 14);
    root = Insert(root, 15);
    root = Insert(root, 34);
    
    printf("the min value of tree: %d\n", findMin(root));
    printf("the max value of tree: %d\n", findMax(root));
    printf("the min value of tree: %d\n", findMinRe(root));
    printf("the max value of tree: %d\n", findMaxRe(root));
    printf("the height of tree: %d\n", findHeight(root));
    
    return 0;
}
