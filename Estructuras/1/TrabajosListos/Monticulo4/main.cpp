#include "Monticulo.h"

int main(int ac, char *av[]) {
	Heap<int> monton = Heap<int>();

	std::cout << "monton.Agregar(45)\n";
	monton.Agregar(45);
	std::cout << "monton.Agregar(20)\n";
  monton.Agregar(20);
	std::cout << "monton.Agregar(14)\n";
  monton.Agregar(14);
	std::cout << "monton.Agregar(12)\n";
  monton.Agregar(12);
	std::cout << "monton.Agregar(31)\n";
  monton.Agregar(31);
	std::cout << "monton.Agregar(7)\n";
  monton.Agregar(7);
	std::cout << "monton.Agregar(11)\n";
  monton.Agregar(11);
	std::cout << "monton.Agregar(13)\n";
  monton.Agregar(13);
	std::cout << "monton.Imprimir()\n";
	monton.Imprimir();
	monton.ImprimirLista();

	std::cout << "monton.EstaVacio(): " << monton.EstaVacio() << "\n";
	std::cout << "monton.ObtenerCapacidad(): " << monton.ObtenerCapacidad() << "\n";
	std::cout << "monton.ObtenerNumeroElementos(): " << monton.ObtenerNumeroElementos() << "\n";
	std::cout << "monton.ObtenerRaiz(): " << monton.ObtenerRaiz() << "\n";

	std::cout << "monton_copia = Heap<int>(monton)\n";
	Heap<int> monton_copia = Heap<int>(monton);

	std::cout << "monton_copia.EliminarRaiz():\n";
	monton_copia.EliminarRaiz();
	std::cout << "monton_copia.EliminarRaiz():\n";
	monton_copia.EliminarRaiz();
	std::cout << "monton_copia.EliminarRaiz():\n";
	monton_copia.EliminarRaiz();
	std::cout << "monton_copia.Imprimir():\n";
	monton_copia.Imprimir();
	monton_copia.ImprimirLista();

	std::cout << "monton_copia.EstaVacio(): " << monton_copia.EstaVacio() << "\n";
	std::cout << "monton_copia.ObtenerCapacidad(): " << monton_copia.ObtenerCapacidad() << "\n";
	std::cout << "monton_copia.ObtenerNumeroElementos(): " << monton_copia.ObtenerNumeroElementos() << "\n";
	std::cout << "monton_copia.ObtenerRaiz(): " << monton_copia.ObtenerRaiz() << "\n";

	Heap<int> monton_igual;
	std::cout << "monton_igual = monton_copia\n";
	monton_igual = monton_copia;

	std::cout << "monton_igual.EstaVacio(): " << monton_igual.EstaVacio() << "\n";
	std::cout << "monton_igual.Vaciar():\n";
	monton_igual.Vaciar();
	std::cout << "monton_igual.EstaVacio(): " << monton_igual.EstaVacio() << "\n";

	try
	{
		std::cout << "provocando excepcion: monton_igual.ObtenerRaiz()\n";
		monton_igual.ObtenerRaiz();
	}
	catch(const Heap<int>::ExcepcionHeapVacio& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
