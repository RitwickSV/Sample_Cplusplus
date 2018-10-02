#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

int main()
{
    int rows,col,i=0,j=0,height,n,empty_space,btwn_space,counter,flag=1,num_itrtr=0,hold_empty_space,hold_btwn_space;
    int num_matrix[21]={2,3,6,1,7,8,9,13,63,11,5,6,7,8,9,10,12,13,14,15,16};

    n = sizeof(num_matrix)/sizeof(num_matrix[0]);

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
        cout << "\n";
    }

}
