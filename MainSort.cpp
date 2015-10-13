#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include"MySort.h"
using namespace std;

//inline  void Swap(int &a, int &b);
//void bubble_sort(int arr[], int arr_size);
//void insertion_sort(int arr[], int arr_size);
//void selection_sort(int arr[], int arr_size);
void print(int arr[], int arr_size);

const int ArrSize = 1000;
int main(){
    //IO redirection from file
    ifstream in("insort.txt");
    streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(in.rdbuf());

    ofstream out("outsort.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    
    int A[ArrSize];
      for(int i = 0; i < ArrSize; ++i)
          cin >> A[i];                
    int B[ArrSize];
    clock_t t1, t2;
 
    //bubble sort
    for(int i = 0; i < ArrSize; ++i)
        B[i] = A[i];
    t1 = clock();
    bubble_sort(B, ArrSize);
    t2 = clock();
    cout << "bubble sort" << endl;
    cout << "Time: " << (double)(t2-t1)/CLOCKS_PER_SEC << endl;
    print(B, ArrSize); 

    //insertion sort
    for(int i = 0; i < ArrSize; ++i)
        B[i] = A[i];
    t1 = clock();
    insertion_sort(B, ArrSize);
    t2 = clock();
    cout << "insertion sort" << endl;
    cout << "Time: " << (double)(t2-t1)/CLOCKS_PER_SEC << endl;    
    print(B, ArrSize); 

    //selection sort
    for(int i = 0; i < ArrSize; ++i)
        B[i] = A[i];
    t1 = clock();
    selection_sort(B, ArrSize);
    t2 = clock();
    cout << "selection sort" << endl;
    cout << "Time: " << (double)(t2-t1)/CLOCKS_PER_SEC << endl;   
    print(B, ArrSize); 

    //quick sort
    for(int i = 0; i < ArrSize; ++i)
        B[i] = A[i];
    t1 = clock();
    quick_sort(B, ArrSize);
    t2 = clock();
    cout << "quick sort" << endl;
    cout << "Time: " << (double)(t2-t1)/CLOCKS_PER_SEC << endl;   
    print(B, ArrSize); 

    //merger sort
    for(int i = 0; i < ArrSize; ++i)
        B[i] = A[i];
    t1 = clock();
    merger_sort(B, ArrSize);
    t2 = clock();
    cout << "merger sort" << endl;
    cout << "Time: " << (double)(t2-t1)/CLOCKS_PER_SEC << endl;   
    print(B, ArrSize); 


    //reset IO
    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);
    return 0;
}


void print(int arr[], int arr_size){
    for (int i = 0; i < arr_size; ++i)
        cout << arr[i] << " ";
    cout <<"\n================================================" << endl;
}





















































