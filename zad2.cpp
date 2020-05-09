/* Kachniarz Krzysztof
 * Wydział Inżynierii Metali i Informatyki Przemysłowej
 * Informatyka Stosowana
 * Grupa 1
 * Nr. albumu: 307668
 * Algorytmy i Struktury danych
 * */

#include <iostream>
#include <string>
#include <math.h>

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

void spacer(string value = "=========") {
    cout << "==========" << value << "==========";
    cout << endl;
}

double average(node *&H) {
    node *p = H;
    double summary = 0;
    while (p != NULL) {
        summary += p->val;
        p = p->next;
    }
    return summary / size(H);
}

bool isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s*s == x);
}

bool isFibonacci(int n)
{
    return isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4);
}

void sort(node *&H) {
    if (isEmpty(H)) {
        cout << "Pusta lista, koncze dzialanie";
        return;
    }
    if (size(H) < 3) {
        cout << "Minimalna liczba elementow w tablicy to 3, koncze dzialanie";
        return;
    }
    node *H1 = NULL;
    node *H2 = NULL;
    node *splitPoint = H;
    node *p = H->next;

    while (p != NULL) {
        if (p->val < splitPoint->val) {
            add(H1, p->val);
            splitPoint->next = p->next;
            delete p;
        } else {
            add(H2, p->val);
            splitPoint->next = p->next;
            delete p;
        }
        p = splitPoint->next;
    }
    last(H1)->next = H;
    H->next = H2;
    H = H1;
}

void moveBiggerThanAverageToTheTail(node *&H) {
    if (isEmpty(H)) {
        cout << "Pusta lista, koncze dzialanie";
        return;
    }
    if (size(H) < 2) {
        cout << "Minimalna liczba elementow w tablicy to 2, koncze dzialanie";
        return;
    }

    double averageValue = average(H);
    node *lastElement = last(H);
    node *p = H;
    node *beforeP = H;
    int counter = 0;

    cout << "Srednia: " << averageValue << endl;
    while (counter < size(H)) {
        if (p->val > averageValue) {
            if (p == H) {
                H = p->next;
                lastElement->next = p;
                p->next = NULL;
                lastElement = p;
                p = H;
            } else {
                if (p != lastElement) {
                    beforeP->next = p->next;
                    lastElement->next = p;
                    p->next = NULL;
                    lastElement = p;
                    p = beforeP->next;
                }
            }
        } else {
            p = p->next;
            if (beforeP->next != p) {
                beforeP = H;
                while (beforeP->next != p) {
                    beforeP = beforeP->next;
                }
            }
        }
        counter++;
    }
}

void removeNodeIfIsFibonacci(node *&H) {
    if (isEmpty(H)) {
        cout << "Pusta lista, koncze dzialanie";
        return;
    }

    node *p = H;
    node *beforeP = H;

    while(p != NULL) {
        if(isFibonacci(p->val)) {
            if(p == H) {
                H = p->next;
                delete p;
                p = H;
            } else {
                while(beforeP->next != p) {
                    beforeP = beforeP->next;
                }
                beforeP->next = p->next;
                delete p;
                p = beforeP->next;
                beforeP = H;
            }
        } else {
            p = p->next;
        }
    }
}

int main() {
    node *H = NULL;
//    int list[0] = {};
//    int list[1] = {10};
//    int list[2] = {8, 5};
    int list[11] = {2, 22, 12, 8, 18, 8, 6, 3, 1, 2, 100};
//    int list[3] = {25, 8, 55};
//    int list[3] = {25, 55, 8};
//    int list[5] = {25, 75, 25, 55, 8};

    for (int &i : list) {
        add(H, i);
    }
    spacer("Przed");
    show(H);
    removeNodeIfIsFibonacci(H);
    spacer("Po");
    show(H);


    return 0;
}
