//
// Created by Eva Wu on 10/30/19.
//
#include <iostream>
#include "Node.h"
#include "Linkedlist.h"
using namespace std;

//default constructor
Linkedlist::Linkedlist() {
    Node(0,nullptr);
}
//copy constructor
Linkedlist::Linkedlist(const Linkedlist &L) {
    cout<<"copy constructor:"<<endl;
    Node* current = L.head;
    Node* copy = head;
    while(current->next!= nullptr){
        copy->next = new Node(current->next->value);
        copy = copy->next;
        current = current->next;
    }
}

//destructor
Linkedlist::~Linkedlist() {
    cout<<"destructor called:"<<endl;
    Node *curr = head;
    Node *next = curr->next;
    while(curr->next != nullptr){
        delete curr;
        curr = next;
        next = next->next;
    }
}

//copy assignment operator
Linkedlist& Linkedlist::operator=(const Linkedlist &assignment) {
    cout<<"copy assignment operator:"<<endl;
    Linkedlist copyObject;
    swap(copyObject.head,head);
    return *this;

}

//append function
void Linkedlist::append(int item){
    if(head == nullptr){
        head = new Node(item);
    }
    else{
        Node *curr = head;
        while(curr->next !=nullptr){
            curr = curr->next;
        }
        curr->next = new Node(item);
    }
}

//insertion sort function
void Linkedlist::InsertionSort( ) {
    Node * curr = head->next;
    Node * temp;
    Node * prev  = head;
    Node * next;
    //if there's 0 or 1 element in the lsit
    if(head == nullptr||head->next == nullptr){
        return;
    }

    while(curr != nullptr){
        //if curr>prev, keep going
        if(curr->value >= prev->value) {
            curr = curr->next;
            prev = prev->next;
        }
        //curr<prev
        else{
            //if the current should be connected after head, which is the first location in the list
            if(curr->value < head->value){
                prev->next = curr->next;
                curr->next = nullptr;
                curr->next = head;
                head = curr;

            }
            //if current should be connected elsewhere than after the head
            else{
                temp = head;
                //loop until find the correct location to insert
                while (curr->value > temp->next->value &&temp->next != nullptr) {
                    temp = temp->next;
                }
                //connect the nodes in correct sequence
                prev->next = curr->next;
                curr->next = nullptr;
                curr->next = temp->next;
                temp->next = curr;
            }
        }
        curr=prev->next;
    }

}
//funtion to print the linked list
void Linkedlist::printList(){
    Node* cursor = head;
    if (!cursor) {
        cout << "Empty" << endl;
    }
    else{
        while(cursor){
            cout << cursor->value << "\t";
            cursor = cursor->next;
        }
    }
    cout << endl;
}







