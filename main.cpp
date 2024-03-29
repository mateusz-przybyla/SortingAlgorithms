#include <iostream>
#include <time.h>

using namespace std;

void bubbleSort(int numbers, int arr[]);
void quicksort(int arr[], int left, int right);
void selectionSort(int numbers, int arr[]);
void insertionSort(int numbers, int arr[]);
void merge(int arr[], int start, int middle, int end);
void mergeSort(int arr[], int start, int end);
bool checkIfArrayIsSorted(int arr[], int numbers);

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
    int *arr2 = new int [numbers];
    int *arr3 = new int [numbers];
    int *arr4 = new int [numbers];
    int *arr5 = new int [numbers];

    srand(time(NULL));

    for (int i = 0; i < numbers; i++)
    {
        arr1[i] = rand()%100000 + 1;
        arr2[i] = arr3[i] = arr4[i] = arr5[i] = arr1[i];
    }

    cout << endl;
    cout << "<<BUBBLE SORT>>" << endl;
    start = clock();
    bubbleSort(numbers, arr1);
    stop = clock();
    sortingTime = (double)(stop - start) / CLOCKS_PER_SEC;

    cout << endl << "Bubble sort time: " << sortingTime << " s" << endl;
    cout << (checkIfArrayIsSorted(arr1, numbers) ? "YES, array is sorted." : "NO, array is not sorted.") << endl << endl;

    cout << "<<QUICKSORT>>" << endl;
    start = clock();
    quicksort(arr2, 0, numbers - 1);
    stop = clock();
    sortingTime = (double)(stop - start) / CLOCKS_PER_SEC;

    cout << endl << "Quicksort time: " << sortingTime << " s" << endl;
    cout << (checkIfArrayIsSorted(arr2, numbers) ? "YES, array is sorted." : "NO, array is not sorted.") << endl << endl;

    cout << "<<SELECTION SORT>>" << endl;
    start = clock();
    selectionSort(numbers, arr3);
    stop = clock();
    sortingTime = (double)(stop - start) / CLOCKS_PER_SEC;

    cout << endl << "Selection sort time: " << sortingTime << " s" << endl;
    cout << (checkIfArrayIsSorted(arr3, numbers) ? "YES, array is sorted." : "NO, array is not sorted.") << endl << endl;

    cout << "<<INSERTION SORT>>" << endl;
    start = clock();
    insertionSort(numbers, arr4);
    stop = clock();
    sortingTime = (double)(stop - start) / CLOCKS_PER_SEC;

    cout << endl << "Insertion sort time: " << sortingTime << " s" << endl;
    cout << (checkIfArrayIsSorted(arr4, numbers) ? "YES, array is sorted." : "NO, array is not sorted.") << endl << endl;

    cout << "<<MERGE SORT>>" << endl;
    start = clock();
    mergeSort(arr5, 0, numbers - 1);
    stop = clock();
    sortingTime = (double)(stop - start) / CLOCKS_PER_SEC;

    cout << endl << "Merge sort time: " << sortingTime << " s" << endl;
    cout << (checkIfArrayIsSorted(arr5, numbers) ? "YES, array is sorted." : "NO, array is not sorted.") << endl << endl;

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
    delete [] arr5;

    return 0;
}

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

void quicksort(int arr[], int left, int right)
{
    int middle = arr[(left + right) / 2];
    int i = 0, j = 0, temp = 0;
    i = left;
    j = right;

    do
    {
        while (arr[i] < middle)
        {
            i++;
        }
        while (arr[j] > middle)
        {
            j--;
        }
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }while(i <= j);

    if (j > left)
    {
        quicksort(arr, left, j);
    }
    if (i < right)
    {
        quicksort(arr, i, right);
    }
}

void selectionSort(int numbers, int arr[])
{
    int minIndex = 0, temp = 0;

    for (int i = 0; i < numbers - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < numbers; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int numbers, int arr[])
{
    int j = 0, temp = 0;

    for (int i = 1; i < numbers; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int arr[], int start, int middle, int end)
{
    int *tempArr = new int[(end - start + 1)];
    int i = start, j = middle + 1, k = 0;

    while (i <= middle && j <= end)
    {
        if (arr[j] < arr[i])
        {
            tempArr[k] = arr[j];
            j++;
        }
        else
        {
            tempArr[k] = arr[i];
            i++;
        }
        k++;
    }

    if (i <= middle)
    {
        while (i <= middle)
        {
            tempArr[k] = arr[i];
            i++;
            k++;
        }
    }
    else
    {
        while (j <= end)
        {
            tempArr[k] = arr[j];
            j++;
            k++;
        }
    }

    for (i = 0; i <= end - start; i++)
    {
        arr[start + i] = tempArr[i];
    }

    delete [] tempArr;
}

void mergeSort(int arr[], int start, int end)
{
    int middle = 0;

    if (start != end)
    {
        middle = (start + end) / 2;
        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);
        merge(arr, start, middle, end);
    }
}

bool checkIfArrayIsSorted(int arr[], int numbers)
{
    bool isSorted = true;
    for (int i = 0; i < numbers - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return isSorted;
}
