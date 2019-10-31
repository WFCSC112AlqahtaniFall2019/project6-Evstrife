#include <iostream>
#include <vector>
#include <cassert>
#include "BinaryInsertionSort.h"
#include "Linkedlist.h"
#include "Node.h"

using namespace std;

int main() {

    int seed, length;
    cout<<"Please enter the seed:"<<endl;
    cin >> seed;
    cout<<"Please enter the length:"<<endl;
    cin>> length;
    srand(seed);

    vector<int> v(length);
    Linkedlist L = Linkedlist();

    // generate vector of random integers
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100;
    }

    //create a linked list for sorting
    for (int i = 0; i < length; i++) {
        L.append(v[i]);
    }
    //print the list to be sorted
    cout<<"Numbers to be sorted:"<<endl;
    L.printList();


    //record the time of binary insertion sort
    clock_t start_binaryInsertionSort = clock();
    insertionSort(v, v.size());
    clock_t end_binaryInsertionSort = clock();

    // check if sorted
    for (int i = 1; i < v.size(); i++) {
        assert(v[i-1] <= v[i]);
    }

    // print out sorted list
    cout<<"after binary insertion sort:"<<endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout<<endl;




    // tracked the time of Linkedlist insertion sort
    clock_t start_linkedListInsertionSort = clock();
    L.InsertionSort();
    clock_t end_linkedListInsertionSort = clock();

    //Print out sorted linked list
    cout << "List after linked list insertion sort: " << endl;
    L.printList();

}

