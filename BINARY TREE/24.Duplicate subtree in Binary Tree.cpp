unordered_set<string> subtrees;

string helper(Node *root)
{
    string s = ""; 
 
    if (root == NULL) 
        return s + '$'; 
 
    string lStr = helper(root->left); 
    if (lStr == s) 
    return s; 
 
    string rStr = helper(root->right); 
    if (rStr == s) 
    return s; 

    s = s + root->data + lStr + rStr; 

    if (s.length() > 3 && subtrees.find(s) != subtrees.end()) 
    return ""; 
 
    subtrees.insert(s); 
 
    return s; 
}

bool dupSub(Node *root)
{
    subtrees.clear();
     string str = helper(root);
     if(str.compare("") == 0)
     {
         return true;
     }
     return false;
}