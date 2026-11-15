#include "Actor.h"
#include "Engine/Engine.h"
#include "Level/Level.h"

namespace Jasbyte
{
	Actor::Actor()
	{
	}

	Actor::~Actor()
	{
	}

	void Actor::BeginPlay()
	{
		// 중복 호출 방지
		m_hasBegunPlay = true;
	}

	void Actor::Tick(float deltaTime)
	{
	}

	void Actor::Render()
	{
	}

	void Actor::Destroy()
	{
		// 액터 삭제 예약
		m_isPendingDestroy = true;
		
	}

	std::shared_ptr<Level> Actor::GetOwner()
	{
		return m_owner.lock();
	}

	void Actor::SetOwner(std::weak_ptr<Level> newOwner)
	{
		m_owner = newOwner;
	}
}