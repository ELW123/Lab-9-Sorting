#include<iostream>
#include<ctime>

using namespace std;

// given
const int NUMBERS_SIZE = 50000;
//const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds

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
int Partitionmid(int numbers[], int lowIndex, int highIndex) {
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
   
    int lowEndIndex = Partitionmid(numbers, i, k);
   
   Quicksort_midpoint(numbers, i, lowEndIndex);
   Quicksort_midpoint(numbers, lowEndIndex + 1, k);
}
	
	

int PartitionMed(int numbers[], int lowIndex, int highIndex) {
	
	int mid =  lowIndex + (highIndex - lowIndex) / 2;
	int pivot;
	
	if(numbers[lowIndex]<numbers[mid] && numbers[mid]<numbers[highIndex])
	pivot=mid;
	
	else if (numbers[lowIndex]>numbers[mid] && numbers[mid]>numbers[highIndex])
	pivot=mid;

	else if(numbers[lowIndex]<numbers[mid] && numbers[lowIndex]>numbers[highIndex])
	pivot=lowIndex;
	
	else if((numbers[lowIndex]>numbers[mid] && numbers[lowIndex]<numbers[highIndex]))
	pivot=lowIndex;
	
	else

  	pivot=highIndex;
	
	
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

void Quicksort_medianOfThree(int numbers[], int i, int k) {
	if (i>= k) 
      return;
   
    int lowEndIndex = PartitionMed(numbers, i, k);
   
   Quicksort_midpoint(numbers, i, lowEndIndex);
   Quicksort_midpoint(numbers, lowEndIndex + 1, k);
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
    const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000;

  /*  cout << "Intial array1: "; 
    display(array1, testnumber);

    cout << "Initial array2: ";
    display(array2, testnumber);

    cout << "Initial array3: ";
    display(array2, testnumber); */

    clock_t Start1 = clock();
	Quicksort_midpoint(array1,0,NUMBERS_SIZE-1);
	clock_t End1 = clock();
    int elapsedTime1 = (End1 - Start1)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
	cout << "Elapsed time of Quicksort_midpoint : " << elapsedTime1 << endl;
	
	//REPEAT ON SORTED 
	clock_t Start2= clock();
	Quicksort_midpoint(array1,0,NUMBERS_SIZE-1);
	clock_t End2 = clock();
    int elapsedTime2 = (End2 - Start2)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
	cout << "Elapsed time of Quicksort_midpointSORTED : " << elapsedTime2<< endl;
	
         
    //display(array1, testnumber);

	clock_t Start3 = clock();
	Quicksort_medianOfThree(array2,0,NUMBERS_SIZE-1);
	clock_t End3 = clock();
    int elapsedTime3= (End3 - Start3)/CLOCKS_PER_MS; 
    cout << "Elapsed time of Quicksort_medianOfThree : " << elapsedTime3 << endl;
    
    //REPEAT ON SORTED
    clock_t Start4 = clock();
	Quicksort_medianOfThree(array2,0,NUMBERS_SIZE-1);
	clock_t End4= clock();
    int elapsedTime4 = (End4 - Start4)/CLOCKS_PER_MS; 
    cout << "Elapsed time of Quicksort_medianOfThreeSORTED : " << elapsedTime4 << endl;
    
    	 
    //display(array2, testnumber);
    
	clock_t Start5 = clock();
	InsertionSort(array3,NUMBERS_SIZE);
	clock_t End5 = clock();
    int elapsedTime5 = (End5- Start5)/CLOCKS_PER_MS; 
    cout << "Elapsed time of InsertionSort : " << elapsedTime5 << endl;
          
    //display(array3, testnumber);
    
    //REPEAT ON SORTED 
    clock_t Start6 = clock();
	InsertionSort(array3,NUMBERS_SIZE);
	clock_t End6 = clock();
    int elapsedTime6 = (End6- Start6)/CLOCKS_PER_MS; 
    cout << "Elapsed time of InsertionSortSORTED : " << elapsedTime6 << endl;
          
    
    
    return 0;
}
