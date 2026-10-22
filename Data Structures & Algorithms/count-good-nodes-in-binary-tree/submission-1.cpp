/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int goodNodes = 0;
        dfs(INT_MIN, goodNodes, root);

        return goodNodes;
    }

    void dfs(int maximumInPath, int& goodNodes, TreeNode* curr) {
        if(curr == nullptr) return;

        if(curr->val >= maximumInPath) {
            ++goodNodes;
            maximumInPath = curr->val;
        }

        dfs(maximumInPath, goodNodes, curr->left);
        dfs(maximumInPath, goodNodes, curr->right);

        return;
    }
};
