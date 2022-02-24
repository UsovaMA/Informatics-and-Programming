//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h> 
//#include "dirent-1.23.2/include/dirent.h"    // для работы с директориями
//#include <sys/stat.h>                           // для установления размера файла
//#include <locale.h>
//#include <time.h>
//#include <malloc.h>
//#include <stdlib.h>
//#include "string.h"
//
//
//#define FILE_COUNT 50
//
///// <summary>
///// функция, возвращающая размер файла
///// </summary>
///// <param name="file">полный или относительный путь до файла</param>
///// <returns>размер файла</returns>
//int getFileSize(const char* file) {
//    struct stat st;
//    int full_size = 0;
//
//    if (stat(file, &st) == 0) {
//        // если это папка
//        if ((st.st_mode & S_IFMT) == S_IFDIR)
//            return -1;
//        // если обычный файл
//        else if ((st.st_mode & S_IFMT) == S_IFREG)
//            return st.st_size;
//        // если что-то иное (сокет, FIFO (именованный канал) и др.)
//        else
//            return -2;
//    }
//}
//
///// <summary>
///// функция, печатающая названия файлов и размеры в каталоге и внутренних подкаталогов
///// </summary>
///// <param name="path">путь до каталога</param>
//void getSizesFromDir(char* path, int fileSizeArray[], char** strs) {
//    struct dirent* cur_file;
//    DIR* dir;
//    int count = 0;
//    char full_file_path[200];
//
//    // открываем рабочую директорию
//    dir = opendir(path);
//
//    // если удалось открыть директорию
//    if (dir) {
//        // считываем файлы внутри директории в переменную cur_file, пока файлы не кончатся
//        while ((cur_file = readdir(dir)) != NULL) {
//            // игнорируем системные папки ./ и ../
//            // если попались записи, начинающиеся на . или .. - пропускаем их
//            if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name)) {
//                // копируем путь в новую переменную, вставляем символ разделителя директории,
//                // добавляем имя элемента (файла или папки)
//                strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
//                // получаем размер или -1, если это не файл, а вложенная папка
//                int cur_file_size = getFileSize(full_file_path);
//                if (cur_file_size >= 0)
//                {
//                    // для файла печатаем его имя и размер
//                    printf("%s - %d B (%d kB)\n", cur_file->d_name, cur_file_size, cur_file_size / 1024);
//                    
//                    fileSizeArray[count] = cur_file_size;
//                    int k;
//                    for (k = 0; cur_file->d_name[k] != '\0'; k++)
//                        strs[count][k] = cur_file->d_name[k];
//                    strs[count][k] = '\0';
//                    count++;
//                }
//                else if (cur_file_size == -1)
//                    // для вложенной папки вызываем РЕКУРСИВНО написанный метод
//                    getSizesFromDir(full_file_path, fileSizeArray, strs);
//            }
//        }
//        // не забываем закрыть директорию
//        closedir(dir);
//    }
//    
//}
//
//
//void bubbleSort(int* num, int size)
//{
//    // Для всех элементов
//    for (int i = 0; i < size - 1; i++)
//    {
//        for (int j = (size - 1); j > i; j--) // для всех элементов после i-ого
//        {
//            if (num[j - 1] > num[j]) // если текущий элемент меньше предыдущего
//            {
//                int temp = num[j - 1]; // меняем их местами
//                num[j - 1] = num[j];
//                num[j] = temp;
//            }
//        }
//    }
//}
//
//void merge(int* a, int n)
//{
//    int mid = n / 2; // находим середину сортируемой последовательности
//    if (n % 2 == 1)
//        mid++;
//    int h = 1; // шаг
//    // выделяем память под формируемую последовательность
//    int* c = (int*)malloc(n * sizeof(int));
//    int step;
//    while (h < n)
//    {
//        step = h;
//        int i = 0;   // индекс первого пути
//        int j = mid; // индекс второго пути
//        int k = 0;   // индекс элемента в результирующей последовательности
//        while (step <= mid)
//        {
//            while ((i < step) && (j < n) && (j < (mid + step)))
//            { // пока не дошли до конца пути
//              // заполняем следующий элемент формируемой последовательности
//              // меньшим из двух просматриваемых
//                if (a[i] < a[j])
//                {
//                    c[k] = a[i];
//                    i++; k++;
//                }
//                else {
//                    c[k] = a[j];
//                    j++; k++;
//                }
//            }
//            while (i < step)
//            { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
//                c[k] = a[i];
//                i++; k++;
//            }
//            while ((j < (mid + step)) && (j < n))
//            {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
//                c[k] = a[j];
//                j++; k++;
//            }
//            step = step + h; // переходим к следующему этапу
//        }
//        h = h * 2;
//        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
//        for (i = 0; i < n; i++)
//            a[i] = c[i];
//    }
//}
//
//void hSort(int* A, int N) //N - длина массива A
//{
//    int temp;
//    if (N <= 1)
//        return;
//    int l = 0, r = N - 1; //l - левая граница, r - правая
//    int pivot = A[rand() % N];
//    while (l != r)
//    {
//        if (A[l] >= pivot)
//        {
//            if (A[r] < pivot)
//            {
//                temp = A[l];
//                A[l] = A[r];
//                A[r] = temp;
//                l++;
//            }
//            if (l != r) r--;
//        }
//        else l++;
//    }
//    if (A[0] == A[N - 1]) return; //проверка на то, что мы сортируем не одинаковые элементы, чтоб не зацикл.
//    hSort(A, l);
//    hSort(A + l, N - l);
//}
//
//int main() {
//    char path[200];
//    
//   
//
//    int* mass = NULL, *fileSizeArray = NULL, *fileSizeArray2, *fileSizeArray3, sort = 0;
//    char* froBubblel;
//
//    
//
//    char** strs = (char**)malloc(FILE_COUNT * sizeof(char*));
//    for (int i = 0; i < FILE_COUNT; i++) {
//        strs[i] = (char*)malloc(100 * sizeof(char));
//    }
//
//    for (int i = 0; i < FILE_COUNT; i++)
//    {
//        for (int j = 0; j < FILE_COUNT; j++)
//        {
//            strs[i][j] = ' ';
//        }
//       
//    }
//
//    fileSizeArray = (int*)malloc(FILE_COUNT * sizeof(int));
//    fileSizeArray2 = (int*)malloc(FILE_COUNT * sizeof(int));
//    fileSizeArray3 = (int*)malloc(FILE_COUNT * sizeof(int));
//
//    
//
//    // считываем путь (по сути scanf_s для строки)
//    printf("Input path to dir: ");
//    gets(path);
//    getSizesFromDir(path, fileSizeArray, strs);
//
//    int j = 0;
//
//    for (int i = 0; i < FILE_COUNT; i++) {
//        for (j = 0; j < 100; j++) {
//            printf("%c", strs[i][j]);
//        }
//        printf("\n");
//        j = 0;
//        
//    }
//
//    printf("\n------------------------------------------------------\n");
//    for (int i = 0; i < FILE_COUNT; i++)
//    {
//        if (fileSizeArray[i] > 0)
//        {     
//              printf("\n%d", fileSizeArray[i]);
//        }
//    }
//    printf("\n------------------------------------------------------\n");
//    for (int i = 0; i < FILE_COUNT; i++)
//    {
//        fileSizeArray2[i] = fileSizeArray[i];
//    }
//
//    for (int i = 0; i < FILE_COUNT; i++)
//    {
//        fileSizeArray3[i] = fileSizeArray[i];
//    }
//    printf("sort type:");
//    scanf_s("%d", &sort);
//    switch(sort)
//    {
//
//        case 1: 
//        {
//            bubbleSort(fileSizeArray2, FILE_COUNT);
//            printf("bubbleSort: \n");
//            for (int i = 0; i < FILE_COUNT; i++)
//            {
//                if (fileSizeArray2[i] > 0)
//                {
//                    printf("\n%d", fileSizeArray2[i]);
//                }
//            }
//            break;
//        }
//
//        case 2:
//        {
//            merge(fileSizeArray3,FILE_COUNT);
//            printf("mergesort: \n");
//
//            for (int i = 0; i < FILE_COUNT; i++)
//            {
//                if (fileSizeArray3[i] > 0)
//                {
//                    printf("\n%d", fileSizeArray3[i]);
//                }
//            }
//            break;
//        }
//          
//        case 3:
//        {
//            hSort(fileSizeArray, FILE_COUNT);
//            printf("hSort: \n");
//            for (int i = 0; i < FILE_COUNT; i++)
//            {
//                if (fileSizeArray[i] > 0)
//                {
//                    printf("\n%d", fileSizeArray[i]);
//                }
//            }
//            break;
//        }
//    }
//    
//    return 0;
//}
//
//
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include "dirent-1.23.2/include/dirent.h"
#include <sys/stat.h>     
#include <locale.h>
#include <time.h>

