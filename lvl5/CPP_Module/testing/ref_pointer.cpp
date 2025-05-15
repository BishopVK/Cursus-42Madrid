#include <iostream>

void modificar_puntero(int* p)
{
	int local = 100;
	p = &local;  // Solo modifica la copia local del puntero
}

void modificar_puntero_ref(int*& p)
{
	int local = 200;
	p = &local;  // Modifica el puntero original
}

int main()
{
	int valor = 10;
	int* ptr = &valor;

	modificar_puntero(ptr);
	std::cout << "*ptr tras modificar_puntero: " << *ptr << std::endl; // Sigue siendo 10

	modificar_puntero_ref(ptr);
	std::cout << "*ptr tras modificar_puntero_ref: " << *ptr << std::endl; // ¡Comportamiento indefinido!

	return 0;
}