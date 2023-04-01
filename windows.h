#ifndef _WINDOWS_H_
#define _WINDOWS_H_

extern int get_screen_width();

extern int get_screen_height();

extern void set_console_color(int color);

extern void set_console_cursor_position(int x, int y);

extern HWND create_general_window(HINSTANCE hInstance, char *className, char *windowTitle);

extern void paint_text(HDC hdc, HWND hwnd, PAINTSTRUCT ps, char *str, int x, int y);

extern void message_box(char *title, char *message);

extern void append_menu(HMENU hMenu, char *title);

extern void append_menu_with_sub(HMENU hMenu, char *title, HMENU sub);

extern void append_menu_with_tag(HMENU hMenu, char *title, UINT tag);

extern HWND create_textbox(HWND hwnd);

#endif