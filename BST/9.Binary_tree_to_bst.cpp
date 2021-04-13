void inorder(Node root,vectorint & arr)
{
    if(root == NULL)
    return;
    
    inorder(root-left,arr);
    arr.push_back(root-data);
    inorder(root-right,arr);
}

void update(Node root,vectorint &arr,int i)
{
    if(root == NULL)
    return;
    
    update(root-left,arr,i);
    
    root-data = arr[i];
    i += 1;
    
    update(root-right,arr,i);
}

Node binaryTreeToBST (Node root)
{
    vectorint arr;
    inorder(root,arr);
    
    sort(arr.begin(),arr.end());
    
    int i=0;
    
    update(root,arr,&i);
    return root;
}
