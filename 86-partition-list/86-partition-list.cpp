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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *temp = new ListNode(-1);
        
        ListNode *sm = head;
        ListNode *lg = head;
        
        ListNode *start = temp;
        
        int idx = 0;
        
        vector<int> small;
        vector<int>large;
        
       // cout << large.size() << endl;
        
        while(head != nullptr) {
            if(head->val >= x){
                large.push_back(idx);
            }
            if(head->val < x){
                small.push_back(idx);
            }
            head = head -> next;
            idx++;
        }
        
        idx = 0;
        int turn = 0;
        
        //cout << "sm - " << small.size() << endl;
        
        if(small.size() > 0){
            while(sm != nullptr) {
                if(idx == small[turn]){
                    //cout << "lg - " << sm->val << endl;
                    ListNode *t = new ListNode(sm->val);
                    temp -> next = t;
                    temp = temp -> next;
                    turn++;
                }
                sm = sm -> next;
                idx++;
                
                if(turn == small.size()) break;
                
            }    
        }
        
        idx = 0;
        turn = 0;
        
        //cout << "lg - " << large.size() << endl;
        
        if(large.size() > 0){
            while(lg != nullptr) {
                if(idx == large[turn]){
                    ListNode *t = new ListNode(lg->val);
                    temp -> next = t;
                    temp = temp -> next;
                    turn++;
                }
                lg = lg -> next;
                idx++;
                
                if(turn == large.size()) break;
            }    
        }
        
        return start->next;
    }
};