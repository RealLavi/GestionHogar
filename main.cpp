#include <iostream>
#include <windows.h>
#include <wtypes.h>

using namespace std;
void mainMenu();
void GetDesktopResolution(int& horizontal, int& vertical);
void logoGen();
int main(){
	mainMenu();
	return 0;
}

void GetDesktopResolution(int& horizontal, int& vertical)
{
   RECT desktop;											// Handler del escritorio. (Rect�ngulo como desktop).
   const HWND hDesktop = GetDesktopWindow();				// Def. hDesktop como ventana.
   GetWindowRect(hDesktop, &desktop);						// Obtenemos tama�o.
   horizontal = desktop.right;								// Def. valores variables.
   vertical = desktop.bottom;
}

void mainMenu(){
	int horizontal = 0;
	int vertical = 0;
	GetDesktopResolution(horizontal, vertical);									// Func. obtener resoluci�n.
	HWND console = GetConsoleWindow();											// Obt. consola en la que se ejecuta el programa.
    RECT r;																		// Handler consola. (Rect�ngulo como r).
    MoveWindow(console, (horizontal - (horizontal - 200)) / 2, (vertical - (vertical - 100)) / 2, horizontal - 200, vertical - 100, TRUE); // Modificamos tama�o consola && centramos.
	GetWindowRect(console, &r);													// Obtenemos tama�o.
	//cout << r.right << "\n";
	//cout << "12345678901234567890123456789012345687901234567890";
	cout << "Hola owo :3";
}

void logoGen(){
}.
