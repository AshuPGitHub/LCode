/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define TRUE 1
#define FALSE 0
bool isPalindrome(struct ListNode* head) {
    
    int count = 0;
    struct ListNode* curr  = head;
    struct ListNode* t1;
    struct ListNode* t2;
    struct ListNode* startSecond;
    int isPal = TRUE;
    int i = 0;
    
    // Count the element in link list
    while(curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    curr = head;
    
    t1 = NULL; // this will carry the pointer to reversed first half;
    // Reverse the first half of list    
    for ( i= 0; i< count/2 ;i++)
    {
        t2 = curr->next;
        curr->next = t1;
        t1 = curr;
        curr = t2;        
    }
    
    // Store t1 in t2 we need this later to reverse back the list
    t2 = t1;
    // Now curr is pointer to second half
    if ( count % 2 == 0)
    {
        startSecond = curr;
    }
    else
    {
        startSecond = curr->next;
    }
    
    while(t1 != NULL)
    {
        if (t1->val != startSecond->val)
        {
            isPal = FALSE;
            break;
        }
        t1 = t1->next;
        startSecond = startSecond->next;
    }
    
    // Reverse back the first half and restore the list
    
    t1 = curr; // this will carry the pointer to second half;
    curr = t2; // Pointer to first half
    // Reverse the first half of list    
    for ( i= 0; i< count/2 ;i++)
    {
        t2 = curr->next;
        curr->next = t1;
        t1 = curr;
        curr = t2;        
    }
    return isPal;
}
