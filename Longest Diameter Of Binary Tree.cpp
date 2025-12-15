















int calculateHeight(TreeNode* node, int &maxDiameter){
    if(node == NULL)
        return 0;
    
    int leftHeight = calculateHeight(node->left, maxDiameter);
    int rightHeight = calculateHeight(node->right, maxDiameter);
    
    int heightThroughThisNode = max(leftHeight, rightHeight) + 1;
    int diameterThroughThisNode = 1 + leftHeight + rightHeight;
    maxDiameter = max(maxDiameter, diameterThroughThisNode);
    
    return heightThroughThisNode;
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        calculateHeight(root, maxDiameter);
        return maxDiameter - 1; 
    }
};
