#include <iostream>
#include <string>

using namespace std;

struct node {
    int val;
    node *next;
};

void add(node *&H, int x) {
    node *p = new node;
    p->val = x;
    p->next = H;
    H = p;
}

int size(node *H) {
    int size = 0;
    while (H != NULL) {
        H = H->next;
        size++;
    }
    return size;
}

void show(node *H) {
    node *p = H;
    cout << "HEAD->";
    while (p != NULL) {
        cout << p->val << "->";
        p = p->next;
    }
    cout << "NULL" << endl;
}

void delTop(node *&H) {
    if (H != NULL) {
        node *p = H;
        H = p->next;
        delete p;
    }
}

void delX(node *&H, int x) {
    if (H != NULL) {
        node *p = H;
        if (H->val == x) {
            delTop(H);
        } else {
            while (p->next != NULL && p->next->val != x) {
                p = p->next;
            }

            if (p->next != NULL) {
                delTop(p->next);
            }
        }
    }
}

void delEverySecondElement(node *&H) {
    delTop(H);
    node *p = H;
    node *p2 = H;
    while (p != NULL && p->next != NULL) {
        p = p->next;
        p2->next = p->next;
        p2 = p2->next;
        delete p;
        p = p2;
    }

}

void copyNumberBehindIfIsEven(node *&H) {
    node *p = H;
    node *p2 = H;
    while (p != NULL && p->next != NULL) {
        if (p->val % 2 == 0) {
            p2 = p->next;
            node *p3 = new node;
            p3->val = p->val;
            p3->next = p2;
            p->next = p3;
            p = p->next->next;
        } else {
            p = p->next;
        }
    }

}


bool isEmpty(node *H) {
    if (H != NULL) {
        return 0;
    } else {
        return 1;
    }
}

void top(node *H) {
    if (H != NULL) {
        cout << H->val << endl;
    } else {
        cout << "empty";
    }
}

void spacer(string value = "=========") {
    cout << "==========" << value << "==========";
    cout << endl;
}

void push() {}

void pop() {}

void removeBetween(node *&H, int firstPointValue, int secondPointValue) {
    node *p = H;
    node *firstElement = H;
    node *secondElement = H;
    node *p2 = H;
    int countOfDeletedNodes = 0;

    while (p->next != NULL && p->val != firstPointValue) {
        p = p->next;
    }
    if (p->next == NULL && p->val != firstPointValue) {
        cout << "Nie znaleziono pierwszego elementu" << endl << "Koncze dzialanie funkcji" << endl;
        return;
    } else {
        firstElement = p;
    }

    p = H;
    while (p->next != NULL && p->val != secondPointValue) {
        p = p->next;
    }
    if (p->next == NULL && p->val != secondPointValue) {
        cout << "Nie znaleziono drugiego elementu" << endl << "Koncze dzialanie funkcji" << endl;
        return;
    } else {
        secondElement = p;
    }

    p = firstElement;
    while (p->next != NULL && p->next != secondElement) {
        p = p->next;
    }
    if (p->next == NULL) {
        p = secondElement;
        if(p->next == firstElement) {
            cout << "Brak elementow pomiedzy, nic nie usunieto" << endl;
            return;
        }
        p = p->next;
        while (p->next != NULL && p->next != firstElement) {
            p2 = p;
            p = p->next;
            delete p2;
            countOfDeletedNodes++;
        }
        delete p;
        countOfDeletedNodes++;
        secondElement->next = firstElement;
    } else {
        p = firstElement;
        if(p->next == secondElement) {
            cout << "Brak elementow pomiedzy, nic nie usunieto" << endl;
            return;
        }
        p = p->next;
        while (p->next != NULL && p->next != secondElement) {
            p2 = p;
            p = p->next;
            delete p2;
            countOfDeletedNodes++;
        }
        delete p;
        countOfDeletedNodes++;
        firstElement->next = secondElement;
    }

    cout << "Liczba usunietych elementow z listy: " << countOfDeletedNodes << endl;

}

int main() {
    node *H = NULL;
    add(H, 12);
    add(H, 17);
    add(H, 18);
    add(H, 20);
    add(H, 22);
    add(H, 24);
    add(H, 2);
    add(H, 4);
    add(H, 6);
    cout << "Lista zaraz po stworzeniu: ";
    show(H);

//    delEverySecondElement(H); // usuwanie co drugiego elementu
//    show(H);

//    copyNumberBehindIfIsEven(H); // kopiuj wartosc za jezeli jest parzysta
//    show(H);
    cout << endl;
    spacer("Operacja usuwania pomiedzy x oraz y");
    removeBetween(H, 6, 12);
    show(H);
    spacer();

    return 0;
}
