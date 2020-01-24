//#include "game_manager.h"
//#include "game_manager.h"
//#include "collision_detector.h"
//
//enum EGameState {
//	START,
//	ONGAME,
//	GAMECLEAR,
//	GAMEOVER,
//};
//
//UGameManager::UGameManager() {}
//
//void UGameManager::InitGame()
//{
//	m_player = new CPlayerObject(new Vector3(0, 0, 0), new Vector3(0, 0, 0), 0.2, 0.5, 0.02, 100, new Vector3(1.0, 0.0, 0.0));
//	m_enemy = new CEnemyObject(new Vector3(2, 0, 2), new Vector3(0.0, 0.0, 0.0), 0.2, 0.04, 0.02, 100, new Vector3(0.0, 0.0, 0.0), m_player);
//	m_heal = new CHealObject(new Vector3(0, 0, 0), new Vector3(0.0, 0.0, 0.0), 0.2, new Vector3(0.0, 1.0, 0.0), 30, m_player);
//	m_ground = new CGroundObject(new Vector3(0, 0, 0), new Vector3(0.0, 0.0, 0.0), 10.0, new Vector3(0.0, 1.0, 0.0));
//	m_camera = m_player;
//}
//
//void UGameManager::UpdateGame()
//{
//	//if (m_gameState != ONGAME)return;
//
//	if (m_player != 0)m_player->UpdatePos();
//	if (m_enemy != 0)m_enemy->UpdatePos();
//
//	for (int i = 0; i < m_player->BulletNum(); ++i) {
//		if (m_player->Bulllets()[i] == 0)continue;
//		m_player->Bulllets()[i]->UpdatePos();
//	}
//
//	if (UCollisionDetector::GetInstance().TriggerStay(m_player, m_enemy)) {
//		m_enemy->Neutralize();
//	}
//}
//
//void UGameManager::DrawGame()
//{
//	glPushMatrix();
//	{
//		m_player->SetObjTransform(m_player);
//		m_player->DrawObj();
//	}
//	glPopMatrix();
//
//	glPushMatrix();
//	{
//		m_enemy->SetObjTransform(m_enemy);
//		m_enemy->DrawObj();
//	}
//	glPopMatrix();
//
//	glPushMatrix();
//	{
//		for (int i = 0; i < m_player->BulletNum(); ++i)
//		{
//			glPushMatrix();
//			m_player->SetObjTransform(m_player->Bulllets()[i]);
//			m_player->Bulllets()[i]->DrawObj();
//			glPopMatrix();
//		}
//	}
//	glPopMatrix();
//
//	glPushMatrix();
//	{
//		m_heal->SetObjTransform(m_heal);
//		m_heal->DrawObj();
//	}
//	glPopMatrix();
//
//	glPushMatrix();
//	{
//		m_ground->SetObjTransform(m_ground);
//		m_ground->DrawObj();
//	}
//	glPopMatrix();
//}
