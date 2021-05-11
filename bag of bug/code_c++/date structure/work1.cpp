#include<iostream>
#include<malloc.h>

using namespace std;

typedef struct {
    int *elem;
    int length;
} Sqlist;

void InitList (Sqlist &L){
    L.elem = (int *)malloc(100 * sizeof(int));
    L.length = 0;
}
void CreateList(Sqlist &L){
    int n, i = 0;
    cin >> n;
    while(n!=-1){
        L.elem[i++] = n;
        cin >> n;
        L.length++;
    }
    cout << "输入完成" << endl << endl;

}
int Listlength(Sqlist L){
    return L.length;
}
void GetElem(Sqlist L,int i, int &e){
    e = L.elem[i - 1];
}
int LocateElem(Sqlist L,int e){
    int i = 0;
    for (i = 0; i < L.length;i++){
        if(L.elem[i]==e)
            return 0;
              
    }
      return 1;
}
void ListInsert(Sqlist &L,int i,int e){
    int j;
    if(i<1||i>L.length +1){
        cout << "Error" << endl;
    exit(0);
    }
    else{
        for (j = L.length; j > i;j--)
            L.elem[j] = L.elem[j - 1];
        L.elem[i - 1] = e;
        L.length++;
    }
}
void UnionList(Sqlist &La, Sqlist Lb){
    int e;
    int Lalen = Listlength(La);
    int Lblen = Listlength(Lb);
    for (int i = 1; i <=Lblen;i++){
        GetElem(Lb, i, e);
        if(LocateElem(La,e))
            ListInsert(La, ++Lalen, e);
    }
}

void ListSort(Sqlist &L){
    int temp;
    int Llen = Listlength(L);
    for (int i = 0; i < Llen;i++)
        for (int j = i + 1; j < Llen;j++){
            if(L.elem[i]>L.elem[j]){
                temp = L.elem[j];
                L.elem[j] = L.elem[i];
                L.elem[i] = temp;
            }
        }
}

void MergeList(Sqlist La, Sqlist Lb, Sqlist &Lc){
    int ai, bi;
    InitList(Lc);
    int i = 1, j = 1, k = 0;
    int Lalen = Listlength(La);
    int Lblen = Listlength(Lb);
    while(i <=Lalen&&j<=Lblen){
        GetElem(La, i, ai);
        GetElem(Lb, j, bi);
        if(ai<=bi){ 
            ListInsert(Lc, ++k, ai);
            i++;
           }
           else {
               ListInsert(Lc, ++k, bi);
               j++;
           }

    }
 while(i<=Lalen){
     GetElem(La, i++, ai);
     ListInsert(Lc, ++k, ai);
 }
  while(j<=Lblen){
     GetElem(Lb, j++, bi);
     ListInsert(Lc, ++k, bi);
 }
}

void PrintList(Sqlist L){
    for (int i = 0; i < L.length;i++)
        cout << L.elem[i] << " ";
    cout << endl;
}


int main()
{
    Sqlist La, Lb, Lc, Ld;
    InitList(La);
    InitList(Lb);
    InitList(Ld);
    CreateList(La);
    CreateList(Lb);
    UnionList(La, Lb);
    ListSort(La);
    PrintList(La);
    CreateList(Ld);
    MergeList(La, Ld, Lc);
    PrintList(Lc);
    return 0;
}