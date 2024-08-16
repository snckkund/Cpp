#include <iostream>
using namespace std;

// @Code360:  Reverse Linked List

template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data) {
        this->data = data;
        this->next = NULL;
    }
};
// recursive 1
void rev(LinkedListNode<int>* &head, LinkedListNode<int>* curr, LinkedListNode<int>* prev) {
    if (curr == NULL) {
        head = prev;
        return;
    }
    LinkedListNode<int>* forward = curr->next;
    rev(head, forward, curr);
    curr->next = prev;
}
// recursive 2
LinkedListNode<int>* rev2(LinkedListNode<int>* &head) {
    // base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    LinkedListNode<int>* tempHead = rev2(head->next);
    head->next->next = head;
    head->next = NULL;
    return tempHead;
}

LinkedListNode<int>* reverseLinkedList(LinkedListNode<int>* head) {

    // recursive 1
    /*
    if (head == NULL || head->next == NULL) {
        return head;
    }
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* prev = NULL;
    rev(head, curr, prev);
    return head; */

    // iterative
    /*
    if (head == NULL || head->next == NULL) {
        return head;
    }
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* forward = NULL;
    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev; */
}

void insertBack(LinkedListNode<int>*& head, LinkedListNode<int>*& tail, int d) {
    LinkedListNode<int>* temp = new LinkedListNode<int>(d);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void print(LinkedListNode<int>* head) {
    LinkedListNode<int>* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    LinkedListNode<int>* head = NULL;
    LinkedListNode<int>* tail = NULL;

    insertBack(head, tail, 1);
    insertBack(head, tail, 2);
    insertBack(head, tail, 3);
    insertBack(head, tail, 4);
    insertBack(head, tail, 5);
    insertBack(head, tail, 6);
    insertBack(head, tail, -1);

    print(head);

    // head = reverseLinkedList(head); // iterative
    // print(head);

    // head = reverseLinkedList(head); // recursion 1
    // print(head);

    head = rev2(head); // recursion 2
    print(head);

    return 0;
}