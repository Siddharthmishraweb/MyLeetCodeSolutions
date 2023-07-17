/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head){
        int cnt = 0;
        while(head != NULL){
            cnt++;
            head = head -> next;
        }
        return cnt;
    }
    ListNode* reverseLL(ListNode* head){
        int len = length(head);
        if(head == NULL || head -> next == NULL) return head;
        ListNode* current = head;
        ListNode* prev = NULL;
        while(current != NULL){
            ListNode* temp = current -> next;
            current -> next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* newHead = new ListNode(head -> val);
        ListNode* temp = head;
        int cnt = 0;
        ListNode* prev = head;
        while(temp != NULL && temp -> next != NULL){
            ListNode* newNode = new ListNode(temp -> next -> val);
            if(cnt == 0)
              newHead -> next = newNode;
            else
                prev -> next = newNode;
            cnt++;
            prev = newNode;
            temp = temp -> next;
        }
        ListNode* reverseHead = reverseLL(newHead);
        while(reverseHead != NULL){
            if(reverseHead -> val != head -> val) return false;
            reverseHead = reverseHead -> next;
            head = head -> next;
        }
        return true;
    }
};