class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        if(head == NULL || head->next ==NULL)
            return head;
        
        ListNode *slow,*fast;
        
        slow = head;
        fast = head;
        
        while(fast && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};