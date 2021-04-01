struct compare {
    bool operator()(struct Node* p1, struct Node* p2)
    {
        return p1->data > p2->data;
    }
};
 
struct Node* sortAKSortedDLL(struct Node* head, int k)
{
    if (head == NULL)
        return head;

    priority_queue<Node*, vector<Node*>, compare> pq;
 
    struct Node* newHead = NULL, *last;

    for (int i = 0; head != NULL && i <= k; i++) {
        pq.push(head);
        head = head->next;
    }
    while (!pq.empty()) {
        if (newHead == NULL) {
            newHead = pq.top();
            newHead->prev = NULL;

            last = newHead;
        }
 
        else {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
        pq.pop();

        if (head != NULL) {
            pq.push(head);
            head = head->next;
        }
    }
    last->next = NULL;
    return newHead;
}