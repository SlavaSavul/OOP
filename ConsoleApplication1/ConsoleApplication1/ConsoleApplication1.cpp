#include "stdafx.h"
#include <iostream>
#include "List.h"
# include<conio.h>  

using namespace std;



node *Tree;     //Указатель на корень дерева
node  *Res;      //Указатель на найденную вершину
int B;                //Признак нахождения вершины в дереве





void main ()
{         setlocale (LC_CTYPE, "Russian");
int el;  
BuildTree();  
Vyvod(GetTree(), 0);
cout<<"Введите ключ вершины, которую нужно найти в дереве: ";
cin>>el;
if  (Poisk (el))   cout<<"В дереве есть такая вершина!\n";
else     cout<<"В дереве нет такой вершины!\n";
cout<<"Введите ключ добавляемой вершины: ";
cin>>el;
Addition (el);  
Vyvod (GetTree(), 0);
}
