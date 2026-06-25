class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;

        while (tempA != NULL) {
            ListNode* tempB = headB;

            while (tempB != NULL) {
                // Compare node addresses, not values
                if (tempA == tempB) {
                    return tempA;
                }

                tempB = tempB->next;
            }

            tempA = tempA->next;
        }

        return NULL;
    }
};