#pragma once

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    void addHead(const int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    
    LinkedList reverseList() const {
        Node* cur = head;
        
        Node* prev = nullptr;

        while(cur != nullptr){
            Node* nextNode = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = nextNode;
        }
        
    }

    Node* head = nullptr;
};
