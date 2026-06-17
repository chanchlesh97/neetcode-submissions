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
    int result = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        maxPathSumFind(root);

        return result;
    }

    int maxPathSumFind(TreeNode* root) {
        if(!root) return 0;
        
        int leftMax, rightMax;
        leftMax = maxPathSumFind(root->left);
        rightMax = maxPathSumFind(root->right);

        result = max(result, root->val + max(leftMax, rightMax));
        result = max(result, root->val + leftMax + rightMax);
        result = max(result, root->val);

        return max(root->val + max(leftMax, rightMax), root->val);
    }
};
