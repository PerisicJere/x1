#include <stdio.h> 
#include <stdbool.h>

int array[] = {295, 95, 299, 132, 100, 270, 274, 137, 124, 178, 289, 143, 234, 117, 24, 107, 148, 140, 33, 82, 201, 198, 19, 165, 21, 151, 292, 218, 283, 287, 45, 190, 29, 70, 75, 90, 84, 47, 96, 224, 171, 228, 51, 225, 238, 125, 91, 159, 25, 201};
unsigned const arrSize = (sizeof(array)/sizeof(array[0]));
int smallestNumberInList();
int subestOfThree();
int insertionSort(int[]);
int gcd(int, int);
int main(){
    smallestNumberInList();
    subestOfThree();
    insertionSort(array);
    gcd(15,130);
    return 0;
}


/*
Linear searching unsorted array to find smallest value in the same.
Thought process, when traversing the array once we encouter smallest value, replace the variable smallInt with it.
smallInt can't be default 0 because then it would already be the smalles value. 
But if the array is sorted, or not we can set smallInt to be the first value. 
*/
int smallestNumberInList(){
    int smallInt = array[0];
    for(int i = 1; i<arrSize;i++){
        if(array[i]<smallInt){
            smallInt = array[i];
        }
    }
    printf("%d\n",smallInt);
}
/*
Traverse through the array, store in subarray after three values are stored print them, easy.
I will explain with inline documentation
*/
int printSubsetArray(int printArr[]){
    printf("[");
    for(int i = 0; i <= 2; i++){
        if(i == 0 || i == 1){
        printf("%d, ",printArr[i]);
        }else if (i==2)
        {
        printf("%d",printArr[i]);
        }
    }
    printf("]");
    return 0;
}
int printRestOfArray(int restArr[], int left){
    if((arrSize-left) == 1){
            printf("[%d]",restArr[0]);
        }
    if((arrSize-left) == 2){
        for(int i = left; i < arrSize; i++)
        {
            if((arrSize-i) == 2){
                printf("[%d, ",restArr[0]);
            }else if ((arrSize-i) == 1)
            {
                printf("%d]\n",restArr[1]);
            }
            
        }
    }
    
    return 0;
}

int subestOfThree(){
    int subset[3] = {};
    int increment = 0;
    for(int i = 0; i< (arrSize)/3;i++){ // Outer for-loop traverses the array, we divide array size with 3 since we are printing subset of 3 elements
        for(int j =  0;j<3;j++){
            subset[j]=array[increment];
            increment++; // increment in inner loop, this is main reason why outer loop is divided by 3
        }
        printSubsetArray(subset); // call to function to print subsets 
        
    }
    if(arrSize%3 != 0){ // not all arrays will be subset of 3 elements
        printRestOfArray(array, increment);
    }
}

/*
Print array method, it is what it is.
*/
int printArray(int prtArr[]){
    printf("[");
    for(int i = 0; i< arrSize;i++){
        if((arrSize-i)==1){
            printf("%d]\n",prtArr[i]);
        }else{
            printf("%d, ",prtArr[i]);
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
    printArray(arr);
}
/*
Find bigger number and start decrementing, once both numbers don't have reminder, we have found gcd.
After that is achieved we break a loop.
*/
int gcd(int x, int y){
    int n = (x > y) ? x : y;
    unsigned int GCD = 0;
    for(int i = n; i>0;i--){
        if((x%i==0) && (y%i==0)){
            GCD = i;
            break;
        }
    }
    printf("%d\n", GCD);
    
}