








class Solution {
public:
    
    int recurse(TreeNode* node, bool &isBalancedTree){
        if(node == NULL || isBalancedTree == false)
            return 0;
        int leftSubtreeHeight = recurse(node->left, isBalancedTree);
        int rightSubtreeHeight = recurse(node->right, isBalancedTree);
        if(abs(leftSubtreeHeight - rightSubtreeHeight) > 1){
            isBalancedTree = false;
        }
        return 1 + max(leftSubtreeHeight, rightSubtreeHeight);
    }
    
    
    bool isBalanced(TreeNode* root) {
        bool isBalancedTree = true;
        recurse(root, isBalancedTree);
        return isBalancedTree;
    }
};
