/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* lastVisited = NULL;
    helper(root, &lastVisited);
}
void helper(struct TreeNode* node, struct TreeNode** lastVisited) {
    if (node == NULL) return;

    struct TreeNode* right = node->right;
    
    if (*lastVisited != NULL) {
        (*lastVisited)->left = NULL;
        (*lastVisited)->right = node;
    }

    *lastVisited = node;

    helper(node->left, lastVisited);
    helper(right, lastVisited);
}