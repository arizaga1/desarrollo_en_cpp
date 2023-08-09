#include <iostream>
#include <windows.h>
#include <string>
const int closeButtonId = 1001; // Custom button ID
const int PDFButtonId   = 1002; // Custom button ID

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
HWND hwnd1,newHwnd;
 static float ventas =0;
    static float costodventas =0;
   	static float utilidadmarginal =0;
    static float gastosdeadministracion =0;
    static float gastos_ventas =0;
    static float gastosdeoperacion =0;
	static float utlidadperdida_desp_operaciones =0;
    static float ingresosfinancieros =0;
    static float gastosfinancieros =0;
  	static float resultado_int_financiamiento =0;
    static float utilidad_antes_impuestos =0;
    static float impuestos =0;
    static float utilidad_desp_impuestos =0;
    char empresa ;
    using namespace std;
    

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc_resultados(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
HWND hwnd, resultWindow, newhwnd, hControl;
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
	static HWND hEdit8;
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
    	  	
    	hLabel = CreateWindow(TEXT("STATIC"), TEXT("Ingrese el Nombre de la Empresa:"),
    	WS_VISIBLE | WS_CHILD,
    	10, 290, 300, 20,
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
		hEdit8  = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""),
            WS_CHILD | WS_VISIBLE ,
            10, 310, 100, 20,
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
            GetWindowText(hEdit8, buffer, sizeof(buffer));
            empresa = atof(buffer);
            std::cout << "Number8: " << empresa << std::endl;
            
            
            //MessageBox(hwnd, TEXT("Button pressed!"), TEXT("Information"), MB_OK);
            MessageBox(hwnd, 0, TEXT("Datos Registrados"), MB_OK);
            
            }
			
            HWND closeButton = CreateWindow(
                TEXT("BUTTON"),
                TEXT("Cerrar"),
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                10, 400, 100, 30,
                newHwnd,
                (HMENU)closeButtonId,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL
            );
            
             HWND PrintButton = CreateWindow(
                TEXT("BUTTON"),
                TEXT("PDF"),
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                200, 400, 100, 30,
                newHwnd,
                (HMENU)PDFButtonId,
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
            char buffer[20];
    			sprintf(buffer, " %.2f", empresa);
            newLabel = CreateWindow(
                TEXT("STATIC"),
                buffer,
                WS_VISIBLE | WS_CHILD,
                340, 100, 100, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
               NULL );	
//            //newLabel = CreateWindow(
//                TEXT("STATIC"),
//                TEXT("MIRJAM JAZMIN REYES DIAZ"),
//                WS_VISIBLE | WS_CHILD,
//                80, 45, 230, 20,
//                newHwnd,
//                NULL,
//                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
//                NULL );
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
                TEXT("VENTAS. . . . . . . . . . . . . . . ."),
                WS_VISIBLE | WS_CHILD,
                10, 100, 320, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL );   
               
    			sprintf(buffer, " %.2f", ventas);
			newLabel = CreateWindow(
                TEXT("STATIC"),
                buffer,
                WS_VISIBLE | WS_CHILD,
                340, 100, 100, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
               NULL );	
			   newLabel = CreateWindow(
                TEXT("STATIC"),
                TEXT("COSTO DE VENTAS. . . . . . . . . ."),
                WS_VISIBLE | WS_CHILD,
                10, 125, 320, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL );   
               sprintf(buffer, " %.2f", costodventas);
               newLabel = CreateWindow(
                TEXT("STATIC"),
                buffer,
                WS_VISIBLE | WS_CHILD,
                340, 125, 100, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
               NULL );
               newLabel = CreateWindow(
                TEXT("STATIC"),
                TEXT("UTILIDAD MARGINAL. . . . . . . . . ."),
                WS_VISIBLE | WS_CHILD,
                10, 150, 320, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL );   
                // Se calcula la utilidad marginal 
                utilidadmarginal= ventas - costodventas;
               sprintf(buffer, " %.2f", utilidadmarginal);
               newLabel = CreateWindow(
                TEXT("STATIC"),
                buffer,
                WS_VISIBLE | WS_CHILD,
                340, 150, 100, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
               NULL );
               // Se calculan los Gastos de Operación
    		gastosdeoperacion = gastosdeadministracion + gastos_ventas;
               
               newLabel = CreateWindow(
                TEXT("STATIC"),
                TEXT("GASTOS DE OPERACIÓN. . . . . . . . . ."),
                WS_VISIBLE | WS_CHILD,
                10, 175, 320, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL );   
               sprintf(buffer, " %.2f", gastosdeoperacion);
               newLabel = CreateWindow(
                TEXT("STATIC"),
                buffer,
                WS_VISIBLE | WS_CHILD,
                340, 175, 100, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
               NULL );
               
            utlidadperdida_desp_operaciones = utilidadmarginal - gastosdeoperacion;
               
               newLabel = CreateWindow(
                TEXT("STATIC"),
                TEXT("UTILIDAD/PERDIDA DSP DE OPERACIONES. . . . . . . . . ."),
                WS_VISIBLE | WS_CHILD,
                10, 200, 320, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL );   
               sprintf(buffer, " %.2f",  utlidadperdida_desp_operaciones);
               newLabel = CreateWindow(
                TEXT("STATIC"),
                buffer,
                WS_VISIBLE | WS_CHILD,
                340, 200, 100, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
               NULL );
               
               resultado_int_financiamiento = ingresosfinancieros + gastosfinancieros ;
               
                newLabel = CreateWindow(
                TEXT("STATIC"),
                TEXT("RESULTADO INTEGRAL DE FINANCIAMIENTO. . . . . . . . . ."),
                WS_VISIBLE | WS_CHILD,
                10, 225, 320, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL );   
               sprintf(buffer, " %.2f", resultado_int_financiamiento);
               newLabel = CreateWindow(
                TEXT("STATIC"),
                buffer,
                WS_VISIBLE | WS_CHILD,
                340, 225, 100, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
               NULL );
               
               utilidad_antes_impuestos = utlidadperdida_desp_operaciones + resultado_int_financiamiento ;
                newLabel = CreateWindow(
                TEXT("STATIC"),
                TEXT("UTILIDAD ANTES DE IMPUESTOS. . . . . . . . . ."),
                WS_VISIBLE | WS_CHILD,
                10, 250, 320, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL );   
               sprintf(buffer, " %.2f", utilidad_antes_impuestos);
               newLabel = CreateWindow(
                TEXT("STATIC"),
                buffer,
                WS_VISIBLE | WS_CHILD,
                340, 250, 100, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
               NULL );
               
                newLabel = CreateWindow(
                TEXT("STATIC"),
                TEXT("IMPUESTOS. . . . . . . . . . . . . . . . . ."),
                WS_VISIBLE | WS_CHILD,
                10, 275, 320, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL );  
               sprintf(buffer, " %.2f", impuestos);
               newLabel = CreateWindow(
                TEXT("STATIC"),
                buffer,
                WS_VISIBLE | WS_CHILD,
                340, 275, 100, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
               NULL );
               
               
    			utilidad_desp_impuestos = utilidad_antes_impuestos - impuestos ;
    			newLabel = CreateWindow(
                TEXT("STATIC"),
                TEXT("UTILIDAD DESPUES DE IMPUESTOS. . . . . . . . . . . . . . . . ."),
                WS_VISIBLE | WS_CHILD,
                10, 300, 320, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL );   
               sprintf(buffer, " %.2f", utilidad_desp_impuestos);
               newLabel = CreateWindow(
                TEXT("STATIC"),
                buffer,
                WS_VISIBLE | WS_CHILD,
                340, 300, 100, 20,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
               NULL );
               
               newLabel = CreateWindow(
                TEXT("STATIC"),
                TEXT("FIRMA DEL CONTADOR ___________________________"),
                WS_VISIBLE | WS_CHILD,
                70, 340, 160, 42,
                newHwnd,
                NULL,
                (HINSTANCE)GetWindowLongPtr(newHwnd, GWLP_HINSTANCE),
                NULL );
    
    
				 
            // Mostrar la nueva ventana
            ShowWindow(newHwnd, SW_SHOWDEFAULT);
            ShowWindow(hwnd, SW_HIDE);
            
			UpdateWindow(newHwnd);
	
		}
//		{
//    // Imprimir la pantalla actual en un archivo PDF
//    ShellExecute(NULL, "printto", "MyWindowClass", "PDFCreator", NULL, 0);
//
//    return 0;
//}
		
		if (hwnd == FindWindow(TEXT("MyWindowClass"), TEXT("ESTADO DE RESULTADOS")))
		{std::cout <<"si entro1";
			if (LOWORD(wParam) == closeButtonId) 	
				{
				std::cout <<"si entro2";
				DestroyWindow(hwnd);DestroyWindow(hwnd1);
				}
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



