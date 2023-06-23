#include <iostream>
#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
HWND hwnd1,newHwnd;
int main()
{
    
    MSG msg;
    WNDCLASS wc = {};

    // Registrar la clase de la ventana
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = TEXT("MyWindowClass");

    if (!RegisterClass(&wc))
    {
        std::cout << "Error al registrar la clase de la ventana." << std::endl;
        return 1;
    }

    // Crear la ventana principal
    hwnd1 = CreateWindow(
        TEXT("MyWindowClass"),
        TEXT("Ventana"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 200,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );

    if (hwnd1 == NULL)
    {
        std::cout << "Error al crear la ventana." << std::endl;
        return 1;
    }

    // Mostrar la ventana
    ShowWindow(hwnd1, SW_SHOWDEFAULT);
    UpdateWindow(hwnd1);

    // Bucle de mensajes de la ventana
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CREATE:
    {
        // Crear el botón
        HWND button = CreateWindow(
           TEXT("BUTTON"),
            TEXT("Click me !"),
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            10, 50, 100, 30,
            hwnd,
            NULL,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL
        );

        // Crear la etiqueta
        HWND label = CreateWindow(
            TEXT("STATIC"),
            TEXT("Etiqueta"),
            WS_VISIBLE | WS_CHILD,
            10, 90, 100, 20,
            hwnd,
            NULL,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL
        );
    }
    break;

    case WM_COMMAND:

    	if (HIWORD(wParam) == BN_CLICKED) // Botón presionado
        {
    	if (hwnd == FindWindow(TEXT("MyWindowClass"), TEXT("Ventana")))
		{            // Destruir la ventana principal
           // DestroyWindow(hwnd);

            // Crear una nueva ventana con la etiqueta "Hola mundo" y un botón de cerrar
             newHwnd = CreateWindow(
                TEXT("MyWindowClass"),
                TEXT("Hola mundo"),
                WS_OVERLAPPEDWINDOW,
                CW_USEDEFAULT, CW_USEDEFAULT, 400, 200,
                NULL,
                NULL,
                GetModuleHandle(NULL),
                NULL
            );

            HWND closeButton = CreateWindow(
                TEXT("BUTTON"),
                TEXT("Cerrar"),
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                10, 50, 100, 30,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL
            );

            HWND newLabel = CreateWindow(
                TEXT("STATIC"),
                TEXT("Hola mundo"),
                WS_VISIBLE | WS_CHILD,
                10, 90, 100, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL
            );

            // Mostrar la nueva ventana
            ShowWindow(newHwnd, SW_SHOWDEFAULT);
            ShowWindow(hwnd, SW_HIDE);
            
			UpdateWindow(newHwnd);
	
		}
		if (hwnd == FindWindow(TEXT("MyWindowClass"), TEXT("Hola mundo")))
		{
			DestroyWindow(hwnd);DestroyWindow(hwnd1);
		}
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}

