# include <stdio.h>
# include <limits.h>
# include <iostream>

using namespace std;

// A utility function to get maximum of two integers
int max(int a, int b) { 
	return (a > b) ? a : b; 
}

/* Function to get minimum number of trails needed in worst
case with e eggs and f floors */
int eggDrop(int e, int f)
{
	//the check how many time it went into the function
	//cout << ".";
	// If there are no floors, then no trials needed. OR if there is
	// one floor, one trial needed.
	if (f == 1 || f == 0)
		return f;

	// We need k trials for one egg and k floors
	if (e == 1)
		return f;

	int min = INT_MAX, x, res;

	// Consider all droppings from 1st floor to kth floor and
	// return the minimum of these values plus 1.
	for (x = 1; x <= f; x++)
	{
		res = max(eggDrop(e - 1, x - 1), eggDrop(e, f - x));
		if (res < min)
			min = res;
	}

	return min + 1;
}

//pick small amounts for the egg and floors like 5 or 8
//the binary tree is big with large numbers
int main()
{
	//e for egg f for floor
	int egg,floor;
	cout << "enter number of eggs: ";
	cin >> egg;
	cout << "enter number of floors: ";
	cin >> floor;
	cout << "calculating";
	int trials = eggDrop(egg, floor);
	cout << endl;
	cout <<"Minimum number of trials in worst case with "<<egg<<" eggs and "<<floor<<" floors is "<<trials<<endl;
	system("PAUSE");
	return 0;
}
