#include <iostream>
#include<queue>
#include<vector>
using namespace std;
class MedianFinder {
private:
    double median;
    vector<int> dataStream;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        //initialising Median 
        double median = 0;
    }
    
    void addNum(int num) {
        dataStream.push_back(num);
        if(maxHeap.size() == minHeap.size()){
            if(num > median){ //
                minHeap.push(num);
                median = minHeap.top();
            }
            else{//
                maxHeap.push(num);
                median = maxHeap.top();
            }
        }
        else if(maxHeap.size() == minHeap.size() + 1){
            if(num > median){ //
                minHeap.push(num);
            }
            else{//
                int maxTop = maxHeap.top();
                maxHeap.pop();
                minHeap.push(maxTop);
                maxHeap.push(num);
            }
            median = (maxHeap.top() + minHeap.top())/2.0 ;
        }
        else if(minHeap.size() == maxHeap.size() + 1){
            if(num > median){
                int minTop = minHeap.top();
                minHeap.pop();
                maxHeap.push(minTop);
                minHeap.push(num);
            }
            else{
                maxHeap.push(num);
            }
            median = (maxHeap.top() + minHeap.top())/2.0 ;
        }
    } 
    double findMedian() {
      return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main() {
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    cout << medianFinder.findMedian() << endl;  // Output: 1.5
    medianFinder.addNum(3);
    cout << medianFinder.findMedian() << endl;  // Output: 2.0

    return 0;
}