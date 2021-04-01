Node * mergeKLists(Node *arr[], int N)
{
       vector<Node*> lists;
       for(int i=0;i<N;i++)
       {
           lists.push_back(arr[i]);
       }
       Node *point = new Node(0);
        Node *head = point;
        priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;
        for(auto a : lists)
        {
            if(a)
            {
                pq.push(make_pair(a->data,a));
            }
        }
        while(!pq.empty())
        {
            pair<int,Node*> top = pq.top();
            pq.pop();
            int val = top.first;
            Node *node = top.second;
            point->next = new Node(val);
            point = point->next;
            node = node->next;
            if(node)
            {
                pq.push(make_pair(node->data,node));
            }
        }
        return head->next;
}