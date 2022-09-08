#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;

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

class CircularLinkedList
{
public:
    Node *head;
    CircularLinkedList()
    {
        head = NULL;
    }

    // 1. Check if node exists using key value
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        if (ptr == NULL)
        {
            return temp;
        }
        else
        {
            do
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            } while (ptr != head);
            return temp;
        }
    }

    // 2. Append a node to the list
    void appendNode(Node *new_node)
    {
        if (nodeExists(new_node->key) != NULL)
        {
            cout << "Node Already exists with key value: " << new_node->key
                 << ". Append another node with different key value" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = new_node;       // new_node will be the head node
                new_node->next = head; // here the new_node of the next value points to the head node.
                cout << "Node Appended at first head position" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head) // loop to iterate the list untill it reaches to the head(circular list )
                {
                    ptr = ptr->next; // ptr will go as n1->n2->n3-----n.n
                }
                ptr->next = new_node;
                new_node->next = head;
                cout << "Node Appended " << endl;
            }
        }
    }

    // 3. Prepend Node- Attach a node at the beginning of the list
    void prependNode(Node *new_node)
    {
        if (nodeExists(new_node->key) != NULL)
        {
            cout << "Node Already exists with the key value : " << new_node->key
                 << ". Append anothe node with different key value" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = new_node;
                new_node->next = head;
                cout << "Node prepended at first Head position " << endl;
            }

            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = new_node; // let n4(new_node)->n1->n2->n3 , ptr is n3 whose next will point to n4(new_node)
                new_node->next = head;
                head = new_node;
                cout << "Node prepended " << endl;
            }
        }
    }
    // 4. Insert a Node afater a parivualr node in the list
    void insertNodeAfter(int k, Node *new_node)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with key value of: " << k << endl;
        }
        else
        {
            if (nodeExists(new_node->key) != NULL)
            {
                cout << "Node Already exists with key value :" << new_node->key
                     << ". Append another node with different key value" << endl;
            }
            else
            {
                if (ptr->next == head) // checking that the key is last node or not
                {
                    new_node->next = head; // inserting at the end.
                    ptr->next = new_node;
                    cout << "Node Inserted at the End " << endl;
                }
                else // inserting between
                {
                }
            }
        }
    }

    // Delete the node

    void DeleteNodeByKey(int k)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with key value of : " << k << endl;
        }
        else
        {
            if (ptr == head)
            {
                if (head->next == NULL)
                {
                    head = NULL;
                    cout << "Head node Unliked... Empty list ";
                }
                else
                {
                    Node *ptr1 = head;
                    while (ptr1->next != head) // traverse the list here
                    {
                        ptr1 = ptr1->next;
                    }
                    ptr1->next = head->next;
                    head = head->next;
                    cout << "Node UNLINKED with key value : " << k << endl;
                }
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                prevptr->next = temp->next;
                cout << "Node UNLINKED with keys value: " << k << endl;
            }
        }
    }
    // 6th update node
    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node data updated successfully..." << endl;
        }
        else
        {
            cout << "Node Doesn't exist with key value : " << k << endl;
        }
    }

    // 7. Printing
    void printList() {
    if (head == NULL) {
      cout << "No Nodes in Circular Linked List";
    } else {
      cout << endl << "head address : " << head << endl;
      cout << "Circular Linked List Values : " << endl;

      Node * temp = head;

      do {
        cout << "(" << temp -> key << "," << temp -> data << "," << ") --> ";
        temp = temp -> next;
      } while (temp != head);
    }

  }
};

int main()
{
    CircularLinkedList obj;
    int option;
    int key1, k1, data1;

    do
    {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;

        cin >> option;
        Node *n1 = new Node();

        switch (option)
        {
        case 0:
            break;

        case 1:
            cout << "Append Node operation \nEnter the key and data of the node to append: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.appendNode(n1);
            break;

        case 2:
            cout << "Prepend Node operation\n Enter the key and data of the node to prepend: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.prependNode(n1);
            break;

        case 3:
            cout << "Insert Node Operation \nEnter key of existing Node after which you want to Insert this New node : " << endl;
            cin >> k1;
            cout << "Enter the key and the data of the new node: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.insertNodeAfter(k1, n1);
            break;

        case 4:
            cout << "Delete Node Operation \nEnter the key of the node which you want to delete : " << endl;
            cin >> k1;
            obj.DeleteNodeByKey(k1);
            break;

        case 5:
            cout << "Update  Node By Key Operation\n Enter the Key and New data " << endl;
            cin >> key1;
            cin >> data1;
            obj.updateNodeByKey(key1, data1);
            break;

        case 6:
            cout << " The Linked List are: " << endl;
            obj.printList();
            break;
        case 7:
            system("cls");
            break;

        default:
            cout << "Enter the proper option number as given above"; 
            break;
        }

    } while (option != 0);
    return 0;
}

// everyone is not talented but everyone are unique on there one and there that uniqeness make the unique from other
