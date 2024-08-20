#include <iostream>
using namespace std;

// @Gfg: Add Number Linked Lists

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
        struct Node* reverse(struct Node* head) {
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
        void insertAtTail(struct Node* &head, struct Node* &tail, int d) {
            Node* temp = new Node(d);
            if (head == nullptr) {
                head = temp;
                tail = temp;
                return;
            }
            tail->next = temp;
            tail = temp;
        }
        struct Node* add(struct Node* first, struct Node* second) {
            Node* ansHead = NULL;
            Node* ansTail = NULL;
            int carry = 0;
            int sum = 0;
            int digit = 0;
            while(first != NULL || second != NULL | carry != 0) {
                int val1 = 0;
                if(first != NULL) {
                    val1 = first->data;
                }
                int val2 = 0;
                if(second != NULL) {
                    val2 = second->data;
                }
                sum = carry + val1 + val2;
                digit = sum%10;
                
                // create node and add ans in LL
                insertAtTail(ansHead,ansTail,digit);
                carry = sum/10;

                if(first != NULL) {
                    first = first->next;
                }
                if(second != NULL) {
                    second = second->next;
                }
            }

            return ansHead;
        }
    public:
        // Function to add two numbers represented by linked list.
        Node* addTwoLists(struct Node* num1, struct Node* num2) {
            // reverse two LLs
            num1 = reverse(num1);
            num2 = reverse(num2);
            
            // add two LL
            Node* ans = add(num1,num2);
            ans = reverse(ans);
            return ans;
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
    
    Node* head1 = NULL;
    Node* tail1 = NULL;
    insertNode(head1,tail1,4);
    insertNode(head1,tail1,5);

    //
    Node* head2 = NULL;
    Node* tail2 = NULL;
    insertNode(head2,tail2,3);
    insertNode(head2,tail2,4);
    insertNode(head2,tail2,5);

    cout << "num1 = ";
    print(head1);
    cout << "num2 = ";
    print(head2);
    Solution obj;
    Node* ans = obj.addTwoLists(head1, head2);
    cout << "num1 + num2 = ";
    print(ans);
    
    return 0;
}