/// <summary>
/// функция, печатающая названия файлов и размеры в каталоге и внутренних подкаталогов
/// </summary>
/// <param name="path">путь до каталога</param>
void getSizesFromDir(char* path, int fileSizeArray[], char** strs) {
    struct dirent* cur_file;
    DIR* dir;
    int count = 0;
    char full_file_path[200];

    // открываем рабочую директорию
    dir = opendir(path);

    // если удалось открыть директорию
    if (dir) {
        // считываем файлы внутри директории в переменную cur_file, пока файлы не кончатся
        while ((cur_file = readdir(dir)) != NULL) {
            // игнорируем системные папки ./ и ../
            // если попались записи, начинающиеся на . или .. - пропускаем их
            if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name)) {
                // копируем путь в новую переменную, вставляем символ разделителя директории,
                // добавляем имя элемента (файла или папки)
                strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
                // получаем размер или -1, если это не файл, а вложенная папка
                int cur_file_size = getFileSize(full_file_path);
                if (cur_file_size >= 0)
                {
                    // для файла печатаем его имя и размер
                    printf("%s - %d B (%d kB)\n", cur_file->d_name, cur_file_size, cur_file_size / 1024);
                    int i, k;;
                    fileSizeArray[i] = cur_file_size;
                    int k;
                    for (k = 0; cur_file->d_name[k] != '\0'; k++)
                        strs[i][k] = cur_file->d_name[k];
                    strs[i][k] = '\0';
                    i++;
               
                }
                else if (cur_file_size == -1)
                    // для вложенной папки вызываем РЕКУРСИВНО написанный метод
                    getSizesFromDir(full_file_path, fileSizeArray, strs);
            }
        }
        // не забываем закрыть директорию
        closedir(dir);
    }
    
}

