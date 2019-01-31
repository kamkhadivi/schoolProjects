//
//  int_LinkedList.cpp
//  CSC340HMWK3
//
//  Created by Kamran Khadivi-Dimbali July 2017.
//
//

#include<iostream>
#include<stdlib.h>

using namespace std;

struct node

{
    int data;
    node *next;
    
}*head,*temp;

class new_Abstract {
    
public:
    ~new_Abstract(){
        
        if(head==NULL)
            return;
        
        while(head!=NULL)
        {
            temp = head -> next;
            delete head;
            head = temp;
        }
        
    }
    
public:
    new_Abstract(){
        head = NULL;
    }
    
    public :
    
    void pushFront(int value){
        temp = head;
        head = new node;
        head -> data  = value;
        head -> next = temp;
        
        cout <<"New Node Inserted  at the Front"<<endl;
        cout << endl << endl;
        cout << "Current List:" << endl;
        
        print();
        
    }
    
public:
    
    void pushBack(int value){
        
        node *temp2;
        if(head==NULL)
        {
            head=new node;
            head-> data = value;
            head-> next =NULL;
        }
        else
        {
            temp = head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp2 = new node;
            temp2 -> data = value;
            temp2 -> next = NULL;
            temp -> next  = temp2;
            
        }
        cout << endl << endl;
        cout << "Current List:" << endl;
        print();
        
    }
    
public:
    
    void popFront(){
        temp = head;
        if(temp == NULL)
        {
            cout << "The List is Empty" << endl;
            return;
        }
        head = temp -> next;
        delete temp;
        cout << "Front node is deleted" << endl;
        
    }
    
public:
    
    void popBack(){
        temp = head;
        if(temp == NULL)
        {
            cout<<"The List is Empty"<<endl;
            return;
        }
        head = temp -> next;
        delete temp;
        cout << "Back node is deleted" << endl;
        
    }
    
public:
    
    void print()
    
    {
        temp = head;
        if(temp == NULL)
        {
            cout << "The list is Empty" << endl;
            return;
        }
        while(temp != NULL)
        {
            cout << temp -> data << "->";
            temp = temp -> next;
        }
        cout << "end of list" << endl;
    }
    
public:
    
    void reverse()
    
    {
        
        node *tempHead;
        tempHead=head;
        node *previous = NULL;
        node *current = tempHead;
        node *next;
        
        while (current != NULL)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head=previous;
        
    }
    
public:
    
    int size()
    {
        int count=0;
        node *temp2;
        temp2=head;
        if (temp2 == NULL)
        {
            cout << "List is Empty" << endl;
            return -1;
        }
        while (temp2 -> next != NULL)
        {
            temp2 = temp2 -> next;
            count++;
        }
        return 1+count;
        
    }
    
public:
    
    int mtoLastElement(int value)
    
    {
        temp = head;
        while(temp != NULL)
        {
            value = temp -> data;
            temp  = temp -> next;
        }
        return value;
        
    }
    
public:
    
    void insert(int value,int position)
    
    {
        node *temp1;
        temp = head;
        if(temp1 == NULL)
        {
            temp1         = new node;
            temp1 -> data = value;
            temp1 -> next = NULL;
            head          = temp1;
            return;
        }
        
        for(int i=0;((i<position)&&(temp->next!=NULL)) ;i++)
        {
            if(i == (position-1))
            {
                temp1         = new node;
                temp1 -> data = value;
                temp1 -> next = temp -> next;
                temp  -> next  = temp1;
            }
            temp = temp -> next;
            
        }
        cout<<"\nThe list after insertion is:"<<endl;
        print();
        
    }
    
};

int main()
{
    
    new_Abstract obj;
    
    int option;
    int list_Size = 0;
    int position  = 0;
    int input;
    
    while(1)
        
    {
        
        cout<<"****************************************************************************"<<endl;
        cout<<"1.  Insert Node at Front"<<endl;
        cout<<"2.  Insert Node at Back"<<endl;
        cout<<"3.  Delete Node at Front"<<endl;
        cout<<"4.  Delete Node at Back"<<endl;
        cout<<"5.  Insert New Node at specified position"<<endl;
        cout<<"6.  Displays the last element of the list"<<endl;
        cout<<"7.  Display the size of the list:"<<endl;
        cout<<"8.  Display the items in the list"<<endl;
        cout<<"9.  Reverse the list"<<endl;
        cout<<"10. Exit"<<endl;
        
        cin >> option;
        
        
        
        switch (option)
        {
                
            case 1:
                cout<<"Enter the Data To insert at Front:"<<endl;
                cin>>input;
                obj.pushFront(input);
                break;
                
            case 2:
                cout<<"Enter the Data To insert at Back:"<<endl;
                cin>>input;
                obj.pushBack(input);
                break;
                
            case 3:
                obj.popFront();
                break;
                
            case 4:
                obj.reverse();
                obj.popBack();
                obj.reverse();
                break;
                
            case 5:
                cout<<"Enter the position to insert the New Node:"<<endl;
                cin>>position;
                cout<<"Enter The Data to insert" << endl;
                cin>>input;
                obj.insert(input,position);
                break;
                
            case 6:
                temp=head;
                cout<<"The Last Elemnt is: "<< obj.mtoLastElement(temp->data) << endl;
                break;
                
            case 7:
                list_Size=obj.size();
                if(list_Size!=0)
                    cout<<"The Size of List:" << list_Size << endl;
                break;
                
            case 8:
                cout<<"\nThe current list: "<<endl;
                obj.print();
                cout << endl;
                break;
                
            case 9:
                temp = head;
                if (temp == NULL)
                    cout<<"The list is empty"<<endl;
                else
                {
                    cout<<"\nThe list reveresed is: "<<endl;
                    obj.reverse();
                }
                obj.print();
                cout << endl;
                break;
                
            case 10:
                exit(0);
                
            default:
                cout<<"Please enter a valid command"<<endl;
                
        }
    }
    return 0;
    
}