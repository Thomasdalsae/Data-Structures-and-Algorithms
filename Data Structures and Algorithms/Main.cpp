#include"Header.h"

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
int LargestSubArraySum(int arr[],int n ) {
	int SubArraySum{0};
	int LargestSubArraySum{0};
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			//Reset
			SubArraySum = 0;
			for (int k = i; k <=j; k++)
			{
				//cout << arr[k] << ",";
				SubArraySum += arr[k];
					//Checking if SybArraySum is larger than LargestSubArraySum. if so,replace
					//IF method
				// if (SubArraySum > LargestSubArraySum)
				// {
				// 	LargestSubArraySum = SubArraySum;
				// }
				
				//Shorter method
				LargestSubArraySum = max(SubArraySum,LargestSubArraySum); 
			}
			//cout << "Subarray sum:" << SubArraySum << endl;
			
		}
	}
	//can cout it within the function,but better to return to main and then cout
	//cout <<"Largest SubArray was :"<< LargestSubArraySum;
	return LargestSubArraySum;
}
int PrintSubArraysMain() {
	//THIS IS BRUTE FORCE SOLUTION <--TimeComplexity->O(n*n*n) = n^3
	int arrN[] = {-2,3,4,-1,5,-12,6,1,3};
	int n = sizeof(arrN) / sizeof(int);

	//This sends inn information to a function that will return the result. the function do a operation to find the largest sum in the subArray.
	cout <<LargestSubArraySum(arrN,n);

	return 0;
}
//-------------------------------------------------------------
int LargestSubArraySumOptimized(int arr[],int n)
{
	//Prefix Sums
	//100 should be changed with a vector or a dynamic,is currently a constant.
	int prefix[100] = {0};
	prefix[0] = arr[0];
	for (int i=1;i<n;i++)
	{
		prefix[i] = prefix [i-1] + arr[i];
	}


	//largest sum login
	int LargestSubArraySum{0};
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			//since I starts at 0 it will be a nullpointer, we can only use the i-1 when i is bigger than 0.
			//  : is used if the condition(i>0) is not met.
			int SubArraySum = i>0 ? prefix[j] - prefix[i-1] : prefix[j];
			//put a check is SubArraySum > largestSubArraySum
			LargestSubArraySum = max(SubArraySum,LargestSubArraySum); 
			
		}
	}
	return LargestSubArraySum;
}
int PrintSubArrayMainOptimized()
{	//Prefix Sum Approach 0(0^2)
	int arrN[] = {-2,3,4,-1,5,-12,6,1,3};
	int n = sizeof(arrN) / sizeof(int);

	//This sends inn information to a function that will return the result. the function do a operation to find the largest sum in the subArray.
	cout <<LargestSubArraySumOptimized(arrN,n);

	return 0;
}
//-------------------------------------------------------------
int MaximumSubArraySum(int arr[],int n){
	int CurrentSum{0};
	int LargestSum{0};
	//goes over and adds all positive variables, if its negative it will turn Current variable it to zero.
	//if current sum is larger than largest sum it will overwrite.
	//Array      [-2,3,4,-1,5,-12]
	//CurrentSum=[ 0,3,7, 6,11, 0]
	//LargestSum=[ 0,3,7, 7,11,11]
	for (int i =0;i<n;i++)
	{
		CurrentSum = CurrentSum + arr[i];
		if (CurrentSum<0)
		{
			CurrentSum = 0;
		}
		LargestSum = max(LargestSum,CurrentSum);
	}
	return LargestSum;
}
int MaximumSubArraySumMain()
{
	//Kadane's algrithmn
	//TimeComplexity O(N)
	int arr[] = {-2,3,4,-1,5,-12,6,1,3};
	int n = sizeof(arr) / sizeof(int);

	cout << MaximumSubArraySum(arr,n);
	return 0;
}//BestSubArray Solution
//-------------------------------------------------------------

