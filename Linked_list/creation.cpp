#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;

        Node(): data(0), next(nullptr){}
        Node(int x): data(x), next(nullptr){}
        Node(int x, Node* next): data(x), next(next){}
};

// When we want to modify linked list 
// we take head by reference 
// other take head by value
void insertAtTail(Node* &head, int val){
    // create new node
    Node* newNode = new Node(val);

    // check if head is null
    if(head==nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

// here we are only traversing LL
// and not modifying it
// so we took head without referece
void display(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertAtHead(Node* &head, int val){
    Node* newNode = new Node(val);
    Node* temp = head;

    newNode->next = temp;
    head = newNode;
}

int main()
{
    /* Creating linked list using constructor
        Node* first = new Node(9);
        Node* second = new Node(10);
        first->next = second;
        Node* third = new Node(12);
        second->next = third;

        Node* temp = first;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    */

    Node* head = nullptr;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    display(head);

    insertAtHead(head, 50);
    display(head);
    return 0;
}