//
//  linkedlist.cpp
//  340FinalTesting
//
//  Created by Kamran Khadivi-Dimbali on 8/9/17.
//  Copyright © 2017 Kamran Khadivi-Dimbali. All rights reserved.
//

#include "linkedlist.hpp"


linkedlist::linkedlist(){
    head = NULL;
    size = 0;
}

linkedlist::linkedlist(int val){
    node* temp = new node;
    temp->data = val;
    // *(temp).next = NULL;
    temp->next = NULL;
    head = temp;
    size = 1;
}

void linkedlist::printList()const{
    node* walk = head;
    while(walk != NULL){
        cout<<walk->data<<" ";
        //walk->data = 4;
        walk = walk->next;
    }
    cout<<endl;
    cout<<"this-> "<<this<<endl;
}

void linkedlist::append(int val){
    node* temp = new node;
    temp->data = val;
    temp->next = NULL;
    
    if(head == NULL)
        head = temp;
    else{
        node* last = head;
        while(last->next != NULL)
            last = last->next;
        last->next = temp;
        
    }
    
    size++;
}

void linkedlist::pushFront(int val){
    node* first = new node;
    first->data = val;
    first->next = head;
    head = first;
    size++;
}

void linkedlist::pop(){
    if(head == NULL)
        return;
    else{
        node* first = head;
        head = head->next;
        delete first;
        first = NULL;
        size--;
    }
    
    
}

void linkedlist::deleteList(){
    node* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
    }
    head = NULL;
    size = 0;
}

linkedlist::~linkedlist(){
    cout<<"in destructor"<<endl;
    if(head == NULL)
        return;
    deleteList();
    
}

bool linkedlist::operator==(const linkedlist& rhs){
    if(head == rhs.head)
        return true;
    if(size != rhs.size)
        return false;
    node* lhshead = head;
    node* rhshead = rhs.head;
    
    int lsize = size;
    while(lsize -- != 0){
        if(lhshead->data != rhshead->data)
            return false;
        lhshead = lhshead->next;
        rhshead = rhshead->next;
    }
    return true;
}

int linkedlist::listSize()const {
    return size;
}

ostream& operator<<(ostream& out, const linkedlist& rhs){
    rhs.printList();
    cout<<"head->"<<rhs.head<<endl;
    //cout<<"this-> "<<this<<endl;
    return out;
}

linkedlist& linkedlist::operator=(const linkedlist& rhs){
    if(rhs.head == NULL)
        deleteList();
    else{
        deleteList();
        node* rhshead = rhs.head;
        node* temp = new node;
        //temp->data = rhshead->data;
        head = temp;
        head->data = rhshead->data;
        head->next = NULL;
        rhshead = rhshead->next;
        //node* link = head;
        size = 1;
        
        while(rhshead != NULL){
            node* second = new node;
            second->data = rhshead->data;
            second->next = NULL;
            temp->next = second;
            temp = temp->next;
            rhshead = rhshead->next;
            size++;
        }
        
        
    }
    
    return *this;
    
}


