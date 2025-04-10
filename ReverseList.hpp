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

        LinkedList list;  

        while(cur != nullptr){
            list.addHead(cur -> data);
            cur = cur -> next;
        }
        
        return list;
    }

    Node* head = nullptr;
};
