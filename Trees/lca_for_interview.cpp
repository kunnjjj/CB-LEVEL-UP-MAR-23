/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
        {
            return NULL; // NULL p or q is not found in this subtree
        }
        // CASE1 and CASE2 get covered, if p is found earlier then no need to find q and vice versa
        if(root==p or root==q) return root; // agar p mil jaye ya q mil jaye toh unka address return karvado 
        TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
        // NULL if any of the two is not found
        // notNUll if it has found p or q

        TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);
        // NULL if any of the two is not found
        // notNUll if it has found p or q

        // CASE3
        if(leftAns!=NULL and rightAns!=NULL) return root; // root is lca
        if(leftAns && rightAns==NULL) return leftAns; // jiska address mila tha wahi return kara rahe hai
        if(leftAns==NULL && rightAns!=NULL) return rightAns;

        return NULL;
    }
};