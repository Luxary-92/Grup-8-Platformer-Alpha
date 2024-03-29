#ifndef __SCENE_H__
#define __SCENE_H__

#include "Module.h"
#include "Player.h"
#include "Item.h"
#include "Enemy.h"
#include "Enemy_aire.h"
#include "Checkpoint.h"
#include "Coin.h"

struct SDL_Texture;

class Scene : public Module
{
public:

	Scene(App* application, bool start_enabled = true);

	// Destructor
	virtual ~Scene();

	// Called before render is available
	bool Awake(pugi::xml_node& config);

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

public:

	//L02: DONE 3: Declare a Player attribute 
	Player* player;

	Enemy* enemy1;
	Enemy* enemy2;
	Enemy* enemy3;
	Enemy* enemy4;
	Enemy* enemy5;
	Enemy* enemy6;
	Enemy* enemy7;

	EnemyAire* enemyaire1;
	EnemyAire* enemyaire2;

	Coin* coin1;
	Coin* coin2;
	Coin* coin3;
	Coin* coin4;
	Coin* coin5;
	Coin* coin6;
	Coin* coin7;
	Coin* coin8;
	Coin* coin9;
	Coin* coin10;
	Coin* coin11;
	Coin* coin12;
	Coin* coin13;
	Coin* coin14;
	Coin* coin15;
	Coin* coin16;
	Coin* coin17;
	Coin* coin18;
	Coin* coin19;

	Checkpoint* checkpoint1;
	Checkpoint* checkpoint2;
	Checkpoint* checkpoint3;

	bool FirstScene = true;
	bool ShowPathfinding = NULL;

private:
	SDL_Texture* img;
	SDL_Texture* mouseTileTex = nullptr;
	SDL_Texture* originTex = nullptr;

	// L12: Debug pathfing
	iPoint origin;
	bool originSelected = false;

};

#endif // __SCENE_H__