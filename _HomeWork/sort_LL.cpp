// @Homework: sort a LL { O(nlog(n)) }
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void insertNode(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);
    if (head == nullptr) {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = tail->next;
}

void print(Node* head) {
    if (head == nullptr) {
        cout << "empty list" << endl;
        return;
    }
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// merge sort
// Function to split the linked list into two halves
Node* getMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;
    
    Node* slow = head;
    Node* fast = head->next;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;
    
    if (left->data <= right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

// Function to perform merge sort on the linked list
Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;
    
    Node* middle = getMiddle(head);
    Node* nextOfMiddle = middle->next;
    
    // Split the linked list into two halves
    middle->next = nullptr;
    
    // Apply merge sort on the left and right halves
    Node* left = mergeSort(head);
    Node* right = mergeSort(nextOfMiddle);
    
    // Merge the sorted halves
    return merge(left, right);
}

int main() {
    
    Node* head = nullptr;
    Node* tail = nullptr;

    insertNode(head,tail,3);
    insertNode(head,tail,2);
    insertNode(head,tail,7);
    insertNode(head,tail,6);
    insertNode(head,tail,1);
    insertNode(head,tail,4);
    insertNode(head,tail,5);

    cout << "Original list: ";
    print(head);

    cout << "Sorted list: ";
    head = mergeSort(head);
    print(head);
    
    return 0;
}