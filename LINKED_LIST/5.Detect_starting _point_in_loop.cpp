Node *find_start(Node *head)
{
	if(!head || head->next == NULL)
	return head;

Node *slow,*fast;
slow = head;
fast = head;
	
	while(slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			break;
	}

	if(slow != fast)
		return head;

	slow = head;

	while(slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}