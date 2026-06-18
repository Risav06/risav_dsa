/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(x) : val(x), next(nullptr) {}
 * ListNode(x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // Dummy node to anchor the result list
        ListNode* tail = &dummy;
        int carry = 0;
        
        // Loop as long as there are digits left to add or a carry-over remains
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;
            
            // Calculate sum and carry
            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            
            // Create a new node with the calculated digit
            tail->next = new ListNode(digit);
            tail = tail->next;
            
            // Move to the next nodes if they exist
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        
        return dummy.next; // The actual list starts after the dummy node
    }
};