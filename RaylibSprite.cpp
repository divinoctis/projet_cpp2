#include "RaylibSprite.h"

// Constructeur : Initialisation des valeurs par d�faut
RaylibSprite::RaylibSprite()
    : x(0), y(0), xSpeed(0), ySpeed(0), radius(20)  // Initialisation
{
}

// Fonction pour d�finir la position du cercle
void RaylibSprite::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}
void RaylibSprite::setSpeed(float xSpeed, float ySpeed) 
{
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;
}
// Fonction pour dessiner le cercle
void RaylibSprite::drawCircle(float x, float y, float radius)
{
    DrawCircle(static_cast<int>(x), static_cast<int>(y), radius, RED);
}

// Fonction pour d�placer le cercle
void RaylibSprite::moveCircle(float xSpeed, float ySpeed)
{
    // Mise � jour de la position
    this->x += xSpeed;
    this->y += ySpeed;

    // V�rification des collisions avec les bords de la fen�tre
    if (this->x - radius <= 0 || this->x + radius >= GetScreenWidth()) {
        this->xSpeed = -this->xSpeed;  // Inversion de la vitesse horizontale
    }
    if (this->y - radius <= 0 || this->y + radius >= GetScreenHeight()) {
        this->ySpeed = -this->ySpeed;  // Inversion de la vitesse verticale
    }

    // Dessin du cercle � la nouvelle position
    drawCircle(this->x, this->y, radius);
}

RaylibSprite::~RaylibSprite() 
{

}






