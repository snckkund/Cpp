#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory is freed for node with data: " << value << endl;
    }
};

void InsertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d) {
    if (tail == NULL) {
        tail = new Node(d);
    } else {
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }
}

void InsertAtPosition(Node* &head, Node* &tail, int position, int d) {
    if (position == 1) {
        InsertAtHead(head, d);
        if (tail == NULL) {
            tail = head; // Case where list was empty
        }
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL) {
        // If position is out of bounds, insert at the tail
        InsertAtTail(tail, d);
        return;
    }
    if (temp->next == NULL) {
        InsertAtTail(tail, d);
    } else {
        Node* newNodeToAdd = new Node(d);
        newNodeToAdd->next = temp->next;
        temp->next = newNodeToAdd;
    }
}

void DeleteNode(Node* &head, Node* &tail, int position) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        if (head == NULL) { // List became empty
            tail = NULL;
        }
        temp->next = NULL;
        delete temp;
    } else {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        if (curr->next == NULL) {
            tail = prev; // If we deleted the last node
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isCircular(Node* head){
    // Write your code here.
    if (head == NULL)
        return 1;

    Node* temp = head->next;

    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    
    if (temp==head)
        return 1;

    return 0;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    InsertAtHead(head, 12);
    InsertAtTail(tail, 15);
    InsertAtPosition(head, tail, 2, 17);
    InsertAtPosition(head, tail, 1, 22);
    InsertAtPosition(head, tail, 6, 20);

    print(head);

    // DeleteNode(head, tail, 1); // deleting head
    // DeleteNode(head, tail, 5); // delete tail
    // DeleteNode(head, tail, 2); // 2nd position element

    // print(head);

    // if (head != NULL) {
    //     cout << "head: " << head->data << ", " << "next address: " << head->next << endl;
    // } else {
    //     cout << "head is NULL" << endl;
    // }

    // if (tail != NULL) {
    //     cout << "tail: " << tail->data << ", " << "next address: " << tail->next << endl;
    // } else {
    //     cout << "tail is NULL" << endl;
    // }

    // circular or not
    if (isCircular(tail)) {
        cout << "circular" << endl;
    }
    else {
        cout << "not circular" << endl;
    }

    return 0;
}