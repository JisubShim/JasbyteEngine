#pragma once

#include "Actor/Actor.h"
#include <vector>
#include <memory>

namespace Jasbyte
{
	// 모든 게임 레벨의 부모 클래스이며, 게임에 배치되는 액터 관리
	class Level : public std::enable_shared_from_this<Level>
	{
		friend class Engine;

	public:
		Level();
		virtual ~Level();

		// 레벨을 초기화한다.
		virtual void OnInitialized();

#pragma region Game Loop Events
		// 첫 Tick 전에 한 번 실행한다.
		virtual void BeginPlay();

		// 매 프레임 상태를 갱신한다.
		virtual void Tick(float deltaTime);

		// 화면을 그린다.
		virtual void Render();
#pragma endregion

		// 액터 생성 함수 템플릿
		template<typename T, typename ...Args, typename = std::enable_if_t<std::is_base_of<Actor, T>::value>>
		std::shared_ptr<T> SpawnActor(Args... args)
		{
			// 새로운 액터 객체 생성
			std::shared_ptr<T> newActor = std::make_shared<T>(std::forward<Args>(args)...);

			m_pendingActors.emplace_back(newActor);

			// 오너십 생성
			newActor->SetOwner(shared_from_this());

			return newActor;
		}

		// 레벨 초기화 여부를 확인한다.
		inline bool HasInitialized() const { return m_hasInitialized;  }

	protected:
		// 이전 프레임에 추가/제거 요청된 액터 처리 함수
		void ProcessAddAndDestroyActors();

	protected:
		// 레벨 초기화 여부 플래그
		bool m_hasInitialized = false;

		// 레벨에 배치된 모든 액터
		std::vector<std::shared_ptr<Actor>> m_actors;

		// 레벨에 추가 요청된 액터
		// 현재 프레임을 안정적으로 처리한 후에 액터 추가 처리
		std::vector<std::shared_ptr<Actor>> m_pendingActors;
	};
}
