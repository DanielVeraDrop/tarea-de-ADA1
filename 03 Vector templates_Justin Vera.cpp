#include <iostream>
using namespace std;
template <typename Type>
class CVector {
private:
    Type* m_pVect; // Pointer to the buffer
    int m_nCount;  // Control how many elements are actually used
    int m_nMax;    // Control the number of allocated elements
    int m_nDelta;  // To control the growing

    void Init(int delta); // Initialize private variables
    void Resize();        // Resize the vector when overflow occurs

public:
    CVector(int delta = 10); // Constructor
    ~CVector();              // Destructor
    void Insert(Type elem);   // Insertar un nuevo elemento
    void Display();           // Soltar en el vector
};

template <typename Type>
void CVector<Type>::Init(int delta) {
    m_nDelta = delta;
    m_nCount = 0;
    m_nMax = delta;
    m_pVect = new Type[m_nMax]; // Memoria inicial
}

template <typename Type>
void CVector<Type>::Resize() {
    m_nMax += m_nDelta; // Agrandar
    Type* newBuffer = new Type[m_nMax];

    for (int i = 0; i < m_nCount; i++) {
        newBuffer[i] = m_pVect[i];
    }
    delete[] m_pVect; 
    m_pVect = newBuffer; 
}

template <typename Type>
CVector<Type>::CVector(int delta) {
    Init(delta);
}

template <typename Type>
CVector<Type>::~CVector() {
    delete[] m_pVect; //Liberar memoria
}

template <typename Type>
void CVector<Type>::Insert(Type elem) {
    if (m_nCount == m_nMax)     
        Resize();               
    m_pVect[m_nCount++] = elem; // Inserta elemento al final
}

template <typename Type>
void CVector<Type>::Display() {
    for (int i = 0; i < m_nCount; i++) {
        std::cout << m_pVect[i] << " "; 
    }
    std::cout << std::endl;
}

int main() {

    CVector<int> intVector;
    intVector.Insert(1);
    intVector.Insert(2);
    intVector.Insert(3);
    std::cout << "Vector: ";
    intVector.Display();

    CVector<double> doubleVector; 
    doubleVector.Insert(1.1);
    doubleVector.Insert(2.2);
    doubleVector.Insert(3.3);
    std::cout << "Vector Doble: ";
    doubleVector.Display();

    return 0;
}