//CODING EXERCISES E=exercise<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int LargestElementE(vector<int>arr)
{
	int CurrentNumber{0};
	int LargestNumber{0};
	for (int i = 0;i<arr.size();i++)
	{
		CurrentNumber =  arr[i];
		LargestNumber = max(CurrentNumber,LargestNumber);
	}

	return LargestNumber;
}
int largestElementMainE()
{
	vector<int> arr1 = {-3,4,1,2,3};
	vector<int> arr2 = {-1-2-3-3,8};
	cout <<LargestElementE(arr1)<<endl;
	cout <<LargestElementE(arr2)<<endl;

	return 0 ;
}
//-------------------------------------------------------------
int MaximumSubarraySumE(vector<int>arr)
{
	int CurrentSum{0};
	int LargestSum{0};
	for (int i = 0;i<arr.size();i++)
	{
			CurrentSum =  CurrentSum + arr[i];
		if (CurrentSum <0)
		{
			CurrentSum = 0;
		}
			LargestSum = max(LargestSum,CurrentSum);
		
	}

	return LargestSum;
}
int MaximumSubarraySumMainE()
{
	vector<int> arr1 = {1,-2,3,4,4,-2};
	vector<int> arr2 = {5,0,-1,0,1,2,-1};
	cout <<MaximumSubarraySumE(arr1)<<endl;
	cout <<MaximumSubarraySumE(arr2)<<endl;

	return 0 ;
}
//-------------------------------------------------------------
int LowerBoundE(vector<int>arr,int Val)
{
	for (int i = 0; i < Val;i++)
	{
		vector<int>::iterator itr = lower_bound(arr.begin(),arr.end(),Val);

		if (Val == *itr)
		{
			cout << "yes" <<(itr - arr.begin())<< endl;	
		}
		else
		{
			cout << "no" <<(itr - arr.begin()) << endl;			
		}



		
		
	}
	
	
	return 0;
}
int LowerBoundMainE()
{
	vector<int> arr1 ={-1,-1,2,3,5};
	vector<int> arr2 ={1,2,3,4,6};
	int Val = 4;

	
	 LowerBoundE(arr1,Val);
	// LowerBoundE(arr2,Val);
	return 0;
}
//-------------------------------------------------------------
void SortedPairSumE(vector<int> arr,int x)
{
	int PairLeft{0};
	int PairRight{0};

	int LeftIndex{0};
	int RightIndex = arr.size()-1;
	int Diff = INT_MAX;

	while (RightIndex>LeftIndex)
	{
		if (abs(arr[LeftIndex] + arr[RightIndex] - x) < Diff)
		{
			PairLeft = LeftIndex;
			PairRight = RightIndex;
			Diff = abs(arr[LeftIndex] + arr[RightIndex] - x);
		}

		if (arr[LeftIndex] + arr[RightIndex] > x)
		{
			RightIndex--;
		}
		else
		{
			LeftIndex++;
		}
	}
cout << "The closest pair is " << arr[PairLeft] << " and " << arr[PairRight];
	
}
int SortedPairSumMainE()
{
	vector<int> arr ={10,22,28,29,30,40};
	int x = 54;


	SortedPairSumE(arr,x);
	
	return 0;
}

void KRotationE(vector<int>arr,int x)
{
	for (int k = 0;k < x;k++)
	{
		for (int i = 0;i < arr.size();i++)
		{
			cout << arr[i];
		}
		cout << endl;
		
		int last = arr.size() - 1;
		int lastNumber = arr[last];
		
		for (int i = arr.size()-2; i >= 0; i--)
			{
				arr[i+1] = arr[i];
			}
		arr[0] = lastNumber;
	}
}




int KRotationMainE()
{


	vector<int> arr ={1,3,5,7,9};
	int x = 2;


	  KRotationE(arr,x);


	
	return 0;
}


int main(){
	
	//ArrayFunctionMain();
	//LinearSearchMain();
	//BinarySearchMain();
	//ArrayReverseMain();
	//PrintAllPairsMain();
	//PrintSubArraysMain();
	//PrintSubArrayMainOptimized();


	//CODING EXERCISES E=exercise--------
	//MaximumSubArraySumMain();
	//largestElementMainE();
	//MaximumSubarraySumMainE();
	//LowerBoundMainE();
	//SortedPairSumMainE();
	KRotationMainE();
	return 0;
}


