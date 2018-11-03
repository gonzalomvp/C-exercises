#include "stdafx.h"
#pragma warning( disable : 4668)
#pragma warning( disable : 4710)

#include "entity.h"
#include "consola.h"
#include "utils.h"


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
