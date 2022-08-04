/*
1. Understanding of what is linked list & Singly linked list
2. C++ Objects & Classes
3. Pointer in C++
4. Dynamic Memory allocation

Operations
1. appendNode()
2. prependNode()
3.insertNodeAfter()
4. deleteNodeByKey()
5. updateNodeByKey()
6. print()
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next; // [key, data, next]

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        head = NULL;
    }

    SinglyLinkedList(Node *n)
    {
        head = n; // To take the head of the node in linked list
    }

    Node* nodeExists(int k)    // To check that node exists or not (i.e not same key for two nodes...)
    {
        Node* temp = NULL; // To traverse the list to the end of the list i.e node1->node2->node-3

        Node* ptr = head;
        while(ptr != NULL)  // If ptr(pointer as given in )
        {
            if(ptr->key==k)  // it will only execute when the k is equal to the head node( i.e. n1)
            {
                temp=ptr;
            }
            // Traverse the entire linked list using the address the n1 will point and store the adderess of the node 2nd i.e.n1
            ptr = ptr->next;  // storing the address of the next node in the ptr
        }
        return temp;
    }

    // 2. Append a node to the list (at the end of the last node)

    void appendNode(Node *n)   // for this firstly we need to check that the address of the new node must not me same as the already existing node
    {
        if(nodeExists(n->key)!=NULL)  // To check that node doesn't exist
        {
            cout<<"Node Already exists with key value: "<<n->key<<". Append another node with different key value:"<<endl;

        }
        else
        {
            if(head==NULL)   // head of the list will only NULL if it is not pointing to the any key
            {
                head = n;
                cout<<"Node Appended"<<endl;
            }
            else{
                Node* ptr = head;   // created pointer as Node make it equal to head(first node)
                while (ptr->next!=NULL)  //traverse (checking) until the next value of the node is not equal to the NULL
                {                        // If equal to the node
                    ptr=ptr->next;       // code to append the ptr(last Node value address) to be store(link) to the new node       
                }
                ptr -> next=n; // stored the address of 3rd node to the second
                cout<<"Node Appended"<<endl; 
            }
        }
    }

// 3. Prepend Node - Attach a node at the start
void prependNode(Node *n)
{
    if(nodeExists(n->key)!=NULL)
    {
        cout<<"Node Already exists with key value: "<<n->key<<". Append anothe node with different key value"<<endl;
    }
    else   // No need to traverse the list till last node (bit easy just've to attach in the start)
    {
        n->next=head; // storing the value of the head(fist node) in the new node
        head =n; // now it will make the new node as the head of the list 
        cout<<"Node Prepended "<<endl;
    }

}

//4. Inset a Node after a particular node in the list
void insertNodeAfter(int k, Node *n)  // Two argument - > int k( key value aft which the new node to be added), Node *n(pass by address) the node which we are going to attach
{// Now we just not only traverse the list but also to exist it
    Node* ptr = nodeExists(k); // ptr directly point to the node whose key value is k.
    if(ptr==NULL)
    {
        cout<<"No node exists with key value: "<<k<<endl;
    }
    else
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"Node Already exists with key value: "<<n->key<<". Append another node with different key value"<<endl;

        }
        else
        {
             // firstly link the newly added n4(btw n2-n3) to n3
            n->next=ptr->next; // n(n2 key value) of ->next value is equal to the next value of n4 which is linking with the n3
            ptr->next=n;
            cout<<"Node Inserted"<<endl;
        }
    }
}
//5. Delete(unlinking) node by unique key
void deleteNodeByKey(int k)
{
    if(head==NULL) // checking whether the linked list exist or not
    {
        cout <<"Singly Linked list already empty. can't delete"<<endl;
    }
    // If linked list exist
    else if(head!=NULL) // checking fist that the node we want to dlt is whether head node or not
    {// If yes
        if(head->key==k) // Head value changed to the n1 to n2
        {
            head = head->next; // changed to n2
            cout<<"Node UNLINKED with keys value: "<<k<<endl;
        }
        else
        {
            Node* temp= NULL;
            Node* prevptr = head;  // prevptr(previous pointer) is equal to the head(bcz it is the node whom we are going to link with the n3 and going to store the value of the n2 in head)
            Node* currentptr = head->next; // current pointer (the pointer which want to delete)
            while(currentptr!=NULL)  // checking whether the current pointer is null or not 
            {
                if(currentptr->key==k)
                {
                    temp = currentptr; // assigning temporary location to store the data of the node which we are going to delete that is currentptr
                    currentptr=NULL; // making the currentptr null
                }
                else{
                    prevptr = prevptr->next;
                    currentptr=currentptr->next;
                }
            }
            if(temp!=NULL)
            {
                prevptr->next=temp->next; // assiging next value(the address of upcoming node) to the value stored the temp location(value of currentptr)
                cout<<"Node UNLINKED with keys value: "<<k<<endl;

            }
            else{
                cout<<"Node Doesn't exist with key value : "<<k<<endl;
            }
        }
    }
}

// 6. update the existing node
void updateNodeByKey(int k, int d) // k->key value , d -> data value
{
    Node* ptr =  nodeExists(k); // checking that the key value exist or not-> if yes it will get stored in the ptr
    if(ptr!=NULL) // if not null
    {
        ptr->data=d; // this ptr assign the value to data that is equal to d
        cout<<"Node Data Updated Successfully "<<endl;
    }
    else{
        cout <<"Node doesn't exist with key value: "<<k<<endl;
    }
}

//7. printing 
void printList()
{
    if(head==NULL)
    {
        cout<<"No Nodes in Singly Linked List ";
    }
    else
    {
    cout<<endl<<"Singly Linked List values: ";
    Node*temp = head;

    while(temp!=NULL)
    {
        cout<<"("<<temp ->key<<","<<temp->data<<") -->";
        temp = temp ->next;
    }
    }
}
 

};

int main()
{
    SinglyLinkedList s;
    int option;
    int key1, k1, data1;
   do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();  // dynamic memory allocation , each time new value is allocated and old data doesn't destroyed
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      s.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.updateNodeByKey(key1, data1);

      break;
    case 6:
      s.printList();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
