// Question4/student.c
// ------------------------------------------------------------
// CS Lab03 - Middle Node of Linked List
//
// TODO:
//   Implement middleNodeValue(head) using fast/slow pointers.
//
// Notes:
// - If even length, return the second middle.
// - Do not allocate new nodes.
// ------------------------------------------------------------

#include "Student.h"

int middleNodeValue(struct ListNode *head) {
    // TODO: implement

    if (head == NULL||head->next == NULL){
        return head->val;
    }
    struct ListNode* fast = head-> next;
    struct ListNode* slow = head;

    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        

    }
    if (fast == NULL){
        return slow->val;

    } else{
        return slow->next->val;
    }

}