
struct  node
{      int Key;  
        int Count;  
        node *Left;  
        node *Right;  
 };

node** GetTree() ;
void Search();
void BuildTree ();
void Vyvod (node **w, int l);
int Poisk (int k);
void Addition (int k);

node *Poisk_1 (int k, node **p) ;
void Delete_1 (node **r, node **q);
void Delete (node **p, int k) ;
