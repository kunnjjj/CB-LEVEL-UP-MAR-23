// https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder {
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int,vector<int>,greater<int>> rightMinHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftMaxHeap.empty())
        {
            leftMaxHeap.push(num);
        }
        else if(num < leftMaxHeap.top())
        {
            leftMaxHeap.push(num);
        }
        else
        {
            rightMinHeap.push(num);
        }
        // left=4, right=2
        // if(4 > 1+ 2)
        if(leftMaxHeap.size() > 1 + rightMinHeap.size())
        {
            int toShift=leftMaxHeap.top();
            leftMaxHeap.pop();
            rightMinHeap.push(toShift);
        }
        else if(rightMinHeap.size() > 1 + leftMaxHeap.size())
        {   
            int toShift=rightMinHeap.top();
            rightMinHeap.pop();
            leftMaxHeap.push(toShift);
        }
    }
    
    double findMedian() {
        if(leftMaxHeap.size() > rightMinHeap.size())
        {
            return leftMaxHeap.top();
        }
        else if(leftMaxHeap.size() < rightMinHeap.size())
        {
            return rightMinHeap.top();
        }
        else //left=4, right=5
        {
            // TAKE CARE OF DOUBLE VALUES (int/int case)
            return (leftMaxHeap.top() + rightMinHeap.top())/2.0;
        }

        // auto DS=leftMaxHeap;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */