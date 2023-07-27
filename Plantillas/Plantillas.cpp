// Plantillas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#include <fstream>



//clase plantilla para guardar datos 
template <typename T> 
class DataHelper

{
	T data; 

public: 
	DataHelper(T newdata)
	{
		data = newdata;
	}
	void print()
	{
		std::cout << data << "\n";
	}
	 
	//imprime al archivo dado por la ruta 
	void printtoFile(const char* filename, bool binary = false)
	{
		if (!binary)
		{
			std::fstream myfile(filename);
			if (myfile.is_open())
			{
				myfile << sizeof(T) << data;
				myfile.close();

			}
			else
			{
				std::cout << "no se puede abrir el archivo" << "\n";
			}
		}
		else
		{
			std::fstream myfile(filename, std::ios_base::out | std::ios_base::binary);
			if (myfile.is_open())
			{
				myfile << sizeof(T) << data;
				myfile.close();

			}
		}
	}
	
};

int main()
{
	std::cout << "Tamanos\n"; 
	std::cout << "int : " << sizeof(int) << "\n";
	std::cout << "float : " << sizeof(float) << "\n";
	std::cout << "double : " << sizeof(double) << "\n";
	std::cout << "char : " << sizeof(char) << "\n";
	std::cout << "string : " << sizeof(std::string) << "\n";

	DataHelper<char>* mychar = new DataHelper<char>(117);
	DataHelper<float>* myfloat = new DataHelper<float>(3.14159);

	DataHelper<char* >* mychars = new DataHelper<char* >((char*)"hola mundo"); 

	mychar->print(); 
	myfloat->print();
	mychars->print();

	myfloat->printtoFile("float.txt");
	myfloat->printtoFile("float.bin", true);

	//abri archivo 
	std::fstream archivo("cripper.bmp", std::ios_base::in);
	if (archivo.is_open())
	{
		int* buffer = new int[8];
		//mientras no termine el archivo, imprimir en bloques de 8 bytes
		while (!archivo.eof())
		{
			archivo.read( (char*)buffer, 8);
			std::cout << std::hex << buffer << "\n";
		}
		
	}


}