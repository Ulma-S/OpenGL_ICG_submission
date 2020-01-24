#include "player.h"
#include "gage.h"
#include "enemy.h"
#include "heal.h"
#include "ground.h"
#include "camera.h"
#include "text.h"

#ifndef INCLUDED_game_manager_h_
#define INCLUDED_game_manager_h_

enum EGameState {
	START = 0,
	ONGAME,
	GAMECLEAR,
	GAMEOVER,
};

class UGameManager {
private:
	EGameState m_gameState;
	UGameManager() = default;
	~UGameManager() = default;

	//Game
	CPlayerObject *m_player;
	CHPGage *m_hpGage;
	vector<CEnemyObject*> m_enemy;
	int m_enemyNum = 5;
	CHealObject *m_heal;
	CGroundObject *m_ground;
	CTextObject *text;
	AObjectBase *m_camera;
public:
	void InitGame();
	void UpdateGame();
	void DrawGame();
	bool GameClear();
	bool GameOver();
	inline EGameState GameState() { return m_gameState; }
	inline void GameState(EGameState value) { m_gameState = value; }
	inline CPlayerObject* Player() { return m_player; }
	inline AObjectBase* Camera() { return m_camera; }

	static UGameManager& GetInstance() {
		static UGameManager instance;
		return instance;
	}
};

#endif // !INCLUDED_game_manager_
