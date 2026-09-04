#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) { 
            head = tail = newNode;
        } else {
            tail->next = newNode; 
            tail = newNode;
        }
    }

    void push_anywhere(int val, int idx) {
        if (idx <= 0 || head == NULL) {
            push_front(val);
            return;
        }

        Node* temp = head;
        int current_idx = 0;
        while (current_idx < idx - 1 && temp->next != NULL) {
            temp = temp->next;
            current_idx++;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL) { 
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "LL is empty\n";
            return;
        }
        
        Node* temp = head;
        head = head->next;
        
        if (head == NULL) { 
            tail = NULL;
        }
        
        temp->next = NULL;
        delete temp;
    }

    void pop_back() {
        if (head == NULL) {
            cout << "LL is empty\n";
            return;
        }
        
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    int search(int key) {
        Node* temp = head;
        int idx = 0;
        while (temp != NULL) {
            if (temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    void printll() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3); 
    
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);   
    
    ll.push_anywhere(7, 3);

    cout << "Original List: ";
    ll.printll();

    ll.pop_front(); 
    ll.pop_back();  
    
    cout << "After popping front and back: ";
    ll.printll(); 

    int key = 7;
    cout << "Searching for " << key << "... Found at index: " << ll.search(key) << endl;

    return 0;
}
