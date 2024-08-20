#include <iostream>
using namespace std;

// @Code360:  Flatten A Linked List

class Node {
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

// Merge two linked lists
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result;
    if (a->data < b->data) {
        result = a;
        result->child = merge(a->child, b);
    } else {
        result = b;
        result->child = merge(a, b->child);
    }

    return result;
}

Node* flattenLinkedList(Node* head) {
    // Base case: if the head is NULL or there is no next list
    if (!head || !head->next)
        return head;

    // Recursively flatten the next list
    head->next = flattenLinkedList(head->next);

    // Merge this list with the next list
    head = merge(head, head->next);

    return head;
}

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
        temp = temp->child;
    }
    cout << endl;
}

int main() {
    /**
     *      1 -> 4 -> 7 -> 9 -> 20 -> X
     *      |    |    |    |
     *      2    5    8    12
     *      |    |
     *      3    6
     */
    Node* head = nullptr;
    Node* tail = nullptr;

    insertNode(head,tail,1);
    insertNode(head,tail,4);
    insertNode(head,tail,7);
    insertNode(head,tail,9);
    insertNode(head,tail,20);

    // Creating child lists for testing
    head->child = new Node(2);
    head->child->child = new Node(3);
    head->next->child = new Node(5);
    head->next->child->child = new Node(6);
    head->next->next->child = new Node(8);
    head->next->next->next->child = new Node(12);

    cout << "flatten list: ";
    Node* flat = flattenLinkedList(head);
    print(flat);
    
    return 0;
}