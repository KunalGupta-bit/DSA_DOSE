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

class List{
    Node*head;
    Node*tail;

public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }

        else{
            newNode ->next = head;
            head = newNode;
        }
    }

// Brute force approach
    // void middleLL(){
    //     int size = 0;
    //     Node* temp = head;

    //     while(temp!=NULL){
    //         size++;
    //         temp = temp->next;
    //     }

    //     int middle = size/2;

    //     temp = head;

    //     for(int i = 0; i< middle; i++){
    //         temp = temp->next;
    //     }
    //     cout<<"Middle Node: "<<temp->data<<"\n";
    // }

    // Optimal approach
    void middleLL(){
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast ->next!=NULL){
            slow = slow -> next;
            fast = fast->next->next;
        }
        cout<<"Middle Node: "<<slow->data<<"\n";
    }

    void printll(){
        Node*temp = head;
        if(head == NULL){
            cout<<"LL is Empty";
        }

        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

};

int main(){
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(45);
    ll.push_front(4);
    ll.push_front(5);

    ll.printll();

    ll.middleLL();

    ll.printll();
    return 0;
}