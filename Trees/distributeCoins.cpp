// https://leetcode.com/problems/distribute-coins-in-binary-tree/description/
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
    int ans=0;
    pair<int,int> getPair(TreeNode* root)// {subtreeSizeOfRoot,totalCoinsInSideSubstree}
    {
        if(root==NULL) return {0,0};

        pair<int,int> leftPair=getPair(root->left);
        // {5,4} ans+=(5-4)
        // {4,7} ans+=(7-4)
        // {3,3} ans+=(3-3)
        ans+=abs(leftPair.first-leftPair.second);

        pair<int,int> rightPair=getPair(root->right);
        ans+=abs(rightPair.first-rightPair.second);

        pair<int,int> myPair;
        myPair.first= 1 + leftPair.first + rightPair.first;// subtree size of cur root
        myPair.second= root->val + leftPair.second + rightPair.second ;// total number of coins in subtree of root
        return myPair;
    }
    int distributeCoins(TreeNode* root) {
        getPair(root);
        
        return ans;
    }
};