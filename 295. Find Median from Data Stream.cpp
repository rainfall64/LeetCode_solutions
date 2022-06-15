class MedianFinder {
private:
    priority_queue<int> small; // max heap
    priority_queue<int, vector<int>, greater<int>> large; // min heap
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        
        if (!small.empty() && !large.empty() && small.top() > large.top())
        {
            large.push(small.top()); small.pop();            
        }
        
        if (small.size() > large.size() + 1)
        {
            large.push(small.top()); small.pop();
        }
        
        if (large.size() > small.size() + 1)
        {
            small.push(large.top()); large.pop();
        }
    }
    
    double findMedian() {
        if (small.size() > large.size()) // odd number of element
        {
            return small.top();
        }
        else if (large.size() > small.size()) // odd number of elements
        {
            return large.top();
        }
        return (small.top() + large.top()) / 2.0; // even number of elements
    }
};