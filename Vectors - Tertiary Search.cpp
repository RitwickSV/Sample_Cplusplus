
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> vector_insert()  //Function which inserts the values to vectors and returns the vector to the main program.
{
	int tmp = 0.0;
	vector<int> vec_ins;
	string value;
	bool done = false;
	cout << "\nPlease enter a int value to be inserted to the vector\n";
	cout << "The insertion terminates when you enter q.\n";


	while (!done)
	{
		cin >> value;
		if (value == "q")
		{
			done = true;
		}
		else
		{
			tmp = stod(value);
			vec_ins.push_back(tmp);
		}
	}

	return vec_ins;
}

void vector_display(vector<int> vec_disp) // Function which displays the contents of the vector. Does not send anything back to the main program.
{
	int itr, vec_size = 0;

	vec_size = vec_disp.size();

	for (itr = 0; itr < vec_size; itr++)
	{
		cout << vec_disp[itr] << "\t";
	}

}

int ter_search(vector<int> v, int v_size, int part1, int part2, int srch_val)
{

	if (part1 < 0 || part2 > v_size - 1 || part1 > part2)
	{
		return -1;
	}
	if (srch_val == v[part1])
	{
		return part1;
	}

	if (srch_val == v[part2])
	{
		return part2;
	}

	// Update the two index part1 and part2 if the element is not found.


	if (srch_val < v[part1])
	{
		return ter_search(v, v_size, part1 - 1, part2, srch_val);
	}

	if (srch_val > v[part1] && srch_val < v[part2])
	{

		return ter_search(v, v_size, part1 + 1, part2 - 1, srch_val);
	}

	if (srch_val > v[part2])
	{
		return ter_search(v, v_size, part1, part2 + 1, srch_val);
	}
}

int main()
{
	vector<int> data;
	int choice, val, vec_size, part1, part2;
	int min, max, total, average, variance, std_dev;
	while (1)
	{
		cout << "\n!-------------------------------!\n";
		cout << "We'll be trying to search a value among a given set of values inserted in a vector. \n";
		cout << "Here are all the options that you are free to choose from. \n";
		cout << "Make sure you insert values into the vector before searching \n \n";
		cout << "1.Input Vector \n";
		cout << "2.Show Vector \n";
		cout << "3.Search for value and return the index \n";
		cout << "4.Quit...\n";

		cout << "Enter your choice : \n \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Inserting new values in the vector \n";
			data = vector_insert();
			break;
		case 2:
			cout << "The Values entered in the vector are: \n";
			vector_display(data);
			break;
		case 3:
		{
			cout << "Enter the number you want to search in the vector\n";
			cin >> val;
			vec_size = data.size();

			part1 = vec_size / 3;  // The two partitions for a tertiary search
			part2 = part1 * 2;

			if (ter_search(data, vec_size, part1 - 1, part2 - 1, val) == -1)
			{
				cout << "There were " << vec_size << " values and the Number does not exist in the vector.\n";
			}
			else
			{
				cout << "There were " << vec_size << " values and the number " << val << " is present at index:" << ter_search(data, vec_size, part1 - 1, part2 - 1, val) << "\n";
			}
			break;
		}
		case 4:
			cout << "Exiting the program.......\n";
			exit(1);
			break;

		default:
			cout << "Wrong Choice !!! Let's try that once again. This time, please choose the numbers from above. \n";
		}
	}
}
