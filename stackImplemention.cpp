// Stack, Linked List Implementation
// ID - 190204065
// 22/08/2021

#include <iostream>


using namespace std;

struct stk{
    int data;
    struct stk *next;
};
stk * ref = NULL;

void push(int data)
{
    struct stk *newStack;
    newStack = new stk();

    newStack->data = data;
    if(ref == NULL)
        newStack->next = NULL;
    else
        newStack->next = ref;
    ref = newStack;

    cout << "Push Done" << endl;
}

void pop()
{
    if(ref == NULL)
    {
        cout << "Stack Empty." << endl;

    }
    else
    {
        struct stk * temp = ref;
        cout << "Deleting: " << temp->data << endl;
        ref = temp->next;
        free(temp);
    }
    if(ref != NULL)
    {
        cout << "Pop Done" << endl;

    }

}

int size()
{
    int size=0;
    struct stk *temp=ref;
    if(ref == NULL)
        size = 0;
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
            size++;
        }
        size++;
    }

    return size;
}

bool isEmpty()
{
    if(ref == NULL)
        return true;
    else
        return false;
}

void viewStack()
{
    struct stk *temp = ref;

    while(temp->next != NULL) {
            cout << temp->data<< "-->" <<" ";
            temp = temp->next;
    }
    cout << temp->data<< "-->NULL" <<" " << endl;
}

void Menu()
{
    cout << "------Menu------" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Check Size" << endl;
    cout << "4. Check if Empty" << endl;
    cout << "5. View Stack" << endl;
    cout << "6. Exit" << endl;
}

int main()
{
    while(true)
    {

        Menu();
        int inp;
        cin >> inp;
        switch (inp) {
            case 1:
                int val;
                cout << "Enter Data to Push: " << endl;
                cin >> val;
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                cout << "Size of the Stack: " << size() << endl;
                break;
            case 4:
                cout << "Stack Empty or not (1/0): " << isEmpty() << endl;
                break;
            case 5:
                viewStack();
                break;
            case 6:
                exit(1);
            default:
                cout << "Wrong Choice";
            
        }
    }
}
