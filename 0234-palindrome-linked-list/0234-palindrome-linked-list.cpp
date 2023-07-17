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
    ListNode* reverseLL(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        while (current != nullptr) {
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        int len = length(head);
        ListNode* newHead = new ListNode(head -> val);
        ListNode* temp = head;
        ListNode* tempo = head;
        int count = 0;
        while(tempo != NULL && count != len/2){
            tempo = tempo -> next;
            count++;
        }

        ListNode* newHeadd = reverseLL(tempo);
        ListNode* gg = newHeadd;
        cout<<"ss"<<endl;;
        while(head != NULL && newHeadd != NULL){
            cout<<head -> val<<" , "<<newHeadd -> val <<endl;
            if(head -> val != newHeadd->val) return false;
            head = head -> next;
            newHeadd = newHeadd -> next;
        }
        return true;
    }
};