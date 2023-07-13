#include <iostream>
#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
HWND hwnd1,newHwnd;
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
LRESULT CALLBACK WndProc_resultados(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
HWND hwnd, resultWindow, newhwnd;
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
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
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
    
    {
        // Crear el botón
       if (hwnd == FindWindow(TEXT("MyWindowClass"), TEXT("Ventana")))
		{ 
        HWND button = CreateWindow(
           TEXT("BUTTON"),
            TEXT("GUARDAR DATOS"),
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            320, 10, 150, 25,
            hwnd,
            NULL,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL
        );

        // Crear las etiquetas y cajas de texto
        
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
    	}
    
	}
    break;

    case WM_COMMAND:

    	if (HIWORD(wParam) == BN_CLICKED) // Botón presionado
        {
    	if (hwnd == FindWindow(TEXT("MyWindowClass"), TEXT("Ventana")))
		{            // Destruir la ventana principal
           // DestroyWindow(hwnd);
            ShowWindow(hwnd, SW_HIDE);

            // Crear una nueva ventana con la etiqueta "Hola mundo" y un botón de cerrar
             newHwnd = CreateWindow(
                TEXT("MyWindowClass"),
                TEXT("ESTADO DE RESULTADOS"),
                WS_OVERLAPPEDWINDOW,
                CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
                NULL,
                NULL,
                GetModuleHandle(NULL),
                NULL
            );
            
             {
            TCHAR buffer[256];
            GetWindowText(hEdit1, buffer, sizeof(buffer));
            ventas = atof(buffer);
            std::cout << "Number1: " << ventas << std::endl;
            GetWindowText(hEdit2, buffer, sizeof(buffer));
            costodventas = atof(buffer);
            std::cout << "Number2: " << costodventas << std::endl;
             GetWindowText(hEdit3, buffer, sizeof(buffer));
            gastosdeadministracion = atof(buffer);
            std::cout << "Number3: " << gastosdeadministracion << std::endl;
             GetWindowText(hEdit4, buffer, sizeof(buffer));
            gastos_ventas = atof(buffer);
            std::cout << "Number4: " << gastos_ventas << std::endl;
             GetWindowText(hEdit5, buffer, sizeof(buffer));
            ingresosfinancieros = atof(buffer);
            std::cout << "Number5: " << ingresosfinancieros << std::endl;
             GetWindowText(hEdit6, buffer, sizeof(buffer));
            gastosfinancieros = atof(buffer);
            std::cout << "Number6: " << gastosfinancieros << std::endl;
             GetWindowText(hEdit7, buffer, sizeof(buffer));
            impuestos = atof(buffer);
            std::cout << "Number7: " << impuestos << std::endl;
            //MessageBox(hwnd, TEXT("Button pressed!"), TEXT("Information"), MB_OK);
            MessageBox(hwnd, 0, TEXT("Datos Registrados"), MB_OK);
            
            }
			
            HWND closeButton = CreateWindow(
                TEXT("BUTTON"),
                TEXT("Cerrar"),
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                10, 300, 100, 30,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL
            );

            HWND newLabel = CreateWindow(
                TEXT("STATIC"),
                TEXT("ESTADO DE RESULTADOS INTEGRAL"),
                WS_VISIBLE | WS_CHILD,
                70, 20, 250, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL
            );
            newLabel = CreateWindow(
                TEXT("STATIC"),
                TEXT("MIRJAM JAZMIN REYES DIAZ"),
                WS_VISIBLE | WS_CHILD,
                80, 45, 230, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL );
			newLabel = CreateWindow(
                TEXT("STATIC"),
                TEXT("01 de enero al 31 de enero de 2023"),
                WS_VISIBLE | WS_CHILD,
                70, 70, 250, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL );
            newLabel = CreateWindow(
                TEXT("STATIC"),
                TEXT("VENTAS. . . . . . . . . ."),
                WS_VISIBLE | WS_CHILD,
                10, 100, 210, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL );   
			newLabel = CreateWindow(
                TEXT("STATIC"),
                TEXT(std::basic_string(ventas)),
                WS_VISIBLE | WS_CHILD,
                230, 100, 50, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL );	 
                
                
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

