//magic square for odd number 
#include<iostream>
#include<iomanip>
using namespace std;
void createSquare(int **array,int r,int c)
{
    int i,j,range,count=1;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            array[i][j]=0;
    }
    range=r*c;
    i=0;
    j=c/2;
    array[i][j]=count;

    while (count<range)
    {
        count++;
        if((i-1)<0&&(j-1)<0)
            i++;
        else if((i-1)<0&&(j-1)<0)
        {
            i=r-1;
            j--;
        }
        else if((j-1)<0)
        {
            j=c-1;
            i--;
        }
        else if(array[i-1][j-1]!=0)
            i++;
        else
        {
            i--;
            j--;
        }
        array[i][j]=count;
        
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            cout<<setw(5)<<array[i][j];
        cout<<endl;
    }
}
main()
{
    int **matrix;
    int row=7,col,sum;
    col=row;
    sum=row*(row*row+1)/2;
    cout<<"check that the sum of nos across row\n";
    matrix=new int*[row];
    for(int i=0;i<row;i++)
    {
        matrix[i]=new int[col];
    }
    createSquare(matrix,row,col);

}