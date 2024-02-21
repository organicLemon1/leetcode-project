/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode* locA=list1;
    struct ListNode* locB=list1;
    for(int i=0; i<(a-1); i++) {
        locA=locA->next;
    }
    for(int i=0; i<(b+1); i++) {
        locB=locB->next;
    }
    locA->next=list2;
    struct ListNode* tail_list2=list2;
    while(tail_list2->next!=NULL) {
        tail_list2=tail_list2->next;
    }
    tail_list2->next=locB;
    return list1;
}