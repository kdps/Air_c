#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <tchar.h>
#include "file_system.h"
#include "network_windows.h"
#include "datetime.h"
#include "windows.h"
#include "audio_windows.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;	
	WndClass.lpfnWndProc = WndProc;	
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
	WndClass.lpszMenuName = NULL;	
	WndClass.lpszClassName = _T("Windows Class Name");
	RegisterClass(&WndClass);	
	hwnd = create_general_window(hInstance, "Windows Class Name", "Sample Windows");
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
  HDC hdc;

	switch (iMsg)
	{
    case WM_CREATE:
      break;
    case WM_PAINT:
      hdc = BeginPaint(hwnd, &ps);
      
      paint_text(hdc, hwnd, ps, "TEXT", 0, 0);
      paint_text(hdc, hwnd, ps, "TEXT", 0, 100);
      
      EndPaint(hwnd, &ps);
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
	}
  
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}