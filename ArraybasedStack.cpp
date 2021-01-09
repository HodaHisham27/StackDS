#include <iostream>
using namespace std ;
#define MaxStack 10000
#define StackEntry int
struct Stack
{
    StackEntry elements [MaxStack] ;
    int StackTop ;
};
void CreateStack(Stack * ps)
{
        ps->StackTop = 0 ;
}
void push (Stack * ps , StackEntry item)
{
        ps->elements[ps->StackTop] = item ;
        ps->StackTop++ ;
}
    void pop(StackEntry *pe, Stack * ps)
    {
        ps->StackTop-- ;
        *pe = ps->elements[ps->StackTop] ;

    }
    StackEntry Top_of_Stack (Stack * ps)
    {
        return ps->elements[ps->StackTop-1] ;
    }
    int Size_of_Stack (Stack * ps)
    {
        return ps->StackTop ;
    }
    bool IsStackEmpty (Stack * ps)
    {
        return ps->StackTop == 0 ;
    }
    bool IsStackFull (Stack * ps)
    {
        return ps->StackTop == MaxStack ;
    }
    void ClearStack (Stack *ps)
    {
        ps->StackTop=0;
    }
    void traverse (Stack *ps, void *pf(StackEntry) )
    {
        for (int i=ps->StackTop; i>0; i--)
        {
            (*pf)(ps->elements[i-1]);
        }

    }
int main ()
{
    Stack s;
    CreateStack(&s);
    push(&s,5);
    push(&s,6);
    push(&s,7);
    push(&s,8);
    push(&s,9);
    cout<<Size_of_Stack(&s)<<endl;
    cout<<IsStackEmpty(&s)<<endl;
    cout<<IsStackFull(&s)<<endl;
    cout<<Top_of_Stack(&s)<<endl;
    StackEntry poped_val;
    pop(&poped_val,&s);
    cout<<Size_of_Stack(&s)<<endl;
    cout<<IsStackEmpty(&s)<<endl;
    cout<<IsStackFull(&s)<<endl;
    cout<<Top_of_Stack(&s)<<endl;
    return 0;


}