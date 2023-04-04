/*
 * Josh Bialkin
 * NodeType.h
 * CPSC223, PSET 4
 * 3/30/23
 * Small struct that is part of a Linked List class
 */

#include "Station.h"
using namespace std;

#ifndef NODETYPE
#define NODETYPE

struct NodeType
{
    Station info;
    NodeType *next;
};

#endif
