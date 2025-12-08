









#define ll long long 
class Solution {
public:
    
    bool recurse(TreeNode* node, ll lower_bound, ll upper_bound){
        if(node == NULL)
            return true;
        
        if(node->val < lower_bound || node->val > upper_bound)
            return false;
        
        return recurse(node->left , lower_bound , node->val - 1LL) && recurse(node->right , node->val + 1LL , upper_bound);
    }
    
    bool isValidBST(TreeNode* root) {
        ll lower_bound = INT_MIN;
        ll upper_bound = INT_MAX;
        
        return recurse(root, lower_bound, upper_bound);
    }
};
