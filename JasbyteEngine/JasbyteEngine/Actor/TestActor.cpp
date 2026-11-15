#include "TestActor.h"
#include <iostream>

namespace Jasbyte
{
	void TestActor::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);

		std::cout << "TestActor::Tick() - deltaTime: " << deltaTime << "| FPS: " << (1.0f / deltaTime) << '\n';
	}
}

