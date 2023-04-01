#include <windows.h>
#include "windows.h"

int get_screen_width() {
    int width = GetSystemMetrics(SM_CXSCREEN);

    return width;
}

int get_screen_height() {
    int width = GetSystemMetrics(SM_CYSCREEN);

    return width;
}
