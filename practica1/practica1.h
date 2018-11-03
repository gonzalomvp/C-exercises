#pragma once

const unsigned int BULLETS_MASK = 0x00FF0000;
const unsigned int INFINITE_AMMO_MASK = 0x00000002;
const unsigned int MAX_BULLETS = 255;

/**
Returns the number of bullets of a character

@param unsigned int representing the character
@return number of bullets of the character
*/
unsigned int getBullets(unsigned int personaje);

/**
Adds a number of bullets to a character

@param unsigned int representing the character
@param number of bullets to add
@return number of bullets of the character after the addition
*/
unsigned int addBullets(unsigned int &personaje, unsigned int bullets);

/**
Returns the status of the infinite ammo mode in a character

@param unsigned int representing the character
@return true if the infinite ammo mode is enable and false if not
*/
bool isInfiniteAmmoEnabled(unsigned int personaje);

/**
Enables the infinite ammo mode in a character

@param unsigned int representing the character
*/
void enableInfiniteAmmo(unsigned int &personaje);