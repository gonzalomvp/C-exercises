#include "stdafx.h"

#include <stdlib.h> 
#include "entity.h"
#include "consola.h"
#include "utils.h"

TEntity::TEntity()
{
	m_ix = rand() % (MAX_X + 1);
	m_iy = rand() % (MAX_Y + 1);

	m_funcs = new funcEntity[2];

	int drawFunc = rand() % 4;
	switch(drawFunc) {
		case 0: m_funcs[0] = &draw1; break;
		case 1: m_funcs[0] = &draw2; break;
		case 2: m_funcs[0] = &draw3; break;
		case 3: m_funcs[0] = &draw4; break;
	}

	int moveFunc = rand() % 4;
	switch (moveFunc) {
		case 0: m_funcs[1] = &move1; break;
		case 1: m_funcs[1] = &move2; break;
		case 2: m_funcs[1] = &move3; break;
		case 3: m_funcs[1] = &move4; break;
	}

	m_life = (rand() % 50) + 20;
}

TEntity::~TEntity()
{
	delete[] m_funcs;
}

void draw1(TEntity *entity)
{
	gotoxy(intToShort(entity->m_ix), intToShort(entity->m_iy));
	printf("X");
}

void draw2(TEntity *entity)
{
	gotoxy(intToShort(entity->m_ix), intToShort(entity->m_iy));
	printf("O");
}

void draw3(TEntity *entity)
{
	gotoxy(intToShort(entity->m_ix), intToShort(entity->m_iy));
	printf("|");
}

void draw4(TEntity *entity)
{
	gotoxy(intToShort(entity->m_ix), intToShort(entity->m_iy));
	printf("-");
}


void move1(TEntity *entity)
{
	entity->m_ix = entity->m_ix + 1;
	checkMoveLimits(entity);
}

void move2(TEntity *entity)
{
	entity->m_iy = entity->m_iy + 1;
	checkMoveLimits(entity);
}

void move3(TEntity *entity)
{
	entity->m_ix = entity->m_ix + 1;
	entity->m_iy = entity->m_iy + 1;
	checkMoveLimits(entity);
}

void move4(TEntity *entity)
{
	entity->m_ix = entity->m_ix - 2;
	entity->m_iy = entity->m_iy + 1;
	checkMoveLimits(entity);
}

void checkMoveLimits(TEntity *entity)
{
	if (entity->m_ix > MAX_X)
	{
		entity->m_ix = 0;
	}
	if (entity->m_ix < MIN_X)
	{
		entity->m_ix = MAX_X;
	}
	if (entity->m_iy > MAX_Y)
	{
		entity->m_iy = 0;
	}
	if (entity->m_iy < MIN_Y)
	{
		entity->m_iy = MAX_Y;
	}
}
