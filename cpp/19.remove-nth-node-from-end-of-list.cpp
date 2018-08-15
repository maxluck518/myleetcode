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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * Head = new ListNode(0);
        Head->next = head;
        ListNode * p1 = head;
        ListNode * p2 = head;
        ListNode * p3 = Head;
        for(int i = 0;i<n;i++){
            p1 = p1->next;
        }
        while(p1 != NULL){
            p3 = p3->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        p3->next = p2->next;
        return Head->next;
    }
};
