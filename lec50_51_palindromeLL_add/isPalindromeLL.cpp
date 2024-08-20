#include <iostream>
using namespace std;

// @Gfg: Palindrome Linked List

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
    private:
        Node* getMid(Node* head) {
            Node* slow = head;
            Node* fast = head->next;
            while(fast!= NULL && fast->next != NULL) {
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }
        Node* reverse(Node* head) {
            Node* curr = head;
            Node* prev = NULL;
            Node* next = NULL;
            while(curr != NULL) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }

    public:
        // Function to check whether the list is palindrome.
        bool isPalindrome(Node *head) {
            // Your code here
            if(head == NULL || head->next == NULL) {
                return true;
            }
            // step 1: find middle
            Node* middle = getMid(head);

            // step 2: reverse list after middle
            Node* temp = middle->next;
            middle->next = reverse(temp);

            // step 3: compare both halves
            Node* head1 = head;
            Node* head2 = middle->next;
            while(head2 != NULL) {
                if(head2->data != head1->data) {
                    temp = middle->next;
                    middle->next = reverse(temp);
                    return false;
                }
                head2 = head2->next;
                head1 = head1->next;
            }
            return true;
        }
};

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

    // // palindrome
    // insertNode(head,tail,1);
    // insertNode(head,tail,2);
    // insertNode(head,tail,1);
    // insertNode(head,tail,1);
    // insertNode(head,tail,2);
    // insertNode(head,tail,1);

    // non palindrome
    insertNode(head,tail,1);
    insertNode(head,tail,2);
    insertNode(head,tail,3);
    insertNode(head,tail,4);

    print(head);
    cout << "head: " << head->data << " tail: " << tail->data << endl;
    
    Solution obj;
    cout << "palindrome? : " << obj.isPalindrome(head) << endl;
    
    return 0;
}