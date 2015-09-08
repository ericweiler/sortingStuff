#include <iostream> //cin, cout
#include <stdlib.h>  //rand()
#include <string>
using namespace std;

bool istaken(int j, int * randomarray, int current);
int* randomarray(int size);
void display(int* myArray);
void bubblesort(int* myArray, int size);

void display(int* myArray,int size)
{
	for (int i = 0; i < size; i++)
		cout << "myArray[" << i << "] = " << myArray[i] << endl;
}

void bubblesort(int* myArray, int size)
{
	int comparisons = 0, temp;
	for (int decrease = 1; decrease < size; decrease++)
	{
		for (int i = 0; i < size - decrease; i++)
		{
			if (myArray[i]>myArray[i + 1])
			{
				temp = myArray[i + 1];
				myArray[i + 1] = myArray[i];
				myArray[i] = temp;
			}
			comparisons = comparisons + 2;
		}
		comparisons++;
	}
	cout << "comparisons: " << comparisons << endl;
}

int* randomarray(int size){
	int * randomarray = new int[size]; //allocates new memory for array using user-defined "size"
	int current = 0; //number of elements in the array that have been initialized
	for (int i = 0; i < size; i++)
	{
		randomarray[i] = rand() % size;
		while (istaken(i, randomarray, current))
			randomarray[i] = rand() % size;
		current++;
	}
	return randomarray;
}

bool istaken(int j, int * myArray,int current) //compares an array element (j) to all other elements in the array to see if the number is in use somewhere else.
{
	for (int i = 0; i < current; i++) //only searches up to "current", the current number of initialized elements in the array.
	{
		if (i == j) //prevents comparison to itself
			i++;
		if (myArray[j] == myArray[i]) //checks to see if the element is already taken, if it is, the function returns true, if not the loop continues through every element.
			return true;
	}
	return false; //if the loop cycles through every element and doesnt find a match, it returns false.
}



int main(){
	string command;
	int size; //length of array, temporary int for switching in bubble sort, number of comparisons occured
	int* myArray = 0;
	bool hasarray = false;
	while (true)
	{
		cout << "What would you like to do?" << endl << "Options: 'print', 'sort', 'new'" << endl;
		cin >> command;
		if (command == "print")
		{
			if (hasarray == true)
				display(myArray, size);
			else
				cout << "You dont have an array yet" << endl << endl;
		}
		else if (command == "sort")
		{
			if (hasarray == true)
				bubblesort(myArray, size);
			else
				cout << "You dont have an array yet" << endl << endl;
		}
		else if (command == "new")
		{
			cout << "Enter the length of array (Max = 32767): ";
			cin >> size;
			cout << "Randomizing..." << endl;
			myArray = randomarray(size);
			cout << "Finished" << endl << endl;
			hasarray = true;
		}
		else
			cout << "Try Again";
	}
}
