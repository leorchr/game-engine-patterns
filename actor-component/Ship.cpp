#include "Ship.h"
#include "SpriteComponent.h"
#include "Assets.h"
#include "InputComponent.h"
#include "Maths.h"
#include "Laser.h"

Ship::Ship() : Actor()
{
	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Ship"));
	InputComponent* ic = new InputComponent(this);
	ic->setMaxForwardSpeed(300.0f);
	ic->setMaxAngularSpeed(Maths::twoPi);
}

void Ship::actorInput(const Uint8* keyState)
{
}

void Ship::updateActor(float dt)
{
}

