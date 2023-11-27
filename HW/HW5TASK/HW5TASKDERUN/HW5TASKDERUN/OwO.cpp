#include <iostream>
#include <cstring>

void bubbleSort(int* array, int n)
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n - 1; j++) 
        {
            if (array[j] > array[j + 1]) 
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void countingSort(int* array, int n, int k) 
{
    int* c = (int*)malloc((k + 1) * sizeof(*array));
    memset(c, 0, sizeof(*array) * (k + 1));

    for (int i = 0; i < n; ++i)
    {
        ++c[array[i]];
    }

    int b = 0;
    for (int i = 0; i < k + 1; ++i)
    {
        for (int j = 0; j < c[i]; ++j) 
        {
            array[b++] = i;
        }
    }

    free(c);
}


//функция, сливающая массивы
void merge(int* A, int first, int last) 
{
    int middle, start, final, j;
    int* mas = new int[100];
    middle = (first + last) / 2;  //вычисление среднего элемента
    start = first;                //начало левой части
    final = middle + 1;           //начало правой части
    for (j = first; j <= last; j++)  //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (A[start] < A[final])))
        {
            mas[j] = A[start];
            start++;
        }
        else
        {
            mas[j] = A[final];
            final++;
        }
    //возвращение результата в список
    for (j = first; j <= last; j++)
        A[j] = mas[j];
    delete[] mas;
};
//рекурсивная процедура сортировки
void mergeSort(int* A, int first, int last)
{
    if (first < last)
    {
        mergeSort(A, first, (first + last) / 2);  //сортировка левой части
        mergeSort(A, (first + last) / 2 + 1, last);  //сортировка правой части
        merge(A, first, last);  //слияние двух частей
    }
}

void solveBubbleSort() 
{
    std::cout << "Bubble Sort" << std::endl;
    int arr[10] = { 4, 6, 3, 1, 8, 3, 7, 3, 4, 9 };
    bubbleSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void solveCountingSort()
{
    std::cout << "Counting Sort" << std::endl;
    int arr[10] = { 4, 6, 3, 1, 8, 3, 7, 3, 4, 9 };
    countingSort(arr, 10, 1024);
    for (int i = 0; i < 10; i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void solveMergeSort()
{
    std::cout << "Merge Sort" << std::endl;
    int arr[10] = { 4, 6, 3, 1, 8, 3, 7, 3, 4, 9 };
    mergeSort(arr, 0, 10);
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    solveBubbleSort();
    solveCountingSort();
    solveMergeSort();

    return 0;
}