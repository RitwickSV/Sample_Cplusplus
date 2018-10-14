
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;


void max_heapify(int *arr, int i, int n)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        max_heapify(arr,largest,n);
    }
    return;
}

void build_maxheap(int *a,int n)
{
    int i;
    for(i = n/2 - 1; i >= 0; i--)
    {
        max_heapify(a,i,n);
    }
}

void heap_tree_print(int num_matrix[],int n)
{
     int rows,col,i=0,j=0,height,empty_space,btwn_space,counter,flag=1,num_itrtr=0,hold_empty_space,hold_btwn_space;


    //n = sizeof(num_matrix)/sizeof(num_matrix[0]);

    cout << n << " is the number of elements in the array" << endl;

    height = log2(n);

    cout << height << " is the height of the heap array" << endl;

    rows=height+1;
    col=pow(2,height+1)-1;

    string op_matrix[rows][col];

     for(i=0; i<rows; i++)
    {
        for(j=0; j<col; j++)
        {
            op_matrix[i][j]="   ";
        }
    }

    for(i=0; i<rows; i++)
    {
        empty_space = pow(2,height-i)-1;

        hold_empty_space = empty_space;

        counter = pow(2,i);


        for(j=0; j<col; j++)
        {
            if(counter!=0)
            {

                if(empty_space>0)
                {
                    empty_space--;
                    continue;
                }

                if(counter==pow(2,i))
                {
                    op_matrix[i][j]=to_string(num_matrix[num_itrtr++]);
                    counter--;
                    continue;
                }

                if(counter<pow(2,i) && hold_btwn_space>0)
                {
                    hold_btwn_space--;
                    continue;
                }

                if(counter<pow(2,i) && hold_btwn_space==0 && num_itrtr<n)
                {
                    op_matrix[i][j]=to_string(num_matrix[num_itrtr++]);
                    counter--;
                    hold_btwn_space=btwn_space;
                    continue;

                }

            }

        }

        btwn_space=hold_empty_space;
        hold_btwn_space=btwn_space;

    }

    for(i=0; i<rows; i++)
    {
        for(j=0; j<col; j++)
        {
            cout << op_matrix[i][j];
        }
        cout << "\n\n";
    }
    return;
}

int main()
{
    int arr_size,arr[]={2,3,6,1,7,8,9,13,63,11,5,6,7,8,9,10,12,13,14,15,16,'NULL'},itrtr=0,choice,value,i=0,tmp;

    while(1)
        {
            cout << "\n\n!-------------------------------!\n";
            cout << "Lets work with heaps \n";
            cout << "Here are all the options that you are free to choose from. \n";
            cout << "Make sure you enter the right choice by entering the number. \n \n";
            cout << "1.Show array entered (basically before the heapify is selected) \n";
            cout << "2.Heapify the array.(Choose option 2 to see the array entered before heapify) \n";
            cout << "3.Show heap in the form of a tree \n";
            cout << "4.Insert the value into the heap and display the heap. \n ";
            cout << "5.Delete element from the heap and display the heap. \n ";
            cout << "6.Quit...\n";

            cout << "Enter your choice : \n \n";

            arr_size = 21;
            cin >> choice;

            switch (choice)
            {

                case 1:
                {
                    cout << "The Values entered in the array are: \n";

                    for(i=0; i<arr_size; i++)
                        cout << arr[i] << "\t";
                    break;
                }

                case 2:
                {
                        cout << "there are " << arr_size << " elements in the array \n." << endl;
                        build_maxheap(arr,arr_size);
                        cout << "The array entered has been max heapified.\n" << endl;
                        break;
                }



                case 3:
                {
                    cout << "The heap tree printed in the form of a tree is as below \n";
                    heap_tree_print(arr,arr_size);
                    break;
                }


                case 4:
                {
                    cout << "Enter the value to be entered into the heap:\n";
                    cin >> value;
                    arr[arr_size] = value;
                    arr_size = arr_size + 1;
                    build_maxheap(arr,arr_size);
                    cout << "The heap after entering the value " << value << " is \n" << endl;
                    heap_tree_print(arr,arr_size);
                    break;
                }

                case 5:
                    cout << "The root value is always deleted from the heap \n";
                    arr[0] = arr[arr_size];
                    arr_size = arr_size - 1;
                    build_maxheap(arr,arr_size);
                    cout << "The heap after deletion is \n" << endl;
                    heap_tree_print(arr,arr_size);
                    break;

                case 6:
                {
                    cout << "Exiting the program.......\n";
                    exit(1);
                    break;
                }
                default:
                    cout << "Wrong Choice !!! Let's try that once again. This time, please choose the numbers from above. \n";
            }
        }
}
