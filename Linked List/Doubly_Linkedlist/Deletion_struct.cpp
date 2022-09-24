#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node*prev;
    struct Node*next;

};

void insertEnd(struct Node** start, int data)
{
    struct Node* newNode = new Node;

    newNode -> data = data;

    newNode -> next = NULL;

    struct Node*temp = *start;

    if(*start == NULL)
    {
        newNode -> prev = NULL;
        *start = newNode;
        return;
    }

    while(temp->next != NULL)
        temp = temp -> next;
    
    temp -> next = newNode;
    newNode -> prev = temp;
}

void deleteNode(struct Node** start, struct Node* del_node)
{
    //if head(start) of del is full, deletion is not possible
    if(*start == NULL || del_node == NULL)
        return;
    
    // if del_node is the head(start) node , point the head pointer to the next node
    if(*start == del_node)
        *start = del_node->next;

    //if del_node is not at the last node, point the prev of node next to del_node to the previous of del_node
    if(del_node -> next != NULL)
        del_node->next->prev = del_node->prev;
    
    //if del_node is not the first node, point the next of the previous node to the next node of del_node
    if(del_node -> prev != NULL)
        del_node -> prev -> next = del_node -> next;

    //if del_node is the last node
    if(del_node-> next == NULL)
        del_node -> prev-> next = NULL;
        del_node->prev = NULL;
    
    // free the memory of del_node
    free(del_node);
}

void dispalyList(struct Node * node)
{
    struct Node* last;
    while(node != NULL)
    {
        cout<<node->data<<" <--> ";
        last = node;
        node = node -> next;
    }

    if(node == NULL)
    cout<<"NULL \n";
}

int main()
{
    //initializing an empty node
    struct Node * start = NULL;
    insertEnd(&start, 5);
    insertEnd(&start, 6);
    insertEnd(&start, 7);
    insertEnd(&start, 9);
    insertEnd(&start, 10);

    deleteNode(&start, start->next->next );
    dispalyList(start);

}
