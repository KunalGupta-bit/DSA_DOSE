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
public:
    Node* head;
    Node* tail;

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

    Node* mergeLL(Node* head1, Node* head2) {
        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;

        if (head1->data <= head2->data) {
            head1->next = mergeLL(head1->next, head2);
            return head1; 
        } else {
            head2->next = mergeLL(head1, head2->next);
            return head2;
        }
    }

    void printll(Node* headNode) {
        Node* temp = headNode;
        if (temp == NULL) {
            cout << "LL is Empty.\n";
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Node* head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);

    Node* head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    List ll;

    cout << "List 1: ";
    ll.printll(head1);
    cout << "List 2: ";
    ll.printll(head2);

    Node* mergedHead = ll.mergeLL(head1, head2);

    cout << "Merged List: ";
    ll.printll(mergedHead);
    return 0;
}
