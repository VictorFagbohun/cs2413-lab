/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int max_int(int a, int b) { return (a > b) ? a : b; }
int abs_int(int x) { return (x < 0) ? -x : x; }

int checkAVL(struct TreeNode* node, bool hasMin, int minVal, bool hasMax, int maxVal) {
    if (node == NULL) return 0;

    if (hasMin && node->val <= minVal) {
        return -1; 
    }
    if (hasMax && node->val >= maxVal){
         return -1;
    }

    int lh = checkAVL(node->left,  hasMin, minVal, true,  node->val);
    if (lh == -1) {
        return -1;
    }

    int rh = checkAVL(node->right, true,  node->val, hasMax, maxVal);
    if (rh == -1) { 
        return -1;
    }

    if (abs_int(lh - rh) > 1) {
        return -1;
    }

    return 1 + max_int(lh, rh);
}

bool isAVL(struct TreeNode* root) {
    // TODO: implement
    // Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced).
    return checkAVL(root, false, 0, false, 0) != -1;
}
