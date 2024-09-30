#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
    int i,j,limit,num=0;
    char yn;
    cout<<"Enter a limit:";
    cin>>limit;
    if(limit<32)
    {
    	int a1[5][5]=
    	{
    		{1,13,0,25,0},
    		{0,3,1517,27},
			{19,0,7,29,0},
			{31,23,0,9,0},
			{0,0,5,21,11}
		};
		int b1[5][5]=
		{
		{2,11,0,23,0},
		{0,14,3,0,27},
		{22,0,30,6,15},
		{0,18,26,0,7},
		{10,0,0,19,31}	
		};
		int c1[5][5]=
		{
		{4,0,0,12,11},
		{13,5,0,23,29},
		{22,6,0,14,0},
		{0,15,31,7,0},
		{28,0,20,0,30}
		};
		int d1[5][5]=
		{
		{8,0,13,0,26},
		{0,9,27,14,0},
		{15,0,10,0,28},
		{0,24,11,0,31},
		{29,30,0,12,25}
		};
		int e1[5][5]=
		{
		{16,0,21,27,0},
		{0,17,29,0,22},
		{0,24,0,20,30},
		{23,0,18,0,25},
		{28,26,0,31,19}
		};
		cout<<"1st\n";
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            cout<<a1[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"2nd\n";
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            cout<<b1[i][j]<<"\t";
        cout<<"\n";
    }
	cout<<"3rd\n";
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            cout<<c1[i][j]<<"\t";
        cout<<"\n";
    }	
    cout<<"4th\n";
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            cout<<d1[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"5th\n";
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            cout<<e1[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"\nTake a number from 1-31 and observe the above matrices";
    for(i=0;i<5;i++)
    {
        cout<<"\nIs it presnet in "<<i+1<<" matrix?(y/n)";
        cin>>yn;
        if(yn=='y')
        {
            num=num+pow(2,i);
        }
    }
    if(num==0)
    {
        cout<<"\nChoose a number from 1-31";
    }
    else
    {
        cout<<"\nThe number choosed is:"<<num;
    }
    
	}
    else if(limit<64)
	{
		
	int a[6][6]=
    {
    {1,13,57,25,47,33},
    {45,3,15,17,27,61},
    {19,0,7,29,35,49},
    {31,23,43,9,53,0},
    {0,37,5,21,11,41},
    {51,59,0,39,63,55}
    };
    int b[6][6]=
    {
    {2,11,0,23,38,54},
    {47,14,3,55,27,0},
    {22,35,30,6,15,39},
    {58,18,26,0,7,46},
    {10,0,42,19,31,51},
    {34,50,54,43,62,59}
    };
    int c[6][6]=
    {
    {4,0,37,12,11,46},
    {13,5,0,23,29,38},
    {22,6,45,14,52,60},
    {61,15,31,7,39,0},
    {28,62,20,55,30,53},
    {47,36,0,44,54,63}
    };
    int d[6][6]=
    {
    {8,40,13,0,26,46},
    {47,9,27,14,41,60},
    {15,56,10,0,28,42},
    {43,24,11,57,31,0},
    {29,30,44,12,25,58},
    {59,62,0,45,61,63}
    };
    int e[6][6]=
    {
    {16,0,21,27,55,50},
    {51,17,29,56,22,0},
    {0,24,57,20,30,52},
    {23,53,18,58,25,62},
    {28,26,59,31,19,48},
    {49,60,54,0,61,63}
    };
    int f[6][6]=
    {
    {32,54,37,43,0,51},
    {50,33,45,60,38,0},
    {0,49,61,36,55,46},
    {62,40,34,56,52,58},
    {39,53,48,57,63,41},
    {44,42,59,47,35,0}
    };
    cout<<"1st\n";
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
            cout<<a[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"\n2nd\n";
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
            cout<<b[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"\n3rd\n";
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
            cout<<c[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"\n4th\n";
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
            cout<<d[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"\n5th\n";
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
            cout<<e[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"\n6th\n";
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
            cout<<f[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"\nTake a number from 1-63 and observe the above matrices";
    for(i=0;i<6;i++)
    {
        cout<<"\nIs it presnet in "<<i+1<<" matrix?(y/n)";
        cin>>yn;
        if(yn=='y')
        {
            num=num+pow(2,i);
        }
    }
    if(num==0)
    {
        cout<<"\nChoose a number from 1-63";
    }
    else
    {
        cout<<"\nThe number choosed is:"<<num;
    }
	}
	else
		cout<<"\nChoose a number from 1-63";
    return 0;
}
