









#define ll long long 
class Solution {
public:
    bool validateNode(TreeNode* node, ll minValue, ll maxValue){
        if(node == NULL)
            return true;
        
        if(node->val < minValue || node->val > maxValue)
            return false;
        
        return validateNode(node->left, minValue, node->val - 1LL) && 
               validateNode(node->right, node->val + 1LL, maxValue);
    }
    
    bool isValidBST(TreeNode* root) {
        ll minValue = INT_MIN;
        ll maxValue = INT_MAX;
        
        return validateNode(root, minValue, maxValue);
    }
};
