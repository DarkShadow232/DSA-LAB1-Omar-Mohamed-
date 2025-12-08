












class Solution {
public:
    
    TreeNode* recurse(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node->val == p->val || node->val == q->val || (node->val > p->val && node->val < q->val)){
            return node;
        }else if(node->val > p->val && node->val > q->val){
            return recurse(node->left, p, q);
        }else{
            return recurse(node->right, p, q);
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(p->val < q->val)
            return recurse(root, p, q);
        else
            return recurse(root, q, p);
    }
};
