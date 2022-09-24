#include<iostream>
using namespace std;

//node creation
struct Node
{
    int data;
    struct Node*prev;
    struct Node*next;
};

void insertEnd(struct Node** start, int data)
{
    // allocate memory for node
    struct Node* newNode = new Node;

    //assign data to newNode
    newNode -> data = data;

    //assign null to next of newNode
    newNode->next = NULL;

    //store the start node temporarily(for later use)
    struct Node* temp = *start;

    //if the linked list is empty, make the newNode as start node
    if(*start == NULL)
    {
        newNode ->prev = NULL;
        *start = newNode;
        return;
    }

    //if the linked list is not empty, traverse to the end of the linked list
    while(temp -> next != NULL)
        temp = temp -> next;
    
    //now, the last node of the linked list is temp
    // assign next of the last node(temp) to newNode
    temp->next = newNode;

    //assign prev of newNode to temp
    newNode -> prev = temp;
    
}

void displayList(struct Node* node)
{
    struct Node * last;
    while(node != NULL)
    {
        cout<<node->data << "<-->";
        last = node;
        node = node->next;
    }
    if(node == NULL)
    cout<<"NULL\n";
}


int main()
{
    //initialize an empty nod
    struct Node * start = NULL;
    insertEnd(&start, 5);
    insertEnd(&start, 6);
    insertEnd(&start, 7);

    displayList(start);

}

int main(){
    
return 0;
}
