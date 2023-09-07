#include <iostream>

void PruebaArgumentos(int argc, char** argv)
{
	//Si el programa fue lanzado con argumentos..
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			std::cout << argv[i] << "\n";
			//Toda acadena de texto termina con un /0
			int j = 0;
			int value = 0;
			std::cout << " ";
 


			do
			{
				value = (int)argv[i][j];
				std::cout << argv[i][j] << " = " << value << " 0x" << std::hex << value << "\n ";
				j++;
			} while (argv[i][j] != 0);


			std::cout << "\n";

		}
	}
	else
	{
		std::cout << "No se dieron argumentos. Cerrando\n";
	}
}

void Promedio(int argc, char** argv)
{
	//ejercicio 2 de apuntadores
	int* x = new int;

	*x = 99;
	std::cout << "sizeof int " << sizeof(int) << "\n";
	std::cout << " x :" << *x << " en " << x << "\n";

	*x = 'k';
	std::cout << "sizeof int " << sizeof(int) << "\n";
	std::cout << " x :" << *x << " en " << x << "\n";

	*(x + 1) = 18;
	std::cout << " x+1 :" << *(x + 1) << " en " << x + 1 << "\n";

	//Arreglo de 100 enteros
	int* y = new int[100];
	memset(y, 0, 100 * sizeof(int));

	//Generar una lista de 100 enteros aleatorios
	int* acumulador = new int;
	int* siguiente = new int;
	float* contador = new float;
	*contador = 0;

	*acumulador = 0;
	for (int i = 0; i < 100; i++)
	{
		std::cout << "Escribe un numero que deseas: " << "\n";
		std::cin >> y[i];
		std::cout << " y[" << i << "] = " << *(y + i) << "\n";
		*contador += 1.0f;
		*acumulador += y[i];

		std::cout << "¿Quieres otro numero? Entonces presiona 12, si no presiona 21" << "\n";
		std::cin >> *siguiente;

		if (*siguiente == 12)
		{

		}
		else if (*siguiente == 21)
		{
			break;
		}
	}
	float promedio = *acumulador / *contador;
	std::cout << " promedio = " << promedio << "\n";
}

int main(int argc, char** argv)
{
	//Apuntador a funcion
	void (*proceso)(int, char**) = nullptr;

	
	std::cout << "Funciones disponibles: \n";
	std::cout << "  1. Prueba de argumentos \n";
	std::cout << "  2. Promedio: \n";
	std::cout << "Ingresa el numero de la funcion que quieres \n";

	int seleccion;
	std::cin >> seleccion;
	std::cout << seleccion << "mem: " << &seleccion << "\n";
	if (seleccion == 1)
		proceso = &PruebaArgumentos;
	else if (seleccion == 2)
		proceso = &Promedio;
	else
	{
		std::cout << "Opcion no valida\n";
		main(argc, argv);
	}

	(*proceso)(argc, argv);
	return 0;
}

//Archivo Listo...
