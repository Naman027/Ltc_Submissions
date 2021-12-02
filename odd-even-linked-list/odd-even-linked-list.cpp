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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr) return head;
        if(head->next==nullptr) return head;
        
        ListNode* fir=head;
        ListNode* sec=head->next;
        ListNode* ans=fir;
        ListNode* j=head->next;
        while(sec!=NULL && sec->next!=nullptr){
            fir->next=sec->next;
            fir=fir->next;
            sec->next=fir->next;
            
            sec=sec->next;
        }
        
        fir->next=j;
        if(sec!=nullptr)
        sec->next=nullptr;
        
        return ans;    
         
    }
};