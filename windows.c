#include <windows.h>
#include <tchar.h>
#include "windows.h"

void append_menu_with_sub(HMENU hMenu, char *title, HMENU sub) {
    AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT) sub, title);
}

void append_menu(HMENU hMenu, char *title) {
    AppendMenu(hMenu, MF_STRING | MF_POPUP, 0, title);
}

void message_box(char *title, char *message) {
    MessageBox(NULL, message, title, MB_ICONEXCLAMATION | MB_OK);
}

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

HWND create_textbox(HWND hwnd) {
    return CreateWindowEx(
        WS_EX_CLIENTEDGE, // dwExStyle
        "EDIT", 
        "", 
        WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 
        0, 
        0, 
        100, 
        100, 
        hwnd, 
        (HMENU)101, 
        GetModuleHandle(NULL), 
        NULL
    );
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
