#include <iostream>
#include <unordered_map>
using namespace std;

// @Gfg: Clone a linked list with next and random pointer

struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
// app 1. SC O(n) : TC O(n)
// class Solution {
//     private:
//         void insertNode(Node* &head, Node* &tail, int d) {
//             Node* temp = new Node(d);
//             if (head == nullptr) {
//                 head = temp;
//                 tail = temp;
//                 return;
//             }
//             tail->next = temp;
//             tail = tail->next;
//         }
//     public:
//         Node *copyList(Node *head) {
//             // Step 1: Create a clone list
//             Node* temp = head;
//             Node* clonedHead = nullptr;
//             Node* clonedTail = nullptr;
            
//             while (temp != nullptr) {
//                 insertNode(clonedHead, clonedTail, temp->data);
//                 temp = temp->next;
//             }
            
//             // Step 2: Create a map from original nodes to cloned nodes
//             unordered_map<Node*, Node*> oldToNewNode;
            
//             Node* originalNode = head;
//             Node* clonedNode = clonedHead;
//             while (originalNode != nullptr) {
//                 oldToNewNode[originalNode] = clonedNode;
//                 originalNode = originalNode->next;
//                 clonedNode = clonedNode->next;
//             }
            
//             // Step 3: Set the random pointers in the cloned list using the map
//             originalNode = head;
//             clonedNode = clonedHead;
            
//             while (originalNode != nullptr) {
//                 if (originalNode->random != nullptr) {
//                     clonedNode->random = oldToNewNode[originalNode->random];
//                 }
//                 originalNode = originalNode->next;
//                 clonedNode = clonedNode->next;
//             }
            
//             return clonedHead;
//         }
// };

// app 2
class Solution {
    public:
        Node *copyList(Node *head) {
            if (head == nullptr) return nullptr;

            // Step 1: Interleave cloned nodes with original nodes
            Node* current = head;
            while (current != nullptr) {
                Node* clonedNode = new Node(current->data);
                clonedNode->next = current->next;
                current->next = clonedNode;
                current = clonedNode->next;
            }

            // Step 2: Set the random pointers of the cloned nodes
            current = head;
            while (current != nullptr) {
                if (current->random != nullptr) {
                    current->next->random = current->random->next;
                }
                current = current->next->next;
            }

            // Step 3: Separate the cloned list from the original list
            Node* originalNode = head;
            Node* clonedHead = head->next;
            Node* clonedNode = clonedHead;

            while (originalNode != nullptr) {
                originalNode->next = clonedNode->next;
                originalNode = originalNode->next;

                if (originalNode != nullptr) {
                    clonedNode->next = originalNode->next;
                }
                clonedNode = clonedNode->next;
            }

            return clonedHead;
        }
};

//
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

void printRandom(Node* head) {
    if (head == nullptr) {
        cout << "empty list" << endl;
        return;
    }
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->random->data << " ";
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
    insertNode(head,tail,2);
    insertNode(head,tail,3);
    insertNode(head,tail,4);
    insertNode(head,tail,5);
    // setting random
    /**
     *      |-----v
     *      |     |-----v
     *      1->2->3->4->5->X
     *      ^--|  ^--|  |
     *         ^--------|
     */
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = tail;
    head->next->next->next->random = head->next->next;
    tail->random = head->next;

    cout << "original list->: ";
    print(head);
    cout << "original list random->: ";
    printRandom(head);
    
    Solution obj;
    Node* copyLL = obj.copyList(head);
    cout << "cloned list->: ";
    print(copyLL);
    cout << "cloned list random->: ";
    printRandom(copyLL);
    
    return 0;
}