#include <iostream>
using namespace std;
void display( int arr[], int size);
void bubble_sort (int arr[], int size);
void linear_search (int arr[], int size, int value);
int binary_search(int arr[], int size, int value , int low , int high);
void selection_sort(int arr[], int size);
void insertion_sort(int arr[], int size);
void simple_sort(int arr[], int size);
void binary_insertion_sort(int arr[] , int size);
int menu();
int main(){
    int size;
    cout<<"Enter the size of your array: ";
    cin>> size;
    int arr[size];
    for (int i = 0; i < size; i++){
        if (i == 0)
        cout<< "Enter the first element of your array:";
        else if (i==1)
        cout<< "Enter the second element of your array:";
        else if (i==2)
        cout<< "Enter the third element of your array:";
        else
        cout<< "Enter the"<< i + 1 <<"th"<<" element of your array:";
        cin>> arr[i];
    }
     int value;
    switch(menu()){
      case 1 : 
        cout<<"Enter the element you want to search: ";
        cin>> value;
        linear_search(arr,size,value);
        break;
      case 2 :
        cout<<"Enter the element you want to search: ";
        cin>> value;
        binary_search(arr,size,value,0,size - 1);
        break; 
      case 3 :
        bubble_sort(arr, size);
        display(arr, size);
        break;
      case 4 :
        selection_sort(arr, size);
        display(arr, size);
        break;
      case 5 :
        insertion_sort(arr, size);
        display(arr, size);
        break;
      case 6 : 
        simple_sort(arr,size);
        display(arr, size);
        break;
      case 7 :
        binary_insertion_sort(arr, size);
        display(arr , size);
        break;
      default :
        exit(1);
    }
    return 0;
}

 void display( int arr[], int size){
    for (int i =0 ; i < size ; i++){
        cout<<arr[i]<<"\t";
    }
    }
void bubble_sort (int arr[],int size){
for (int i = 0; i < size - 1; i++){
    for (int j = 0 ; j < size - 1 - i; j++){
        if (arr[j] > arr[j + 1]){
            int temp = arr[j];
            arr[j] = arr[j +1];
            arr[j +1] = temp;
        }
    }
}
}
void linear_search (int arr[], int size, int value){
for (int i = 0; i < size; i++){
    if (arr[i] == value){
        cout << "The value is found at index\t"<<i<<"!\n";
    }
    break;
}
cout<< "Value not found!\n";
}
int binary_search(int arr[], int size, int value, int low, int high) { 
    if (low > high) {
        cout << "Value not found in the array!\n";
        return low;
    }

    int mid = (low + high) / 2;

    if (value == arr[mid]) {
        cout << "Value found at index " << mid << "!\n";
        return mid; 
    }
    else if (value < arr[mid]) {
        return binary_search(arr, size, value, low, mid - 1);
    }
    else {
        return binary_search(arr, size, value, mid + 1, high);
    }
}
int menu(){
    int choice;
    cout<<"--------Menu----------\nChoose:\n'1' for Linear Searching\n'2' for Binary Searching\n'3' for Bubble Sorting\n'4' for Selection Sorting\n'5' for Insertion Sorting\n'6' for Simple Sorting\n'7' for Binary Insertion Sorting\n'8' to Exit\n ";
cin >> choice;
return choice;
}
void selection_sort(int arr[], int size){
 for (int i = 0; i < size; i++){
    int min = i;
     for (int j = i + 1; j < size; j++){
        if (arr[min] > arr[j])
        min = j;
     }
     int temp = arr[i];
     arr[i] = arr[min];
    arr[min] = temp;
 }
}
void insertion_sort(int arr[], int size){
    for (int i = 1; i < size ; i++){
        int temp = arr[i];
        int j = i - 1;
        while ( j >= 0 && arr[j] > temp){
          arr[j + 1] = arr[j];
          j--;
        }
      arr[j + 1] = temp; 
    }
}
void simple_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void binary_insertion_sort(int arr[] , int size){
    int temp,pos,j;
    for (int i = 1; i < size; i++){ 
        temp = arr[i];
        j = i - 1;
        pos = binary_search(arr ,size, temp, 0, j);
        while( j >= pos){
            arr[j + 1] = arr[j];
            j--;
        }
            arr[pos] = temp;
    }
}
