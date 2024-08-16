#include <iostream>
#include <map>
using namespace std;
    
class Node {
    public :

    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};
void InsertAtTail(Node* &tail, int d) {
    if (tail == NULL) {
        tail = new Node(d);
    } else {
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
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
// @Code360:  Detect and Remove Loop
// approach 1
bool detectLoop(Node *head) {

    if (head == NULL) {
        return false;
    }

    map<Node*,bool> visited;

    Node* temp = head;

    while(temp != NULL){
        // check for cycle
        if (visited[temp] == true) {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}
// approach 2 (floyd's cycle detection algo)
Node* floydCycle(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return slow; // Intersection point in the cycle
        }
    }
    return NULL;
}

// Function to find the start of the loop
Node* getStartingNode(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* intersection = floydCycle(head);
    if (intersection == NULL) {
        return NULL;
    }
    Node* slow = head;

    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// Function to remove the loop in the linked list
Node *removeLoop(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    Node* startNode = getStartingNode(head);
    if (startNode == NULL) {
        return head;
    }

    // Find the last node in the loop
    Node* temp = startNode;
    while (temp->next != startNode) {
        temp = temp->next;
    }
    
    // Remove the loop
    temp->next = NULL;

    return head;
}
//

int main() {
    
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    InsertAtTail(tail,2);
    InsertAtTail(tail,3);
    InsertAtTail(tail,4);
    InsertAtTail(tail,5);
    InsertAtTail(tail,6);

    // loop created
    tail->next = head->next->next;
    // cout << tail->next->data << endl;

    // // loop detected approach 1
    // if (detectLoop(head)) {
    //     cout << "loop found" << endl;
    // }
    // else {
    //     cout << "no loop" << endl;
    // }

    // // approach 2
    // if (floydCycle(head) != NULL) {
    //     cout << "loop found" << endl;
    // }
    // else {
    //     cout << "no loop" << endl;
    // }
    // Node* ans = removeLoop(head);

    // cout << "loop starting Node data: " << getStartingNode(head)->data << endl;

    // remove loop
    head = removeLoop(head);
    print(head);
    
    return 0;
}