#include <iostream>
#include <iomanip>
using namespace std;

void PrintArray(int** root, int height, int width);

int main() {
	int height = 0;//Student notes. I believe these are ints holding values for height and width, initalized to 0. 
	int width = 0;

	//get input from user for table row and column (height and width respectively)
	cout << " Please enter a number of rows on the interval [1, 10]: ";
	cin >> height;
	while (height > 10) {//validate height is less than 10
		cout << " This is not within the interval [1, 10]. Please try again \n Please enter a number of rows on the interval [1, 10]: ";
		cin >> height;
	}
	cout << " Please enter a number of columns on the interval [1, 10]: ";
	cin >> width;
	while (width > 10) {//validate width is less than 10
		cout << " This is not within the interval [1, 10]. Please try again \n Please enter a number of columns on the interval [1, 10]: ";
		cin >> width;
	}

	// Create the root double pointer for the 2D array.
	int** ppRootPointer = NULL; //Student notes. This is a variable of type int, that will hold the address of another variable that holds an address. 
								// It is initalized to null. This is a double pointer.

	// Allocate an array of int* variables and attach to the double pointer.
	ppRootPointer = new(int*[height]); //now we are asking for an array of integer pointers, and those pointers are set to the ppRootPointer variable. 

	// Allocate arrays of int variables and attach each array to one of the
	// pointers in ppRootPointer's array of pointers.
	for (int i = 0; i < height; i++) {
		ppRootPointer[i] = new(int[width]);//over here we are now looking at each of the height pointers, and allocating space next to it for the width pointers. 
	}

	// Fill the array with a count.
	// this is the int that is filled out as the the program works through the pointer addresses
	int column = 0;//sets column to 0
	for (int i = 0; i < height; i++) { //i < height
		column++;//counts column up
		int row = 0;//sets row to 0
		for (int j = 0; j < width; j++) { //j < width
			row++;//counts row up
			ppRootPointer[i][j] = column * row;//sets ppRootPointer at that width to the counter value. each [] is a dereference so its not printing out the address. multiplies column and row
		}
	}

	// Print the array.
	PrintArray(ppRootPointer, height, width); //passes ppRootPointer, height and width as inputs for the void function print array

	// Deallocate the memory.
	for (int i = 0; i < height; i++) { //Instructor comments makes sense, i kept them. 
		// Since each pointer has multiple elements attached (the widths)
		// we must include the [] with the delete operation.
		// Omitting the [] with the delete operation will only deallocate
		// memory for a single element in the array.  Including the []
		// will use the array size indicated in the new statement used
		// to initially allocate the memory.  If in doubt, use the []
		// with the delete operation.
		delete[] ppRootPointer[i];
	}

	delete[] ppRootPointer; //deletes root pointer. 
}

void PrintArray(int** root, int height, int width) {//prints array
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << right;
			cout << setw(3) << root[i][j] << "|";//root with [] dereferences the memory. setwidth to 3 for spacing, ends with "|" and fills empty space with _.
		}

		cout << endl;
		for (int j = 0; j < width; j++) {
			cout << "---+";
		}
		cout << endl;
	}


}
