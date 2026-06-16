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
        int result = 0;
        countGood(root, result, -101);
        return result;
    }

    void countGood(TreeNode* root, int &result, int maxTill) {
        if(!root) return;
        if(root->val >= maxTill) {
            // cout<<"$"<<maxTill<<endl;
            result++;
            maxTill = root->val;
        }

        countGood(root->left, result, maxTill);
        countGood(root->right, result, maxTill);

    }
};
