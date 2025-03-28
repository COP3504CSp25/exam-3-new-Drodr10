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

    int* getStats() const{
        int* stats = new int[3];
        stats[0] = stats[1] = stats[2] = 0;
        
        Node* cur = head;
        if(cur == nullptr)
            return stats;

        stats[0] = stats[1] = stats[2] = cur -> data;

        int count = 1;

        cur = cur -> next;

        int info;
        while(cur != nullptr){
            info = cur -> data;   
            stats[0] = (info < stats[0]) ? info : stats[0];
            stats[1] = (info > stats[1]) ? info : stats[1];
            stats[2] += info;
            ++count; 
            cur = cur -> next;
        }

        stats[2] /= count;
        return stats;
    }
    

private:
    Node* head = nullptr;
};
