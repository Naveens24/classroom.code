#include <iostream>
#include <math.h>
using namespace std;

void swap(int &x, int &y)
{
  int temp;
  temp = x;
  x = y;
  y = temp;
}

class MinHeap
{
public:
  int *harr;     // Pointer to array of element in heap
  int capacity;  // Maximum possible size of Min Heap
  int heap_size; // Current number of element in min heap

  MinHeap(int cap)
  {
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
  }

  void linearSearch(int val)
  {
    for (int i = 0; i < heap_size; i++)
    {
      if (harr[i] == val)
      {
        cout << "Value is Found !";
        return;
      }
      cout << "Value is Not Found !";
    }
  }

  void printArray()
  {
    for (int i = 0; i < heap_size; i++)
    {
      cout << harr[i] << " ";
      // cout<<endl;
    }
  }

  int height()
  {
    return ceil(log2(heap_size + 1)) - 1;
  }

  int parent(int i)
  {
    return (i - 1) / 2;
  }

  int left(int i)
  {
    return (2 * i + 1);
  }

  int right(int i)
  {
    return (2 * 1 + 1);
  }

  int getMin(int i)
  {
    return harr[0];
  }

  void insertKey(int k)
  {
    if (heap_size == capacity)
    {
      cout << "Overflow: Couldn't insert element";
      return;
    }

    // First Insert the key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Fix the Heap Property if it get voilated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
      swap(harr[i], harr[parent(i)]);
      i = parent(i);
    }
  }

  // Method to Remove the minumum element from the heap
  int extractMin()
  {
    if (heap_size <= 0)
    {
      return INT_MAX;
    }

    if (heap_size == 1)
    {
      heap_size--;
      return harr[0];
    }

    // Store the minimum value and remove it from the heap

    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);
    return root;
  }

  void MinHeapify(int i)
  {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l] < harr[i])
      smallest = l;

    if (r < heap_size && harr[r] < harr[i])
      smallest = r;

    if (smallest != i)
    {
      swap(harr[i], harr[smallest]); // call by reference
      MinHeapify(smallest);          // Recursive Operation
    }
  }

  void decreaseKey(int i, int new_val)
  {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
      swap(harr[i], harr[parent(i)]);
      i = parent(i);
    }
    
  }

  void deleteKey(int i)
  {
    decreaseKey(i, INT_MIN);
    extractMin();
  }
};

int main()
{
  int s;
  cout << "Enter Size of Min Heap" << endl;
  cin >> s;
  MinHeap obj(s);
  cout << "Min Heap Created" << endl;

  int option, val;

  do
  {
    cout << "What operation do you want to perform? "
         << " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Key/Node" << endl;
    cout << "2. Search Key/Node" << endl;
    cout << "3. Delete Key/Node" << endl;
    cout << "4. Get Min" << endl;
    cout << "5. Extract Min" << endl;
    cout << "6. Height of Heap" << endl;
    cout << "7. Print/Traversal Heap values" << endl;
    cout << "8. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;

    switch (option)
    {
    case 0:
      break;
    case 1:
      cout << "INSERT Operation -" << endl;
      cout << "Enter VALUE to INSERT in HEAP: ";
      cin >> val;
      obj.insertKey(val);
      cout << endl;
      break;
    case 2:
      cout << "SEARCH Operation -" << endl;
      cout << "Enter VALUE to SEARCH in HEAP: ";
      cin >> val;
      obj.linearSearch(val);
      break;
    case 3:
      cout << "DELETE Operation -" << endl;
      cout << "Enter INDEX of Heap Array to DELETE: ";
      cin >> val;
      obj.deleteKey(val);
      break;
    case 4:
      cout << "GET Min value : " << endl;
      // cout << obj.getMin() << endl;
      cout << endl;
      break;
    case 5:
      cout << "EXTRACT Min value : " << endl;
      cout << obj.extractMin();
      cout << endl;
      break;
    case 6:
      //   cout << "HEAP TREE HEIGHT : " << obj.height() << endl;
      break;

    case 7:
      cout << "PRINT Heap Array : ";
      obj.printArray();
      cout << endl;
      break;

    case 8:
      system("cls");
      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
