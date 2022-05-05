class MyStack {
public:
    queue<int>r;
    queue<int>q;
    queue<int>q1;
    int c=0;
    MyStack() {
    }
    void push(int x) { 
        q.push(x);
        int d=q.size();
        while(d>1){
            int f=q.front();
            q.pop();
            q.push(f);
            d--;
        }
    }
    
    int pop() {
        cout<<q.size();
        int a=q.front();
        q.pop();
        return a;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

