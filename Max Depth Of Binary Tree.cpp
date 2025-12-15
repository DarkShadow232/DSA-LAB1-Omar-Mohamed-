







class Solution {
public:
    int calculateDepth(TreeNode* node){
        if(node == NULL)
            return 0;
        return 1 + max(calculateDepth(node->left), calculateDepth(node->right));
    }
    
    int maxDepth(TreeNode* root) {
        return calculateDepth(root);
    }
};
