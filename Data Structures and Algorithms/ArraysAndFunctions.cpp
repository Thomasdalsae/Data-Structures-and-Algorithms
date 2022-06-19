#include"Header.h";




//WRONG
void WrongprintArray(int arr[]) {
	

	cout << "In the Wrong function there is :" << sizeof(arr) << endl;
	int n = sizeof(arr) / sizeof(int);
	
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}


}
//CORRECT
void CorrectPrintArray(int * arr, int n) {

	cout << "In the Correct function there is :" << sizeof(arr) << endl;
	arr[0] = 100;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
	
}



int main() {

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
	WrongprintArray(arr);

	cout << "In main there is :" << sizeof(arr) << endl;
	//loop that goes trough each slot inn the arra writing out the value.
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;

	}
	//here we are sending the reference of arr to the function printArray

	
	return 0;

}