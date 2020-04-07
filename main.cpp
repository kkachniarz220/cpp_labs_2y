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

node *last(node *H) {
    node *p = H;
    while (p->next != NULL) {
        p = p->next;
    }
    return p;
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

bool include(node *&H, int searchValue) {
    node *p = H;

    while (p->next != NULL && p->val != searchValue) {
        p = p->next;
    }
    if (p->next == NULL && p->val != searchValue) {
        return false;
    } else {
        return true;
    }
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
    if(isEmpty(H)) {
        cout << "Pusta lista, brak elementow do skopiowania" << endl << "Koncze dzialanie funkcji" << endl;
        return;
    }
    node *p = H;
    node *p2 = H;
    while (p->next != NULL) {
        if (p->val % 2 == 0) {
            p2 = p->next;
            node *p3 = new node;
            p3->val = p->val;
            p3->next = p2;
            p->next = p3;
            p = p->next->next;
            cout << p->val;
        } else {
            p = p->next;
        }
    }
    if(p->next == NULL) {
        if(p->val % 2 == 0) {
            p2 = new node;
            p2->val = p->val;
            p->next = NULL;
            p->next = p2;
            return;
        }
    }

}

void spacer(string value = "=========") {
    cout << "==========" << value << "==========";
    cout << endl;
}

void removeBetween(node *&H, int firstPointValue, int secondPointValue) {
    node *p = H;
    node *firstBoundaryNode = H;
    node *secondBoundaryNode = H;
    node *p2 = H;
    int countOfDeletedNodes = 0;

    if (isEmpty(H)) {
        cout << "Pusta lista, brak elementow do usuniecia" << endl << "Koncze dzialanie funkcji" << endl;
        return;
    }

    if (!include(H, firstPointValue)) {
        cout << "Nie znaleziono pierwszego elementu" << endl << "Koncze dzialanie funkcji" << endl;
        return;
    }
    while (p->next != NULL && p->val != firstPointValue) {
        p = p->next;
    }
    firstBoundaryNode = p;

    if (!include(H, secondPointValue)) {
        cout << "Nie znaleziono drugiego elementu" << endl << "Koncze dzialanie funkcji" << endl;
        return;
    }
    p = H;
    while (p->next != NULL && p->val != secondPointValue) {
        p = p->next;
    }
    secondBoundaryNode = p;

    p = firstBoundaryNode;
    while (p->next != NULL && p->next != secondBoundaryNode) {
        p = p->next;
    }
    if (p->next == NULL) {
        p = secondBoundaryNode;
        if (p->next == firstBoundaryNode) {
            cout << "Brak elementow pomiedzy, nic nie usunieto" << endl;
            return;
        }
        p = p->next;
        while (p->next != NULL && p->next != firstBoundaryNode) {
            p2 = p;
            p = p->next;
            delete p2;
            countOfDeletedNodes++;
        }
        delete p;
        countOfDeletedNodes++;
        secondBoundaryNode->next = firstBoundaryNode;
    } else {
        p = firstBoundaryNode;
        if (p->next == secondBoundaryNode) {
            cout << "Brak elementow pomiedzy, nic nie usunieto" << endl;
            return;
        }
        p = p->next;
        while (p->next != NULL && p->next != secondBoundaryNode) {
            p2 = p;
            p = p->next;
            delete p2;
            countOfDeletedNodes++;
        }
        delete p;
        countOfDeletedNodes++;
        firstBoundaryNode->next = secondBoundaryNode;
    }

    cout << "Liczba usunietych elementow z listy: " << countOfDeletedNodes << endl;
}

void moveNodesThatAreBetween(node *&H, int firstPointValue, int secondPointValue) {
    node *p = H;
    node *firstBoundaryNode = NULL;
    node *secondBoundaryNode = NULL;

    if (isEmpty(H)) {
        cout << "Pusta lista, brak elementow do przeniesienia" << endl << "Koncze dzialanie funkcji" << endl;
        return;
    }

    node *lastNode = last(H);

    if (!include(H, firstPointValue)) {
        cout << "Nie znaleziono pierwszego elementu" << endl << "Koncze dzialanie funkcji" << endl;
        return;
    }
    while (p->next != NULL && p->val != firstPointValue) {
        p = p->next;
    }
    firstBoundaryNode = p;

    if (!include(H, secondPointValue)) {
        cout << "Nie znaleziono drugiego elementu" << endl << "Koncze dzialanie funkcji" << endl;
        return;
    }
    p = H;
    while (p->next != NULL && p->val != secondPointValue) {
        p = p->next;
    }
    secondBoundaryNode = p;

    p = firstBoundaryNode;
    while (p->next != NULL && p->next != secondBoundaryNode) {
        p = p->next;
    }
    if (p->next == NULL) {
        p = secondBoundaryNode;
        if (p->next == firstBoundaryNode) {
            cout << "Brak elementow pomiedzy, nic nie przeniesiono" << endl;
            return;
        }
        p = p->next;
        lastNode->next = p;
        while (p->next != NULL && p->next != firstBoundaryNode) {
            p = p->next;
        }
        p->next = NULL;
        secondBoundaryNode->next = firstBoundaryNode;
    } else {
        p = firstBoundaryNode;
        if (p->next == secondBoundaryNode) {
            cout << "Brak elementow pomiedzy, nic nie przeniesiono" << endl;
            return;
        }
        p = p->next;
        lastNode->next = p;
        while (p->next != NULL && p->next != secondBoundaryNode) {
            p = p->next;
        }
        p->next = NULL;
        firstBoundaryNode->next = secondBoundaryNode;
    }
}

void copyListAtTheEndInReverseOrder(node *&H) {
    if (isEmpty(H)) {
        cout << "Pusta lista, brak elementow do skopiowania, koncze dzialanie funkcji" << endl;
        return;
    }
    node *p = H;
    node *lastCopiedNode = NULL;
    node *lastNode = last(H);
    node *latestCopy = new node;
    latestCopy->val = lastNode->val;
    lastNode->next = latestCopy;
    lastCopiedNode = lastNode;
    while (lastCopiedNode != H) {
        p=H;
        while (p->next != lastCopiedNode) {
            p = p->next;
        }
        latestCopy->next = new node;
        latestCopy = latestCopy->next;
        latestCopy->val = p->val;
        lastCopiedNode = p;
    }
}

void moveToTopMaximalElement(node *&H) {
    if(isEmpty(H)) {
        cout << "Pusta lista, koncze dzialanie funkcji" << endl;
        return;
    }
    node *maximalElement = H;
    node *p = H;
    node *p2 = NULL;

    while(p->next != NULL) {
        p = p->next;
        if(p->val > maximalElement->val) {
            maximalElement = p;
        }
    }

    if(maximalElement == H) {
        return;
    }

    p=H;
    while(p->next != maximalElement) {
        p = p->next;
    }

    p->next = maximalElement->next;
    p = H;
    H = maximalElement;
    maximalElement->next = p;

}

int main() {
    node *H = NULL;
//    int list[0] = {};
//    int list[1] = {10};
//    int list[2] = {8, 5};
//    int list[10] = {22, 12, 8, 5, 18, 5, 8, 6, 3, 5};
    int list[3] = {25, 8, 55};
//    int list[3] = {25, 55, 8};
//    int list[5] = {25, 75, 25, 55, 8};

    for (auto &i : list) {
        add(H, i);
    }

    cout << "Lista zaraz po utworzeniu: ";
    show(H);

//    cout << endl;
//    spacer("Usuwanie co drugiego elementu");
//    delEverySecondElement(H); // usuwanie co drugiego elementu
//    show(H);
//    spacer();

//    cout << endl;
//    spacer("Operacja kopiowania elementu za jeżeli jest parzysty");
//    copyNumberBehindIfIsEven(H); // kopiuj wartosc za jezeli jest parzysta
//    show(H);
//    spacer();

//    cout << endl;
//    spacer("Operacja usuwania pomiedzy x oraz y");
//    removeBetween(H, 5, 22);
//    show(H);
//    spacer();

//    cout << endl;
//    spacer("Operacja przeniesienia elementow pomiedzy x oraz y na koniec listy");
//    moveNodesThatAreBetween(H, 18, -5);
//    show(H);
//    spacer();

//    cout << endl;
//    spacer("Operacja skopiowania listy na koniec w odwrotnej kolejnosci");
//    copyListAtTheEndInReverseOrder(H);
//    show(H);
//    spacer();

    cout << endl;
    spacer("Operacja przeniesienia najwiekszego elementu na początek listy");
    moveToTopMaximalElement(H);
    show(H);
    spacer();


    return 0;
}