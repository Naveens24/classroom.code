/* Here we are sorting the element by comparing the one element to the other element and with than go on
arranging  the less element to the left and the rest putting on the right side.

*/

#include <iostream>
using namespace std;

void selectionSort(int arr[])
{
    for (int i = 0; i < 4; i++)
    {
        int min = i;

        for (int j = i + 1; j < 5; j++) // Nested for-> this will iterate the value and check the all elements wheteher it is greate to the current elemet (i) or not ?
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int myarr[5];
    cout << "Enter 5 Integers in random order: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> myarr[i];
    }

    cout << "UNSORTED ARRAY: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << myarr[i] << " ";
    }
    cout << endl;
    selectionSort(myarr); // Sorting actually happening

    cout << "SORTED ARRAY: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << myarr[i] << " ";
    }
    return 0;
}
