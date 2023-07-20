#include <iostream>

int main(int argc, char** argv)
{
	//Si el programa fue lanzado con argumentos..
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++) 
		{
			std::cout << argv[i] << "\n";
			//Toda cadena de texto termina con un /0
			int j = 0;
			int value = 0;
			std::cout << " ";
			do
			{
				value = (int)argv[i][j];
			  std::cout << argv [i][j] << " = " << value << " 0" <<std::hex << value << "\n ";
			  j++;
			} while (argv[i][j] != 0);


			std::cout << "\n";
		}
	}
	else 
	{
		std::cout << "No se dieron argumentos. Cerrando\n";
	}

    return 0;
}
