#include <iostream>
using namespace std;

class Node {
public:
    Node* prev;
    int data;
    Node* next;

    // constructor
    Node(int data) {
        this->prev = NULL;
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

// traversing a linked list
void print(Node* &head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// length of LL
int getLength(Node* &head) {
    Node* temp = head;
    int len = 0;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int d) {
    if (head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int d) {
    if (tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else {
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
    // insert at start
    if(position == 1) {
        insertAtHead(head, tail, d);
        return;
    }
    int cnt = 1;
    Node* temp = head;
    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }
    // insert at last
    if (temp->next == NULL) {
        insertAtTail(head,tail,d);
        return;
    }
    // insert at position
    Node* NodeToInsert = new Node(d);
    
    NodeToInsert->next = temp->next;
    temp->next->prev = NodeToInsert;
    temp->next = NodeToInsert;
    NodeToInsert->prev = temp;

}

void deleteNode(Node* &head, Node* &tail,int position) {
    if (position == 1) {
        Node* temp = head;
        if (temp->next != NULL) {
            temp->next->prev = NULL;
            head = temp->next;
            temp->next = NULL;
        } else {
            head = NULL;
            tail = NULL;
        }
        delete temp;
    }
    else {
        // deleting any middle element or tail
        Node* temp = head;

        int cnt = 1;
        while (cnt < position) {
            temp = temp->next;
            cnt++;
        }

        // Check if temp is the tail node
        if (temp->next == NULL) {
            temp->prev->next = NULL;
            tail = temp->prev;
            temp->prev = NULL;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = NULL;
            temp->prev = NULL;
        }
        delete temp;
    }
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    // insert at head
    insertAtHead(head,tail,11);

    // insert at tail
    insertAtTail(head,tail,7);

    // insert at position
    insertAtPosition(head,tail,2,100);
    insertAtPosition(head,tail,1,2); // inserting at head
    insertAtPosition(head,tail,getLength(head)+1,13); // inserting at tail

    print(head);

    // delete nodes
    deleteNode(head,tail,2);
    print(head);
    deleteNode(head,tail,1);
    print(head);
    deleteNode(head,tail,getLength(head));
    print(head);

    if (head != NULL) {
        cout << "head: " << head->data << endl;
    } else {
        cout << "head is NULL" << endl;
    }

    if (tail != NULL) {
        cout << "tail: " << tail->data << endl;
    } else {
        cout << "tail is NULL" << endl;
    }

    return 0;
}
