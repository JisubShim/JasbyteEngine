#pragma once
#include "Actor/Actor.h"

namespace Jasbyte
{
	class TestActor : public Actor
	{
	public:
		virtual void Tick(float deltaTime) override;
	};
}