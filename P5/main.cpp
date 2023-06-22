#include <iostream>
#include <windows.h>

    static float ventas =0;
    static float costodventas =0;
   	//static float utilidadmarginal =0;
    static float gastosdeadministracion =0;
    static float gastos_ventas =0;
    //static float gastosdeoperacion =0;
	//static float utlidadperdida_desp_operaciones =0;
    static float ingresosfinancieros =0;
    static float gastosfinancieros =0;
  	//static float resultado_int_financiamiento =0;
    //static float utilidad_antes_impuestos =0;
    static float impuestos =0;
    static float utilidad_desp_impuestos =0;
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
        TEXT("DATOS ESTADO DE RESULTADOS"),
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
           while (GetMessage(&msg, NULL, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
	
    
       // if (number == 100)
            break;

        // Resto del código del bucle principal
        // ...

        // Ejemplo: Mostrar el valor actual de 'number'
       } 
	
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static HWND hEdit1; 
	static HWND hEdit2;
    static HWND hEdit3; 
	static HWND hEdit4;
	static HWND hEdit5;
	static HWND hEdit6;
	static HWND hEdit7;

   	static HWND hLabel;



    switch (msg)
    {
    case WM_CREATE:
    	hLabel = CreateWindow(TEXT("STATIC"), TEXT("Ingrese las Ventas:"),
    	WS_VISIBLE | WS_CHILD,
    	10, 10, 300, 20,
    	hwnd, NULL, NULL, NULL);
    	hLabel = CreateWindow(TEXT("STATIC"), TEXT("Ingrese el Costo de Ventas:"),
    	WS_VISIBLE | WS_CHILD,
    	10, 50, 300, 20,
    	  	hwnd, NULL, NULL, NULL);
    	hLabel = CreateWindow(TEXT("STATIC"), TEXT("Ingrese los Gastos de Administración:"),
    	WS_VISIBLE | WS_CHILD,
    	10, 90, 300, 20,
    	hwnd, NULL, NULL, NULL);
    	hLabel = CreateWindow(TEXT("STATIC"), TEXT("Ingrese los Gastos de Venta:"),
    	WS_VISIBLE | WS_CHILD,
    	10, 130, 300, 20,
    	  	hwnd, NULL, NULL, NULL);
    	hLabel = CreateWindow(TEXT("STATIC"), TEXT("Ingrese los Ingresos Financieros:"),
    	WS_VISIBLE | WS_CHILD,
    	10, 170, 300, 20,
    	  	hwnd, NULL, NULL, NULL);
        hLabel = CreateWindow(TEXT("STATIC"), TEXT("Ingrese los Gastos Financieros :"),
    	WS_VISIBLE | WS_CHILD,
    	10, 210, 300, 20,
    	  	hwnd, NULL, NULL, NULL);
    	hLabel = CreateWindow(TEXT("STATIC"), TEXT("Ingrese los Impuestos:"),
    	WS_VISIBLE | WS_CHILD,
    	10, 250, 300, 20,
    	  	hwnd, NULL, NULL, NULL);
		hEdit1 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""),
            WS_CHILD | WS_VISIBLE | ES_NUMBER | ES_RIGHT,
            10, 30, 100, 20,
            hwnd, (HMENU)1, GetModuleHandle(NULL), NULL);
        hEdit2  = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""),
            WS_CHILD | WS_VISIBLE | ES_NUMBER | ES_RIGHT,
            10, 70, 100, 20,
            hwnd, (HMENU)1, GetModuleHandle(NULL), NULL);
        hEdit3  = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""),
            WS_CHILD | WS_VISIBLE | ES_NUMBER | ES_RIGHT,
            10, 110, 100, 20,
            hwnd, (HMENU)1, GetModuleHandle(NULL), NULL);
        hEdit4  = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""),
            WS_CHILD | WS_VISIBLE | ES_NUMBER | ES_RIGHT,
            10, 150, 100, 20,
            hwnd, (HMENU)1, GetModuleHandle(NULL), NULL);
        hEdit5  = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""),
            WS_CHILD | WS_VISIBLE | ES_NUMBER | ES_RIGHT,
            10, 190, 100, 20,
            hwnd, (HMENU)1, GetModuleHandle(NULL), NULL);  
		hEdit6  = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""),
            WS_CHILD | WS_VISIBLE | ES_NUMBER | ES_RIGHT,
            10, 230, 100, 20,
            hwnd, (HMENU)1, GetModuleHandle(NULL), NULL); 
		hEdit7  = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""),
            WS_CHILD | WS_VISIBLE | ES_NUMBER | ES_RIGHT,
            10, 270, 100, 20,
            hwnd, (HMENU)1, GetModuleHandle(NULL), NULL);	 
        CreateWindow(TEXT("button"), TEXT("GUARDAR DATOS"), WS_VISIBLE | WS_CHILD,
            320, 10, 150, 25, hwnd, (HMENU)2, NULL, NULL);
           
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == 2)
        {
            TCHAR buffer[256];
            GetWindowText(hEdit1, buffer, sizeof(buffer));
            number = atoi(buffer);
            std::cout << "Number1: " << number << std::endl;
            GetWindowText(hEdit2, buffer, sizeof(buffer));
            number = atoi(buffer);
            std::cout << "Number2: " << number << std::endl;
             GetWindowText(hEdit3, buffer, sizeof(buffer));
            number = atoi(buffer);
            std::cout << "Number3: " << number << std::endl;
             GetWindowText(hEdit4, buffer, sizeof(buffer));
            number = atoi(buffer);
            std::cout << "Number4: " << number << std::endl;
             GetWindowText(hEdit5, buffer, sizeof(buffer));
            number = atoi(buffer);
            std::cout << "Number5: " << number << std::endl;
             GetWindowText(hEdit6, buffer, sizeof(buffer));
            number = atoi(buffer);
            std::cout << "Number6: " << number << std::endl;
             GetWindowText(hEdit7, buffer, sizeof(buffer));
            number = atoi(buffer);
            std::cout << "Number7: " << number << std::endl;
            //MessageBox(hwnd, TEXT("Button pressed!"), TEXT("Information"), MB_OK);
            MessageBox(hwnd, 0, TEXT("Datos Registrados"), MB_OK);
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
