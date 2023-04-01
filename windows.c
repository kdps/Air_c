#include <windows.h>
#include <tchar.h>
#include "windows.h"
 
void paint_text(HDC hdc, HWND hwnd, PAINTSTRUCT ps, char *str, int x, int y) {
	HFONT hFont, oldFont;
    hFont = CreateFont(
        15, 
        0, 
        0, 
        0, 
        FW_NORMAL, 
        0, 
        0, 
        0, 
        HANGEUL_CHARSET, 
        OUT_DEFAULT_PRECIS, 
        CLIP_DEFAULT_PRECIS, 
        DEFAULT_QUALITY, 
        DEFAULT_PITCH, 
        _T("Arial")
    );
    oldFont = (HFONT)SelectObject(hdc, hFont);
    TextOut(hdc, x, y, _T(str), _tcslen(_T(str)));
    SelectObject(hdc, oldFont);
    DeleteObject(hFont);
}

HWND create_general_window(HINSTANCE hInstance, char *className, char *windowTitle) {
    return CreateWindow(
		_T(className),	//lpClassName
		_T(windowTitle),	            //lpWindowName
		WS_OVERLAPPEDWINDOW,	    //dsStyle
		CW_USEDEFAULT,		        //x
		CW_USEDEFAULT,		        //y
		CW_USEDEFAULT,		        //nWidth
		CW_USEDEFAULT,		        //nHeight
		NULL,	                    //hMenu 
		NULL,	                    //hMenu
		hInstance,		            //hInstance
		NULL		                //lpParam 
	);
}

void set_console_cursor_position(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void set_console_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int get_screen_width() {
    int width = GetSystemMetrics(SM_CXSCREEN);

    return width;
}

int get_screen_height() {
    int width = GetSystemMetrics(SM_CYSCREEN);

    return width;
}
