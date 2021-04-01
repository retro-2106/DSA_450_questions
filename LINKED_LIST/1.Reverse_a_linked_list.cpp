struct Node* reverseList(struct Node *head)
{
    if(!head || head->next == NULL)
    return head;
    
    struct Node* temp = reverseList(head->next);
    
    head->next->next = head;
    head->next = NULL;
    return temp;
}

//Iterative

struct Node* reverse(struct Node *head)
{
	if(!head || head->next == NULL)
		return head;

	struct Node* prev=NULL;
	struct Node *current=head;
	struct Node *next = NULL;


	while(current != NULL)
	{
		next = current->next;
		current->next = prev;

		prev = current;
		current = next;
	}

	return prev;
}