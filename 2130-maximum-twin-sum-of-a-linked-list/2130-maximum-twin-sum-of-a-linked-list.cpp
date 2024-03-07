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
    //middle node finding
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next){
            slow=slow->next; fast=fast->next->next;
        }
        return slow;
    }
    
    //reverse list
    ListNode* revlist(ListNode* head){
        ListNode* p, *q;
        p=head, q=NULL;
        while(p!=NULL){
            ListNode* neww= p->next;
            p->next=q;
            q=p;
            p=neww;
        }
        return q;
    }
    
    int pairSum(ListNode* head) {
       ListNode* mid= middleNode(head);
        ListNode* p=head, *q=revlist(mid->next);
        
        mid->next=NULL;
        
        int ans=0;
        while(p!=NULL && q!=NULL){
            ans= max(ans, p->val + q->val);
            p=p->next; q=q->next;
        }
        return ans;
    }
};