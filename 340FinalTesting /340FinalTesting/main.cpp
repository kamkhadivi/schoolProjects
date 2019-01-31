#include <iostream>
using namespace std;

void printArr(int* arr, int size){
    for(int i = 0; i<size; i++)
        cout<<arr[i]<<" ";
    //cout<<*(arr+i)<<" "
    cout<<endl;
}

void merge(int* arr, int start, int middle, int end){
    // Example assume array to be: 1 4 6 8 | 2 5 7 9
    // Here both left array (1 4 6 8) and right array (2 5 7 9) are sorted
    // we have to merge them in to a single sorted array like "1 2 4 5 6 7 8 9"
    // Here start Index is 0; End index is 7; middle is (start+end)/2 which is (0+7)/2 = 3;
    if(end-start > 0){
        
        // For above example left array length is 4; which is (middle - start + 1) = (3-0+1) = 4;
        int lSize = (middle - start + 1);
        // Right array length is 4; which is (end -middle) = (7-3) = 4;
        int rSize = (end - middle );
        
        // creating a temporary left and right arrays for holding the values of the original array
        int lArr[lSize];
        int rArr[rSize];
        // we will use these two temporary arrays to store and compare the values from the origial array.
        // and will store the result of comparison in to the original array which was passed
        // as an argument to this function. "void merge(int* arr, int start, int middle, int end)"
        
        // left Index is the starting point of the Left half of the original array.
        int leftIndex = start;
        
        // This loop will store the left half values of the original array in to left temporary array.
        // left half of the original array starts from index 0 and goes till index 3;
        // left temporary array can hold the left half portion of the original array.
        // left temporray array index starts from 0 and goes till 3 (since size of left temporary array is 4(0,1,2,3))
        for(int i = 0; leftIndex <= middle; i++, leftIndex++)
            lArr[i] = arr[leftIndex];
        
        // right index is the starting point of the Right half of hte original array.
        // which starts from index 4 and goes till index 7;
        // so we have to store the values starting from index 4 till index 7 in to the right temporary array.
        // right temporary array starts from index 0 and goes till index 3 (since size of right temporary array is 4);
        // so right index starts from index 4 which is (middle+1) = (3+1) = 4
        int righIndex = middle+1;
        
        
        // we store the arr[4] value in the rArr[0] location
        // arr[5] in to rArr[1] location
        // arr[6] in to rArr[2] location
        // arr[7] in to rArr[3] location
        // Thus right temporary array now contains the right half of the original array.
        for(int j = 0; righIndex <= end; j++,righIndex++)
            rArr[j] = arr[righIndex];
        
        
        // Now we will start comparing the left(1 4 6 8) and right(2 5 7 9) temporary array and we will write
        // the result of the comparision back in to the original array. arr (1 4 6 8 2 5 7 9 )
        
        // Now left and right temporay arrays index starts from 0 and they will go till 3;
        leftIndex = 0;
        righIndex = 0;
        
        // original array index starts from start index;
        int originalIndex = start;
        
        // Important steps:
        // First we have to make sure the list is not empty
        // we will keep on comparing untill one to the lists reaches to end and then
        // after we will append the other list values directly to the original array.
        while(leftIndex < lSize && righIndex < rSize){
            
            // First we will compare the left & right  temporary arrays elements
            // if lArr[0]  is less than rArr[0]
            // the we know it is the smallest element in the two temporary arrays
            // Thus we have to place it at the starting index of the original array
            // which will be done my this code arr[originalIndex] = lArr[leftIndex];
            // Then we will increment the index of both left temporary array and original array
            
            if(lArr[leftIndex] < rArr[righIndex]){
                arr[originalIndex] = lArr[leftIndex];
                leftIndex++;
            }else{
                arr[originalIndex] = rArr[righIndex];
                righIndex++;
            }
            originalIndex++;
        }
        
        // One we reach end of the either lists. All we have to do is to append the
        // non empty temporaray array items to the original array, which will be done by the below steps:
        while(leftIndex < lSize){
            arr[originalIndex] = lArr[leftIndex];
            leftIndex++;
            originalIndex++;
        }
        
        while(righIndex < rSize){
            arr[originalIndex] = rArr[righIndex];
            righIndex++;
            originalIndex++;
        }		
        
    }
    return;
    
}

// Remember mergeSort has 3 recursive steps. Please draw the function calls flow
// to better understand the flow of the program.
void mergeSort(int* arr, int start, int end){
    if(end-start > 0){
        int middle = (start+end)/2;
        mergeSort(arr, start, middle);
        mergeSort(arr, middle+1, end);
        merge(arr, start, middle, end);
    }
    return;
}

int main(){
    
    
    int arr[] = {8,1,6,4,9,5,2,7};
    cout<<"before mergeSort"<<endl;
    printArr(arr, 8);
    mergeSort(arr, 0, 7);
    cout<<"after mergeSort"<<endl;
    printArr(arr, 8);
    
    return 0;
    
    
    
}
