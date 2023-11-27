#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <string>
#include <cctype>
#include <conio.h>
#include <cstdio>
#include <sstream>
#include <limits>
#include <ctime>

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
int consuProduct(products items [], int acum); //funcion de consumir productos.
void checker(); //funcion para revisar archivo de guardado.
bool checkCaducidad(int anoCad, int mesCad, int diaCad); //funcion para revisar si un producto caduc�.

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
				acum = consuProduct(items, acum);
				break;
			default:
				cout << "Por favor, ingresa una opci�n v�lida...";
				getch();
				system("CLS");
				cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
		}
	}
	return 0;
}

//	string nombre, string categoria, int cantidad, int precio, 
//	int diaCom, int mesCom, int anoCom, int diaCad, int mesCad, 
//	int anoCad, int iteracion, global int acum
/*
void saver(Product items [], int acum) {
	string savedText;
    FILE* file = fopen("database.txt", "w");

    if (file == nullptr) {
        std::cerr << "Error al abrir el archivo database.txt para escritura.\n";
        return;
    }
    fprintf(file, "%d\n", acum);
    for (int i = 0; i < acum; i++) {
        fprintf(file, "%s %s %d %d %d %d %d %d %d %d\n", items[i].nombre.c_str(), items[i].categoria.c_str(),
                items[i].cantidad, items[i].precio, items[i].diaCom, items[i].mesCom, items[i].anoCom,
                items[i].diaCad, items[i].mesCad, items[i].anoCad);
    }

    fclose(file);
}
*/
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
    string answerTemp;
	products itemsTemp [999];
    FILE *file = fopen("database.txt", "a");
	cout << "\n#####  Has seleccionado 'A�adir nuevo mercado'  #####" << endl << endl;
    cout << "\nPara comenzar, indica la fecha de compra del mercado:  \n";
    while(true){
       	cout << "---Dia: ";
       	if(!(cin >> diaComTemp) || (cin.peek() != '\n') || diaComTemp < 1 || diaComTemp > 31){
       		cout << "Has ingresado una cantidad inv�lida... Por favor, intenta nuevamente.";
       		cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
       		getch();
       		system("CLS");
		}else{
			break;
		}
    }
    while(true){
       	cout << "---Mes: ";
       	if(!(cin >> mesComTemp) || (cin.peek() != '\n') || mesComTemp < 1 || mesComTemp > 12){
       		cout << "Has ingresado una cantidad inv�lida... Por favor, intenta nuevamente.";
       		cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
       		getch();
       		system("CLS");
		}else{
			break;
		}
    }
       while(true){
       	cout << "---A�o: ";
       	if(!(cin >> anoComTemp) || (cin.peek() != '\n') || anoComTemp < 1){
       		cout << "Has ingresado una cantidad inv�lida... Por favor, intenta nuevamente.";
       		cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
       		getch();
       		system("CLS");
		}else{
			break;
		}
    }
    system("CLS");
    while (exit == 1 && continuar) {
		cout << "\nProducto #" << iteracion + 1 << ":\n\n";
        cout << "\nIngresa el NOMBRE del producto:  ";
        cin >> nombreTemp;
        for (size_t i = 0; i < nombreTemp.length(); ++i) { //pasamos el nombre a min�scula para prevenir errores.
        	nombreTemp[i] = tolower(nombreTemp[i]);
    	}
        cout << "\nIngresa la CATEGOR�A del producto:  ";
        cin >> categoriaTemp;
        for (size_t i = 0; i < categoriaTemp.length(); ++i) { //pasamos el nombre a min�scula para prevenir errores.
        	categoriaTemp[i] = tolower(categoriaTemp[i]);
    	}
        while(true){
        	cout << "\nIngresa la CANTIDAD de productos:  ";
        	if(!(cin >> cantidadTemp) || (cin.peek() != '\n') || cantidadTemp < 1){
        		cout << "Has ingresado una cantidad inv�lida... Por favor, intenta nuevamente.";
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		getch();
        		system("CLS");
			}else{
				break;
			}
        }
        while(true){
	        cout << "\nIndica el PRECIO del producto:  $";
	        if(!(cin >> precioTemp) || (cin.peek() != '\n') || precioTemp < 1){
        		cout << "Has ingresado una cantidad inv�lida... Por favor, intenta nuevamente.";
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		getch();
        		system("CLS");
			}else{
				break;
			}
	    }
        cout << "\nIndica la FECHA DE CADUCIDAD del producto:  \n";
        while(true){
        	cout << "---Dia: ";
        	if(!(cin >> diaCadTemp) || (cin.peek() != '\n') || diaCadTemp < 1 || diaCadTemp > 31){
        		cout << "Has ingresado una cantidad inv�lida... Por favor, intenta nuevamente.";
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		getch();
        		system("CLS");
			}else{
				break;
			}
    	}
    	while(true){
        	cout << "---Mes: ";
        	if(!(cin >> mesCadTemp) || (cin.peek() != '\n') || mesCadTemp < 1 || mesCadTemp > 12){
        		cout << "Has ingresado una cantidad inv�lida... Por favor, intenta nuevamente.";
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		getch();
        		system("CLS");
			}else{
				break;
			}
    	}
        while(true){
        	cout << "---A�o: ";
        	if(!(cin >> anoCadTemp) || (cin.peek() != '\n') || anoCadTemp < 1){
        		cout << "Has ingresado una cantidad inv�lida... Por favor, intenta nuevamente.";
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		getch();
        		system("CLS");
			}else{
				break;
			}
    	}
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
                precioAcum += items[j].precio * items[j].cantidad;
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
            precioAcum += items[acum].precio * items[acum].cantidad;
            acum++;
        }

		//el fprintf siguiente se debe actualizar con los nuevos inputs.
        cout << "�Desea agregar otro producto? (1 para Si, 0 para no): ";
        if (!(cin >> exit) || (cin.peek() != '\n') || exit != 1) {
        	system("CLS");
            continuar = false;
            //mostrar resumen de productos a�adidos.
            cout << "Los productos recientemente a�adidos con fecha de compra " << itemsTemp[iteracion].diaCom << "/" << itemsTemp[iteracion].mesCom << "/" << itemsTemp[iteracion].anoCom << " son: \n\n";
            for (int i = 0; i <= iteracion; i++){
	            cout << "\n\t ** Producto #" << i+1 << endl;
				cout << "Nombre: " << itemsTemp[i].nombre << endl;
				cout << "Categor�a: " << itemsTemp[i].categoria << endl;
				cout <<	"Precio: " << itemsTemp[i].precio << endl;
				cout << "Cantidad: " << itemsTemp[i].cantidad << endl;
				cout <<	"Fecha de caducidad: " << itemsTemp[i].diaCad << "/" << itemsTemp[i].mesCad << "/" << itemsTemp[i].anoCad << endl;
				cout << "------------------//--------------------\n\n";
			}
			cout << "\nEl valor total de los productos recientemente a�adidos es de $"<< precioAcum <<". \n\n";
			cout << "------------------//--------------------\n\n\n";
			cout << "Presione enter para volver al men� principal...";
			cin.ignore();
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

bool checkCaducidad(int anoCad, int mesCad, int diaCad) {
    time_t t = time(0);
    struct tm* now = localtime(&t);

    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;				// cuadramos la fecha actual

    if (anoCad < currentYear ||
        (anoCad == currentYear && mesCad < currentMonth) ||
        (anoCad == currentYear && mesCad == currentMonth && diaCad < currentDay)) { // no caducado
        return false;
    } else {
        return true;																// caducado
    }
}

void listProduct(products items [], int acum){
	//cout << acum;
	string val;
	char opcion;
	cout << "\n1. Consultar todos los productos existentes.\n";
    cout << "2. Consultar productos por fecha de vencimiento. \n";
    cout << "0. Volver al men� principal.\n\n";
	int diaTemp, mesTemp, anoTemp;
    cout << "Seleccione una opci�n:  ";
    cin >> opcion;
	    if (opcion == '1'){
			if(acum == 0){
				system("CLS");
				cout << "�A�n no has ingresado ning�n producto!";
				getch();
				system("CLS");
				return;
			}
			for (int i = 0; i < acum; i++){
				if (checkCaducidad(items[i].anoCad, items[i].mesCad, items[i].diaCad)){
					val = "Producto APTO para consumo.";
				}else{
					val = "Producto NO APTO para consumo.";
				}
				cout << "\n\t ** Producto #" << i+1 << endl;
				cout << "Nombre: " << items[i].nombre << endl;
				cout << "Categor�a: " << items[i].categoria << endl;
				cout <<	"Precio: " << items[i].precio << endl;
				cout << "Cantidad: " << items[i].cantidad << endl;
				cout <<	"Fecha de compra: " << items[i].diaCom << "/" << items[i].mesCom << "/" << items[i].anoCom << endl;
				cout <<	"Fecha de caducidad: " << items[i].diaCad << "/" << items[i].mesCad << "/" << items[i].anoCad << endl;
				cout << "Apto para consumo: " << val << endl;
				cout << "------------------//--------------------\n\n\n";
			}
			cout << "Presione enter para volver al men� principal...";
			getch();
		    system("CLS");
		}
		else if (opcion == '2'){
			if(acum == 0){
				system("CLS");
				cout << "�A�n no has ingresado ning�n producto!";
				getch();
				system("CLS");
				return;
			}
			system("CLS");
			cout << "\nPor favor ingrese la fecha de caducidad que desea buscar:  \n";
			while(true){
        	cout << "---Dia: ";
        	if(!(cin >> diaTemp) || (cin.peek() != '\n') || diaTemp < 1 || diaTemp > 31){
        		cout << "Has ingresado una cantidad inv�lida... Por favor, intenta nuevamente.";
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		getch();
        		system("CLS");
			}else{
				break;
			}
	    	}
	    	while(true){
	        	cout << "---Mes: ";
	        	if(!(cin >> mesTemp) || (cin.peek() != '\n') || mesTemp < 1 || mesTemp > 12){
	        		cout << "Has ingresado una cantidad inv�lida... Por favor, intenta nuevamente.";
	        		cin.clear();
	        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        		getch();
	        		system("CLS");
				}else{
					break;
				}
	    	}
	        while(true){
	        	cout << "---A�o: ";
	        	if(!(cin >> anoTemp) || (cin.peek() != '\n') || anoTemp < 1){
	        		cout << "Has ingresado una cantidad inv�lida... Por favor, intenta nuevamente.";
	        		cin.clear();
	        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        		getch();
	        		system("CLS");
				}else{
					break;
				}
	    	}
			system("CLS");
			for (int i = 0; i < acum; i++){
				if (diaTemp == items[i].diaCad && mesTemp == items[i].mesCad && anoTemp == items[i].anoCad){
					if (checkCaducidad(items[i].anoCad, items[i].mesCad, items[i].diaCad)){
						val = "Producto APTO para consumo.";
					}
					else{
						val = "Producto NO APTO para consumo.";
					}
					cout << "\n\t ** Producto #" << i+1 << endl;
					cout << "Nombre: " << items[i].nombre << endl;
					cout << "Categoria: " << items[i].categoria << endl;
					cout <<	"Precio: " << items[i].precio << endl;
					cout << "Cantidad: " << items[i].cantidad << endl;
					cout <<	"Fecha de compra: " << items[i].diaCom << "/" << items[i].mesCom << "/" << items[i].anoCom << endl;
					cout <<	"Fecha de caducidad: " << items[i].diaCad << "/" << items[i].mesCad << "/" << items[i].anoCad << endl;
					cout << "Apto para consumo: " << val << endl;
					cout << "------------------//--------------------\n\n\n";
				}
			}
		}
		cout << "Has ingresado una cantidad inv�lida...\n";
		cout << "Presione enter para volver al men� principal...";
		getch();
		system("CLS");	
}
	

void modProduct(products items [], int acum) {
	if(acum == 0){
		system("CLS");
		cout << "�A�n no has ingresado ning�n producto!";
		cout << "Presione enter para volver al men� principal...";
		getch();
		system("CLS");
		return;
	}
    string nombreBuscar;
    cout << "Ingrese el nombre del producto que desea modificar: ";
    cin >> nombreBuscar;
    for (size_t i = 0; i < nombreBuscar.length(); ++i) { //pasamos el nombre a minuscula para prevenir errores.
        nombreBuscar[i] = tolower(nombreBuscar[i]);
   	}
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
                    for (size_t j = 0; j < items[i].nombre.length(); ++j) { //pasamos el nombre a minuscula para prevenir errores.
        				items[i].nombre[j] = tolower(items[i].nombre[j]);
   					}
                    system("CLS");
                    cout << "�Producto modificado con �xito!" << endl;
                    break;
                case 2:
                    cout << "Nueva categor�a: ";
                    cin >> items[i].categoria;
                    for (size_t j = 0; j < items[i].categoria.length(); ++j) { //pasamos el nombre a minuscula para prevenir errores.
        				items[i].categoria[j] = tolower(items[i].categoria[j]);
   					}
                    system("CLS");
                    cout << "�Producto modificado con �xito!" << endl;
                    break;
                case 3:
                	while(true){
	                    cout << "Nuevo precio: ";
	                    if(!(cin >> items[i].precio) || (cin.peek() != '\n') || items[i].precio < 1){
                    		cout << "Has ingresado un valor inv�lido... Intenta de nuevo.";
                    		cin.clear();
        					cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    		getch();
                    		system("CLS");
						}else{
							break;
						}
	                }
                    system("CLS");
                    cout << "�Producto modificado con �xito!" << endl;
                    break;
                case 4:
                	while(true){
	                    cout << "Nueva cantidad: ";
	                    if(!(cin >> items[i].cantidad) || (cin.peek() != '\n') || items[i].cantidad < 1){
                    		cout << "Has ingresado un valor inv�lido... Intenta de nuevo.";
                    		cin.clear();
        					cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    		getch();
                    		system("CLS");
						}else{
							break;
						}
	                }
                    system("CLS");
                    cout << "�Producto modificado con �xito!" << endl;
                    break;
                case 5:
                    cout << "Nuevo d�a de compra: ";
                    while(true){
	                    if(!(cin >> items[i].diaCom) || (cin.peek() != '\n') || items[i].diaCom > 31 || items[i].diaCom < 1){
	                    	cout << "Esta fecha no es v�lida... Intenta nuevamente.";
	                    	cin.clear();
        					cin.ignore(numeric_limits<streamsize>::max(), '\n');
	                    	getch();
	                    	system("CLS");
						}else{
							break;
						}
					}
					while(true){
                    	cout << "Nuevo mes de compra: ";
                    	if(!(cin >> items[i].mesCom) || (cin.peek() != '\n') || items[i].mesCom > 12 || items[i].mesCom < 1){
                    		cout << "Esta fecha no es v�lida... Intenta nuevamente.";
                    		cin.clear();
        					cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    		getch();
                    		system("CLS");
						}else{
							break;
						}	
					}
					while(true){
	                    cout << "Nuevo a�o de compra: ";
	                    if(!(cin >> items[i].anoCom) || (cin.peek() != '\n') || items[i].anoCom < 1){
	                    	cout << "Esta fecha no es v�lida... Intenta nuevamente.";
	                    	cin.clear();
        					cin.ignore(numeric_limits<streamsize>::max(), '\n');
	                    	getch();
	                    	system("CLS");
						}else{
							break;
						}
					}
	                system("CLS");
	                cout << "�Producto modificado con �xito!" << endl;
	                break;
                case 6:
                	while(true){
                    	cout << "Nuevo d�a de caducidad: ";
                    	if(!(cin >> items[i].diaCad) || (cin.peek() != '\n') || items[i].diaCad > 31 || items[i].diaCad < 1){
                    		cout << "Esta fecha no es v�lida... Intenta nuevamente.";
                    		cin.clear();
        					cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    		getch();
                    		system("CLS");
						}else{
							break;
						}
                	}
                	while(true){
                    	cout << "Nuevo mes de caducidad: ";
                    	if(!(cin >> items[i].mesCad) || (cin.peek() != '\n') || items[i].mesCad > 12 || items[i].mesCad < 1){
                    		cout << "Esta fecha no es v�lida... Intenta nuevamente.";
                    		cin.clear();
        					cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    		getch();
                    		system("CLS");
						}else{
							break;
						}
                    }
                    while(true){
	                    cout << "Nuevo a�o de caducidad: ";
	                    if(!(cin >> items[i].anoCad) || (cin.peek() != '\n') || items[i].anoCad < 1){
                    		cout << "Esta fecha no es v�lida... Intenta nuevamente.";
                    		cin.clear();
        					cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    		getch();
                    		system("CLS");
						}else{
							break;
						}
	                }
                    system("CLS");
                    cout << "�Producto modificado con �xito!" << endl;
                    break;
                case 0:
                	system("CLS");
                    break;
                default:
                    cout << "Opci�n no v�lida.";
                    cin.clear();
        			cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
    }
    cout << "Presione enter para volver al men� principal...";
    getch();
	system("CLS");
}

