class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

      if (head == NULL) {
    return NULL;
}

if (head->next == NULL) {
    return NULL;
}

        int n = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        int pos = n / 2;

        ListNode* right = head;
        ListNode* left = NULL;
        n = 0;

        while (right != NULL) {
            left = right;
            right = right->next;
            n++;

            if (pos == n) {
    left->next = right->next;
    right->next = NULL;
    delete right;
    return head;
}
        }

        return head;
    }
};