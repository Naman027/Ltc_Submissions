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
    
    ListNode* rev(ListNode* root){
        ListNode* cur=root;
        ListNode* temp=root;
        ListNode* prev=NULL;
        
        while(temp!=NULL){
            temp=temp->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
            
        }
        
        return prev;
        
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL || head->next==NULL || m==n) return head;
        
        ListNode* temp=head;
        ListNode* temp2=head;

        
        int i=1;
        while(i<m-1){
            temp=temp->next;
            i++;
        }
        
        ListNode* first=temp->next;
        if(m==1) first=head;
        
        i=1;
        while(i<n){
            temp2=temp2->next;
            i++;
        }
        if(m!=1) temp->next=NULL;
        
        ListNode* last=temp2->next;
        temp2->next=NULL;
        
        ListNode* ans=rev(first);
        if(m!=1)
            temp->next=ans;
        else{
            head=ans;
        }
        while(ans->next!=NULL) ans=ans->next;
        
        ans->next=last;
        return head;
        
    }
};