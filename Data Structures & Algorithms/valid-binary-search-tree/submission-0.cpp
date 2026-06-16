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
    bool isValidBST(TreeNode* root) {
        return checkValidBST(root, -1001, 1001);
    }

    bool checkValidBST(TreeNode * root, int minTill, int maxTill) {
        if(!root) return true;

        if(root->val <= minTill || root->val >= maxTill) {
            // cout<< root->val << " " << minTill << " " << maxTill << endl;
            return false;
        }
        return checkValidBST(root->left, minTill, root->val) && checkValidBST(root->right, root->val, maxTill);
    }
};
