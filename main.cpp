#include<iostream>
#include<ctime>

using namespace std;

// given
const int NUMBERS_SIZE = 50000;
const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds

// helper function to display array elements
void display(int array[], int numsize) {
    for(int i = 0; i < numsize; i++) {
        cout << " " << array[i];
    }

    cout << endl;
}

// given
int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}
// change i < NUMBERS_SIZE for testing purposes
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

// required 3 functions
int PartitionMid(int numbers[], int lowIndex, int highIndex) {
	int midpoint = lowIndex + (highIndex - lowIndex) / 2;
	int pivot = numbers[midpoint];
	bool done = false;

	 while (!done) {
      
      while (numbers[lowIndex] < pivot) 
         lowIndex += 1;
         
      while (pivot < numbers[highIndex]) 
         highIndex -= 1;
         
      if (lowIndex >= highIndex) 
         done = true;
         
      else {
         
         int temp = numbers[lowIndex];
         numbers[lowIndex] = numbers[highIndex];
         numbers[highIndex] = temp;
         
         lowIndex += 1;
    	 highIndex -= 1;
    	}
   }
	return highIndex;	

}
    	

         
      
void Quicksort_midpoint(int numbers[], int i, int k) {
	
    if (i>= k) 
      return;
   
    int lowEndIndex = PartitionMid(numbers, i, k);
   
   Quicksort_midpoint(numbers, i, lowEndIndex);
   Quicksort_midpoint(numbers, lowEndIndex + 1, k);
}

void Quicksort_medianOfThree(int numbers[], int i, int k) {

}

void InsertionSort(int numbers[], int numbersSize) {
    int i, j, key = 0;
    
    for(i = 1; i < numbersSize; i++) {
        key = numbers[i];
        j = i - 1;

        while(j >= 0 && numbers[j] > key) {
            numbers[j+1] = numbers[j];
            j--;
        }

        numbers[j+1] = key;
    }
}

int main() {
    int testnumber = NUMBERS_SIZE;

    int array1[testnumber];
    int array2[testnumber];
    int array3[testnumber];

    fillArrays(array1, array2, array3);

    cout << "Intial array1: "; 
    display(array1, testnumber);

    cout << "Initial array2: ";
    display(array2, testnumber);

    cout << "Initial array3: ";
    display(array2, testnumber);

    clock_t Start = clock();
    
    //call sort function here

    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.

    cout << "Elapsed time: " << elapsedTime
         << "array1, Quicksort_midpoint: "; 
    display(array1, testnumber);

    cout << "array2, Quicksort_medianOfThree: ";
    display(array2, testnumber);

    cout << "array3, InsertionSort: ";
    display(array2, testnumber);
    
    return 0;
}
