#include <iostream>
using namespace std;

// @Code360:  Reverse List In K Groups

class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node* kReverse(Node* head, int k) {
    //base case
    if(head == NULL)
        return head;

    //if our length is less than k so return as it is
    int len =0;
    Node* check = head;
    while(check != NULL){
        len++;
        check = check->next;
    }

    if(len<k ){
        return head;
    }

    //step1: reverse 1st k group
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;
    int cnt = 0;
    while(cnt < k && curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    //step2: for others use recursion
    if (next != NULL) {
        head->next = kReverse(next, k);
    }

    return prev;
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
    Node* ans1 = NULL;

    insertBack(head1, tail1, 5);
    insertBack(head1, tail1, 4);
    insertBack(head1, tail1, 3);
    insertBack(head1, tail1, 7);
    insertBack(head1, tail1, 9);
    insertBack(head1, tail1, 2);

    print(head1);

    ans1 = kReverse(head1,4);
    print(ans1);

    cout << endl;

    Node* head2 = NULL;
    Node* tail2 = NULL;
    Node* ans2 = NULL;

    insertBack(head2, tail2, 4);
    insertBack(head2, tail2, 3);
    insertBack(head2, tail2, 2);
    insertBack(head2, tail2, 8);

    print(head2);

    ans2 = kReverse(head2,4);
    print(ans2);

    return 0;
}