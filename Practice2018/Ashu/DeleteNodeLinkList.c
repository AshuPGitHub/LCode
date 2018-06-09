/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* ptrNodeNext;
    
    if(!node)
        return node;

    /* node is never a tail, so it points to some none-Null node*/
    ptrNodeNext = node->next;
    node->val = ptrNodeNext->val;
    node->next = ptrNodeNext->next;
}
