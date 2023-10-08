#include <iostream>
using namespace std;
//Declare global variables.
int LinearCount = 0, BinaryCount = 0;
//Function prototypes.
int LinearSearch(int[], int, int);
int BinarySearch(int[], int, int);
int main() {
	//Declare variables and constants.
	const int SIZE = 20;
	int Array[SIZE] = { 2,4,6,7,8,9,11,14,15,16,17,19,20,22,24,30,35,39,43,48 };
	int value = 30;
	//Call the functions that conduct linear and binary search.
	int positionlinear = LinearSearch(Array, SIZE, value);
	int positionBinary = BinarySearch(Array, SIZE, value);
	//Display the results of the searches.
	cout << "The value being searched is " << value << "." << endl;
	cout << "It was found in position " << positionlinear + 1 << " of the array using the linear search algorithm." << endl;
	cout << "Tt was found in position " << positionBinary + 1 << " of the array using the binary search algorithm." << endl;
	cout << "The number of comparisons made by the linear search algorithm was " << LinearCount << "." << endl;
	cout << "The number of comparisons made by the binary search algorithm was " << BinaryCount << "." << endl;
	return 0;
}
//Function for conducting linear search.
int LinearSearch(int array[], int size, int VALUE) {
	int position = -1, index = 0;
	bool found = false;
	while (index < size && !found) {
		LinearCount++;
		if (array[index] == VALUE) {
			found = true;
			position = index;
		}
		index++;
	}
	return position;
}
//Function for conducting binary search.
int BinarySearch(int array[], int size, int VALUE) {
	int first = 0, last = size - 1, middle, position = -1;
	bool found = false;
	while (!found && first <= last) {
		BinaryCount++;
		middle = (first + last) / 2;
		if (array[middle] == VALUE) {
			found = true;
			position = middle;
		}
		else if (array[middle] > VALUE)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}