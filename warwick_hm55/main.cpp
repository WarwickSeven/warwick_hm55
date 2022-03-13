#include <iostream>

using namespace std;

bool isCheckBalance1 (int *arr, int size, int *b)       //алгоритм для маленьких массивов
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

bool isCheckBalance2 (int *arr, int size, int *b)       //алгоритм для больших массивов
{
    int x = 0, y = 0;
    for (size_t j = 0; j < size/2; j++)                 //проверку начинаем из центра массива
            x += arr[j];
    for (size_t k = size-1; k >= size/2; k--)
            y += arr[k];
    if (x==y)
        *b = size/2;
    else if (x > y)                                     //если сумма левой части выше - искать баланс справа бесполезно
    {
        x = 0;
        y = 0;
        for (int i = size/2 ; i > 0; i--)
        {
            for (size_t j = 0; j < i-1; j++)
                x += arr[j];
            for (size_t k = size-1; k >= i-1; k--)
                y += arr[k];
            if ((x==y)||(x < y))                        //если за 1 шаг баланс сумм стал обратным - дальше искать бесполезно
            {
                *b = i-1;
                break;
            }
            else
            {
                x = 0;
                y = 0;
            }
        }
    }
    else if (x < y)                                     //если сумма правой части выше - искать баланс слева бесполезно
    {
        x = 0;
        y = 0;
        for (int i = size/2 ; i < size-1; i++)
        {
            for (size_t j = 0; j < i+1; j++)
                x += arr[j];
            for (size_t k = size-1; k >= i+1; k--)
                y += arr[k];
            if ((x==y)||(x > y))                       //если за 1 шаг баланс сумм стал обратным - дальше искать бесполезно
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
    }
    cout << x << endl;
    cout << y << endl;
    
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
    const int mySize = 11;
    int myArr[mySize] = { 10,1,1,1,1,1,1,1,1,1,1 };
    int b = 0;
    
    printArray(myArr, mySize);
    if (mySize <= 8)
    {
        if (isCheckBalance1(myArr, mySize, &b))
            cout << "баланс между " << b << " и " << b+1 << " элементами" << endl;
        else
            cout << "баланс отсутствует" << endl;
    }
    else
    {
        if (isCheckBalance2(myArr, mySize, &b))
            cout << "баланс между " << b << " и " << b+1 << " элементами" << endl;
        else
            cout << "баланс отсутствует" << endl;
    }
    return 0;
}
