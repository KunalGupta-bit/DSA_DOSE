#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularLL{
    Node* head;
    Node* tail;

public:
    CircularLL(){
        head = tail = NULL;
    }

    void IAH(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
            return;
        }

        newNode->next = head;
        head = newNode;
        tail->next = newNode;
    }

    void printcll(){
        if (head == NULL) {
            cout << "CLL is empty" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head); 
        
        cout <<head->data <<endl;
    }
};


int main(){
    CircularLL cll;

    cll.IAH(1);
    cll.IAH(2);
    cll.IAH(3);
    cll.IAH(4);

    cll.printcll();
    return 0;
}