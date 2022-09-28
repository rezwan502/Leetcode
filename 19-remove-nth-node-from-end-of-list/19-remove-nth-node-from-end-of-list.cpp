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
        ListNode* prev;
        ListNode* next;
  
        prev = head;
        next = head;
        
        while(n--) {
            next = next -> next;
        }
        
        if(!next) {
            return head->next;
        }
        
        while(next->next) {
            next = next -> next;
            prev = prev->next;
        }
        
        prev->next = prev->next->next;
        
        return head;
    }
};