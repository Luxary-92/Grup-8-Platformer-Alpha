#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Entity.h"
#include "Point.h"
#include "SDL/include/SDL.h"
#include "Animation.h"
#include <time.h>

struct SDL_Texture;

class Player : public Entity
{
public:

	Player();
	
	virtual ~Player();

	bool Awake();

	bool Start();

	bool Update();

	bool CleanUp();



	// L07 DONE 6: Define OnCollision function for the player. Check the virtual function on Entity class
	void OnCollision(PhysBody* physA, PhysBody* physB);

	bool LoadStateEntity(pugi::xml_node&);
	bool SavelStateEntity(pugi::xml_node&);

	void LoadPosition(int x,int y);


public:

	Animation* currentAnimation = nullptr;


	Animation idle_r;
	Animation idle_l;

	Animation walk_r;
	Animation walk_l;

	Animation run_r;
	Animation run_l;

	Animation kneel_r;
	Animation kneelup_r;
	Animation kneel_l;
	Animation kneelup_l;

	Animation jump_up_r;
	Animation jump_up_l;
	Animation jump_down_r;
	Animation jump_down_l;

	Animation death;

	Animation atac_r;
	Animation atac_l;

	Animation test;
	
	bool cam = true;



private:

	//L02: DONE 1: Declare player parameters
	SDL_Texture* texture;
	const char* texturePath;

	// L07 DONE 5: Add physics to the player - declare a Physics body
	PhysBody* pbody;


	int pickCoinFxId;
	int deathsound;
	int speed = 7;


	bool salto = false; //false = no esta saltando / true = esta saltando
	bool usalto = false; //Puede hacer salto (true = no puede hacer salto)
	bool usalto2 = false;//Si esta en el aire no puede hacer salto
	int posy = position.y;//Si la posicion cambia despues de tocar una plataforma = esta en el aire
	bool hit = false;
	bool caida = false;
	int i;//altitud del salto (definido en la funcion)
	float j;
	int salto2 = 0;
	bool godmode = false;

	bool delete_bala = false;
	PhysBody* bala;
	int i10 = 1;
	int i10_aux = 0;
	PhysBody* bala_aux [10];

	bool derecha = true;



};

#endif // __PLAYER_H__