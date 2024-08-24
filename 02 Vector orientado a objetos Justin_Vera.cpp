#include <iostream>
#include <stdexcept>
using namespace std;

class CVector {
private:
    int* m_pVect;   // Pointer to the buffer
    int m_nCount;   // Control how many elements are actually used
    int m_nMax;     // Control how many are allocated as maximum
    int m_nDelta;   // To control the growing

    void Init(int delta); // Init our private variables, etc
    void Resize();        // Resize the vector when occurs an overflow

public:
    CVector(int delta = 10); // Constructor
    void Insert(int elem);   // Insert a new element
    ~CVector();              // Destructor
    void Print() const;     //  Imprime elementos 
    int GetCount() const;   // Conteo de elementos
    int GetMax() const;     // Tamaño maximo
};

// Constructor
CVector::CVector(int delta) : m_nCount(0), m_nMax(delta), m_nDelta(delta) {
    m_pVect = new int[m_nMax];
}

// Destructor
CVector::~CVector() {
    delete[] m_pVect;
}

void CVector::Init(int delta) {
    m_nDelta = delta;
}

// Resize
void CVector::Resize() {
    m_nMax += m_nDelta;
    int* new_pVect = new int[m_nMax];
    for (int i = 0; i < m_nCount; ++i) {
        new_pVect[i] = m_pVect[i];
    }
    delete[] m_pVect;
    m_pVect = new_pVect;
}

// Insertar
void CVector::Insert(int elem) 
{
    if (m_nCount == m_nMax) {   // Verify the overflow
        Resize();               // Resize the vector before inserting elem
    }
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

// Imprime Vector
void CVector::Print() const {
    for (int i = 0; i < m_nCount; ++i) {
        std::cout << m_pVect[i] << " ";
    }
    std::cout << std::endl;
}

int CVector::GetCount() const {
    return m_nCount;
}

int CVector::GetMax() const {
    return m_nMax;
}

int main() {
    CVector vector; //Crea un vector de "10" por predeterminado

    vector.Insert(1);
    vector.Insert(2);
    vector.Insert(3);

    std::cout << "Vector elements: ";
    vector.Print();

    std::cout << "Numero de Elementos: " << vector.GetCount() << std::endl;
    std::cout << "Tamaño maximo: " << vector.GetMax() << std::endl;

    return 0;
}