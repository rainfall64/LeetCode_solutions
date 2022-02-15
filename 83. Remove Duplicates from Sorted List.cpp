/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) // if head == NULL
            return head;
        ListNode* curr = head;
        while (curr->next)
        {
            if (curr->val == curr->next->val)
                curr->next = curr->next->next; // if two consecutive values are same skip second node
            else
                curr = curr->next; // otherwise go to next node
        }
        return head;
    }
};