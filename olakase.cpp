#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <string>
#include <cctype>
#include <conio.h>
#include <cstdio>


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
void checker(); //funcion para revisar archivo de guardado


int main() {
	checker();
	setlocale(LC_ALL, "");
	products items [9999]; //iniciamos muchos espacios en memoria
	int menuOpt = 0, acum = 0; //usamos acum para tener en cuenta cuantos preguntos hay existentes.
	while(true){
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
			default:
				cout << "Por favor, ingresa una opción válida...";
				getch();
				system("CLS");
				break;
		}
	}
	return 0;
}


void checker() {
    FILE *file = fopen("database.txt", "w");
    if (file == NULL) {
        FILE *newFile = fopen("database.txt", "w");
        if (newFile != NULL) {
            fclose(newFile);
        } else {
            cerr << "Error al crear el archivo 'database.txt'.\n";
        }
	}
}

void addProduct(products items [], int acum) {
    int exit = 1;
    FILE *file = fopen("database.txt", "a");
    if (file == NULL) {
        cerr << "Error abriendo la base de datos." << endl;
        return;
    }
    for (int i = acum; exit == 1; i++) {
        cout << "Ingresa el nombre del producto:  ";
        cin >> items[i].nombre;
        cout << "\nIngresa la categoría del producto:  ";
        cin >> items[i].categoria;
        cout << "\nIngresa la cantidad de productos:  ";
        cin >> items[i].cantidad;
        cout << "\nIndica el precio del producto:  ";
        cin >> items[i].precio;
        fprintf(file, "%s %s %d %d\n", items[i].nombre.c_str(), items[i].categoria.c_str(), items[i].cantidad, items[i].precio);
        cout << "¿Desea agregar otro producto? (1 para Sí, 0 para No): ";
        cin >> exit;
    }
    fclose(file);
    acum++;
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
