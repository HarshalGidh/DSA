#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Info {
public:
    char val;
    int count;
    Info(char str, int freq) : val(str), count(freq) {};
};

class compare {
public:
    bool operator()(Info a, Info b) {
        return a.count < b.count;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        //create a Max Heap to store char and its freq:
        priority_queue<Info, vector<Info>, compare> pq;
        if (a > 0) {
            Info temp('a', a);
            pq.push(temp);
        }
        if (b > 0) {
            Info temp('b', b);
            pq.push(temp);
        }
        if (c > 0) {
            Info temp('c', c);
            pq.push(temp);
        }
        //create a string ans and insert Happy String :
        string ans = "";
        while (pq.size() > 1) {
            Info first = pq.top();
            pq.pop();
            Info second = pq.top();
            pq.pop();
            if (first.count >= 2) { //inserting 2 times
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.count -= 2;
            }
            else { //inserting once
                ans.push_back(first.val);
                first.count--;
            }
            if (second.count >= 2 && second.count >= first.count) {
                //inserting twice only when second count >=2 and >=first.count so that we can 
                //consume both elements faster,else we will only consume first(max) count fast
                ans.push_back(second.val);
                ans.push_back(second.val);
                second.count -= 2;
            }
            else {
                //insert once
                ans.push_back(second.val);
                second.count--;
            }
            //reinsert elements in Heap
            if (first.count > 0) pq.push(first);
            if (second.count > 0) pq.push(second);
        }
        if (pq.size() == 1) {//if a char is remaining:
            Info rem = pq.top();
            pq.pop();
            if (rem.count >= 2) { //inserting 2 times
                ans.push_back(rem.val);
                ans.push_back(rem.val);
                rem.count -= 2;
            }
            else { //inserting once
                ans.push_back(rem.val);
                rem.count--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int a = 1, b = 1, c = 7;
    cout << "Input: a = " << a << ", b = " << b << ", c = " << c << endl;
    string result = sol.longestDiverseString(a, b, c);
    cout << "Output: \"" << result << "\"" << endl;
    return 0;
}
