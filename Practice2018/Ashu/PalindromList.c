/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void printList(struct ListNode* head)
{
    
    while(head != NULL) {
            printf("head->val: %d \n", head->val);
            head = head->next;
    }
        


    
}
struct ListNode* reverseList(struct ListNode** head)
{
    struct ListNode* first;
    struct ListNode* second;
    struct ListNode* third;
    
    if(!head)
        return NULL;
    
    first = NULL;
    second = *head;
    third = second->next;
    
    //printf("second->val:%d third->val:%d\n", second->val, third->val);
    
    while (third != NULL) {
           second->next = first;
           first = second;
           second = third;
           third = third->next;

           second->next = first; 
    }
    *head = second;
    return *head;
}

bool isPalindrome(struct ListNode* head) {
   
    struct ListNode* fast;
    struct ListNode* slow;
    struct ListNode* orig_first_half;
    struct ListNode* reversed_half_list;

    fast = slow = orig_first_half = head;
    
    if ( !fast || !fast->next )
        return true;
    
    #if 0
    if ( !fast->next || !fast->next->next ) 
            return false;
    #endif
    
    
   // printf("ORIG LIST \n");
    //printList(fast);
    
    while ( fast->next != NULL)
    {        
        if(fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        else {
               break;
        }
    }
    
    reversed_half_list = reverseList(&(slow->next));

     slow->next = NULL;
    
  //  printf("ORIG LIST AGAIN \n");
   //  printList(orig_first_half);
    
    //printf("REVERSE LIST \n");


    // printList(reversed_half_list);



    
    while(reversed_half_list != NULL){
    
       // printf("reversed_half_list->val:%d", reversed_half_list->val);
         //  printf("orig_first_half->val:%d", orig_first_half->val);


        if(reversed_half_list->val != orig_first_half->val) {
        //    printf("return false");
        
                return false;
        }
        
        reversed_half_list = reversed_half_list->next;
        orig_first_half = orig_first_half->next;
    }
    return true;
}
