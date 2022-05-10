// Default.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Default.h"
#include "MainGame.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.
HWND	g_hWnd;

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM                MyRegisterClass(HINSTANCE hInstance);		// â ������ ���õ� ������ ��Ҹ� ����
BOOL                InitInstance(HINSTANCE, int);				// ���������� â�� �����ϰ� �� â�� �ڵ��� ����� ���
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DEFAULT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DEFAULT));

    MSG msg;
	msg.message = WM_NULL;

	CMainGame*	pMainGame = new CMainGame;
	
	if (nullptr == pMainGame)
		return FALSE;

	pMainGame->Initialize();

    // �⺻ �޽��� �����Դϴ�.
   /* while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) // �޴� ����� ����Ű�� ����� �۵��ϵ��� �˻��ϴ� �Լ�
        {
            TranslateMessage(&msg);	// Ű���� �޼����� �����Ͽ� ���α׷����� ���� ����� �� �ֵ��� �����ϴ� �Լ�
            DispatchMessage(&msg);	// �ý��� �޼��� ť���� ���� �޼����� ���α׷����� ó��(WndProc ȣ��) �ϵ��� ����
        }
    }*/

	// �ü���� ���۵� �ķ� �帥 �ð��� ���� ���·� ��ȯ
	// 1 / 1000���� DWORD ���������� ��ȯ(�и� ������ ����)
	DWORD		dwOldTime = GetTickCount();



	while (true)
	{
		// PM_REMOVE   : �޽����� �о�Ȱ� ���ÿ� �޽��� ť���� ����
		// PM_NOREMOVE : �޽��� ť�� �޽����� �����ϴ����� �ľ�, ���� �޽����� �������� GetMessage�� �ٽ� ȣ���ؾ� ��

		if(PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (WM_QUIT == msg.message)
				break;

			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) // �޴� ����� ����Ű�� ����� �۵��ϵ��� �˻��ϴ� �Լ�
			{
				TranslateMessage(&msg);	// Ű���� �޼����� �����Ͽ� ���α׷����� ���� ����� �� �ֵ��� �����ϴ� �Լ�
				DispatchMessage(&msg);	// �ý��� �޼��� ť���� ���� �޼����� ���α׷����� ó��(WndProc ȣ��) �ϵ��� ����
			}
		}

		else
		{
			if (dwOldTime + 10 < GetTickCount())
			{
				pMainGame->Update();
				pMainGame->Late_Update();
				pMainGame->Render();

				dwOldTime = GetTickCount();
			}		

			/*pMainGame->Update();
			pMainGame->Late_Update();
			pMainGame->Render();*/
		}

	}


	Safe_Delete<CMainGame*>(pMainGame);

    return (int) msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DEFAULT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.
   RECT rc{ 0, 0, WINCX, WINCY };

   // ���â�� ���� ũ�� = ���� â ������ + �⺻ ������ â ���� �� + �޴��� ũ�� ��� ����
   AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      400, 300,  // ����ϰ��� �ϴ� â�� left�� top ��ǥ
	   rc.right - rc.left, 
	   rc.bottom - rc.top, // �����ϰ��� �ϴ� â�� ����, ���� ������
	   nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   g_hWnd = hWnd;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {

#pragma region ������ �ڵ�
		/*case WM_CREATE:

		SetTimer(hWnd, 0, 0, 0);

		/ *SetTimer : Ÿ�̸Ӹ� ��ġ�ϴ� �Լ�
		1���� :������ �ڵ�
		2���� : Ÿ�̸��� id ��ȣ, �������� Ÿ�̸Ӱ� ������ �� �ֱ� ������, ����� 0�� Ÿ�̸�
		3���� : Ÿ�̸� �ֱ�, �⺻������ ����, 1000�� 1��
		4���� : null�� ��� wm_timer��� �޼����� �߻���Ŵ* /
		break;

		case WM_TIMER:

		InvalidateRect(hWnd, 0, true);
		// InvalidateRect : ������ ȭ�� ���� �Լ�, �Լ� ȣ�� �� wm_paint �޼����� �߻�
		/ *1���� : ������ ������ �ڵ�
		2���� : ������ �ȿ��� ������ ���� ����, null�� ��� ������ ��ü ����
		3���� : false�� true�Ŀ� ���� ȭ�� ���� ���� ����* /
		// false�� ��� ���� �׸��� �κи� ����, true�� ��� �׷��� ���� �ʴ� ��� ������ ����
		break;*/
#pragma endregion ������ �ڵ�	

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �޴� ������ ���� �м��մϴ�.
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(g_hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.

			// �׸��� �Լ�
			/*MoveToEx(hdc, 100, 100, nullptr);
			LineTo(hdc, 200, 100);
			LineTo(hdc, 200, 200);
			LineTo(hdc, 100, 200);
			LineTo(hdc, 100, 100);*/

			// �簢�� �׸��� �Լ�
			//Rectangle(hdc, 100, 100, 200, 200);

			// �� �׸��� �Լ�
			//Ellipse(hdc, 300, 300, 400, 400);

			/*LineTo(hdc, 200, 200);
			LineTo(hdc, 200, 300);*/

			/*Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

			for (auto& iter : m_BulletList)
			{
				Ellipse(hdc, iter.left, iter.top, iter.right, iter.bottom);
				
				iter.top    -= 10;
				iter.bottom -= 10;
			}*/
			
            EndPaint(hWnd, &ps);
        }
        break;

	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}

		break;

    case WM_DESTROY:
		// KillTimer(hWnd, 0);
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
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


// �Լ� ȣ�� �Ծ��� �߻� ���� : �Լ� ������ ����Ǹ� �Ҵ�Ǿ��� ���� �޸𸮸� �����ؾ� �ϴµ� �Լ��� ȣ���� ȣ���(caller)���� ȣ�� ���� ��ȣ����(callee)���� �� ���ΰ��� ���� ���, �Ծ�
// __cdecl, __stdcall, __fastcall, thiscall, naked ��

// __cdecl(ȣ���ڿ��� ������ ����)
/*
- c, c++�� �⺻ ȣ�� �Ծ�, ȣ����(caller)�� ������ �����Ѵ�.
- �������� �ڱ� �ڽſ��� � �Ű������� ������ �𸥴�. (�������ڰ� ������ �Լ�)
- �̷� ���� ������ ������ ������ �� ����.*/

// __stdcall

/*
- WIN32 api�� �⺻ ȣ�� �Ծ�, ��ȣ����(callee)�� ������ �����Ѵ�.
- api���� �����ϴ� ��κ��� �Լ���ó�� __stdcall�� '���� ���� �Լ�'�̴�.
- �Ű������� �����Ǿ� �ִٺ��� � ������ Ÿ���� ������ �˰� �ֱ� ������ ��ȣ���� ������ ������ ������ �� �ִ�.*/

// __fastcall

/*
- �Լ� ȣ���� ������ ó���ϱ� ���� ȣ�� �Ծ��̰�.
- ecx�� edx��� �������͸� ���� ����ȴ�. �������� ����ϰ� �ִٴ� �� ������ �Լ� ȣ���� ��������.*/

// thiscall
 
// - this �����͸� ���ڷ� �Ѱܹ޾��� �� ����ϴ� ȣ�� �Ծ��̴�.

