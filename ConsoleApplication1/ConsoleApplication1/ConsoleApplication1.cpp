#include "stdafx.h"
#include <iostream>
#include "List.h"
# include<conio.h>  

using namespace std;



node *Tree;     //��������� �� ������ ������
node  *Res;      //��������� �� ��������� �������
int B;                //������� ���������� ������� � ������





void main ()
{         setlocale (LC_CTYPE, "Russian");
int el;  
BuildTree();  
Vyvod(GetTree(), 0);
cout<<"������� ���� �������, ������� ����� ����� � ������: ";
cin>>el;
if  (Poisk (el))   cout<<"� ������ ���� ����� �������!\n";
else     cout<<"� ������ ��� ����� �������!\n";
cout<<"������� ���� ����������� �������: ";
cin>>el;
Addition (el);  
Vyvod (GetTree(), 0);
}
