#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int numbers = 0;

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

    delete [] arr1;

    return 0;
}
