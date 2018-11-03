#pragma once
#include <stdlib.h> 

struct TEntity;
typedef void(*funcEntity)(TEntity *);

// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
	int m_ix;
	int m_iy;
	int m_life;
	funcEntity *m_funcs;
	
	TEntity();
	~TEntity();
};

void draw1(TEntity *entity);
void draw2(TEntity *entity);
void draw3(TEntity *entity);
void draw4(TEntity *entity);

void move1(TEntity *entity);
void move2(TEntity *entity);
void move3(TEntity *entity);
void move4(TEntity *entity);

void checkMoveLimits(TEntity *entity);