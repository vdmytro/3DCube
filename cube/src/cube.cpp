#include "resource.h"
#include "cube.h"

#define WIN32_LEAN_AND_MEAN 

#include <windows.h>
#include <exception>

#include "Cuboid.hpp"
#include "Point.hpp"

#define MAX_LOADSTRING 100

HINSTANCE hInst;                               
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];


ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


SHORT TimeX = 0, TimeY = 0, TimeZ = 0;
SHORT MouseX = 0, MouseY = 0;
SHORT BtRotateX = 0, BtRotateY = 0, BtRotateZ = 0;
Cuboid cube;
bool MouseDown = false;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CUBE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CUBE));

    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CUBE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CUBE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; 

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static PAINTSTRUCT ps;
    static HDC hdc;
    
    static RECT rt;
    static HPEN hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 255));

    switch (message)
    {

    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;

    case WM_MOUSEMOVE:
        TimeX = MouseX;
        TimeY = MouseY;
        MouseX = LOWORD(lParam);
        MouseY = HIWORD(lParam);
        if (MouseDown) {
            cube.RotateCube(MouseX, MouseY, TimeZ, TimeX, TimeY, TimeZ);
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_LBUTTONDOWN:
        MouseDown = true;
        break;
    case WM_LBUTTONUP:
        MouseDown = false;
        break;
    case WM_RBUTTONUP:
        ReleaseCapture();
        break;
    case WM_KEYDOWN:
        if (wParam == 0x58) { //x
            cube.SetScale( 1.1);
        }
        if (wParam == 0x5a) { //z
            cube.SetScale( 0.9);
        }
        //----------- x ------------------
        if (wParam == 0x57) { //w
            TimeX = BtRotateX;
            BtRotateX--;
            if (BtRotateX < TimeX) {
                cube.SetAngleX(0.02);
            }
            else if (BtRotateX > TimeX)
            {
                cube.SetAngleX(-0.02);
            }
        }
        if (wParam == 0x53) { //s
            TimeX = BtRotateX;
            BtRotateX++;
            if (BtRotateX < TimeX) {
                cube.SetAngleX(0.02);
            }
            else if (BtRotateX > TimeX)
            {
                cube.SetAngleX(-0.02);
            }
        }
        //----------- y ------------------
        if (wParam == 0x41) { //a
            TimeY = BtRotateY;
            BtRotateY--;
            if (BtRotateY < TimeY) {
                cube.SetAngleY(0.02);
            }
            else if (BtRotateY > TimeY)
            {
                cube.SetAngleY(-0.02);
            }
        }
        if (wParam == 0x44) { //d
            TimeX = BtRotateY;
            BtRotateY++;
            if (BtRotateY < TimeY) {
                cube.SetAngleY(0.02);
            }
            else if (BtRotateY > TimeY)
            {
                cube.SetAngleY(-0.02);
            }
        }
        //----------- z ------------------
        if (wParam == 0x51) { //q
            TimeZ = BtRotateZ;
            BtRotateZ--;
            if (BtRotateZ < TimeZ) {
                cube.SetAngleZ(0.02);
            }
            else if (BtRotateZ > TimeZ)
            {
                cube.SetAngleZ(-0.02);
            }
        }
        if (wParam == 0x45) { //e
            TimeZ = BtRotateZ;
            BtRotateZ++;
            if (BtRotateZ < TimeZ) {
                cube.SetAngleZ(0.02);
            }
            else if (BtRotateZ > TimeZ)
            {
                cube.SetAngleZ(-0.02);
            }
        }

        //--------------------------------
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_KEYUP:
        if (wParam == 0x57) { //w
           // cube.SetScale(-1, true);
        }
        if (wParam == 0x53) { //s 
            //cube.SetScale(-1, false);
        }
        break;
    case WM_PAINT:
        {
        try
        {
            GetClientRect(hWnd, &rt);
            hdc = BeginPaint(hWnd, &ps);

           
            SelectObject(hdc, hPen); 

            Rectangle(hdc, 10, 10, rt.right - 10, rt.bottom - 10);
            static char buf[80];
            TextOut(hdc, 10, 10, (LPCWSTR)buf, wsprintf((LPWSTR)buf, L"X position :  %5d", MouseX));
            TextOut(hdc, 10, 30, (LPCWSTR)buf, wsprintf((LPWSTR)buf, L"Y position :  %5d", MouseY));
            TextOut(hdc, 10, 50, (LPCWSTR)buf, wsprintf((LPWSTR)buf, L"FLU X: %i", (int)cube.getCP().getX()));
			TextOut(hdc, 10, 70, (LPCWSTR)buf, wsprintf((LPWSTR)buf, L"FLU Y: %i", (int)cube.getCP().getY()));
			TextOut(hdc, 10, 90, (LPCWSTR)buf, wsprintf((LPWSTR)buf, L"FLU Z: %i", (int)cube.getCP().getZ()));
            TextOut(hdc, 10, 110, (LPCWSTR)buf, wsprintf((LPWSTR)buf, L"Angle: %i", (int)cube.getAngle()));
            cube.DrawCube(hWnd, hdc, rt);
            
            EndPaint(hWnd, &ps);
        }
        catch (const std::exception& ex)
        {
            MessageBox(hWnd, (LPCWSTR)ex.what(), NULL, NULL);
        }
            
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
