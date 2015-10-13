#include"MySort.h"
#include<cstdlib>//rand, srand
#include<ctime> //time
#ifndef MYSORT
#define MYSORT


inline void Swap(int &a, int &b){
    int k = a;
    a = b;
    b = k;
}
void bubble_sort(int arr[], int arr_size){
    if(arr_size > 1){
        int size = arr_size;
        for(bool sorted = false; sorted = !sorted; --size)
            for(int i = 1; i < size; ++i)
                if(arr[i-1] > arr[i]){
                    Swap(arr[i-1], arr[i]);
                    sorted = false;
                }
    }
}
void insertion_sort(int arr[], int arr_size){
    if(arr_size > 1){
        int size = arr_size;
        for(int i = 1; i < size; ++i){
            int j = i - 1;
            int key = arr[i];
            while(j >= 0 && arr[j] > key){
                arr[j+1] = arr[j];
                --j; 
            }
            arr[j+1] = key;
        }
    }
}
void selection_sort(int arr[], int arr_size){
    for(int i = 0; i < arr_size - 1; ++i){
        int min = i;
        for(int j = i+1; j < arr_size; ++j)
            if(arr[j] < arr[min])
                min = j;
        Swap(arr[min], arr[i]);
    }
}
//quick sort
/*******************quick sort algorithm 1 *****************
void QuickSort(int arr[], int lo, int hi){
    if(lo < hi){
        int i = lo, j = hi, x = arr[lo];
        while(i < j){
            while(i < j && arr[j] >= x)
                --j;
            if(i < j) 
                arr[i++] = arr[j];
            while(i < j && arr[i] < x)
                ++i;
            if(i < j)
                arr[j--] = arr[i];
        }
        arr[i] = x;
        QuickSort(arr, lo, i-1);
        QuickSort(arr, i+1, hi);
    }
}
*********************************************************/
/****************quick sort algorithm 2******************/
//reload rand to produce random number in a fixed range 
inline int rand(int p, int q){
    int size = q - p + 1;
//    srand(time(NULL));
    return (p + rand() % size);
}
int Partition(int arr[], int lo, int hi){
    //produce ramdom subscript
    int t = rand(lo, hi);
    Swap(arr[t], arr[hi]);

    int index = lo - 1; 
    int key = arr[hi];
    for(int i = lo ; i < hi; i++){
        if(arr[i] <= key)
            Swap(arr[++index], arr[i]);
    }
    Swap(arr[++index], arr[hi]);
    return index;
}
void QuickSort(int arr[], int lo, int hi){
    if(lo < hi){
        int index = Partition(arr, lo, hi);
        QuickSort(arr, lo, index-1);
        QuickSort(arr, index+1, hi);
    }
}

void quick_sort(int arr[], int arr_size){
    QuickSort(arr, 0, arr_size-1);   
}

//meger sort
void Merger(int arr[], int lo, int  mi, int hi){
    int *temp = new int[hi-lo+1];//temporary merger array
    int i = lo, j = mi + 1;//i is for left-hand,j is for right-hand
    int k = 0;//k is for the temporary array
    while(i <= mi && j <=hi){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];            
    }
    //rest elements of left-half
    while(i <= mi)
        temp[k++] = arr[i++];
    //rest elements of right-half
    while(j <= hi)
        temp[k++] = arr[j++];
    //copy the mergered temporary array to the original array
    for(k = 0, i = lo; i <= hi; ++i, ++k)
        arr[i] = temp[k];

    delete []temp;
}
void MergerSort(int arr[], int lo, int hi){
    int mid;
    if(lo < hi){
        mid = (lo + hi) >> 1;
        MergerSort(arr, lo, mid);
        MergerSort(arr, mid+1, hi);
        Merger(arr, lo, mid, hi);
    }
}
void merger_sort(int arr[], int arr_size){
    MergerSort(arr, 0, arr_size-1);   
}
#endif






