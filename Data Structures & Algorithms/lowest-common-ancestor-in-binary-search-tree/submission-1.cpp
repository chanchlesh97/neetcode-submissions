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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool pf = false, qf = false;
        return lca(root, p, q, pf, qf);
    }

    TreeNode * lca(TreeNode * root, TreeNode*p, TreeNode*q, bool &pf, bool &qf) {
        if(!root)return nullptr;

        bool lpf = false, lqf = false, rpf = false, rqf = false;
        TreeNode *l, *r;
        l = lca(root->left, p, q, lpf, lqf);
        if(l)return l;
        r = lca(root->right, p, q, rpf, rqf);
        if(r) return r;

        pf = lpf || rpf;
        qf = lqf || rqf;

        if(root == p) {
            pf  = true;
        } 
        if(root == q) {
            qf = true;
        }

        if(pf && qf) {
            return root;
        } 
        return nullptr;
    }
};
