#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <string>
#include <cctype>

using namespace std;
struct products { //Creamos la estructura de los productos que vamos a ingresar.
	string nombre;
	string categoria;
	int cantidad;
	int precio;
	int diaCom; //Fecha de compra.
	int mesCom;
	int anoCom;
	int diaCad; //Fecha de caducidad.
	int mesCad;
	int anoCad;
};

void addProduct(products items [], int acum); //funcion de añadir productos.
void listProduct(); //funcion de listar productos.
void modProduct(); //funcion de modificar productos.
void consuProduct(); //funcion de consumir productos.

int main() {
	setlocale(LC_ALL, "spanish");
	products items [9999]; //iniciamos muchos espacios en memoria
	int menuOpt, acum = 0; //usamos acum para tener en cuenta cuantos preguntos hay existentes.
	cout << "MENÚ:\n\n"; //menú provisional
	cout << "\t1. Añadir un producto.\n";
	cout << "\t2. Listar productos existentes.\n";
	cout << "\t3. Modificar un producto.\n";
	cout << "\t4. Consumir un producto.\n\n";
	cout << "Ingrese la opción deseada:  ";
	cin >> menuOpt;
	
	switch (menuOpt){ //revisamos la entrada
		case 1:
			addProduct(items, acum);
			break;
		case 2:
			listProduct();
			break;
		case 3:
			modProduct();
			break;
		case 4:
			consuProduct();
			break;
	}
	return 0;
}

void addProduct(products items [], int acum){
	int exit = 1;
	for (int i = acum; exit == 1; i++){
		cout << "Ingresa el nombre del producto:  ";
		cin >> items[i].nombre;
		cout << "\nIngresa la categoría del producto:  ";
		cin >> items[i].categoria;
		cout << "\nIngresa la cantidad de productos:  ";
		cin >> items[i].cantidad;
		cout << "\nIndica el precio del producto:  ";
		cin >> items[i].precio;
		cin >> exit;
	}
	
}

void listProduct(){
	cout << "Hola mundo";
}

void modProduct(){
	cout << "Hola mundo";
}

void consuProduct(){
	cout << "Hola mundo";
}
	
