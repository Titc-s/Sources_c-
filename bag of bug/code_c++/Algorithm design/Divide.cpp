#include<iostream>
using namespace std;
const int N = 4;


void input(int n, float put[][N])
{
    int i, j;
    for (int i = 0; i < N; i++)
    {
        cout << "请输入第" << i + 1 << "行数据:";
        for (int j = 0; j < N; j++)
            cin >> put[i][j];
        cout << endl;
    }
}
void output(int n, float out[][N])
{
    int i, j;

    cout << "C的计算结果为:";
    for (i = 0;i<n;i++)
    {
        cout << endl;
        for (j = 0; j < n;j++)
            cout << out[i][j] << "\t";
    }
}

// void MatrixMultiply(float A[][N], float B[][N],float C[][N])
// {
//     int i, j, k;
//     for (i = 0; i < 2;i++)
//         for (j = 0; j < 2;j++){
//             C[i][j] = 0;
//             for (k = 0; k < 2;k++)
//                 C[i][j] = C[i][j] + A[i][k]*B[i][j];
//         }
//  }

void Matrix_Add(int n,float A[][N], float B[][N],float C[][N])
{
    int i, j;
    for (i = 0; i < n;i++)
        for (j = 0; j < n;j++)
            C[i][j] = A[i][j] + B[i][j];
}

void Matrix_Sub(int n,float A[][N], float B[][N],float C[][N])
{
    int i, j;
     for (i = 0; i < n;i++)
        for (j = 0; j < n;j++)
            C[i][j] = A[i][j] - B[i][j];
}

void Strassen(int n,float A[][N],float B[][N] ,float C[][N])
{
    float A11[N][N], A12[N][N], A21[N][N], A22[N][N];
    float B11[N][N], B12[N][N], B21[N][N], B22[N][N];
    float C11[N][N], C12[N][N], C21[N][N], C22[N][N];
    float M1[N][N], M2[N][N], M3[N][N], M4[N][N], M5[N][N], M6[N][N], M7[N][N];
    float AA[N][N], BB[N][N], MM1[N][N], MM2[N][N];

    int i, j;
    if (n == 2)
      {
		for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				C[i][j]=0;
				for(int t=0;t<2;t++){
					C[i][j]+=A[i][t]*B[t][j];
				}
			}
		}
		return ;
	}
    else
    {
        for (i = 0; i < n / 2;i++)
            for (j = 0; j < n / 2;j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + n / 2];
                A21[i][j] = A[i + n / 2][j];
                A22[i][j] = A[i + n / 2][j + n / 2];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + n / 2];
                B21[i][j] = B[i + n / 2][j];
                B22[i][j] = B[i + n / 2][j + n / 2];

            }
        Matrix_Sub(n / 2, B12, B22, BB);
        Strassen(n / 2, A11, BB, M1);//M1 = A11(B12 -B22)

        Matrix_Add(n / 2, A11, A12, AA);
        Strassen(n / 2, AA, B22, M2);//M2 = (A11+A12)B22

        Matrix_Add(n / 2, A21, A22, AA);
        Strassen(n / 2, AA, B11, M3);// M3 = (A21+A22)B11

        Matrix_Sub(n / 2, B21, B11, BB);
        Strassen(n / 2, A22, BB, M4);//M4 = A22*(B21-B11)

        Matrix_Add(n / 2, A11, A22, AA);
        Matrix_Add(n / 2, B11, B22, BB);
        Strassen(n / 2, AA, BB, M5);//M5 = (A11+A22)(B11+B22)

        Matrix_Sub(n / 2, A12, A22, AA);
        Matrix_Add(n / 2, B21, B22, BB);
        Strassen(n / 2, AA, BB, M6);// M6 = (A12-A22)*(B21+B22)

        Matrix_Sub(n / 2, A11, A21, AA);
        Matrix_Add(n/2,B11,B12,BB);
        Strassen(n / 2, AA, BB, M7); //M7 = (A11-A21)*(B11+B12)

        Matrix_Add(n / 2, M5, M4, MM1);
        Matrix_Sub(n / 2, M6, M2, MM2);
        Matrix_Add(n / 2, MM1, MM2, C11); //C11 = M5+M4-M2+M6;

        Matrix_Add(n / 2, M1, M2, C12); //C12 = M1+M2;

        Matrix_Add(n / 2, M3, M4, C21); //C21 = M3+M4;

        Matrix_Add(n / 2, M5, M1, MM1);
        Matrix_Add(n / 2, M3, M7, MM2);
        Matrix_Sub(n / 2, MM1, MM2, C22); //c22 = M5+M1-M3-M7;
        for (i = 0; i < n / 2;i++)
            for (j = 0; j < n / 2;j++)
            {
                C[i][j] = C11[j][i];
                C[i][j + n / 2] = C12[i][j];
                C[i + n / 2][j] = C21[i][j];
                C[i + n / 2][j + n / 2] = C22[i][j];
            }
    }
}

 int main()
 {
     float A[N][N],B[N][N],C[N][N];
     cout << "请输入矩阵A:";
     input(N, A);
     cout << "请输入矩阵B：";
     input(N, B);

     Strassen(N, A, B, C);
         output(N, C);

 }