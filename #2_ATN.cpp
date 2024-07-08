#include <bits/stdc++.h>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 != nullptr && l2 != nullptr){
            int c = l1->val+l2->val;
            if(l1->next != nullptr)
                l1->next->val =l1->next->val+ (c-(c%10))/10;
            else if(l2->next != nullptr)
                l2->next->val =l2->next->val+ (c-(c%10))/10;
            return new ListNode(c%10, addTwoNumbers(l1->next, l2->next));
        }
        else{
            if(l1 != nullptr){
                int c = l1->val;
                if(l1->next != nullptr)
                    l1->next->val =l1->next->val+ (c-(c%10))/10;
                return new ListNode(c%10, addTwoNumbers(l1->next, new ListNode(0)));
            }
            else if(l2 != nullptr){
                int c = l2->val;
                if(l2->next != nullptr)
                    l2->next->val =l2->next->val+ (c-(c%10))/10;
                return new ListNode(c%10, addTwoNumbers(new ListNode(0), l2->next));
            }
        }

        return nullptr;
    }
};

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

// Example usage
int main() {

    Solution s;
    // Creating a linked list: 1 -> 2 -> 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *head = s.addTwoNumbers(l1, l2);
    // Print the linked list
    printList(head);

    // Freeing allocated memory
    /*while (l1 != nullptr) {
        ListNode* temp = l1;
        l1 = l1->next;
        delete temp;
    }*/

    return 0;
}