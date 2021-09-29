class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1;
        int len = 0;
        while(len!=a-1){
            head = head->next;
            len++;
        }

        ListNode* beg = head;
        while(len!=b){
            head = head->next;
            len++;
        }

        ListNode* end = head->next;
        beg->next = list2;
        ListNode* cur = list2;
        while(cur->next!=nullptr){
            cur = cur->next;
        }

        cur->next = end;
        return list1;

    }
};