#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Node* helper(Node* node,unordered_map<Node*,Node*> &mp)
{
    if(node==NULL)
    {
        return NULL;
    }
    
    Node* clone = new Node(node->val);
    
    mp[node]=clone;
    
    for(auto n : node->neighbors)
    {
        if(!mp.count(n))
        {
            Node* y = helper(n,mp);
            (clone->neighbors).push_back(y);
        }
        else
        {
            (clone->neighbors).push_back(mp[n]);
        }
    }
    
    return clone;
    
}

Node* cloneGraph(Node* node) {
    
    unordered_map<Node* , Node*> mp;
    
    return helper(node,mp);
    
}
};
