// Program to Print the element of the linked list

#include<iostream>
using namespace std;

class Node
{
    public:
    int val;
    Node *next;
};

void insertNode(Node** head, int val)
{
    Node * newNode = new Node();

    newNode -> val = val;
    newNode -> next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        cout<< newNode -> val << " Inserted "<<endl;
        return;
    }

    Node *tempNode = *head;

    while(tempNode -> next != NULL)
    {
        tempNode = tempNode -> next;

    }

    tempNode -> next = newNode;
    cout<< newNode -> next <<" Inserted "<<endl;
}

void display(Node *node)
{
    cout<<endl;
    while (node != NULL)
    {
        cout<<node -> next <<" "; 
        node = node -> next;
    }
    cout<<endl;
    
}


int main()
{
    Node *head = NULL;
    cout<<endl;

    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);

    display(head);

    return 0;
}
