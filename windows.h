#ifndef _WINDOWS_H_
#define _WINDOWS_H_

extern int get_screen_width();

extern int get_screen_height();

extern void set_console_color(int color);

extern void set_console_cursor_position(int x, int y);

extern HWND create_general_window(HINSTANCE hInstance, char *className, char *windowTitle);

extern void paint_text(HDC hdc, HWND hwnd, PAINTSTRUCT ps, char *str, int x, int y);

#endif