







class Solution {
public:
    
    int recurse(TreeNode* node){
        if(node == NULL)
            return 0;
        return 1 + max(recurse(node->left) , recurse(node->right));
    }
    
    int maxDepth(TreeNode* root) {
        return recurse(root);
    }
};
