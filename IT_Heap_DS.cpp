#include <iostream>
#define SPACE 10

using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    TreeNode *root;
    BST()
    {
        root = NULL;
    }
    bool isTreeEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insertNode(TreeNode *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            cout << "Value Inserted as root node!" << endl;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (new_node->value == temp->value)
                {
                    cout << "Value Already exist,"
                         << "Insert another value!" << endl;
                    return;
                }
                else if ((new_node->value < temp->value) && (temp->left == NULL))
                {
                    temp->left = new_node;
                    cout << "Value Inserted to the left!" << endl;
                    break;
                }
                else if (new_node->value < temp->value)
                {
                    temp = temp->left;
                }
                else if ((new_node->value > temp->value) && (temp->right == NULL))
                {
                    temp->right = new_node;
                    cout << "Value Inserted to the right!" << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    void print2D(TreeNode *r, int space)
    {
        if (r == NULL) // Base case  1
            return;
        space += SPACE;           // Increase distance between levels   2
        print2D(r->right, space); // Process right child first 3
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5
            cout << " ";                    // 5.1
        cout << r->value << "\n";           // 6
        print2D(r->left, space);            // Process left child  7
    }

    void printPreorder(TreeNode*r) // (Current node, Left, Right)
    {
        if(r==NULL)
        return;
        // first print data of node
        cout<<r->value<<" ";
        // then recur on left subtree
        printPreorder(r->left);
        // now recur on right subtree
        printPreorder(r->right);
    }

    void printInorder(TreeNode *r)   //(Left, Current node, Right)
    {
        if(r==NULL)
        return;
        printInorder(r->left);//recurision to go to the left of the node
        cout<<r->value<<" "; // Print the value of the node
        printInorder(r->right);// recursion to go to the right of the node

    }

    void printPostorder(TreeNode *r)
    {
        if(r==NULL)
        return;

        printPostorder(r->left);
        printPostorder(r->right);
        cout<<r->value<<" ";
    }

    TreeNode* iterativeSearch(int val)
    {
        if(root==NULL)
        {
            return root;

        }
        else
        {
            TreeNode *temp=root;
            while (temp != NULL)
            {
                if (val == temp->value)
                {
                    return temp;
                }
                else if(val < temp->value)
                {
                    return temp = temp->left;
                }
                else
                {
                    temp=temp->right;
                }
                   
            }
            return NULL;
            
        }
    }
    int height(TreeNode* r)
    {
        if(r==NULL)
            return -1;
        
        else
        {
            int lheight = height(r->left);
            int rheight = height(r->right);

            if(lheight>rheight)
             return(lheight + 1);
            else
                return(rheight +1);
            
        }

    }
    
    // 1. Breadth first search
    void printGivenLevel(TreeNode *r, int level)
    {
        if (r==NULL)
          return;
        else if (level == 0)
        {
            cout << r->value<<" ";
        }
        else  //Level > 0
        {
            printGivenLevel(r->left, level-1);
            printGivenLevel(r->right, level-1);
        }
        
    }

    // 2. Breadth first search
    void PrintLevelOrderBFS(TreeNode *r)
    {
        int h= height(r);   // using Height function to calculate height of BST
        for (int i = 0; i <= h; i++)
        {
            printGivenLevel(r,i);
        }
        
    }

    TreeNode* minValueNode(TreeNode* node)
    {
    TreeNode* current = node;
    while(current->left != NULL)
    {
        current = current -> left;
    }

    return current;
    }

    TreeNode* deleteNode(TreeNode* r, int v)
    {
        // Base case
        if (r == NULL)
        {
            return NULL;
        }
        
        //If the key to be deleted is smaller than the root's key,and value
        //Then it lies in left subtree.
        else if(v<r->value)
        {
            r->left = deleteNode(r->left, v);
        }

        else if(v> r-> value)
        {
            r->right = deleteNode(r->right, v);
        }

        //If key is same as root's key, then this is the node to
        else
        {
            //node with only one child or no child
            if(r->left == NULL)
            {
                TreeNode* temp = r->right;
                delete r;
                return temp;
            }

            else if(r->right == NULL)
            {
                TreeNode* temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                //node with two children: Get the inorder successor
                // in the right subtree
                TreeNode* temp = minValueNode(r->right);
                // Copy the inorder successor's content to this node 
                r->value = temp->value;
                //Delete the inorder successor
                r->right = deleteNode(r->right, temp->value);
                //deleteNode(r->right, temp->value);
            }
            
        }
        return r;

    }
    
    // Get Balance factor of Node n
    
    int getBalanceFactor(TreeNode *n)
    {
        if(n==NULL)
        return -1;
        else
        return height(n->left) - height(n->right);
    }
    
    TreeNode *rightRotate(TreeNode *y)
    {
        TreeNode *x = y-> left;
        TreeNode *T2 = x->right;
        
        //Perform Rotation
        x->right = y;
        y->left = T2;

        return x;
    }

    TreeNode *leftRotate(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;

        // Perform Rotation
        y->left = x;
        x->right = T2;
        return y;
    }

    TreeNode *insert( TreeNode *r, TreeNode*new_node)
    {
        if(r==NULL)
        {
            r=new_node;
            return r;
        }
        if (new_node -> value < r->value)
        {
            r->left = insert(r->left, new_node);

        }
        else if(new_node -> value < r->value)
        {
            r->right = insert(r->right, new_node);

        }
        else 
        {
            cout<<"NO DUPLICATES VALUE"<<endl;
            return r;
        }
        
        int bf = getBalanceFactor(r);

        //Left-Left Rotation case
        if(bf>1 && new_node -> value < r->left->value);
        return rightRotate(r);

        //Left - Right Rotation case
        if (bf < 1 && new_node -> value > r->left->value);
        {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }

        //Right-right Rotation case
        if(bf>-1 && new_node->value > r->right->value)
        return leftRotate(r);
        

        //Right-Left Rotation case
        if(bf<-1 && new_node->value > r->right->value)
        {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }
        return r;

    }
    


};

int main()
{
    BST obj;
    int option, val;

    do
    {
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal BST values" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        // Node n1;
        TreeNode *new_node = new TreeNode();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT" << endl;
            cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
            cin >> val;
            new_node->value = val;
            obj.root = obj.insert(obj.root, new_node);
            // obj.insertNode(new_node);
            cout << endl;
            break;

        case 2:
            cout << "SEARCH" << endl;
            cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
            cin >> val;
            new_node = obj.iterativeSearch(val);
            
            if (new_node != NULL)
            {
                cout << "Value found" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 3:
            cout << "DELETE" << endl;
            cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
            cin >> val;
            new_node = obj.iterativeSearch(val);
            
            if (new_node != NULL)
            {
                obj.deleteNode(obj.root, val);
                cout << "Value Deleted" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 4:
            cout << "PRINT 2D: " << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            cout << "Print Level Order BFS: \n";
            obj.PrintLevelOrderBFS(obj.root);
            cout<<endl;
            //   obj.printPreorder(obj.root);
            //   cout<<endl;
            //   obj.printInorder(obj.root);
            //   cout<<endl;
            //   obj.printPostorder(obj.root);
            //   cout<<endl;
            cout << endl;
            
            break;
        case 5:
            cout << "TREE HEIGHT" << endl;
              cout << "Height : " << obj.height(obj.root) << endl;
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}
