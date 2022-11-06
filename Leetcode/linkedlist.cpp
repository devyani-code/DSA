
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *temp=head;
        int count=0;
        while(temp->next!=nullptr){
            count++;
            temp=temp->next;
        }
        temp=head;
        int sum;
        while(temp!=nullptr){
            sum=sum+ temp->val*(2,count);
            count--;
            temp=temp->next;

        }

        return sum;

        
    }
};