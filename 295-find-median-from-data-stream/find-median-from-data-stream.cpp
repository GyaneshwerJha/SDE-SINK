class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int cnt;
    MedianFinder() {
        cnt = 0;
    }
    
    void addNum(int num) {
        if(max_heap.empty() || max_heap.top() > num){
            max_heap.push(num);
            cnt++;
        }
        else{
            min_heap.push(num);
            cnt++;
        }
        
        if(max_heap.size() > min_heap.size() + 1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(min_heap.size() > max_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(cnt % 2 == 0){
            return (double)((min_heap.top() + max_heap.top()) / 2.0);
        }

        return max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */