#include <bits/stdc++.h>
using namespace std;
  struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*l1=head;
        while(l1->next!=nullptr){
            while(l1->next->val==l1->val){
                l1->next=l1->next->next;
                
            }
            cout<<l1->val;
            if(l1->next!=nullptr){
                l1=l1->next;
            }
            
            
        }
        return head;
    }
};