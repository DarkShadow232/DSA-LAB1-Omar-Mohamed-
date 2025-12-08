













class Solution {
public:
    
    TreeNode* recurse(vector<int>& nums, int low, int high){
        
        if(low > high)
            return NULL;
        
        int mid = low + ((high - low)/2);
        
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = recurse(nums, low, mid - 1);
        node->right = recurse(nums, mid + 1, high);
        
        return node;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recurse(nums, 0, nums.size() - 1);
    }
};
