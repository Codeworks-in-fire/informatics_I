#include <stack>
class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> store;
    stack<int> act;
    void push(int x) {
        store.push(x); 
       
    }
    int temp;
    int pop() {
        if (act.empty()) {
            while (!store.empty()) {
                act.push(store.top());
                store.pop();
            }
        }
        temp = act.top();
        act.pop();
        return temp;

    }
    
    int peek() {
        if (act.empty()) {
            while (!store.empty()) {
                act.push(store.top());
                store.pop();
            }
        } 
        return act.top();
    }
    
    bool empty() {
        if (act.empty() && store.empty()) {
            return true;
        } else {
            return false;
        }
    }
};