/*
@author: Jere Perisic
@version: 30/1/2024
*/

#include <stdio.h> 
#include <stdbool.h>

int array[] = {295, 95, 299, 132, 11, 270, 274, 137, 124, 15, 289, 72}; // global
unsigned const int arrSize = (sizeof(array)/sizeof(array[0])); // read-only variable


int smallestNumberInList(int);
int subestOfThree();
int insertionSort(int[]);
int gcd(int, int);

int main(){
    printf("First Algorithm\n");
    smallestNumberInList(5);

    printf("\n");
    printf("Second Algorithm\n");
    subestOfThree();

    printf("\n");
    printf("Thrid Algorithm\n"); 
    insertionSort(array);

    printf("\n");
    printf("Fourth Algorithm\n");
    gcd(15,130);
    return 0;
}
/*
Print array method, it is what it is.
*/
void printArray(int prtArr[], int size){
    printf("[");
    for(int i = 0; i< size;i++){
        if((size-i)==1){
            printf("%d]\n",prtArr[i]);
        }else{
            printf("%d, ",prtArr[i]);
        }
    }
}

/*
My thought was loop over the array and write element in another array, do it for m times.
In the end print the array. Simple but it needs to decrement and reassign values.
*/
int smallestNumberInList(int m){
    int subArrOfSmallInt[m];  
    int size = arrSize; // I wanted to experiment with "const" so I declared arrSize as global read-only value
    for (int i = 0; i < m; i++) { // outer loop
        int smallInt = array[0];
        int index = 0;

        for (int j = 1; j < size; j++) { // inner loop
            if (array[j] < smallInt) {
                smallInt = array[j]; // assign new smallest value
                index = j; // assign index so we can remove it from array
            }
        }

        subArrOfSmallInt[i] = smallInt; // write in sub array
        array[index] = array[size - 1]; // remove smallest from array
        size--; // decrement size to avoid segmentation fault
    }
    printArray(subArrOfSmallInt, (sizeof(subArrOfSmallInt)/sizeof(subArrOfSmallInt[0])));

  
} 
/*
I think since we know that it is a subset of three this is sufficient.
*/
int subestOfThree(){
    char charArr[] = {'a','b','c','d','e'};
    int charArrSize = (sizeof(charArr) / sizeof(charArr[0]));
    int count = 1;
    for (int i =0;i<charArrSize;i++) { // this one iterates over first char
        for(int j = i+1;j<charArrSize;j++){ // changes second char i+1 to make it unique
            for(int l = j+1;l<charArrSize;l++){ // changes third char j+1=(i+1)+1 to make it unique
                printf("Subset %d: {%c, %c, %c}\n", count, charArr[i],charArr[j],charArr[l]); // for each iteration print, simple
                count++; // just so output is prettier
            }
        }
    }
}

/*
Loop an array and find number at [j] position, and if it's bigger then number at [j+1] position.
Sort it.
*/
int insertionSort(int arr[]){
   for(int i = 1; i < arrSize; i++){
        int curr = arr[i];
        int j = i-1; 
        while(j>=0 && arr[j]>curr){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = curr;
   }
    printArray(arr,arrSize);
}
/*
Find bigger number and start decrementing, once both numbers don't have reminder, we have found gcd.
After that is achieved we break a loop.
*/
int gcd(int x, int y){
    int n = (x > y) ? x : y; // finding which number is greater
    unsigned int GCD = 0;
    for(int i = n; i>0;i--){ // decrement loop
        if((x%i==0) && (y%i==0)){ // when condition is meet break loop
            GCD = i;
            break;
        }
    }
    printf("Greatest common divisor: {%d}\n", GCD);
    
}

