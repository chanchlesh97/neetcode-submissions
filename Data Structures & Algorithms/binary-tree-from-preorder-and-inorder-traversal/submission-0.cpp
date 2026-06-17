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
    unordered_map<int,int> posMap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i<preorder.size();i++) {
            posMap[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, 0, 0, preorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int index, int l, int h) {

        if(l>h) return nullptr;
        int pos = -1;
        for(int i = index;i < preorder.size();i++) {
            if(posMap[preorder[i]] >= l && posMap[preorder[i]] <= h) {
                pos = i;
                break;
            }
        }
        TreeNode * left, * right, * curr = nullptr ;
        if(pos != -1) {
            // cout << 
            curr = new TreeNode(preorder[pos]);
            curr -> left = buildTree(preorder, inorder, index+1, l, posMap[preorder[pos]]-1);
            curr -> right = buildTree(preorder, inorder, index+1, posMap[preorder[pos]]+1, h);
        }
        
        return curr;
    }
};
