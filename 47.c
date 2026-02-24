//
// Created by lhl on 2026/2/24.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int result = 0;

void resolution(struct TreeNode* root, int cur) {
    cur = (cur << 1) + root->val;
    if (root->left == NULL && root->right == NULL){
        result += cur;
        return;
    }
    if (root->left != NULL){
        resolution(root->left, cur);
    }
    if (root->right != NULL){
        resolution(root->right, cur);
    }
}

int sumRootToLeaf(struct TreeNode* root) {
    result = 0;
    resolution(root, 0);
    return result;
}

// GPT Version
/*
 * static int dfs(struct TreeNode* root, int cur) {
 *     if (root == NULL) {
 *         return 0;
 *     }
 *
 *     cur = (cur << 1) | root->val;
 *     if (root->left == NULL && root->right == NULL) {
 *         return cur;
 *     }
 *
 *     return dfs(root->left, cur) + dfs(root->right, cur);
 * }
 *
 * int sumRootToLeaf(struct TreeNode* root) {
 *     return dfs(root, 0);
 * }
 */

