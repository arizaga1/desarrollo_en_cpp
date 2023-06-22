#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

    HWND hwnd,hwnd2;int main()
{
    HWND hwnd,hwnd2;
    MSG  msg;
    WNDCLASS wc = { 0 };

    wc.lpszClassName = TEXT("MyDialogClass");
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpfnWndProc = WndProc;
    wc.style = CS_HREDRAW | CS_VREDRAW;

    RegisterClass(&wc);

    hwnd = CreateWindow(
        TEXT("MyDialogClass"),
        TEXT("Window 2"),
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        100,
        100,
        500,
        500,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );

     hwnd2 = CreateWindow(
        TEXT("MyDialogClass"),
        TEXT("Window 1"),
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        100,
        100,
        500,
        500,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );

    ShowWindow(hwnd, SW_SHOW);
    ShowWindow(hwnd2, SW_HIDE);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static HWND hButton; 
	static HWND hText;

    switch (msg)
    {
	case WM_CREATE:
		if (hwnd == FindWindow(TEXT("MyDialogClass"), TEXT("Window 2")))
		{
			hButton = CreateWindow(TEXT("BUTTON"), TEXT("Cerrar ventana"),
				WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
				10, 10, 200, 20,
				hwnd, (HMENU)1, NULL, NULL);

			hText = CreateWindow(TEXT("STATIC"), TEXT("Esta bien"),
				WS_VISIBLE | WS_CHILD | SS_CENTER,
				50, 50, 200, 20,
				hwnd, NULL, NULL, NULL);
		}
		
		if (hwnd == FindWindow(TEXT("MyDialogClass"), TEXT("Window 1")))
		{
			hButton = CreateWindow(TEXT("BUTTON"), TEXT("cambia de  ventana"),
				WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
				10, 10, 200, 20,
				hwnd, (HMENU)1, NULL, NULL);

			hText = CreateWindow(TEXT("STATIC"), TEXT("Hola"),
				WS_VISIBLE | WS_CHILD | SS_CENTER,
				50, 50, 200, 20,
				hwnd, NULL, NULL, NULL);
		}
    	break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
			case 1:
				if (hwnd == FindWindow(TEXT("MyDialogClass"), TEXT("Window 1")))
				{
					
					ShowWindow(hwnd, SW_HIDE);
					ShowWindow(hwnd2, SW_SHOW);
				}
				else
				{
					DestroyWindow(hwnd2);
					DestroyWindow(hwnd);
				}
				break;
			default:
				break;
		}
    	break;

	case WM_DESTROY:
    	PostQuitMessage(0);
    	break;

	default:
    	return DefWindowProc(hwnd, msg, wParam, lParam);
    	break;
    }

    return 0;
}
