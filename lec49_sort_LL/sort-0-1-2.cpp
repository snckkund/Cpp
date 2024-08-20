#include <iostream>
using namespace std;

// @Code360:  Sort linked list of 0s 1s 2s

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

void insertAtTail(Node* &tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node *head){
    // Write your code here.
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    while(curr != NULL) {

        int value = curr->data;

        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }
    if(oneHead->next != NULL) {
        zeroTail->next = oneHead->next;

    } else {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;
    
    delete zeroHead;    
    delete oneHead;    
    delete twoHead;    

    return head;
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

int main() {
    
    Node* head = NULL;
    Node* tail = NULL;

    insertNode(head,tail,1);
    insertNode(head,tail,0);
    insertNode(head,tail,2);
    insertNode(head,tail,1);
    insertNode(head,tail,0);
    insertNode(head,tail,2);
    insertNode(head,tail,1);

    cout << "Original list: ";
    print(head);

    cout << "Sorted list: ";
    head = sortList(head);
    print(head);
    
    return 0;
}