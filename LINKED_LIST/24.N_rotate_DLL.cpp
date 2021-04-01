void rotate(struct Node** head_ref, int N) 
{ 
    if (N == 0) 
        return; 
    struct Node* current = *head_ref; 

    int count = 1; 
    while (count < N && current != NULL) { 
        current = current->next; 
        count++; 
    } 

    if (current == NULL) 
        return; 

    struct Node* NthNode = current; 
 
    while (current->next != NULL) 
        current = current->next; 

    current->next = *head_ref; 

    (*head_ref)->prev = current; 

    *head_ref = NthNode->next; 

    (*head_ref)->prev = NULL; 

    NthNode->next = NULL; 
}