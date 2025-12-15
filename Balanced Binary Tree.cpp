








class Solution {
public:
    int getHeightAndCheckBalance(TreeNode* node, bool &balanced){
        if(node == NULL || balanced == false)
            return 0;
            
        int leftHeight = getHeightAndCheckBalance(node->left, balanced);
        int rightHeight = getHeightAndCheckBalance(node->right, balanced);
        
        if(abs(leftHeight - rightHeight) > 1){
            balanced = false;
        }
        
        return 1 + max(leftHeight, rightHeight);
    }
    
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        getHeightAndCheckBalance(root, balanced);
        return balanced;
    }
};
