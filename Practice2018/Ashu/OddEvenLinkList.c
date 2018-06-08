/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void moveOddNode(struct ListNode* LastOddNode_ptr,struct ListNode* MoveOddNode_ptr,struct ListNode*  LastEvenNode_ptr)
{
    LastEvenNode_ptr->next = MoveOddNode_ptr->next;
    MoveOddNode_ptr->next = LastOddNode_ptr->next;
    LastOddNode_ptr->next = MoveOddNode_ptr;
}

struct ListNode* oddEvenList(struct ListNode* head) {
     struct ListNode *LastOddNode_ptr;
     struct ListNode *LastEvenNode_ptr;
     struct ListNode *MoveOddNode_ptr;
    

    LastOddNode_ptr = head;
    LastEvenNode_ptr = LastOddNode_ptr->next;
    
    while ( LastEvenNode_ptr != NULL) {
            MoveOddNode_ptr = LastEvenNode_ptr->next;
            if (MoveOddNode_ptr == NULL)
                     break;
            
            moveOddNode(LastOddNode_ptr, MoveOddNode_ptr, LastEvenNode_ptr);
            LastOddNode_ptr = LastOddNode_ptr->next;
            LastEvenNode_ptr = LastEvenNode_ptr->next;
    }
    return head;
}


