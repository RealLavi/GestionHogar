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
   RECT desktop;											// Handler del escritorio. (Rectángulo como desktop).
   const HWND hDesktop = GetDesktopWindow();				// Def. hDesktop como ventana.
   GetWindowRect(hDesktop, &desktop);						// Obtenemos tamaño.
   horizontal = desktop.right;								// Def. valores variables.
   vertical = desktop.bottom;
}

void mainMenu(){
	int horizontal = 0;
	int vertical = 0;
	GetDesktopResolution(horizontal, vertical);									// Func. obtener resolución.
	HWND console = GetConsoleWindow();											// Obt. consola en la que se ejecuta el programa.
    RECT r;																		// Handler consola. (Rectángulo como r).
    MoveWindow(console, (horizontal - (horizontal - 200)) / 2, (vertical - (vertical - 100)) / 2, horizontal - 200, vertical - 100, TRUE); // Modificamos tamaño consola && centramos.
	GetWindowRect(console, &r);													// Obtenemos tamaño.
	//cout << r.right << "\n";
	//cout << "12345678901234567890123456789012345687901234567890";
	cout << "Hola owo :3";
}

void logoGen(){
}.
