#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <string>
#include <cctype>
#include <conio.h>
#include <cstdio>
#include <sstream>
#include <limits>


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

int addProduct(products items [], int acum); //funcion de añadir productos.
void listProduct(products items [], int acum); //funcion de listar productos.
void modProduct(); //funcion de modificar productos.
void consuProduct(); //funcion de consumir productos.
void checker(); //funcion para revisar archivo de guardado.


int main() {
	checker();
	setlocale(LC_ALL, "");
	products items [9999]; //iniciamos muchos espacios en memoria
	int menuOpt = 0, acum = 0; //usamos acum para tener en cuenta cuantos objetos hay existentes.
	while(true){
		cout << "MENÚ:\n\n"; //menú provisional
		cout << "\t1. Añadir un nuevo mercado.\n";
		cout << "\t2. Listar productos existentes.\n";
		cout << "\t3. Modificar un producto.\n";
		cout << "\t4. Consumir un producto.\n\n";
		cout << "Ingrese la opción deseada:  ";
		cin >> menuOpt;
		switch (menuOpt){ //revisamos la entrada
			case 1:
				acum = addProduct(items, acum);
				break;
			case 2:
				listProduct(items, acum);
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

int addProduct(products items [], int acum) {
    int exit = 1, cantidadTemp, precioTemp, diaComTemp, mesComTemp, anoComTemp, diaCadTemp, mesCadTemp, anoCadTemp;
    string varFecha, nombreTemp, categoriaTemp;
    FILE *file = fopen("database.txt", "a");
    for (int i = acum; exit == 1; i++) {
        cout << "Ingresa el nombre del producto:  ";
        cin >> nombreTemp;
        
        cout << "\nIngresa la categoría del producto:  ";
        cin >> categoriaTemp;
        
        cout << "\nIngresa la cantidad de productos:  ";
        cin >> cantidadTemp;
        
        cout << "\nIndica el precio del producto:  ";
        cin >> precioTemp;
        cin.ignore();
        
        cout << "\nIndica la fecha de compra del producto:  \n";
        cout << "Dia: ";
        cin >> diaComTemp;
        cout << "Mes: ";
        cin >> mesComTemp;
        cout << "Año: ";
        cin >> anoComTemp;
        
        cout << "\nIndica la fecha de caducidad del producto:  \n";
        cout << "Dia: ";
        cin >> diaCadTemp;
        cout << "Mes: ";
        cin >> mesCadTemp;
        cout << "Año: ";
        cin >> anoCadTemp;
        
        bool encontrado = false;
        for (int j = 0; j < i; j++){
        	if (nombreTemp == items[j].nombre && categoriaTemp == items[j].categoria && precioTemp == items[j].precio && diaComTemp == items[j].diaCom &&
			mesComTemp == items[j].mesCom && anoComTemp == items[j].anoCom && diaCadTemp == items[j].diaCad && mesCadTemp == items[j].mesCad && anoCadTemp == items[j].anoCad){
				items[j].cantidad += cantidadTemp;
				encontrado = true;
				break;
			}
		}
		if (!encontrado){
			items[i].nombre = nombreTemp;
			items[i].categoria = categoriaTemp;
			items[i].precio = precioTemp;
			items[i].cantidad = cantidadTemp;
			items[i].diaCom = diaComTemp;
			items[i].mesCom = mesComTemp;	
			items[i].anoCom = anoComTemp;
			items[i].diaCad = diaCadTemp;
			items[i].mesCad = mesCadTemp;
			items[i].anoCad = anoCadTemp;
			acum++;
		}
		
		//el fprintf siguiente se debe actualizar con los nuevos inputs.
		fprintf(file, "%s %s %d %d\n", items[i].nombre.c_str(), items[i].categoria.c_str(), items[i].cantidad, items[i].precio);
		
		cout << "¿Desea agregar otro producto? (1 para Sí, 0 para No): ";
        cin >> exit;
    }
    fclose(file);
    return acum;
}

void listProduct(products items [], int acum){
	cout << acum;
	for (int i = 0; i < acum; i++){
		cout << "\nProducto #" << i+1 << endl;
		cout << "Nombre: " << items[i].nombre << endl;
		cout << "Categoria: " << items[i].categoria << endl;
		cout <<	"Precio: " << items[i].precio << endl;
		cout << "Cantidad: " << items[i].cantidad << endl;
		cout <<	"Fecha de compra: " << items[i].diaCom << "/" << items[i].mesCom << "/" << items[i].anoCom << endl;
		cout <<	"Fecha de caducidad: " << items[i].diaCad << "/" << items[i].mesCad << "/" << items[i].anoCad << endl;
		cout << "------------------//--------------------\n\n";
	}
}

void modProduct(){
	cout << "Hola mundo";
}

void consuProduct(){
	cout << "Hola mundo";
}
