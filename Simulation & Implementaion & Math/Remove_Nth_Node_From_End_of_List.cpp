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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        if (head->next == NULL && n == 1) return NULL;
        
        ListNode* now = head;
        ListNode* l = head;
        
        int idx = 0;
        
        while (now->next != NULL) {
            idx++;
            now = now->next;
        }
        
        if (idx == n - 1) {
            head = head->next;
            return head;
        }
        
        now = head;
        
        for (int i = 1; i < idx - n + 1; i++) {
            now = now->next;
        }
        
        now->next = now->next->next;
        return head;
    }
};