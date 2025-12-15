









void findPreSuc(Node* root, Node*& predecessor, Node*& successor, int targetKey)
{
    if (root == NULL) return;

    if (root->key == targetKey)
    {
        if (root->left != NULL)
        {
            Node* current = root->left;
            while (current->right)
                current = current->right;
            predecessor = current;
        }

        if (root->right != NULL)
        {
            Node* current = root->right;
            while (current->left)
                current = current->left;
            successor = current;
        }
        return;
    }

    if (root->key > targetKey)
    {
        successor = root;
        findPreSuc(root->left, predecessor, successor, targetKey);
    }
    else 
    {
        predecessor = root;
        findPreSuc(root->right, predecessor, successor, targetKey);
    }
}
