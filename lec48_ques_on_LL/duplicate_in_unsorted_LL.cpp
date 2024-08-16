#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

// @Code360:  Remove Duplicates From an Unsorted Linked List

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


Node* removeDuplicates(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;

    // Unordered set to track visited node values
    unordered_set<int> visited;

    while (curr != NULL) {
        // Check if the current node's value is already in the set
        if (visited.find(curr->data) != visited.end()) {
            Node* nodeToDelete = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete nodeToDelete;  // Delete the duplicate node
        } else {
            visited.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}