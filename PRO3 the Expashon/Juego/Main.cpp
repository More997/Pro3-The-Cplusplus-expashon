#include <iostream>
#if DEBUG
#include <vld.h>
#else 
#include <Windows.h>
#endif
#include "Menu.h"


#if DEBUG
int main()
{
	Menu menu;
	menu.Start();
	return 0;
}
#else
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCMD)
{
	Menu menu;
	menu.Start();
	return 0;
}
#endif
	