void selectionSort(int* arr1, char** arr2, int size) {
    for (int i = 0; i < size - 1; i++)
    {
        int min_i = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr1[j] < arr1[min_i])
            {
                min_i = j;
            }
        }

        if (min_i != i)
        {
            int temp = arr1[i];
            arr1[i] = arr1[min_i];
            arr1[min_i] = temp;

            char* temp2 = arr2[i];
            arr2[i] = arr2[min_i];
            arr2[min_i] = temp2;

        }
    }

    int j = 0;

    for (int i = 0; i < size; i++) {
        for (j = 0; j < 100; j++) {
            printf("%c", arr2[i][j]);
        }
        j = 0;
        printf(" - %d (B) (%d kB)\n", arr1[i], arr1[i] / 1024);
    }
}

void quickSort(int* arr1, int size, int first, int last, char** arr2)
{

    int i = first, j = last;
    int x = arr1[(first + last) / 2];
    do {
        while (arr1[i] < x) {
            i++;
        }
        while (arr1[j] > x) {
            j--;
        }

        if (i <= j)
        {
            if (i != j && arr1[i] != arr1[j])
            {
                int temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;

                char* temp2 = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp2;
            }
            i++;  j--;
        }
    } while (i <= j);

    if (i < last)
        quickSort(arr1, size, i, last, arr2);
    if (first < j)
        quickSort(arr1, size, first, j, arr2);
    if (i == ((size - 1) / 2)) {
        for (int i = 0; i < size; i++) {
            for (j = 0; j < 100; j++) {
                printf("%c", arr2[i][j]);
            }
            j = 0;
            printf(" - %d (B) (%d kB)\n", arr1[i], arr1[i] / 1024);
        }
    }
}


#define MAX_FILE_COUNT 20

int main() {

    setlocale(LC_ALL, "LC_CTYPE=.utf8");

    char path[200];

    struct dirent* cur_file;
    DIR* dir;

    int file_count = 0;

    char full_file_path[200];

    int fileSizeArray[MAX_FILE_COUNT];

    char** strs = (char**)malloc(MAX_FILE_COUNT * sizeof(char*));
    for (int i = 0; i < MAX_FILE_COUNT; i++) {
        strs[i] = (char*)malloc(100 * sizeof(char));
    }

    char** strs2 = (char**)malloc(MAX_FILE_COUNT * sizeof(char*));
    for (int i = 0; i < MAX_FILE_COUNT; i++) {
        strs2[i] = (char*)malloc(100 * sizeof(char));
    }

    char** strs3 = (char**)malloc(MAX_FILE_COUNT * sizeof(char*));
    for (int i = 0; i < MAX_FILE_COUNT; i++) {
        strs3[i] = (char*)malloc(100 * sizeof(char));
    }

    int exit = 0;

   
    printf("Input path to dir: ");
    gets(path);

    
    dir = opendir(path);

    file_count = getSizesFromDir(path, strs, fileSizeArray);

    do {

        int cFileSizeArray[MAX_FILE_COUNT];
        int cFileSizeArray2[MAX_FILE_COUNT];

        for (int i = 0; i < file_count; i++) {
            strs2[i] = strs[i];
        }

        for (int i = 0; i < file_count; i++) {
            strs3[i] = strs[i];
        }

        for (int i = 0; i < file_count; i++) {
            cFileSizeArray[i] = fileSizeArray[i];
        }

        for (int i = 0; i < file_count; i++) {
            cFileSizeArray2[i] = fileSizeArray[i];
        }

        int sortSelect;

        printf("Enter type of sort you would like to do (1 - Selection, 2 - Quick, 3 - Merge): ");
        scanf_s("%d", &sortSelect);

        switch (sortSelect) {
        case 1: {
            printf("-------------------------------------------\n");
            int time = clock();
            selectionSort(fileSizeArray, testchar2, file_count);
            time = clock() - time;
            printf("%d - time of work (ms)", time);
            break;
        }
        case 2: {
            printf("-------------------------------------------\n");
            int time = clock();
            quickSort(cFileSizeArray, file_count, 0, file_count - 1, testchar3);
            time = clock() - time;
            printf("%d - time of work (ms)", time);
            break;
        }

        case 3: {
            printf("-------------------------------------------\n");
            int time = clock();
            mergeSort(cFileSizeArray2, testchar4, 0, file_count - 1, file_count);
            time = clock() - time;
            printf("%d - time of work (ms)", time);
            break;
        }

        default: {
            printf("-------------------------------------------\n");
            printf("Error, wrong input.");
            break;
        }
        }
        printf("\nDo you want to exit the program? 1/0: ");
        scanf_s("%d", &exit);
    } while (exit != 1);

    return 0;
}