/*
 * LinkedList.cpp
 * CPSC 223
 * 
 * Implementation for Linked List of Green Line Extension Stations
 * Don't forget to remove //TODO when you submit!
 */

#include "LinkedList.h"
#include <iostream>
using namespace std;

// Default constructor
LinkedList::LinkedList(){
    length = 0;
    head = NULL;
    currPos = NULL;
}

// Destructor
LinkedList::~LinkedList() {
    //TODO
}

// Assignment operator overloading
// Don't change anything here. This is needed for copying objects.
LinkedList & LinkedList::operator = (const LinkedList &l){
    NodeType *temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
    length = l.length;
    currPos = NULL;
    if (l.head == NULL)
        head = NULL;
    else{
        head = new NodeType;
        head->info = l.head->info;
        head->next = NULL;
        NodeType *curr = head;
        NodeType *orig = l.head;
        while (orig->next != NULL){
            curr->next = new NodeType;
            curr->next->info = orig->next->info;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
    return *this;
}

// Input: nothing
// Returns: the length
// Does: returns the length of the LL
int LinkedList::getLength() const{
    return length;
}

// Input: nothing
// Returns: true if currPos is NULL
// Does: determines if currPos is NULL or not
bool LinkedList::isCurrPosNull() const{
    return currPos == NULL;    
}

// Input: 
// Returns: 
// Does: 
void LinkedList::insertStation(Station s){
    //TODO
}

// Input: 
// Returns: 
// Does: 
void LinkedList::removeStation(Station s){
    //TODO
}


// Input: 
// Returns: 
// Does: 
Station LinkedList::getNextStation(){
    //TODO
}

// Input: 
// Returns: 
// Does: 
void LinkedList::resetCurrPos(){
   currPos = NULL;
}

// Input: 
// Returns: 
// Does: 
void LinkedList::makeEmpty(){
    //TODO
}



// Input: 
// Returns: 
// Does: 
void LinkedList::print(ostream &out){
    //TODO
}



