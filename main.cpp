#include <iostream>
#include <time.h>

using namespace std;

void bubbleSort(int numbers, int arr[])
{
    int temp = 0;

    for (int i = 1; i < numbers; i++)
    {
        for (int j = numbers - 1; j >= i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int numbers = 0;
    clock_t start, stop;
    double sortingTime = 0;

    cout << ">>>> COMPARISON OF SORTING ALGORITHMS <<<<" << endl;
    cout << "==========================================" << endl << endl;
    cout << "Enter the number of elements: ";
    cin >> numbers;

    int *arr1 = new int [numbers];

    srand(time(NULL));

    for (int i = 0; i < numbers; i++)
    {
        arr1[i] = rand()%100000 + 1;
    }

    cout << endl;
    cout << "<<BUBBLE SORT>>" << endl;
    start = clock();
    bubbleSort(numbers, arr1);
    stop = clock();
    sortingTime = (double)(stop - start) / CLOCKS_PER_SEC;

    cout << endl << "Bubble sort time: " << sortingTime << " s" << endl;

    delete [] arr1;

    return 0;
}
