#include"Header.h";

//-------------------------------------------------------------
void Wrongprintarray(int arr[]) {


	cout << "in the wrong function there is :" << sizeof(arr) << endl;
	int n = sizeof(arr) / sizeof(int);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}


}
void CorrectPrintArray(int* arr, int n) {

	cout << "In the Correct function there is :" << sizeof(arr) << endl;
	arr[0] = 100;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}

}
int ArrayFunctionMain() {

	//here is make a array with 6 int values, taking the spot 0-5 in the array.
	int arr[] = { 1,2,3,4,5,6 };
	//n will be the size of the array divided by the bit value of a int"4".
	//we have 6*4 = 24 -> 24/4 = 6
	int n = sizeof(arr) / sizeof(int);

	//Since the function is using pointer it will recive the correct value
	//it's also reciving the correct array size from the main function.
	//They are now sharing a common memory.

	CorrectPrintArray(arr, n);

	//since it passed with reference it will only get the address.
	Wrongprintarray(arr);

	cout << "In main there is :" << sizeof(arr) << endl;
	//loop that goes trough each slot inn the arra writing out the value.
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;

	}
	//here we are sending the reference of arr to the function printArray


	return 0;

}
//-------------------------------------------------------------
int LinearSearch(int arr[], int n, int key) {

	for (int i = 0; i < n; i++) {
		//check if current element matches the key
		if (arr[i] == key) {
			return i;
		}
	}
	//out of the loop
	return -1;
}
int LinearSearchMain() {
	//Searching algorithm to find the index of element in a given array
	//BruteForce
	//Will go trough the list until it hits the req then stops.
	//N0 of operations is based on N, larger n longer time. Linear search has a complexity of order of n
	int arr[] = { 10,15,12,9,6,4,3,10,8 };
	int n = sizeof(arr) / sizeof(int);

	int key;
	cin >> key;


	int index = LinearSearch(arr, n, key);
	if (index != -1) {
		cout << key << " is present at index " << index << endl;
	}
	else
	{
		cout << " is MISSING!" << endl;

	}

	return 0;
}
//-------------------------------------------------------------
int BinarySearch(int arr[], int n, int key) {
	int Start = 0;
	// N - 1 is the last element in an array
	int End = n - 1;
	//K = Log(2)^N ---- O(Log.N) Example(16->8->4->2->1) log(2)^16 = 4.
	while (Start<=End){
		int mid = (Start + End) / 2;
		if (arr[mid] == key) 
		{
			return mid;
		}
		//take the end marker and put it on mid - 1
		else if (arr[mid] > key)
		{
			End = mid - 1;
		}
		//take the Start marker and put it on mid + 1
		else
		{
			Start = mid + 1;
		}
	}

	return -1;

}
int BinarySearchMain() {
	//Efficient searching algorithm to find the index of element in a given sorted array.
	//(ONLY works in sorted/Monotonic search space)Monotonic= Non-dereasing/Increasing curve
	int arr[] = { 10,20,30,40,45,60,70,89 };
	
	int n = sizeof(arr)/sizeof(int);

	int key;
	cin >> key;

	int index = BinarySearch(arr, n, key);
	if (index!=-1){
		cout <<key<< " Is present in the index" << index << endl;
	}
	else
	{
		cout << " Is MISSING from the index!" << endl;
	}


	return 0;
}
//-------------------------------------------------------------
void ReverseArray(int arr[], int n) {
	int Start = 0;
	int End = n - 1;

	while (Start<End)
	{
		swap(arr[Start], arr[End]);
		Start += 1;
		End -= 1;
	}
	
}
int ArrayReverseMain() {
	//This is used to reverse all the elements of a given array(This will change the array)(12345 ->54321)
	//Time complexity N/2 = O(N)Time   space complexity would remain order of one.
	int arr[] = { 10,20,30,45,60,80,90 };
	//array got 7,each variable is 4 bit.7*4=28/4 =7
	int n = sizeof(arr) / sizeof(int);
	//printing output
	
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	
	ReverseArray(arr, n);

	//printing output
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
//-------------------------------------------------------------
void PrintAllPairs(int arr[], int n) {

	//print all the elements(2 snested loops)
	for (int i = 0; i < n;i++) {
		int x = arr[i];
		//The +1 changes the use case, either all pairs or less for each loop
		for (int j = i+1; j < n; j++){
			int y = arr[j];
			
			cout << x << "," <<y<< endl;
		}
		cout << endl;
	}
}
int PrintAllPairsMain() {
	int arr[] = { 10,20,30,40,50,60};
	int n = sizeof(arr) / sizeof(int);
	
	
	PrintAllPairs(arr, n);
	return 0;
}
//-------------------------------------------------------------
void PrintSubArrays(int arr[],int n ) {
	int sum{0};
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			//cout << "(" << i << "," << j << "),";
			for (int k = i; k <=j; k++)
			{
				cout << arr[k] << ",";
				sum += arr[k];
			}
			cout << "Subarray sum:" << sum << endl;
			sum = 0;
		}
	}
}
int PrintSubArraysMain() {
	//TimeComplexity->O(n*n*n) = n^3
	int arr[] = { 10,20,30,40,50,60 };
	int n = sizeof(arr) / sizeof(int);


	PrintSubArrays(arr,n);

	return 0;
}
//-------------------------------------------------------------
int main(){
	
	//ArrayFunctionMain();
	//LinearSearchMain();
	//BinarySearchMain();
	//ArrayReverseMain();
	//PrintAllPairsMain();
	PrintSubArraysMain();
	return 0;
}

