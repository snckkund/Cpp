#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// @Code360:  Merge Two Sorted Linked Lists

template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
}


void print(Node<int>* head) {
    if (head == nullptr) {
        cout << "empty list" << endl;
        return;
    }
    Node<int>* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertNode(Node<int>* &head, Node<int>* &tail, int d) {
    Node<int>* temp = new Node<int>(d);
    if (head == nullptr) {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = tail->next;
}

int main() {
    
    Node<int>* head1 = NULL;
    Node<int>* tail1 = NULL;

    insertNode(head1,tail1,7);
    insertNode(head1,tail1,8);
    insertNode(head1,tail1,-1); // null

    cout << "first list: ";
    print(head1);

    Node<int>* head2 = NULL;
    Node<int>* tail2 = NULL;

    insertNode(head2,tail2,1);
    insertNode(head2,tail2,3);
    insertNode(head2,tail2,4);
    insertNode(head2,tail2,6);
    insertNode(head2,tail2,-1); // null

    cout << "second list: ";
    print(head2);

    cout << "Sorted list: ";
    Node<int>* ans = sortTwoLists(head1,head2);
    print(ans);
    
    return 0;
}