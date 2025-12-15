














class Solution {
public:
    TreeNode* buildBSTFromRange(vector<int>& preorder, int startIndex, int endIndex) {
        if(startIndex > endIndex){
            return NULL;
        }
        
        if(startIndex == endIndex){
            TreeNode* node = new TreeNode(preorder[startIndex]);
            return node;
        }
        
        TreeNode* node = new TreeNode(preorder[startIndex]);
        
        int rightSubtreeStart = -1;
        
        for(int i = startIndex + 1; i <= endIndex; i++){
            if(preorder[i] > preorder[startIndex]){
                rightSubtreeStart = i;
                break;
            }
        }
        
        if(rightSubtreeStart == -1){
            node->left = buildBSTFromRange(preorder, startIndex + 1, endIndex);
        } else {
            node->left = buildBSTFromRange(preorder, startIndex + 1, rightSubtreeStart - 1);
            node->right = buildBSTFromRange(preorder, rightSubtreeStart, endIndex);
        }
    
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildBSTFromRange(preorder, 0, preorder.size() - 1);
    }
};













class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int &currentIndex, int maxValue) {
        int arraySize = preorder.size();
        
        if(currentIndex == arraySize || preorder[currentIndex] > maxValue)
            return NULL;
        
        TreeNode *node = new TreeNode(preorder[currentIndex++]);
        node->left = buildTree(preorder, currentIndex, node->val);
        node->right = buildTree(preorder, currentIndex, maxValue);
        
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int currentIndex = 0;
        int maxValue = INT_MAX;
        return buildTree(preorder, currentIndex, maxValue);
    }
};
