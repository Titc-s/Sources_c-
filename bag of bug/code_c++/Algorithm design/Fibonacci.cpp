#include<iostream>
using namespace std;

void Multiply(int M[2][2],int N[2][2])
{
    int **a=new int*[2];
    int **b=new int*[2];
    for(int i=0;i<2;i++)
    {
        a[i]=new int[2];
        b[i]=new int[2];
    }

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        { 
            a[i][j]=M[i][j];
            b[i][j]=N[i][j];
        }

    M[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
    M[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
    M[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];
    M[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];

   for(int i = 0;i < 2;i++)
	{
		delete a[i];
        delete b[i];
		a[i] = NULL;
        b[i] = NULL;
	}
	delete []a;
    delete []b;
	a = NULL;
    b = NULL;

}

void Fibonacci(int M[2][2],int n)
{
    int N[2][2]={{1,1},{1,0}};
    if(n==1)
    return;
    else{
        Fibonacci(M,n/2);
        Multiply(M,M);
        if(n%2==1)
        Multiply(M,N);
    }
}

int main()
{
    int M[2][2]={{1,1},{1,0}};
    cout<<"请输入求解的项数 n: ";
    int n;
    cin>>n;
    Fibonacci(M,n);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
    system("pause");
    return 0;
}
