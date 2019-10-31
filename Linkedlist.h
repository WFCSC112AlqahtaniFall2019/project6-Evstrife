//
// Created by Eva Wu on 10/30/19.
//
#include <iostream>
#include "Node.h"
using namespace std;
#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H


class Linkedlist {

public:
    //default constructor
    Linkedlist();
    //copy constructor
    Linkedlist(const Linkedlist&L);
    //destructor
    ~Linkedlist();
    //copy assignment operator
    Linkedlist&operator = (const Linkedlist &assignment);


    //append function
    void append(int item);
    //insertion sort function
    void InsertionSort();
    void printList();

private:
    Node*head = nullptr;

};


#endif //BINARYINSERTIONSORT_LINKEDLIST_H
