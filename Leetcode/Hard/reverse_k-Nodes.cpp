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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }
        if (count < k) {
            return head;
        }
        // step 1 reverse 1st K nodes

        ListNode* next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        count = 0;
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // step 2 recursion
        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};