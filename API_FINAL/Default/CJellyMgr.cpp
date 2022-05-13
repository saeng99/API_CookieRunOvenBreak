#include "stdafx.h"
#include "CJellyMgr.h"
#include "CollisionMgr.h"

CJellyMgr* CJellyMgr::m_pInstance = nullptr;

CJellyMgr::CJellyMgr()
{
}


CJellyMgr::~CJellyMgr()
{
	Release();
}

/*CJelly* CJellyMgr::Get_Target(OBJID eID, CObj* pObj)
{
	if (m_JellyList[eID].empty())
		return nullptr;

	CJelly* pTarget = nullptr;
	float		fDistance = 0.f;

	for (auto& iter : m_JellyList[eID])
	{
		if (iter->Get_Dead())
			continue;

		float	fWidth = abs(pObj->Get_Info().fX - iter->Get_Info().fX);
		float	fHeight = abs(pObj->Get_Info().fY - iter->Get_Info().fY);

		float	fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

		if ((!pTarget) || (fDistance > fDiagonal))
		{
			pTarget = iter;
			fDistance = fDiagonal;
		}
	}

	return pTarget;
}*/

void CJellyMgr::Add_Object(JELLYID eID, CJellyMgr* pJelly)
{
	if ((eID >= JELLY_END) || (nullptr == pJelly))
		return;

	m_JellyList[eID].push_back(pJelly);
}

int CJellyMgr::Update(void)
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter = m_JellyList[i].begin();
			iter != m_JellyList[i].end(); )
		{
			int iResult = (*iter)->Update();

			if (OBJ_DEAD == iResult)
			{
				Safe_Delete<CJellyMgr*>(*iter);
				iter = m_JellyList[i].erase(iter);
			}
			else
				++iter;
		}
	}

	return 0;
}

void CJellyMgr::Late_Update(void)
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_JellyList[i])
		{
			iter->Late_Update();

			if (m_JellyList[i].empty())
				break;

			RENDERID eRender = iter->Get_RenderID2();
			m_RenderSort[eRender].push_back(iter);
		}
	}

	//CCollisionMgr::Collision_RectEx(m_ObjList[OBJ_FORK], m_ObjList[OBJ_PLAYER]);
	//CCollisionMgr::Collision_RectEx(m_ObjList[OBJ_THORN], m_ObjList[OBJ_PLAYER]);
	//CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_MONSTER], m_ObjList[OBJ_BULLET]);
}

template<typename T>
bool		CompareY(T Dest, T Sour)
{
	return Dest->Get_Info().fY < Sour->Get_Info().fY;
}

void CJellyMgr::Render(HDC hDC)
{
	/*for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
			iter->Render(hDC);
	}*/


	for (int i = 0; i < RENDER_END; ++i)
	{
		m_RenderSort[i].sort(CompareY<CObj*>);

		for (auto& iter : m_RenderSort[i])
			iter->Render(hDC);

		m_RenderSort[i].clear();
	}

}

void CJellyMgr::Release(void)
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_JellyList[i])
			Safe_Delete<CJellyMgr*>(iter);

		m_JellyList[i].clear();
	}
}

void CJellyMgr::Delete_ID(JELLYID eID)
{
	for (auto& iter : m_JellyList[eID])
		Safe_Delete(iter);

	m_JellyList[eID].clear();
}