int consuProduct(products items [], int acum) {
	if(acum == 0){
		system("CLS");
		cout << "�A�n no has ingresado ning�n producto!";
		cout << "Presione enter para volver al men� principal...";
		getch();
		system("CLS");
		return acum;
	}
    string nombreBuscar;
    cout << "Ingrese el nombre del producto que desea consumir: ";
    cin >> nombreBuscar;
    for (size_t i = 0; i < nombreBuscar.length(); ++i) { //pasamos el nombre a minuscula para prevenir errores.
        	nombreBuscar[i] = tolower(nombreBuscar[i]);
    }

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
            if (cin >> cantidadConsumir && cantidadConsumir > 0 && cantidadConsumir <= items[i].cantidad) {
                items[i].cantidad -= cantidadConsumir;
            	for(int j = i; j < acum - 1; j++) {
			        items[j].nombre = items[j + 1].nombre;
			        items[j].categoria = items[j + 1].categoria;
			        items[j].cantidad = items[j + 1].cantidad;
			        items[j].precio = items[j + 1].precio;
			        items[j].diaCom = items[j + 1].diaCom;
			        items[j].mesCom = items[j + 1].mesCom;
			        items[j].anoCom = items[j + 1].anoCom;
			        items[j].diaCad = items[j + 1].diaCad;
			        items[j].mesCad = items[j + 1].mesCad;
			        items[j].anoCad = items[j + 1].anoCad;
				}
				--acum;
				items[acum].nombre = "";
				items[acum].categoria = "";
				items[acum].cantidad = 0;
				items[acum].precio = 0;
				items[acum].diaCom = 0;
				items[acum].mesCom = 0;
				items[acum].anoCom = 0;
				items[acum].diaCad = 0;
				items[acum].mesCad = 0;
				items[acum].anoCad = 0;
				//fprintf(file, "%s %s %d %d %d %d %d %d %d %d\n", items[i].nombre.c_str(), items[i].categoria.c_str(), items[i].cantidad, items[i].precio,
                //items[i].diaCom, items[i].mesCom, items[i].anoCom, items[i].diaCad, items[i].mesCad, items[i].anoCad);
                cout << "Producto consumido exitosamente.\n";
            }
			else{
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
    return acum;
}
