/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head1 = l1;
        ListNode *head2 = l2;
        ListNode *head = new ListNode(0);
        ListNode *pos= head;
        while(head1 != NULL && head2 != NULL){
            if(head1->val < head2->val){
                pos->next = head1;
                head1 = head1 -> next;
                pos = pos->next;
            }
            else{
                pos->next = head2;
                head2 = head2 -> next;
                pos = pos->next;
            }
        }

        if(head1 == NULL){
            pos->next = head2;
        }
        else{
            pos->next = head1;
        }
       return head->next; 
    }
};
