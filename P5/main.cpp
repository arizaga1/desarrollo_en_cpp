#include <iostream>
#include <windows.h>

    static int number =0;
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int main()
{
    HWND hwnd;
    MSG  msg;
    WNDCLASS wc = { 0 };

    wc.lpszClassName = TEXT("MyDialogClass");
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpfnWndProc = WndProc;
    wc.style = CS_HREDRAW | CS_VREDRAW;

    RegisterClass(&wc);
while (true)
    {
    hwnd = CreateWindow(
        TEXT("MyDialogClass"),
        TEXT("My Dialog"),
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        100,
        100,
        300,
        200,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );
           while (GetMessage(&msg, NULL, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
	std::cout << "Number: " << number << std::endl;
    
        if (number == 100)
            break;

        // Resto del código del bucle principal
        // ...

        // Ejemplo: Mostrar el valor actual de 'number'
       } 
	
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static HWND hEdit;
   

    switch (msg)
    {
    case WM_CREATE:
        hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""),
            WS_CHILD | WS_VISIBLE | ES_NUMBER | ES_RIGHT,
            10, 10, 100, 20,
            hwnd, (HMENU)1, GetModuleHandle(NULL), NULL);
        CreateWindow(TEXT("button"), TEXT("OK"), WS_VISIBLE | WS_CHILD,
            120, 10, 80, 25, hwnd, (HMENU)2, NULL, NULL);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == 2)
        {
            TCHAR buffer[256];
            GetWindowText(hEdit, buffer, sizeof(buffer));
            number = atoi(buffer);
            //MessageBox(hwnd, TEXT("Button pressed!"), TEXT("Information"), MB_OK);
            //MessageBox(hwnd, buffer, TEXT("Number entered"), MB_OK);
            DestroyWindow(hwnd);
           // MessageBox(hwnd, std::to_string(number), TEXT("Number as integer"), MB_OK);
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
