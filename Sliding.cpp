#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;


int convertToIntArray(int argc, char* argv[], float array[]) {
	
	if (argc < 3){
		cerr<<"You have too few numbers. Please input more."<<endl;
		return -3;
	}
	if (argc > 22) {
		cerr<<"Too many numbers, shorten your list."<<endl;
		return -22;
	}
	else {
	for(int i = 2; i < argc; i++) {
		int k = 0;
		if (argv[i][0] == '-') {
			k = 1; //if integers are negative, it should still work 
		}
		//proof reading the code 
		for (/*null*/; argv[i][k] != 0; k++) {
			if (!isdigit(argv[i][k])){
				return -i;
			}
		for (int j = 2; j < argc; j++) {
			array[j-2] = atoi(argv[j]);
		}
		for (int j = 2; j < argc; j++) {
			if (argv[j][0] == '-' && array [j-2] > 0) {    //if number surpasses intmax and returns a negative, it should return a negative
				return -j;
			}
			else if (isdigit(argv[j][0]) && array[j-2] < 0) {
				return -j;
			}
			else {
				//null
			}
			}
			
		}
		}
		for(int i = 0; i < argc -1; i++){
		if(array[i] < -2000000 || array[i] > 2000000){
			cerr << "Too big of a number." << endl;
			exit(-1);
		}
		}
		
		return argc - 1;
		
	
}
}	

	float Average(int array[], int numElements) {
		float sum = 0;
		float average = 0;
		for (int j = 0; j < numElements; j++) {
		sum = sum + array[j];
		}
		average = sum/numElements;
		return average;
	}
	
	float findMin(int array [], int numElements) {
		int min = INT_MAX;
		for (int i = 0; i < numElements; i++) {
			if (array[i] < min) {
				min = array[i];
			}
		}
		
	return min;
	}
	long long findMax(int array [], int numElements) {
		int max = 0;
		for (int i = 0; i < numElements; i++) {
			if (array[i] > max) {
				max = array[i];
			}
		}
		return max;
	}
	//int findMax(int array[], int numElements)
	//int findMin(int array[], int numElements)

	int slideAvg(float inputVoltages[], int sampleSize, int windowSize, float slidingAverage[]){
	
	int inputV [windowSize];
	
	for (int a = 0; a < sampleSize-windowSize+1; a++){
		
		
		for (int x = 0; x < windowSize; x++){
			inputV[x] = inputVoltages[x+a];
		}
		float sums = 0;
		for (int x = 0; x < windowSize; x++){
			sums+=inputV[x];
		}
		slidingAverage [a] = sums/windowSize;
	}

	}

void displayHistogram(int numElements, float array[]){
	
	cout << "100V------105V------110V------115V------120V------125V------130V------135V------140V" << endl;
	
	
	
	for (int i = 0; i < numElements; i++){
		if (array[i] < 100){
			cout << "!";
		} 
		else if (array[i] > 140){
			for (int x = 0; x < 81; x++){
				cout << "#";
			}
			cout << "+";
		} 
		else {
		
		
			for (int j = 0; j <(floor((array[j]*2)+0.5)/2)/0.5 - 200 + 1; j++){
				cout << "#";
			}
		}
		cout<< endl;
	}
	return;
} 

int main(int argc, char *argv[])

{
		int slideSize = atoi(argv[1]); //first argument in the array
		
		if (slideSize < 1 || slideSize > argc - 2){ //error checking the input
			cerr << "Error: You have entered an invalid slide size.";
			exit(-1);
		}
		
		float slideAvgArray [argc-2-slideSize+1];
		float intArray [20];
		//outputting error message
		if (convertToIntArray(argc, argv, intArray) < 0){
				cerr << "Error: Argument " << -convertToIntArray(argc, argv, intArray) << " is not an integer.";
				exit (-1);
		}
		
		

		slideAvg (intArray, argc - 2, slideSize, slideAvgArray);
		displayHistogram(argc -2,intArray);
		displayHistogram(argc- 2- slideSize +1, slideAvgArray);
	
	return 0;
}



	
