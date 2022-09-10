#include <iostream>
#include <fstream>
#include <string>
using namespace std;

static int f;
const int arraySize = 100000;
void swap(int& a, int& b);
void getFile();
void selectionSort(int name[arraySize], int size);
int megaint[arraySize];
int binarySearch(int array[], int size, int userValue);

int main() {

	getFile();

	return 0;
}
void getFile() {
	// get the file
	cout << "enter name of file path: ";
	string name;
	getline(cin, name);
	ifstream inputFile;
	inputFile.open(name);
	if (inputFile.is_open()) { // filename input validation
		for (int i = 0; i < arraySize; i++) {
			inputFile >> megaint[i];
		}
		// array has a value assigned. 
		cout << "\n\nwhat value are you looking for?: ";
		cin >> f;
		// we have our array and value to search. sequential search for it now.
		int count = 0;
		for (int i = 0; i < arraySize; i++) { // could make a function but its so simple that its not worth it at the moment.
		if (megaint[i] == f) {
			break;
		}	
		count++;
		}

		cout << "\n\nSequential search took " << count << " tries.";
		//just need to sort the array now. send it
		selectionSort(megaint, arraySize);
	}
	else
	{
		cout << "sorry file invalid try again m8;";
		getFile();
	}
}

void selectionSort(int name[], int size) {
	for (int start = 0; start < (size - 1); start++) { // itereate through 0-999999 for comparrison 1.
		for (int index = start + 1; index < size; index++) { // iterate through 1-100000 for comparrison 2.
			// essentially if array [0] < array [1] so fourth... hence index = start + 1...
			if (name[index] < name[start]) { // lowest value has been found now. just assign it to appropriate subscript if needed.
				swap(name[index], name[start]);
			}
		}
	}

	// values are sorted lets binary search now.
	cout << "\n\nBinary search took " << binarySearch(name, arraySize, f) << " tries.";

}

void swap(int& a, int& b) {
	int x = a;
	a = b;
	b = x;
}

int binarySearch(int array[], int arraySize, int userValue) {
	int count = 0;
	int low = 0;
	int high = arraySize - 1;
	
	while (low <= high) {
		count++;
		int mid = (low + high) / 2;
		if (userValue == array[mid]) {
			return count;
		}
		else if (userValue > array[mid]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return count;
}
