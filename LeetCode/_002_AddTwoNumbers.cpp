/*
 https://leetcode.com/problems/add-two-numbers/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int firstLength = getLength(l1);
        int secondLength = getLength(l2);
        
        ListNode* bigger = firstLength > secondLength ? l1 : l2;
        ListNode* smaller = firstLength > secondLength ? l2 : l1;
        
        ListNode* pre = nullptr;
        int carry = 0;
        
        while (bigger != nullptr) {
            int a = bigger->val;
            int b = smaller ? smaller->val : 0;
            
            bigger->val = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            
            pre = bigger;
            bigger = bigger->next;
            smaller = smaller ? smaller->next : nullptr;
        }
        
        pre->next = carry ? new ListNode(1) : nullptr;
        return firstLength > secondLength ? l1 : l2;    
    }
private:
    int getLength(ListNode* node) {
        int length = 0;
        while (node->next != nullptr) {
            length++;
            node = node->next;
        }
        
        return length;
    }
};