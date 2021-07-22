class MinStack {
public:
    /** initialize your data structure here. */
    
    class Node{
    public:
        int val;
        int minimum;
        Node* next;
    };
    
    Node* head;
    
    MinStack() {
        head=nullptr;
    }
    
    void push(int val) {
        if(head==nullptr){
            Node* newnode = new Node();
            newnode->val = val;
            newnode->minimum = val;
            newnode->next = NULL;
            head = newnode;
        }
        else{
            Node* newnode = new Node();
            newnode->val = val;
            newnode->minimum = min(val,head->minimum);
            newnode->next = head;
            head = newnode;
        }
        
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */