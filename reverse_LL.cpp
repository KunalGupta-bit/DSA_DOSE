#include <iostream>
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
    Node* head;
    Node* tail;

public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        Node*temp = head;
        if(head == NULL){
            head = tail = newNode;
        }

        else{
            newNode ->next = head;
            head = newNode;
        }
    }

    void reverseLL(){
        Node*prev = NULL;
        Node*curr = head;
        Node*next = NULL;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
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
    ll.push_front(3);
    ll.push_front(4);

    ll.printll();

    ll.reverseLL();

    ll.printll();

    return 0;
};