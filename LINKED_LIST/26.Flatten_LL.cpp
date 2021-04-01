Node *merge(Node  *a,Node *b)
{
    if(a == NULL)
    return b;
    
    if(b == NULL)
    return a;
    
    Node *ans;
    
    if(a->data < b->data)
    {
        ans = a;
        ans->bottom =  merge(a->bottom,b);
    }
    else
    {
        ans = b;
        ans->bottom = merge(b->bottom,a);
    }
    
    ans->next = NULL;
    return ans;
}
    
Node *flatten(Node *root)
{
   if(root == NULL || root->next == NULL)
   return root;
   
   return merge(root,flatten(root->next));
}