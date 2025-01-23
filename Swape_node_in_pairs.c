/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode*ptr1,*ptr2;
    if(head==NULL || head->next==NULL){
        return head;
    }
    ptr1=head;
    ptr2=head->next;
    if(ptr1==head){
        ptr1->next=ptr2->next;
        ptr2->next=ptr1;
        head=ptr2;
        ptr2=ptr1->next;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr2->next==NULL){
            return head;
        }
        ptr1->next=ptr2->next;
        ptr2->next=ptr1->next->next;
        ptr1->next->next=ptr2;
        ptr1=ptr2;
        ptr2=ptr1->next;
    }
    return head;
}