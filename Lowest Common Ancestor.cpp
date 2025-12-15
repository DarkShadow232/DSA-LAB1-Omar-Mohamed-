

















class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* firstNode, TreeNode* secondNode) {
        if(root == NULL)
            return NULL;
        
        if(root == firstNode || root == secondNode){
            return root;
        }
        
        TreeNode* leftResult = lowestCommonAncestor(root->left, firstNode, secondNode);
        TreeNode* rightResult = lowestCommonAncestor(root->right, firstNode, secondNode);
        
        if(leftResult == NULL){
            return rightResult; 
        } else if(rightResult == NULL){
            return leftResult; 
        } else {
            return root; 
        }
    }
};
