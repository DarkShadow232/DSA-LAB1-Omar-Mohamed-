















int recurse(TreeNode* node, int &longestDiameter){
    if(node == NULL)
        return 0;
    
    int left = recurse(node->left, longestDiameter);
    int right = recurse(node->right, longestDiameter);
    
    int pathLeftOrRight = max(left, right) + 1;
    int pathLeftANDRight = 1 + left + right;
    longestDiameter = max(longestDiameter, pathLeftANDRight);
    
    return pathLeftOrRight;
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int longestDiameter = 0;
        recurse(root, longestDiameter);
        return longestDiameter - 1; 
    }
};
