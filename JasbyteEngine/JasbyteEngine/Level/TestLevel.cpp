#include "TestLevel.h"
#include "Actor/TestActor.h"

namespace Jasbyte
{
	void TestLevel::OnInitialized()
	{
		Level::OnInitialized();

		SpawnActor<TestActor>();
	}
}