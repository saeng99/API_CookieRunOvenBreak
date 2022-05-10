#include "stdafx.h"
#include "Logo.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"


CLogo::CLogo()
{
}

CLogo::~CLogo()
{
	Release();
}

void CLogo::Initialize(void)
{
	// MCIWndCreate : mci(��Ƽ�̵�� ��ġ�� ����ϰ� ���ҽ� ������ ����ϱ� ���� �������̽�), ����� �� ���� �ֺ� ��ġ�� �����ϴ� ��ġ
	// : ��Ƽ�̵� ����ϱ� ���� ������â�� �����ϴ� �Լ�

	// 1���� : �θ��� ������ �ڵ�, 2���� : mci������ �ν��Ͻ� �ڵ�
	// 3���� : â ��Ÿ�� WS_CHILD : �ڽ� â�� ����, WS_VISIBLE : �� ��� ȭ�� ���� MCIWNDF_NOPLAYBA : �÷��� �ٸ� ������ �ʰڴ�.
	// 4���� : ���� ���
	m_hVideo = MCIWndCreate(g_hWnd, nullptr, WS_CHILD | WS_VISIBLE | MCIWNDF_NOPLAYBAR, L"../Video/Wildlife.wmv");

	// MoveWindow : �������� ����� ũ�⸦ ����, �������� ���� ��� �������� ���� ũ���� ���
	MoveWindow(m_hVideo, 0, 0, WINCX, WINCY, FALSE);

	MCIWndPlay(m_hVideo);


	//CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Logo/Logo.bmp", L"Logo");
}

void CLogo::Update(void)
{
	
}

void CLogo::Late_Update(void)
{
	if (MCIWndGetLength(m_hVideo) <= MCIWndGetPosition(m_hVideo) ||		
		CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_MENU);

		return;
	}
}

void CLogo::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Logo");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CLogo::Release(void)
{
	MCIWndClose(m_hVideo);
}
