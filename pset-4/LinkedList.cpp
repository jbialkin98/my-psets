/*
 * LinkedList.cpp
 * Josh Bialkin
 * CPSC 223, PSET 4
 * 3/30/23
 * Implementation for Linked List of Green Line Extension Stations
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
LinkedList::~LinkedList(){
    makeEmpty();
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

// Input: station
// Returns: void
// Does: creates a new node for the inputted station and adds it to the head 
//       of the list
void LinkedList::insertStation(Station s){
    NodeType *newNode = new NodeType;
    newNode->info = s;
    newNode->next = head;
    head = newNode;
    length++;
}

// Input: station
// Returns: void
// Does: deletes the station that is equal to the input
void LinkedList::removeStation(Station s){
    NodeType *curr = head;
    // if the station to delete is the head
    if (curr->info.isEqual(s) == true) {
        NodeType *deleteHead = curr;
        head = curr->next;
        if (currPos == deleteHead) {
            resetCurrPos();
        }
        delete deleteHead;
        length--;
        return;
    }
    // traverses through the list until the station is found to be equal
    while (curr->next->info.isEqual(s) != true) {
        if (curr->next != NULL) {
            curr = curr->next;
        } else {
            // if no station is equal, nothing is done
            return;
        }
    }
    NodeType *nodeToDelete = curr->next;
    curr->next = nodeToDelete->next;
    if (currPos == nodeToDelete) {
        resetCurrPos();
    }
    delete nodeToDelete;
    length--;
}


// Input: none
// Returns: station
// Does: returns the station at the current position and sets currPos to the
//       next station. If currPos is the last station in the list, currPos is
//       reset to NULL. If currPoss is already NULL and the list is not empty,
//       the first station is returned. If the list is empty, the default
//       station is returned.
Station LinkedList::getNextStation(){
    if (head == NULL) {
        return Station();
    }
    if (isCurrPosNull() == true) {
        currPos = head->next;
        return head->info;
    } 
    NodeType *tempCurrPos = currPos;
    currPos = currPos->next;
    return tempCurrPos->info;
}

// Input: none
// Returns: void
// Does: sets curPos to NULL
void LinkedList::resetCurrPos(){
   currPos = NULL;
}

// Input: none
// Returns: void
// Does: removes each node from the list and deletes it from memory
void LinkedList::makeEmpty(){
    NodeType *curr = head;
    while (curr != NULL) {
        NodeType *tmp = curr->next;
        delete curr;
        curr = tmp;
    }
    length = 0;
}



// Input: out file
// Returns: void
// Does: prints every station in the linked list with the specified
//       formatting. The length is decremented on each loop. On the last
//       iteration of the while loop, there is a new line printed.
void LinkedList::print(ostream &out){
    int newLength = getLength();
    newLength--;
    NodeType *currentStation = head;
    while (currentStation != NULL) {
        currentStation->info.print(out);
        if (currentStation->next != NULL) {
            out << " " << newLength << " == ";
        } else {
            out << " " << newLength << endl;
        }
        currentStation = currentStation->next;
        newLength--;
        }
}



