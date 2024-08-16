#include <iostream>
using namespace std;

// @Code360:  Middle Of Linked List

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

// approach 1
int getLen(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}
Node *findMiddle(Node *head) {
    // approach 2 (optimised)
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* fast = head;
    Node* slow = head;

    while (fast->next != NULL) {
        if (fast->next->next == NULL) {
            fast = fast->next;

        } else {
            fast = fast->next->next;
        }
        slow = slow->next;
    }
    return slow;

    /*
    int len = (getLen(head)/2);
    while (len--) {
        head = head->next;
    }
    return head; */
}
//
void insertBack(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* mid1 = NULL;

    insertBack(head1, tail1, 1);
    insertBack(head1, tail1, 2);
    insertBack(head1, tail1, 3);
    insertBack(head1, tail1, 4);
    insertBack(head1, tail1, 5);

    print(head1);

    mid1 = findMiddle(head1);
    print(mid1);

    cout << endl;

    Node* head2 = NULL;
    Node* tail2 = NULL;
    Node* mid2 = NULL;

    insertBack(head2, tail2, 1);
    insertBack(head2, tail2, 2);
    insertBack(head2, tail2, 3);
    insertBack(head2, tail2, 4);
    insertBack(head2, tail2, 5);
    insertBack(head2, tail2, 6);

    print(head2);

    mid2 = findMiddle(head2);
    print(mid2);

    return 0;
}