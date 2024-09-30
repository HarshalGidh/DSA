#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
void createbox(int **arr,int limit,int r,int c)
{
    int i,j,num=0,x=2;
    int bin[32];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            arr[i][j]=0;
    }
    cout<<"\n1st\n";
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        { 
               if(num<limit)
               {
                cout<<num+1<<" ";
                num=num+2;
               }
               else
               {
                   cout<<"0 ";
               }
        }
        cout<<endl;
    }
    cout<<"\n2nd\n";
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(x<limit)
          {
			int k=0,y=x;
            while(x>0)
            {
                bin[k]=x%2;
                x=x/2;
                k++;
            }
            if (bin[1]==1)
                arr[i][j]=y;
            	cout<<arr[i][j]<<" ";
            x=y;
            x++;
           }
        }
        cout<<endl;
    }
    cout<<"\n3rd\n";

}
int main()
{
    int n,i;
    int **matrix;
    int row,col;
    cout<<"Enter n:\n";
    cin>>n;
    for(i=0;i<n;i++)
    {
        if(n<pow(2,i))
        {
            row=i;
            break;
        }
    }
    col=row;
    matrix=new int*[row];
    for(int i=0;i<row;i++)
    {
        matrix[i]=new int[col];
    }
    createbox(matrix,n,row,col);
}
