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
	int iteracion;
};

int addProduct(products items [], int acum); //funcion de a�adir productos.
void listProduct(products items [], int acum); //funcion de listar productos.
void modProduct(products items [], int acum); //funcion de modificar productos.
void consuProduct(products items [], int acum); //funcion de consumir productos.
void checker(); //funcion para revisar archivo de guardado.


int main() {
	checker();
	setlocale(LC_ALL, "");
	products items [9999]; //iniciamos muchos espacios en memoria
	int menuOpt = 0, acum = 0, iteracion = 0; //usamos acum para tener en cuenta cuantos objetos hay existentes.
	while(true){
		cout << "############  MEN�:  #############\n\n"; //men� provisional
		cout << "1.\t A�adir un nuevo mercado.\n";
		cout << "2.\t Listar productos existentes.\n";
		cout << "3.\t Modificar un producto.\n";
		cout << "4.\t Consumir un producto.\n\n";
		cout << "Ingrese la opci�n deseada:  ";
		cin >> menuOpt;
		switch (menuOpt){ //revisamos la entrada
			case 1:
    			system("CLS");
    			iteracion += 1;
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
				cout << "Por favor, ingresa una opci�n v�lida...";
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

int addProduct(products items[], int acum) {
    bool continuar = true;
    string nombreTemp, categoriaTemp;
    int iteracion = 0, cantidadTemp, precioTemp, diaComTemp, mesComTemp, anoComTemp, diaCadTemp, mesCadTemp, anoCadTemp, exit = 1, precioAcum = 0;
    products itemsTemp [999];
    FILE *file = fopen("database.txt", "a");
	cout << "\n#####  Has seleccionado 'A�adir nuevo mercado'  #####" << endl << endl;
	

    cout << "\nPara comenzar, indica la fecha de compra del mercado:  \n";
    cout << "---Dia: ";
	cin >> diaComTemp;
    cout << "---Mes: ";
    cin >> mesComTemp;
    cout << "---A�o: ";
    cin >> anoComTemp;
    system("CLS");
    while (exit == 1 && continuar) {
		cout << "\nProducto #" << iteracion + 1 << ":\n\n";
        cout << "\nIngresa el NOMBRE del producto:  ";
        cin >> nombreTemp;

        cout << "\nIngresa la CATEGOR�A del producto:  ";
        cin >> categoriaTemp;

        cout << "\nIngresa la CANTIDAD de productos:  ";
        cin >> cantidadTemp;

        cout << "\nIndica el PRECIO del producto:  ";
        cin >> precioTemp;

        cout << "\nIndica la FECHA DE CADUCIDAD del producto:  \n";
        cout << "---Dia: ";
        cin >> diaCadTemp;
        cout << "---Mes: ";
        cin >> mesCadTemp;
        cout << "---A�o: ";
        cin >> anoCadTemp;
        
        itemsTemp[iteracion].nombre = nombreTemp;
        itemsTemp[iteracion].categoria = categoriaTemp;
        itemsTemp[iteracion].precio = precioTemp;
        itemsTemp[iteracion].cantidad = cantidadTemp;
        itemsTemp[iteracion].diaCom = diaComTemp;
        itemsTemp[iteracion].mesCom = mesComTemp;
        itemsTemp[iteracion].anoCom = anoComTemp;
        itemsTemp[iteracion].diaCad = diaCadTemp;
        itemsTemp[iteracion].mesCad = mesCadTemp;
        itemsTemp[iteracion].anoCad = anoCadTemp;

        bool encontrado = false;
        for (int j = 0; j < acum; j++) {
            if (nombreTemp == items[j].nombre && categoriaTemp == items[j].categoria &&
                precioTemp == items[j].precio && diaComTemp == items[j].diaCom &&
                mesComTemp == items[j].mesCom && anoComTemp == items[j].anoCom &&
                diaCadTemp == items[j].diaCad && mesCadTemp == items[j].mesCad &&
                anoCadTemp == items[j].anoCad) {

                items[j].cantidad += cantidadTemp;
                precioAcum += items[j].precio;
                encontrado = true;
                
                break;
            }
        }

        if (!encontrado) {
            items[acum].nombre = nombreTemp;
            items[acum].categoria = categoriaTemp;
            items[acum].precio = precioTemp;
            items[acum].cantidad = cantidadTemp;
            items[acum].diaCom = diaComTemp;
            items[acum].mesCom = mesComTemp;
            items[acum].anoCom = anoComTemp;
            items[acum].diaCad = diaCadTemp;
            items[acum].mesCad = mesCadTemp;
            items[acum].anoCad = anoCadTemp;
            precioAcum += items[acum].precio;
            acum++;
        }

		//el fprintf siguiente se debe actualizar con los nuevos inputs.
        cout << "�Desea agregar otro producto? (1 para S�, 0 para No): ";
        cin >> exit;

        if (exit != 1) {
        	system("CLS");
            continuar = false;
            //mostrar resumen de productos a�adidos.
            cout << "Los productos recientemente a�adidos con fecha de compra " << itemsTemp[iteracion].diaCom << "/" << itemsTemp[iteracion].mesCom << "/" << itemsTemp[iteracion].anoCom << " son: \n\n";
            for (int i = 0; i <= iteracion; i++){
	            cout << "\nProducto #" << i+1 << endl;
				cout << "Nombre: " << itemsTemp[i].nombre << endl;
				cout << "Categoria: " << itemsTemp[i].categoria << endl;
				cout <<	"Precio: " << itemsTemp[i].precio << endl;
				cout << "Cantidad: " << itemsTemp[i].cantidad << endl;
				cout <<	"Fecha de caducidad: " << itemsTemp[i].diaCad << "/" << itemsTemp[i].mesCad << "/" << itemsTemp[i].anoCad << endl;
				cout << "------------------//--------------------\n\n";
			}
			cout << "\nEl valor total de los productos recientemente a�adidos es de $"<< precioAcum <<". \n\n";
			cout << "------------------//--------------------\n\n\n";
			cout << "Presione enter para volver al men� principal...";
			cin.ignore();
			cin.get();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("CLS");
        }
        else { 
        	iteracion += 1;
        	system("CLS");
		}
    }
    fclose(file);
    return acum;
}

void listProduct(products items [], int acum){
	//cout << acum;
	if(acum == 0){
		system("CLS");
		cout << "�A�n no has agregado ning�n producto!";
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
		cout << "------------------//--------------------\n\n\n";
	}
	cout << "Presione enter para volver al men� principal...";
	getch();
    system("CLS");
}

void modProduct(products items [], int acum) {
	if(acum == 0){
		system("CLS");
		cout << "�A�n no has agregado ning�n producto!";
		cout << "Presione enter para volver al men� principal...";
		getch();
		system("CLS");
		return;
	}
    string nombreBuscar;
    cout << "Ingrese el nombre del producto que desea modificar: ";
    cin >> nombreBuscar;
    bool encontrado = false;
    for (int i = 0; i < acum; i++) {
        if (nombreBuscar == items[i].nombre) {
            encontrado = true;

            cout << "\nModificar Producto\n";
            cout << "1. Nombre: " << items[i].nombre << endl;
            cout << "2. Categor�a: " << items[i].categoria << endl;
            cout << "3. Precio: " << items[i].precio << endl;
            cout << "4. Cantidad: " << items[i].cantidad << endl;
            cout << "5. Fecha de compra: " << items[i].diaCom << "/" << items[i].mesCom << "/" << items[i].anoCom << endl;
            cout << "6. Fecha de caducidad: " << items[i].diaCad << "/" << items[i].mesCad << "/" << items[i].anoCad << endl;
            cout << "0. Volver al men� principal\n";

            int opcion;
            cout << "Seleccione el n�mero de la opci�n que desea modificar: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    cout << "Nuevo nombre: ";
                    cin >> items[i].nombre;
                    break;
                case 2:
                    cout << "Nueva categor�a: ";
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
                    cout << "Nuevo d�a de compra: ";
                    cin >> items[i].diaCom;
                    cout << "Nuevo mes de compra: ";
                    cin >> items[i].mesCom;
                    cout << "Nuevo a�o de compra: ";
                    cin >> items[i].anoCom;
                    break;
                case 6:
                    cout << "Nuevo d�a de caducidad: ";
                    cin >> items[i].diaCom;
                    cout << "Nuevo mes de caducidad: ";
                    cin >> items[i].mesCom;
                    cout << "Nuevo a�o de caducidad: ";
                    cin >> items[i].anoCom;
                    break;
                case 0:
                	system("CLS");
                    break;
                default:
                    cout << "Opci�n no v�lida.";
            }
        }
    }

    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
        cout << "Presione enter para volver al men� principal...";
        getch();
		system("CLS");
    }
}

void consuProduct(products items [], int acum) {
	if(acum == 0){
		system("CLS");
		cout << "�A�n no has agregado ning�n producto!";
		cout << "Presione enter para volver al men� principal...";
		getch();
		system("CLS");
		return;
	}
    string nombreBuscar;
    cout << "Ingrese el nombre del producto que desea consumir: ";
    cin >> nombreBuscar;

    bool encontrado = false;
    FILE *file = fopen("database.txt", "r+");
    for (int i = 0; i < acum; i++) {
        if (nombreBuscar == items[i].nombre) {
            encontrado = true;
            cout << "\nInformaci�n del Producto\n";
            cout << "Nombre: " << items[i].nombre << endl;
            cout << "Categor�a: " << items[i].categoria << endl;
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
                cout << "La cantidad ingresada no es v�lida o excede la cantidad disponible.\n";
            }
            break;
        }
    }
	
    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
    }
    cout << "Presione enter para volver al men� principal...";
    getch();
    system("CLS");
}
