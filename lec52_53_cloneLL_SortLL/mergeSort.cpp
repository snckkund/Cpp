#include <iostream>
using namespace std;

// @Code360: MergeSort Linked List

class node{
    public:
        int data;
        node * next;
        node(int data){
            this->data=data;
            this->next=NULL;
        }
};

node* findMid(node* head) {
    node* slow = head;
    node* fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        if(fast->next != NULL) {
            fast = fast->next;
        }
    }
    return slow;
}
node* merge(node* left, node* right){

     if(left == NULL) {
        return right;
     }
     if(right == NULL) {
        return left;
     }

    node* ans = new node(-1);
    node* temp = ans;

    // sort two LL and merge
    while(left != NULL && right != NULL) {
        if(left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;

        } else {
            temp->next = right;
            temp = right;
            right = right->next;

        } 
    }
    while(left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;

    return ans;

}
node* mergeSort(node *head) {

    if(head == NULL || head->next == NULL) {
        return head;
    }

    // get mid
    node* mid = findMid(head);

    // split into left and right part
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    // recursive calls
    left = mergeSort(left);
    right = mergeSort(right);

    // merge
    node* result = merge(left,right);

    return result;
    
}

void insertNode(node* &head, node* &tail, int d) {
    node* temp = new node(d);
    if (head == nullptr) {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = tail->next;
}

void print(node* head) {
    if (head == nullptr) {
        cout << "empty list" << endl;
        return;
    }
    node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    
    node* head = nullptr;
    node* tail = nullptr;

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
    node* sorted = mergeSort(head);
    print(sorted);
    
    return 0;
}