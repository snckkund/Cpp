// @Homework: split the circular LL in half
/**
 *  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 ->1  =>  { 1 -> 2 -> 3 -> 4 -> 1 } { 5 -> 6-> 7-> 5 }
 *  1 -> 2 -> 3 -> 4 -> 5 -> 6 ->1  =>  { 1 -> 2 -> 3 -> 1 } { 4 -> 5 -> 6 -> 4 }
 */
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        temp->next = temp;
        tail = temp;
        head = temp;
        return;
    }
    tail->next = temp;
    temp->next = head;
    tail = temp;
}

void print(Node* head) {
    if (head == NULL) {
        cout << "empty list." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << temp->data << endl;
}

void splitLL(Node* head, Node* &firstHalfHead, Node* &firstHalfTail, Node* &secondHalfHead, Node* &secondHalfTail) {
    if (head == NULL) return;

    Node* slow = head;
    Node* fast = head;

    // Using the fast and slow pointer technique to find the midpoint
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Setting the heads of the two halves
    firstHalfHead = head;
    secondHalfHead = slow->next;

    // Setting the tails of the two halves
    firstHalfTail = slow;
    secondHalfTail = fast->next == head ? fast : fast->next;

    // Closing the two circular linked lists
    firstHalfTail->next = firstHalfHead;
    secondHalfTail->next = secondHalfHead;
}

int main() {

    // // Odd

    Node* head = NULL;
    Node* tail = NULL;

    // Insert nodes into the circular linked list
    insertNode(head, tail, 1);
    insertNode(head, tail, 2);
    insertNode(head, tail, 3);
    insertNode(head, tail, 4);
    insertNode(head, tail, 5);
    insertNode(head, tail, 6);
    insertNode(head, tail, 7);

    // Print the original circular linked list
    cout << "Original Circular Linked List: ";
    print(head);

    // Initialize the heads and tails for the split lists
    Node* firstHalfHead = NULL;
    Node* firstHalfTail = NULL;
    Node* secondHalfHead = NULL;
    Node* secondHalfTail = NULL;

    // Split the circular linked list
    splitLL(head, firstHalfHead, firstHalfTail, secondHalfHead, secondHalfTail);

    // Print the two halves
    cout << "First Half: ";
    print(firstHalfHead);
    cout << "Second Half: ";
    print(secondHalfHead);

    // // // Even
    // Node* head = NULL;
    // Node* tail = NULL;

    // // Insert nodes into the circular linked list
    // insertNode(head, tail, 1);
    // insertNode(head, tail, 2);
    // insertNode(head, tail, 3);
    // insertNode(head, tail, 4);
    // insertNode(head, tail, 5);
    // insertNode(head, tail, 6);

    // // Print the original circular linked list
    // cout << "Original Circular Linked List: ";
    // print(head);

    // // Initialize the heads and tails for the split lists
    // Node* firstHalfHead = NULL;
    // Node* firstHalfTail = NULL; 
    // Node* secondHalfHead = NULL;
    // Node* secondHalfTail = NULL;

    // // Split the circular linked list
    // splitLL(head, firstHalfHead, firstHalfTail, secondHalfHead, secondHalfTail);

    // // Print the two halves
    // cout << "First Half: ";
    // print(firstHalfHead);
    // cout << "Second Half: ";
    // print(secondHalfHead);

    return 0;
}
