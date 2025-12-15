













class Solution {
public:
    TreeNode* search(TreeNode* currentNode, int targetValue){
        if(currentNode == NULL)
            return NULL;
        
        if(currentNode->val == targetValue){
            return currentNode;
        } else if(currentNode->val > targetValue){
            return search(currentNode->left, targetValue);
        } else {
            return search(currentNode->right, targetValue);
        }
    }
    
    TreeNode* searchBST(TreeNode* root, int targetValue) {
        return search(root, targetValue);
    }
};
