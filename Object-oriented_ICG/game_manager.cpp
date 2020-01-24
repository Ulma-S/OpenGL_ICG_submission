#include "game_manager.h"
#include "collision_detector.h"

void UGameManager::InitGame()
{
	m_player = new CPlayerObject(new Vector3(0, 0, 0), new Vector3(0, 0, 0), 0.2, 0.5, 0.02, 100, new Vector3(1.0, 0.0, 0.0));
	m_hpGage = new CHPGage(m_player, new Vector3(0, 1, 0));
	m_enemy.resize(m_enemyNum);
	for (int i = 0; i < m_enemyNum; ++i) {
		m_enemy[i] = new CEnemyObject(new Vector3(4 * (1 + (i % 3)), 0, 4 * (1 + (i % 2))), new Vector3(0.0, 0.0, 0.0), 0.2, 0.01*(1 + (i % 3)), 0.02, 100, new Vector3(0.0, 0.0, 0.8), m_player);
	}
	m_heal = new CHealObject(new Vector3(0, 0, 0), new Vector3(0.0, 0.0, 0.0), 0.2, new Vector3(0.0, 1.0, 0.0), 30, m_player);
	m_ground = new CGroundObject(new Vector3(0, 0, 0), new Vector3(0.0, 0.0, 0.0), 10.0, new Vector3(1.0, 1.0, 0.0));
	text = new CTextObject();
	m_camera = m_player;
	m_gameState = START;
}

void UGameManager::UpdateGame()
{
	if (m_gameState != ONGAME)return;

	if (m_player != 0)m_player->UpdatePos();
	for (int i = 0; i < m_enemyNum; ++i) {
		if (m_enemy[i] == nullptr)continue;
		if (m_enemy[i] != nullptr)m_enemy[i]->UpdatePos();
	}
	for (int i = 0; i < m_player->BulletNum(); ++i) {
		if (m_player->Bulllets()[i] == nullptr)continue;
		m_player->Bulllets()[i]->UpdatePos();
	}

	//’e‚Æenemy
	for (int i = 0; i < m_enemyNum; ++i) {
		if (m_enemy[i] == nullptr)continue;
		for (int j = 0; j < m_player->BulletNum(); ++j) {
			if (m_player->Bulllets()[i] == nullptr)continue;
			if (UCollisionDetector::GetInstance().TriggerStay(m_player->Bulllets()[j], m_enemy[i]) && m_enemy[i]->IsVisible() && m_player->Bulllets()[j]->IsVisible()) {
				m_enemy[i]->Neutralize();
				//‚²‚Ü‚©‚µ@Œã‚ÅC³ (INIT‚ÌŒvŽZƒ^ƒCƒ~ƒ“ƒO)
				m_player->Bulllets()[j]->State(INIT);
			}
		}
	}

	//player‚ÆEnemy
	for (int i = 0; i < m_enemyNum; ++i) {
		if (m_enemy[i] == nullptr)continue;
		if (m_enemy[i]->IsVisible() && UCollisionDetector::GetInstance().TriggerStay(m_player, m_enemy[i])) {
			m_player->CurrHP(m_player->CurrHP()-0.1);
		}
	}
	if (GameClear())m_gameState = GAMECLEAR;
	if (GameOver())m_gameState = GAMEOVER;
}

void UGameManager::DrawGame()
{
	//Player
	glPushMatrix();
	{
		m_player->SetObjTransform(m_player);
		m_player->DrawObj();
	}
	glPopMatrix();

	//HPGage
	if (m_player->CurrHP() >= 0) {
		glPushMatrix();
		{
			glTranslatef(m_player->Pos().x, m_player->Pos().y, m_player->Pos().z);
			glRotatef(m_camera->EulerAngle().y, 0, 1, 0);
			m_hpGage->DrawObj();
		}
		glPopMatrix();
	}

	//Enemy
	for (int i = 0; i < m_enemyNum; ++i) {
		glPushMatrix();
		{
			m_enemy[i]->SetObjTransform(m_enemy[i]);
			m_enemy[i]->DrawObj();
		}
		glPopMatrix();
	}

	//Bullet
	glPushMatrix();
	{
		for (int i = 0; i < m_player->BulletNum(); ++i)
		{
			glPushMatrix();
			m_player->SetObjTransform(m_player->Bulllets()[i]);
			m_player->Bulllets()[i]->DrawObj();
			glPopMatrix();
		}
	}
	glPopMatrix();

	//Heal
	glPushMatrix();
	{
		m_heal->SetObjTransform(m_heal);
		m_heal->DrawObj();
	}
	glPopMatrix();

	//Ground
	glPushMatrix();
	{
		m_ground->SetObjTransform(m_ground);
		m_ground->DrawObj();
	}
	glPopMatrix();

	//Text
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 640, 0, 480, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	text->DrawObj();
}

bool UGameManager::GameClear()
{
	for (int i = 0; i < m_enemyNum; ++i) {
		if (m_enemy[i]->IsVisible())break;
		if (i == m_enemyNum - 1)return true;
	}
	return false;
}

bool UGameManager::GameOver()
{
	if (m_player->CurrHP() <= 0)return true;
	return false;
}
