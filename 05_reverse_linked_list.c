/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev=NULL;
    struct ListNode* next=NULL;
    struct ListNode* current=head;
    while(current!=NULL) {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    prev=NULL;
    return head;
}