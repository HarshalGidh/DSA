#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0); // Dummy node to handle edge cases
        dummy->next = head;
        ListNode* temp = dummy;
        
        while (temp) {
            int sum = 0;
            ListNode* curr = temp->next;
            while (curr) {
                sum += curr->val;
                if (sum == 0) {
                    temp->next = curr->next; // Remove the sublist
                }
                curr = curr->next;
            }
            temp = temp->next; // Move to the next node
        }
        
        return dummy->next; // Return the head of the modified list
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    Solution sol;
    ListNode* modifiedHead = sol.removeZeroSumSublists(head);
    printList(modifiedHead); // Output: 3 1
    return 0;
}
