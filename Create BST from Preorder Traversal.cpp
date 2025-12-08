














class Solution {
public:
    TreeNode* recurse(vector<int>& preorder, int start, int end) {
        
        if(start > end){
            return NULL;
        }
        
        if(start == end){
            TreeNode* node = new TreeNode(preorder[start]);
            return node;
        }
        
        TreeNode* node = new TreeNode(preorder[start]);
        
        int mid = -1;
        
        for(int i = start + 1 ; i <= end ; i++){
            if(preorder[i] > preorder[start]){
                mid = i;
                break;
            }
        }
        
        if(mid == -1){
            node->left = recurse(preorder, start + 1, end);
        }else{
            node->left = recurse(preorder, start + 1, mid - 1);
            node->right = recurse(preorder, mid, end);
        }
    
        return node;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return recurse(preorder, 0, preorder.size() - 1);
        
    }
};













class Solution {
public:
    TreeNode* builtTree(vector<int>& preorder, int &index, int upper_bound) {
        
        int N = preorder.size();
        
        if(index == N || preorder[index] > upper_bound)
            return NULL;
        
        TreeNode *node = new TreeNode(preorder[index++]);
        node->left = builtTree(preorder, index, node->val);
        node->right = builtTree(preorder, index, upper_bound);
        
        return node;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int index = 0;
        int upper_bound = INT_MAX;
        return builtTree(preorder, index, upper_bound);
        
    }
};
