#include <stdio.h> 
int smallestNumberInList();
int subestOfThree();
int main(){
    smallestNumberInList();
    subestOfThree();
    return 0;
}
int arr[] = {295, 95, 299, 132, 100, 270, 274, 137, 124, 178, 289, 143, 234, 117, 24, 107, 148, 140, 33, 82, 201, 198, 19, 165, 21, 151, 292, 218, 283, 287, 45, 190, 29, 70, 75, 90, 84, 47, 96, 224, 171, 228, 51, 225, 238, 125, 91, 159, 25, 201};
unsigned const arrSize = (sizeof(arr)/sizeof(arr[0]));
/*
Linear searching unsorted array to find smallest value in the same.
Thought process, when traversing the array once we encouter smallest value, replace the variable smallInt with it.
smallInt can't be default 0 because then it would already be the smalles value. 
But if the array is sorted, or not we can set smallInt to be the first value. 
*/
int smallestNumberInList(){
    int smallInt = arr[0];
    for(int i = 1; i<arrSize;i++){
        if(arr[i]<smallInt){
            smallInt = arr[i];
        }
    }
    printf("%d\n",smallInt);
}
/*
Traverse through the array, store in subarray after three values are stored print them, easy.
I will explain with inline documentation
*/
int printArray(int printArr[]){
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
                printf("%d]",restArr[1]);
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
            subset[j]=arr[increment];
            increment++; // increment in inner loop, this is main reason why outer loop is divided by 3
        }
        printArray(subset); // call to function to print subsets 
        
    }
    if(arrSize%3 != 0){ // not all arrays will be subset of 3 elements
        printRestOfArray(arr, increment);
    }
}