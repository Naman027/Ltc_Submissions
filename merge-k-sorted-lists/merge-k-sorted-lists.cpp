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
    struct comp{
    bool operator()(const ListNode* l1,const ListNode* l2){
        return l1->val>=l2->val; 
        }
    };

    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;
        
        priority_queue<ListNode*,vector<ListNode*>,comp> pq;
        
        for(int i=0;i<k;i++){
            if(lists[i]!=nullptr)
                pq.push(lists[i]);
        }
        
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(!pq.empty()){
            ListNode* cur=pq.top();
            pq.pop();
            temp->next=cur;
            temp=temp->next;
            if(cur->next!=NULL) pq.push(cur->next);
            
        }
        temp->next=NULL;
        return ans->next;
        
    }
};