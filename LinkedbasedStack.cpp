#include <iostream>

using namespace std;

#define StackEntry int

struct StackNode {
    StackEntry element ;
    StackNode* next ;
};
struct Stack {
    StackNode* TopElement ;
    int StackSize ;
};
void CreateStack (Stack *ps){
      ps->TopElement =  NULL ;
      ps->StackSize = 0 ;
    }
void push (Stack *ps ,StackEntry item){
    StackNode* temp = new StackNode ;
    temp->element = item ;
    temp->next  = ps->TopElement ;
    ps->TopElement = temp ;
    ps->StackSize++ ;
}
void pop (StackEntry * pe ,Stack *ps){
    *pe = ps->TopElement->element ;
    StackNode* temp = ps->TopElement ;
    ps->TopElement = ps->TopElement->next ;
    delete temp ;
    ps->StackSize-- ;
}
StackEntry Top_of_Stack (Stack *ps){
return ps->TopElement->element ;
}
bool IsStackEmpty (Stack *ps){
  return ps->TopElement ==  NULL;
}
int Size_of_Stack (Stack *ps)
{
    return ps->StackSize;
}
bool IsStackFull (Stack *ps){
return 0 ;
}
void ClearStack (Stack *ps){
   StackNode* temp = ps->TopElement ;
   while(temp){
    temp = temp->next ;
    delete ps->TopElement ;
    ps->TopElement = temp ;
   }
    ps->StackSize = 0 ;
}


int main()
{
 Stack s;
 CreateStack(&s);
 push(&s,5);
 push(&s,6);
 push(&s,7);
 push(&s,8);
 cout<<Top_of_Stack(&s)<<endl;
 cout<<IsStackEmpty(&s)<<endl;
 StackEntry poped_val;
 pop(&poped_val,&s);
 cout<<poped_val<<" "<<Top_of_Stack(&s)<<endl;
 cout<<Size_of_Stack(&s)<<endl;
 return 0;

}