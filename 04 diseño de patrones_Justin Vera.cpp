#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 

using namespace std;

// Función plantilla para imprimir elementos de cualquier contenedor
template <typename Container>
void PrintContainer(const Container& container, ostream& os)
{
    typename Container::const_iterator iter = container.begin();
    for (; iter != container.end(); ++iter)
    {
        os << *iter << "\n";
    }
}

// Objeto de función para incrementar un valor
class Increment
{
public:
    Increment(int value) : incrementValue(value) {}
    void operator()(int& element) const
    {
        element += incrementValue;
    }

private:
    int incrementValue;
};

int main()
{
    list<int> myList;
    vector<int> myVector;

    // Llenar los contenedores con datos
    for (int i = 0; i < 10; ++i)
    {
        myList.push_back(i);
        myVector.push_back(i + 50);
    }

    // Imprimir elementos originales de los contenedores
    cout << "Lista Original:\n";
    PrintContainer(myList, cout);

    cout << "Vector original:\n";
    PrintContainer(myVector, cout);

    // Incrementar cada elemento en la lista y el vector
    Increment incrementor(1);
    for_each(myList.begin(), myList.end(), incrementor);
    for_each(myVector.begin(), myVector.end(), incrementor);

    // Imprimir elementos después de incrementar
    cout << "Elementos antes del incremento:\n";
    PrintContainer(myList, cout);

    cout << "Elementos luego del incremento:\n";
    PrintContainer(myVector, cout);

    return 0;
}
