

















class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL)
            return NULL;
        
        if(root == p || root == q){
            return root;
        }
        
        TreeNode* LCAattainedFromLeftSubtree = lowestCommonAncestor(root->left, p, q);
        TreeNode* LCAattainedFromRightSubtree = lowestCommonAncestor(root->right, p, q);
        
        if(LCAattainedFromLeftSubtree == NULL){
            return LCAattainedFromRightSubtree; 
        }else if(LCAattainedFromRightSubtree == NULL){
            return LCAattainedFromLeftSubtree; 
        }else{
            return root; 
        }
    }
};
