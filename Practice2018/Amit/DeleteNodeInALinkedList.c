/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    
    if(node != NULL && node->next != NULL)
    {
        struct ListNode* toFree;
        node->val = node->next->val;
        toFree = node->next;
        node->next = node->next->next;
        free(toFree);
    }
    
}
