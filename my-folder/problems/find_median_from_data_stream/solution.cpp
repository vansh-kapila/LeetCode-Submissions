class MedianFinder {
public:
    priority_queue<int> half1;
    priority_queue<int,vector<int>,greater<int>> half2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(half1.empty() and half2.empty())
        {
            half1.push(num);
            return;
        } 
        
        if(num<=half1.top())
        {
            half1.push(num);
        }
        else
        {
            half2.push(num);
        }
    }
    
    double findMedian() {
        while(half1.size()<half2.size())
        {
            int x = half2.top(); 
            half2.pop();
            half1.push(x);
        }
        while(half1.size()>1+half2.size())
        {
            int x = half1.top();
            half1.pop();
            half2.push(x);
        }
        if((half1.size()+half2.size())%2)
        {
            return (double)half1.top();
        } 
        return (double)(half1.top()+half2.top())/(double)(2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */