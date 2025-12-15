













class Solution {
public:
    TreeNode* buildBalancedBST(vector<int>& numbers, int leftIndex, int rightIndex){
        if(leftIndex > rightIndex)
            return NULL;
        
        int middleIndex = leftIndex + ((rightIndex - leftIndex)/2);
        
        TreeNode* node = new TreeNode(numbers[middleIndex]);
        node->left = buildBalancedBST(numbers, leftIndex, middleIndex - 1);
        node->right = buildBalancedBST(numbers, middleIndex + 1, rightIndex);
        
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& numbers) {
        return buildBalancedBST(numbers, 0, numbers.size() - 1);
    }
};
