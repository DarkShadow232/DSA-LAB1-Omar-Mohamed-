












class Solution {
public:
    TreeNode* findLCA(TreeNode* currentNode, TreeNode* firstNode, TreeNode* secondNode){
        if(currentNode->val == firstNode->val || currentNode->val == secondNode->val || 
           (currentNode->val > firstNode->val && currentNode->val < secondNode->val)){
            return currentNode;
        } else if(currentNode->val > firstNode->val && currentNode->val > secondNode->val){
            return findLCA(currentNode->left, firstNode, secondNode);
        } else {
            return findLCA(currentNode->right, firstNode, secondNode);
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* firstNode, TreeNode* secondNode) {
        if(firstNode->val < secondNode->val)
            return findLCA(root, firstNode, secondNode);
        else
            return findLCA(root, secondNode, firstNode);
    }
};
