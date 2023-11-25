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
void modProduct(products items [], int acum); //funcion de modificar productos.
void consuProduct(products items [], int acum); //funcion de consumir productos.
void checker(); //funcion para revisar archivo de guardado.


int main() {
	checker();
	setlocale(LC_ALL, "");
	products items [9999]; //iniciamos muchos espacios en memoria
	int menuOpt = 0, acum = 0; //usamos acum para tener en cuenta cuantos objetos hay existentes.
	while(true){
		cout << "############  MENÚ:  #############\n\n"; //menú provisional
		cout << "1.\t Añadir un nuevo mercado.\n";
		cout << "2.\t Listar productos existentes.\n";
		cout << "3.\t Modificar un producto.\n";
		cout << "4.\t Consumir un producto.\n\n";
		cout << "Ingrese la opción deseada:  ";
		cin >> menuOpt;
		switch (menuOpt){ //revisamos la entrada
			case 1:
    			system("CLS");
				acum = addProduct(items, acum);
				break;
			case 2:
    			system("CLS");
				listProduct(items, acum);
				break;
			case 3:
    			system("CLS");
				modProduct(items, acum);
				break;
			case 4:
    			system("CLS");
				consuProduct(items, acum);
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
    FILE *file = fopen("database.txt", "a");
    if (file == NULL) {
        FILE *newFile = fopen("database.txt", "a");
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
	//cout << acum;
	if(acum == 0){
		system("CLS");
		cout << "¡Aún no has agregado ningún producto!";
		getch();
		system("CLS");
		return;
	}
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
	getch();
    system("CLS");
}

void modProduct(products items [], int acum) {
    string nombreBuscar;
    cout << "Ingrese el nombre del producto que desea modificar: ";
    cin >> nombreBuscar;
    bool encontrado = false;
    for (int i = 0; i < acum; i++) {
        if (nombreBuscar == items[i].nombre) {
            encontrado = true;

            cout << "\nModificar Producto\n";
            cout << "1. Nombre: " << items[i].nombre << endl;
            cout << "2. Categoría: " << items[i].categoria << endl;
            cout << "3. Precio: " << items[i].precio << endl;
            cout << "4. Cantidad: " << items[i].cantidad << endl;
            cout << "5. Fecha de compra: " << items[i].diaCom << "/" << items[i].mesCom << "/" << items[i].anoCom << endl;
            cout << "6. Fecha de caducidad: " << items[i].diaCad << "/" << items[i].mesCad << "/" << items[i].anoCad << endl;
            cout << "0. Volver al menú principal\n";

            int opcion;
            cout << "Seleccione el número de la opción que desea modificar: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    cout << "Nuevo nombre: ";
                    cin >> items[i].nombre;
                    break;
                case 2:
                    cout << "Nueva categoría: ";
                    cin >> items[i].categoria;
                    break;
                case 3:
                    cout << "Nuevo precio: ";
                    cin >> items[i].precio;
                    break;
                case 4:
                    cout << "Nueva cantidad: ";
                    cin >> items[i].cantidad;
                    break;
                case 5:
                    cout << "Nueva fecha de compra (DD MM YYYY): ";
                    cin >> items[i].diaCom >> items[i].mesCom >> items[i].anoCom;
                    break;
                case 6:
                    cout << "Nueva fecha de caducidad (DD MM YYYY): ";
                    cin >> items[i].diaCad >> items[i].mesCad >> items[i].anoCad;
                    break;
                case 0:
                	system("CLS");
                    break;
                default:
                    cout << "Opción no válida.";
            }
        }
    }

    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
        getch();
		system("CLS");
    }
}

void consuProduct(products items [], int acum) {
    string nombreBuscar;
    cout << "Ingrese el nombre del producto que desea consumir: ";
    cin >> nombreBuscar;

    bool encontrado = false;
    FILE *file = fopen("database.txt", "r+");
    for (int i = 0; i < acum; i++) {
        if (nombreBuscar == items[i].nombre) {
            encontrado = true;
            cout << "\nInformación del Producto\n";
            cout << "Nombre: " << items[i].nombre << endl;
            cout << "Categoría: " << items[i].categoria << endl;
            cout << "Precio: " << items[i].precio << endl;
            cout << "Cantidad disponible: " << items[i].cantidad << endl;

            int cantidadConsumir;
            cout << "Ingrese la cantidad que desea consumir: ";
            cin >> cantidadConsumir;

            if (cantidadConsumir > 0 && cantidadConsumir <= items[i].cantidad) {
                items[i].cantidad -= cantidadConsumir;
				fprintf(file, "%s %s %d %d %d %d %d %d %d %d\n", items[i].nombre.c_str(), items[i].categoria.c_str(), items[i].cantidad, items[i].precio,
                items[i].diaCom, items[i].mesCom, items[i].anoCom, items[i].diaCad, items[i].mesCad, items[i].anoCad);
                cout << "Producto consumido exitosamente.\n";
            } else {
                cout << "La cantidad ingresada no es válida o excede la cantidad disponible.\n";
            }
            break;
        }
    }
	
    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
    }
    getch();
    system("CLS");
}
