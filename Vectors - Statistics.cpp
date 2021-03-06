

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<double> vector_insert()  //Function which inserts the values to vectors and returns the vector to the main program.
{
	double tmp = 0.0;
	vector<double> vec_ins;
	string value;
	bool done = false;
	cout << "\nPlease enter a double value to be inserted to the vector\n";
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

void vector_display(vector<double> vec_disp) // Function which displays the contents of the vector. Does not send anything back to the main program.
{
	int itr,vec_size = 0;

	vec_size = vec_disp.size();

	for (itr = 0; itr < vec_size; itr++)
	{
		cout << vec_disp[itr] << "\t";
	}

}

double vector_min(vector<double> vec_min) // Function which returns the minimum value among the vector values.
{
	double tmp_min;
	int vec_size,itr,itr2;

	vec_size = vec_min.size();
	tmp_min = 1000000.00;
	for (itr = 0; itr < vec_size; itr++)
	{
		if (tmp_min > vec_min[itr])
		{
			tmp_min = vec_min[itr];
		}
	}

	return tmp_min;

	
}

double vector_max(vector<double> vec_max) // Function which returns the maximum value among the vector values.
{
	double tmp_max;
	int vec_size, itr;

	vec_size = vec_max.size();
	tmp_max = -1000000.00;
	for (itr = 0; itr < vec_size; itr++)
	{
		if (tmp_max < vec_max[itr])
		{
			tmp_max = vec_max[itr];
		}
	}

	return tmp_max;

}

double vector_total(vector<double> vec_tot) // Function which returns the total value of all the vector values.
{
	double total;
	int vec_size, itr;

	vec_size = vec_tot.size();
	total = 0.0;
	for (itr = 0; itr < vec_size; itr++)
	{
		total = total + vec_tot[itr];
	}

	return total;

}

double vector_average(vector<double> vec_avg) // Function which returns the average value of all the vector values.
{
	double total;
	int vec_size, itr;

	vec_size = vec_avg.size();
	total = vector_total(vec_avg);

	return total / vec_size;

}

double vector_variance(vector<double> vec_var) // Function which returns the variance of all the vector values.
{
	double avg,diff,sq_of_diff;
	double numerator = 0.0;
	int vec_size, itr;

	avg = vector_average(vec_var);
	vec_size = vec_var.size();

	for (itr = 0; itr < vec_size; itr++)
	{
		diff = avg - vec_var[itr];
		sq_of_diff = pow(diff, 2);
		numerator = numerator + sq_of_diff;
	}

	return numerator / vec_size;

}

void vector_std_dev(vector<double> vec_std_dev) // Function which returns the standard deviation of all the vector values.
{
	double var, std_dev;
	double numerator = 0.0;
	int vec_size, itr;

	var = vector_variance(vec_std_dev);
	std_dev = sqrt(var);

	cout << std_dev << endl;

	return;

}


int main()
{
	vector<double> data;
	int choice;
	double min, max, total, average, variance, std_dev;
	while(1)
	{
		cout << "!-------------------------------!\n";
		cout << "Lets work with Vectors \n";
		cout << "Here are all the options that you are free to choose from. \n";
		cout << "Make sure you enter the right choice by entering the number. \n \n";
		cout << "1.Input Vector \n";
		cout << "2.Show Vector \n";
		cout << "3.Find Min \n";
		cout << "4.Find Max \n ";
		cout << "5.Find Total \n ";
		cout << "6.Find Average \n";
		cout << "7.Find Variance \n";
		cout << "8.Find Standard Deviation \n";
		cout << "9.Quit...\n";

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
			cout << "The minimum of all the values entered in the vector is:\n";
			min = vector_min(data);
			cout << min << endl;
			break;
		case 4:
			cout << "The maximum of all the values entered in the vector is:\n";
			max = vector_max(data);
			cout << max << endl;
			break;
		case 5:
			cout << "The total of all the values entered in the vector is:\n";
			total = vector_total(data);
			cout << total << endl;
			break;
		case 6:
			cout << "The average of all the values entered in the vector is:\n";
			average = vector_average(data);
			cout << average << endl;
			break;
		case 7:
			cout << "The variance of all the values entered in the vector is:\n";
			variance = vector_variance(data);
			cout << variance << endl;
			break;
		case 8:
			cout << "The standard deviation of all the values entered in the vector is:\n";
			vector_std_dev(data);
			break;
		case 9:
			cout << "Exiting the program.......\n";
			exit(1);
			break;
		default:
			cout << "Wrong Choice !!! Let's try that once again. This time, please choose the numbers from above. \n";
		}
	}
}
