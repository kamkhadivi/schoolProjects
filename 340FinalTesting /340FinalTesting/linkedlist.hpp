//
//  linkedlist.hpp
//  340FinalTesting
//
//  Created by Kamran Khadivi-Dimbali on 8/9/17.
//  Copyright © 2017 Kamran Khadivi-Dimbali. All rights reserved.
//

#ifndef linkedlist_hpp
#define linkedlist_hpp

#include <stdio.h>

#endif /* linkedlist_hpp */

#include <iostream>
using namespace std;

#pragma once

struct node{
    int data;
    node* next;
};


class linkedlist{
    
private:
    node* head;
    int size;
    
public:
    linkedlist();
    linkedlist(int val);
    ~linkedlist();
    void printList() const;
    void append(int val);
    void pushFront(int val);
    void pop();
    void deleteList();
    bool operator==(const linkedlist& rhs);
    int listSize() const;
    friend ostream& operator<<(ostream& out, const linkedlist& rhs); // As a friend function.
    linkedlist& operator=(const linkedlist& rhs);
    
};