#include <iostream>

using namespace std;

bool isCheckBalance1 (int *arr, int size, int *b)
{
    int x = 0, y = 0;
    for (int i = 0; i < size-1; i++)
    {
        for (size_t j = 0; j <= i; j++)
            x += arr[j];
        for (size_t k = size-1; k > i; k--)
            y += arr[k];
        if (x==y)
        {
            *b = i+1;
            break;
        }
        else
        {
            x = 0;
            y = 0;
        }
    }
    return ((x == y)&&(x!=0));
}


void printArray (int *arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
cout << endl;
}

int main()
{
    const int mySize = 8;
    int myArr[mySize] = { 7,1,1,1,1,1,1,7 };
    int b = 0;
    printArray(myArr, mySize);
    if (isCheckBalance1(myArr, mySize, &b))
        cout << "баланс массива между " << b << " и " << b+1 << " элементами" << endl;
    else
        cout << "баланс отсутствует" << endl;
    return 0;
}
