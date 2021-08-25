#include <iostream> //for cout, endl, etc.
#include <cstdlib> //for rand()
#include <ctime> //for clock()
#include <algorithm> //for reverse()

using namespace std; //for cout, endl, etc.

void insertionSort(int* arr, int n);
void selectionSort(int* arr, int n);
void bubbleSort(int* arr, int n);
void mergeSort(int* arr, int n);
void mergeSort(int* arr, int start, int end);
void merge(int* arr, int start, int end);
void quickSort(int* arr, int n);
int partition(int* arr, int start, int end);
void quickSort(int* arr, int start, int end);
void systemSort(int* arr, int n);

bool isDescending(int* arr, int n);
void print(int* arr, int n);

int main()
{ 
    int size = 15;
    int arrIn[size];

    long start, end;
/*
    srand(time(NULL)); //for diff random number each time
    for (int i = 0; i < size; i++) 
    {
        arrIn[i] = rand()% size;
    }
    //cout << "before sorting"<<endl;
    //print(arrIn, size);
    cout<<endl;
    
    
    start = clock();
    insertionSort(arrIn, size);
    end = clock();
    cout << "after insertion sort: " << endl;
    //print(arrIn, size);
    if(isDescending(arrIn, size))
        cout << "YES, the array is in descending order."<<endl;
    else
        cout<< "Not in descending order."<<endl;
    cout << "insertion sort: " << (end-start)/(double)(CLOCKS_PER_SEC/1000) << " ms" << endl;
    cout << endl;

    srand(time(NULL)); //for diff random number each time
    for (int i = 0; i < size; i++) 
    {
        arrIn[i] = rand()% size;
    }
    //cout << "before sorting"<<endl;
    //print(arrIn, size);
    cout<<endl;
    
    start = clock();
    selectionSort(arrIn, size);
    end = clock();
    cout << "after selection sort: " << endl;
    //print(arrIn, size);
    if(isDescending(arrIn, size))
        cout << "YES, the array is in descending order."<<endl;
    else
        cout<< "Not in descending order."<<endl;
    cout << "selection sort: " << (end-start)/(double)(CLOCKS_PER_SEC/1000) << " ms" << endl;
    cout << endl;
    
    srand(time(NULL)); //for diff random number each time
    for (int i = 0; i < size; i++) 
    {
        arrIn[i] = rand()% size;
    }
    //cout << "before sorting"<<endl;
    //print(arrIn, size);
    cout<<endl;

    start = clock();
    bubbleSort(arrIn, size);
    end = clock();
    cout << "after bubble sort: " << endl;
    //print(arrIn, size);
    if(isDescending(arrIn, size))
        cout << "YES, the array is in descending order."<<endl;
    else
        cout<< "Not in descending order."<<endl;
    cout << "bubble sort: " << (end-start)/(double)(CLOCKS_PER_SEC/1000) << " ms" << endl;
    cout << endl;

    srand(time(NULL)); //for diff random number each time
    for (int i = 0; i < size; i++) 
    {
        arrIn[i] = rand()% size;
    }
    //cout << "before sorting"<<endl;
    //print(arrIn, size);
    cout<<endl;

    start = clock();
    mergeSort(arrIn, size);
    end = clock(); 
    cout << "after merge sort: " << endl;
    //print(arrIn, size);
    if(isDescending(arrIn, size))
        cout << "YES, the array is in descending order."<<endl;
    else
        cout<< "Not in descending order."<<endl;
    cout << "merge sort: " << (end-start)/(double)(CLOCKS_PER_SEC/1000) << " ms" << endl;
    cout << endl;
*/
    srand(time(NULL)); //for diff random number each time
    for (int i = 0; i < size; i++) 
    {
        arrIn[i] = rand()% size;
    }
    cout << "before sorting"<<endl;
    print(arrIn, size);
    cout<<endl;    

    start = clock();
    quickSort(arrIn, size);
    end = clock();
    cout << "after quick sort: " << endl;
    print(arrIn, size);
    if(isDescending(arrIn, size))
        cout << "YES, the array is in descending order."<<endl;
    else
        cout<< "Not in descending order."<<endl;
    cout << "quick sort: " << (end-start)/(double)(CLOCKS_PER_SEC/1000) << " ms" << endl;
    cout << endl;

    srand(time(NULL)); //for diff random number each time
    for (int i = 0; i < size; i++) 
    {
        arrIn[i] = rand()% size;
    }
    cout << "before sorting"<<endl;
    print(arrIn, size);
    cout<<endl; 

    start = clock();
    systemSort(arrIn, size);
    end = clock();
    cout << "after system sort: " << endl;
    print(arrIn, size);
    if(isDescending(arrIn, size))
        cout << "YES, the array is in descending order."<<endl;
    else
        cout<< "Not in descending order."<<endl;
    cout << "system provided sort: " << (end-start)/(double)(CLOCKS_PER_SEC/1000) << " ms" << endl;
    cout << endl;
}

