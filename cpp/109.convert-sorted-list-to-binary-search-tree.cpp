/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode * lchild;
        TreeNode * rchild;
        ListNode * fast = head;
        ListNode * slow = nullptr;
        ListNode * head2 = nullptr;
        ListNode * mid = nullptr;

        if(head == nullptr)
            return nullptr;
        else if(head->next == nullptr){
            TreeNode * root = new TreeNode(head->val);
            return root;
        }
        /* split */
        // while(fast->next != nullptr && fast != nullptr){
        while(fast != nullptr){
            if(fast->next == nullptr)
                break;
            fast = fast->next->next;
            slow = slow == nullptr ? head : slow->next;
        }
        mid = slow == nullptr ? nullptr : slow->next;
        head2 = mid == nullptr ? nullptr : mid->next;
        if(slow != nullptr)
            slow->next = nullptr;
        /* mid search */
        lchild = sortedListToBST(head);
        TreeNode * root = new TreeNode(mid->val);
        rchild = sortedListToBST(head2);
        root->left = lchild; 
        root->right = rchild; 
        return root;
    }
};
