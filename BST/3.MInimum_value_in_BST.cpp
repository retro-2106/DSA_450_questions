int minValue(Node* root)
{
    Node *current = root;
    
    while(current && current->left != NULL)
    {
        current = current->left;
    }
    return current->data;
}