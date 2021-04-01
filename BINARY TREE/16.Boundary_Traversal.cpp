vector<int> ans;
void printLeft(Node *root){
    if(!root) 
     return;
    if(root->left){
         //cout<<root->data<<" ";
         ans.push_back(root->data);
        printLeft(root->left);
    }
    else if(root->right){
        //cout<<root->data<<" ";
        ans.push_back(root->data);
        printLeft(root->right);
    }
}

void printLeaf(Node *root){
    if(root==NULL) 
     return;
    printLeaf(root->left);
     if(root->left==NULL && root->right==NULL){
        //cout<<root->data<<" ";
        ans.push_back(root->data);
    }
    printLeaf(root->right);
}

void printRight(Node *root){
     if(!root) 
      return;
    if(root->right){
        printRight(root->right);
          //cout<<root->data<<" ";
          ans.push_back(root->data);
    }
    else if(root->left){
        printRight(root->left);
         //cout<<root->data<<" ";
         ans.push_back(root->data);
    }
}



vector<int> printBoundary(Node *root)
{
    ans.clear();
    if(!root) return ans;
    //cout<<root->data<<" ";
    ans.push_back(root->data);
     printLeft(root->left);
     printLeaf(root);
     printRight(root->right);
     
     return ans;
}