/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    
    struct ListNode *oddList;
    struct ListNode *evenList;
    struct ListNode *tmpOddList;
    struct ListNode *tmpEvenList;
    struct ListNode *tmpList;
    
    if(head == NULL)
    {
        return head;
    }
    tmpOddList = oddList = head;
    if(oddList != NULL)
    {
        tmpEvenList = evenList = oddList->next;
    }
    while(head != NULL && oddList != NULL && evenList != NULL)
    {
        if(oddList->next != NULL)
        {
            oddList->next = oddList->next->next;
        }
        if (evenList != NULL && evenList->next != NULL)
        {
            evenList->next = evenList->next->next;
        }
        head = oddList->next;
        oddList = oddList->next;
        evenList = evenList->next;
    }
    
    tmpList = tmpOddList;
    
    while(tmpList->next != NULL)
    {
        tmpList = tmpList->next;
    }
    tmpList->next = tmpEvenList;
    return tmpOddList;
    
}