//we start from the next element and then look back (left) to find the element lower than it
// then we will place the lower element as pivot, similar to bubble but we will be looking through each element using o(n2)
void insertionSort(int* arr, int n) // n= length of arr
{
    for(int i = 1; i < n; i++)
    {
        int pivot = arr[i];
        int j = i - 1; //at start, j = index...position left to the i
        while(j >= 0 && arr[j] < pivot) //descending
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = pivot; 
    }
}
//in selection sort, we select the 1st index to be max and then keep getting the next max number,
//similar idea as the pigeon hole, once the max is found, that is sorted and wont be checked again
//time complexity = o(n2)
void selectionSort(int* arr, int n) //n=length of array
{
    for(int i = 0; i < n - 1; i++)
    {
        int max = i; //max to min, descending order
        for(int j = i + 1; j<n; j++)
        {
            if(arr[j] > arr[max])
                max = j;
        }
        if(max != i)
        {
            swap(arr[max], arr[i]); //swap = built in function in std
        }
    }
}
//bubble sort = simplest/easiest algorithm, suitable for small data set it works by repeatedly swapping the adjacent elements if they are in the wrong order
//is same as selection sort, in the worst, sace it's still o(n2)
//first task = put the smallest element to the right most
//THIS WAS PROVIDED
void bubbleSort(int* arr, int n) // n = length of array
{
    for(int j = n-1; j >=1; j--)
    {
        for(int i=0; i<j; i++)
        {
            if(arr[i] < arr[i+1]) //descending, therefore the lowest integer will bubble up to right most part
            {
                //or can use swap built in function
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }   
        }   
    }
}
//merge sort:
//step 1 = divide 
//step2 = resursive 
//step3 = sort
//THIS WAS PROVIDED
void mergeSort(int* arr, int n)
{
    mergeSort(arr, 0, n-1); 
}
void mergeSort(int* arr, int start, int end)
{
    if (start >= end)
       return;

    int mid = (start + end)/2;
    mergeSort(arr, start, mid); 
    mergeSort(arr, mid+1, end);
    merge(arr, start, end); 
}

void merge(int* arr, int start, int end)
{
    int mid = (start + end)/2;

    int i = start;
    int j = mid+1; 
    int* brr = new int[end-start+1];
    int k = 0; 

    while (i <= mid && j <= end)
    {
        if (arr[i] > arr[j])
        {
           brr[k] = arr[i];
           i++;
           k++;
        }
        else if (arr[i] < arr[j])
        {
            brr[k] = arr[j];
            j++;
            k++;
        }
        else
        {
            brr[k] = arr[i]; 
            brr[k+1] = arr[j];
            i++;
            j++;
            k += 2; 
        }
    }

    while (i <= mid)
    {
        brr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        brr[k] = arr[j];
        j++;
        k++;
    }

    k = 0; 
    i = start;
    while (i <= end)
    {
        arr[i] = brr[k];
        i++;
        k++;
    }
    delete[] brr;
    brr = nullptr;

}
//similar to merge sort
//but this time we dont need the temp array to hold the sorted array
//we sort them along the way
void quickSort(int* arr, int n)
{
    quickSort(arr, 0, n-1);
}
int partition(int* arr, int start, int end)
{
    int pivot = arr[end];
    int index = start;
    for (int i = start; i < end - 1; i++) 
    {
        if (arr[i] > pivot)  // <= for ascending
        {
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;

            index++;            
        }
    } //after this for loop, out pivot is still at the end of the array

    //make pivot in the middle.. such that all the elements greater than pivot will be in the left hand side, and all less than pivot will be in the right 
    //bring pivot over to the nect index after the for loop


    //swap(arr[end], arr[index]); //takes longer time to compile tho
    int temp = arr[end];
    arr[end] = arr[index];
    arr[index] = temp;
    return index;
}
void quickSort(int* arr, int start, int end)
{
    if (start < end) 
    {
        int p = partition(arr, start, end); 
        quickSort(arr, start, p - 1); // p = partititon / mid value...found in partition function
        quickSort(arr, p + 1, end);
    }
}
//we are testing the sort function thats built in the system
//them making them descending as well ... using reverse()
void systemSort(int* arr, int n)
{
    sort(arr, arr + n); //built in function sort() 
    reverse(arr, arr + n); //built in function reverse()
}
bool isDescending(int* arr, int n)
{
    bool yes = true;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] < arr[i+1]) {
            return false;
        }
    }
    return yes;
}
//use this function to test small batches of array
void print(int* arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}