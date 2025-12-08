













class Solution {
public:
    
    TreeNode* recurse(TreeNode* node, int val){
        
        if(node == NULL)
            return NULL;
        
        if(node->val == val){
            return node;
        }else if(node->val > val){
            return recurse(node->left, val);
        }else{
            return recurse(node->right, val);
        }
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        return recurse(root, val);
    }
};
