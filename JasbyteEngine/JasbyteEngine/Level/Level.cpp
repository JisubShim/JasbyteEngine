#include "Level.h"

namespace Jasbyte
{
	Level::Level()
	{
	}

	Level::~Level()
	{
	}

	void Level::OnInitialized()
	{
		m_hasInitialized = true;
	}

	void Level::BeginPlay()
	{
		for (std::shared_ptr<Actor>& actor : m_actors)
		{
			// BeginPlay가 이미 실행된 액터는 건너뛰기
			if (actor->HasBegunPlay())
			{
				continue;
			}

			actor->BeginPlay();
		}
	}

	void Level::Tick(float deltaTime)
	{
		for (std::shared_ptr<Actor>& actor : m_actors)
		{
			// 비활성화된 액터는 건너뛰기
			if (actor->IsActive() == false)
			{
				continue;
			}

			actor->Tick(deltaTime);
		}
	}

	void Level::Render()
	{
		for (std::shared_ptr<Actor>& actor : m_actors)
		{
			// 비활성화된 액터는 건너뛰기
			if (actor->IsActive() == false)
			{
				continue;
			}

			actor->Render();
		}
	}

	void Level::ProcessAddAndDestroyActors()
	{
		// 액터 제거
		for (auto iterator = m_actors.begin(); iterator != m_actors.end(); ++iterator)
		{
			if ((*iterator)->IsPendingDestroy())
			{
				iterator = m_actors.erase(iterator);
				continue;
			}
		}

		// 액터 추가
		if (m_pendingActors.empty())
		{
			return;
		}

		for (const std::shared_ptr<Actor>& actor : m_pendingActors)
		{
			m_actors.emplace_back(actor);
		}

		m_pendingActors.clear();
	}
}