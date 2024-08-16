#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int val = this->data;
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory is freed for node with data: " << val << endl;
    }
};

void insertNode(Node* &tail, int element, int d) {
    // assuming element is present in the list

    // empty list
    if (tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        Node* curr = tail;
        while (curr->data != element) {
            curr = curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* &tail) {
    if (tail==NULL) {
        cout << "empty list" << endl;
        return;
    }
    Node* temp = tail;

    do {
        cout << tail->data << " ";
        tail = tail->next;
    }
    while (tail != temp);

    cout << endl;
}

void deleteNode(Node* &tail, int value) {
    // assuming value is present
    // deleting tail
    if (tail == NULL) {
        return;
    }
    Node* pre = tail;
    Node* curr = pre->next;
    // single node
    if (curr == pre) {
        tail = NULL;
    }
    while (curr->data != value) {
        pre = curr;
        curr = curr->next;
    }
    // value found
    // deleting any mid element
    pre->next = curr->next;
    if (curr == tail) {
        tail = pre;
    }
    curr->next = NULL;
    delete curr;
}
// @Code360:  Circularly Linked
bool isCircular(Node* head) {
    // An empty list is circular
    if (head == NULL) {
        return true;
    }

    Node* slow = head;
    Node* fast = head;

    // Traverse the linked list
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move slow pointer by one
        fast = fast->next->next;    // Move fast pointer by two

        // If they meet, there is a cycle
        if (slow == fast) {
            // Verify if the cycle includes all nodes
            Node* temp = slow;
            do {
                temp = temp->next;
            } while (temp != slow && temp != head);

            return temp == head; // True if the cycle includes all nodes
        }
    }

    // If fast pointer reaches NULL, list is not circular
    return false;
}

int main() {

    Node* tail = NULL;

    insertNode(tail,0,3);
    insertNode(tail,3,5);
    insertNode(tail,5,7);
    insertNode(tail,7,9);

    insertNode(tail,5,6);

    insertNode(tail,9,10);

    insertNode(tail,3,4);

    print(tail);

    // deleteNode(tail,3);
    // deleteNode(tail,5);
    // deleteNode(tail,9);
    // print(tail);

    // circular or not
    if (isCircular(tail)) {
        cout << "circular" << endl;
    }
    else {
        cout << "not circular" << endl;
    }

    return 0;
}