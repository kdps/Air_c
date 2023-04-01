#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <tchar.h>
#include "file_system.h"
#include "network_windows.h"
#include "datetime.h"
#include "windows.h"
#include "audio_windows.h"
#include <conio.h>
#include <mmsystem.h>

const char g_szClassName[] = "exampleWindowClass";

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS WndClass;

	// Registering the Window Class
	WndClass.style = CS_HREDRAW | CS_VREDRAW;	
	WndClass.lpfnWndProc = WndProc;	
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
	WndClass.lpszMenuName = NULL;	
	WndClass.lpszClassName = g_szClassName;

	if (!RegisterClass(&WndClass))
    {
		return 0;
	}

	hwnd = create_general_window(hInstance, "exampleWindowClass", "Sample Windows");
	if(hwnd == NULL)
    {
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// The Message Loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

void CALLBACK MidiInProc(HMIDIIN hMidiIn, UINT wMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2)
{
	switch(wMsg) {
	case MIM_OPEN:
		printf("wMsg=MIM_OPEN\n");
		break;
	case MIM_CLOSE:
		printf("wMsg=MIM_CLOSE\n");
		break;
	case MIM_DATA:
		printf("wMsg=MIM_DATA, dwInstance=%08x, dwParam1=%08x, dwParam2=%08x\n", dwInstance, dwParam1, dwParam2);
		break;
	case MIM_LONGDATA:
		printf("wMsg=MIM_LONGDATA\n"); 
		break;
	case MIM_ERROR:
		printf("wMsg=MIM_ERROR\n");
		break;
	case MIM_LONGERROR:
		printf("wMsg=MIM_LONGERROR\n");
		break;
	case MIM_MOREDATA:
		printf("wMsg=MIM_MOREDATA\n");
		break;
	default:
		printf("wMsg = unknown\n");
		break;
	}
	return;
}

// Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	HMENU hMenu, hSubMenu;
	HICON hIcon, hIconSm;

	HWND hTextbox;
	RECT rcClient;

	switch (iMsg)
	{
		case WM_SIZE:
			GetClientRect(hwnd, &rcClient);
    		SetWindowPos(hTextbox, NULL, 0, 0, rcClient.right, rcClient.bottom, SWP_NOZORDER);

			break;
        case WM_COMMAND:
			printf("%d", wParam);

			
			play_midi("110BPM_Piano_v1229a.mid");

			switch(LOWORD(wParam))
            {
				
            }

			break;
		case WM_LBUTTONDOWN:
			break;
		case WM_CREATE:
			hMenu = CreateMenu();

			hSubMenu = CreatePopupMenu();
			append_menu(hSubMenu, "&SubMenu");
			append_menu(hSubMenu, "&SubMenu");
			append_menu_with_tag(hMenu, "&FirstMenu", 1000);

			SetMenu(hwnd, hMenu);

			hTextbox = create_textbox(hwnd);

			GetClientRect(hwnd, &rcClient);
    		SetWindowPos(hTextbox, NULL, 0, 0, rcClient.right, rcClient.bottom, SWP_NOZORDER);

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