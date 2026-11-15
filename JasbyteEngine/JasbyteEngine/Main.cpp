#include "Engine/Engine.h"
#include "Level/TestLevel.h"

using namespace Jasbyte;

int main()
{
	Engine engine;
	engine.LoadLevel<TestLevel>();
	engine.Run();
}