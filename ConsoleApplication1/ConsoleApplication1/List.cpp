
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "List.h"
using namespace std;


extern node *Tree;
extern node  *Res;  
extern int B;  


node** GetTree() 
{    return & Tree;    
}


void Search (int x, node **p)    //Поиск звена x
{       if (*p == NULL)   //*p - указатель на вершину 
        {       *p = new(node);  
                 (**p).Key = x;    (**p).Count = 1;
                 (**p).Left = (**p).Right = NULL;  
         }
         else   if(x<(**p).Key)    Search (x, &((**p).Left));
                  else   if  (x>(**p).Key)    Search (x, &((**p).Right));
                           else  (**p).Count += 1;
 }
void BuildTree ()      //Построение бинарного дерева
{      int el;
        cout<<"Введите ключи вершин дерева: \n";     cin>>el;   
        while  (el != 0)
        {      Search (el, &Tree);    cin>>el;     }
}
void Vyvod (node **w, int l)  //Вывод на экран
{      int i;
        if  (*w != NULL)            //*w - указатель на корень 
                  {     Vyvod (&((**w).Right), l + 1);
                         for  (i = 1;  i <= l;  i++)  cout<<"   ";
                         cout<<(**w).Key<<endl;
                         Vyvod (&((**w).Left),  l  + 1); 
         }
}	
int Poisk (int k)        //Поиск вершины с ключом k 
{       node *p,*q=NULL; B = false; p = Tree;
         if  (Tree != NULL)
         do
         {       q = p; 
                  if  ((*p).Key == k)    B = true;
                  else  {   q = p;   if  (k < (*p).Key)  p = (*p).Left;   else  p = (*p).Right;    }   
          }  while  (!B  &&  p != NULL); 
         Res = q;
         return B;
}
void Addition (int k)    //Добавление звена k 
{        node *s;  Poisk (k);
if  (!B)
{      s = new(node);
        (*s).Key  = k;    (*s).Count = 1;
        (*s).Left = (*s).Right = NULL;
        if  (Tree == NULL)   Tree = s;
        else  if  (k<(*Res).Key)   (*Res).Left = s;
                else  (*Res).Right = s;    
}
else  (*Res).Count += 1;
}




node *Poisk_1 (int k, node **p)   //Поиск вершины с ключом k 
{     if  (*p == NULL) return (NULL);
      else    if  ((**p).Key == k)   return (*p);
                else  if  (k < (**p).Key)   return Poisk_1 (k, &((**p).Left));
                        else   return Poisk_1 (k, &((**p).Right));
}
void Delete_1 (node **r, node **q)
{      node *s;
        if  ((**r).Right == NULL)
        {      (**q).Key = (**r).Key;   (**q).Count = (**r).Count;
                *q = *r; s = *r;  *r = (**r).Left;   delete s; 
         }
         else  Delete_1 (&((**r).Right), q);
}
void Delete (node **p, int k)   //Удаление вершины k 
{     node *q; 
      if  (*p == NULL) 
      cout<<"Вершина с заданным ключом не найдена!\n";
else  if  (k<(**p).Key) Delete (&((**p).Left), k);
        else   if  (k>(**p).Key) Delete (&((**p).Right), k);
                 else
                {     q = *p;
                       if  ((*q).Right == NULL) 
                       {     *p = (*q).Left; 
                              delete q;
                         }
                         else   if  ((*q).Left == NULL) 
                                  {     *p = (*q).Right; 
                                         delete q; 
                                   }
                                  else  Delete_1 (&((*q).Left), &q);  
                  }
}

