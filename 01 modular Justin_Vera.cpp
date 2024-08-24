#include <iostream>
#include <cstdlib> //necesita esta libreria para el realloc xd
using namespace std;
//MODULAR 3.2
struct Vector {
    int* m_pVect;  // Pointer to the buffer
    int m_nCount;  // Control how many elements are actually used
    int m_nMax;    // Control how many are allocated as maximum
    int m_nDelta;  // To control the growing
};

void Resize(Vector* pThis) {

    int newSize = pThis->m_nMax + pThis->m_nDelta; // The Max has to be increased by delta
    int* newVect = (int*) realloc (pThis->m_pVect, sizeof(int) * newSize);

    if (newVect == nullptr) {
        std::cerr << "Memory allocation failed!\n";
        exit(1);
    }
    pThis->m_pVect = newVect;
    pThis->m_nMax = newSize;
}

void Insert(Vector* pThis, int elem) {
    if (pThis->m_nCount == pThis->m_nMax) {
        Resize(pThis); // Resize the vector before inserting elem
    }
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

void PrintVector(const Vector* pThis) {
    for (int i = 0; i < pThis->m_nCount; ++i) {
        cout << pThis->m_pVect[i] << ' ';
    }
    cout << std::endl;
}

int main() {
    Vector v;

    v.m_nCount = 0;
    v.m_nMax = 5;
    v.m_nDelta = 10;
    v.m_pVect = (int*)malloc(sizeof(int) * v.m_nMax);

    if (v.m_pVect == nullptr) {
        std::cerr << "Memoria fallo D:\n";
        return 1;
    }

    for (int i = 0; i < 15; ++i) {
        Insert(&v, i);
    }

    PrintVector(&v);

    return 0;
}