class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (head == NULL) {
            return NULL;
        }

        if (head->next == NULL) {
            delete head;
            return NULL; 
        }

        int cnt = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        int pos = cnt - n; 

        if (pos == 0) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        ListNode* right = head;
        ListNode* left = NULL;

        cnt = 0;

        while (right != NULL) {
            left = right;
            right = right->next;
            cnt++; 

            if (cnt == pos) {
                left->next = right->next;
                right->next = NULL;
                delete right;
                return head; 
            }
        }

        return head; 
    }
};