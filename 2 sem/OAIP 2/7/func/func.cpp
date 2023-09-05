

void push(stack*& p, int value) //Добавление символа в начало списка
{
    stack* newP = new stack;
    if (newP != NULL)     //есть ли место?  
    {
        newP->digit = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

void show(stack* p) {
    if (p->next == NULL)
    {
        cout << "Список пуст!\n";
        return;
    }
    while (p != NULL) {
        cout << p->digit << " ";
        p = p->next;
    }
    cout << endl;
}


void pop(stack*& p) {
    p->next = (p->next)->next;
}

void clear(stack*& p) {
    p->next = NULL;
    p = NULL;
}