//
//  functions.cpp
//  340FinalTesting
//
//  Created by Kamran Khadivi-Dimbali on 8/9/17.
//  Copyright © 2017 Kamran Khadivi-Dimbali. All rights reserved.
//
/*
#include "functions.hpp"

//**************** Operator Overloading functions
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

ostream& operator<<(ostream& out, spaceShip& rhs){
    cout<<"ligths: "<<rhs.getLights()<<endl;
    cout<<"name: "<<rhs.getName()<<endl;
    return out;
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

//*********** destructors
linkedlist::~linkedlist(){
    cout<<"in destructor"<<endl;
    if(head == NULL)
        return;
    deleteList();
}

linkedlist::~linkedlist(){
    cout<<"in destructor"<<endl;
    if(head == NULL)
        return;
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

//*********** constructors
linkedlist::linkedlist(){
    head = NULL;
    size = 0;
}

spaceShip::spaceShip():ligths(5),name("alien"){}

linkedlist(){
    head = NULL;
    size = 0;
}

linkedlist(int val){
    node* temp = new node;
    temp->data = val;
    // *(temp).next = NULL;
    temp->next = NULL;
    head = temp;
    size = 1;
}

//*********** assignment operator

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

//************* recursion

int digitSum( int input)
{
    if (input < 9)
        return input;
    else
        return input % 10 + digitSum(input/10);
}

bool isPalindrome(const string &s)
{
    if(s.length() = 1)
        return true;
    if(s.length() == 2)
        return s[0] == s[1];
    return (s[0] == s[s.length()-1]) && isPalindrome(s.substr(1, s.lenght() -2)));
}

int waysToClimb(int stairs)
{
    if(stairs <= 1)
        return stairs;
    else
        return waysToClimb(stairs-1) + waysToClimb(stairs-2);
}

int myFactorial( int integer)
{
    if( integer == 1)
        return 1;
    else
    {
        return (integer * (myFactorial(integer-1)));
    }
}


*/






















