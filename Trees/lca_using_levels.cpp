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
    unordered_map<TreeNode*,TreeNode*> parentPointers;

    void getParentPointers(TreeNode* root,TreeNode* par)
    {
        if(root==NULL) return ;

        parentPointers[root]=par;
        getParentPointers(root->left,root);
        getParentPointers(root->right,root);
    }

    int getLevel(TreeNode* root,TreeNode* target,int level)
    {
        if(root==NULL) return -1; // -1 means that target node was not found inside substree of root
        if(root==target) return level;
        int leftMeinTargetMila=getLevel(root->left,target,level+1);
        if(leftMeinTargetMila!=-1) return leftMeinTargetMila;

        int rightMeinTargetMila=getLevel(root->right,target,level+1);
        if(rightMeinTargetMila!=-1) return rightMeinTargetMila;

        return -1;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        getParentPointers(root,NULL);
        int level_p=getLevel(root,p,0),level_q=getLevel(root,q,0); 

        // assumption level_p < level_q
        if(level_p > level_q)
        {
            swap(p,q);
            swap(level_p,level_q);
        }

        for(int i=1;i<=(level_q-level_p);i++) q=parentPointers[q];

        // if(level_p < level_q) // q neeche hai toh raise it by level_q-level_q
        // {
        //     for(int i=1;i<=(level_q-level_p);i++) q=parentPointers[q];
        // } 
        // else 
        // {
        //     for(int i=1;i<=(level_p-level_q);i++) p=parentPointers[p];
        // }

        while(p!=q)
        {
            p=parentPointers[p];
            q=parentPointers[q];
        }
        return p;
    }
};