void traverse(Node *root,unordered_set<int> &all_nodes,unordered_set<int> &leaf_nodes)
{
    if(root == NULL)
    return;
    
    all_nodes.insert(root->data);
    
    if(root->left == NULL && root->right == NULL)
    {
        leaf_nodes.insert(root->data);
        return;
    }
    
    traverse(root->left,all_nodes,leaf_nodes);
    traverse(root->right,all_nodes,leaf_nodes);
}

bool isDeadEnd(Node *root)
{
    if(root == NULL)
    return false;
   unordered_set<int> all_nodes,leaf_nodes;
   all_nodes.insert(0);
   traverse(root,all_nodes,leaf_nodes);
   
   for(auto it = leaf_nodes.begin();it != leaf_nodes.end(); it++)
   {
       int a = *it;
       
       if(all_nodes.find(a+1) != all_nodes.end() && all_nodes.find(a-1) != all_nodes.end())
       return true;
   }
   
   return false;
}
