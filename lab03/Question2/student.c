// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement

      struct ListNode* curr = head;
      struct ListNode* prevTail = NULL;

    // After the first swap, head will change to the 2nd node
      if (head != NULL && head->next != NULL) {
        head = head->next;
      }

      while (curr != NULL && curr->next != NULL) {
            struct ListNode* first = curr;
            struct ListNode* second = curr->next;
            struct ListNode* after = second->next;

            second->next = first;
            first->next = after;

            if (prevTail != NULL) {
                  prevTail->next = second;
            }

            prevTail = first;
            curr = after;
    }

    return head;


}