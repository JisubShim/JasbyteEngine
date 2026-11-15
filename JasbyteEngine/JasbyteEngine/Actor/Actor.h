#pragma once

#include <memory>

namespace Jasbyte
{
	class Level;

	class Actor
	{
	public:
		Actor();
		virtual ~Actor();

#pragma region Game Loop Events
		// 첫 Tick 전에 한 번 실행한다.
		virtual void BeginPlay();

		// 매 프레임 상태를 갱신한다.
		virtual void Tick(float deltaTime);

		// 화면을 그린다.
		virtual void Render();
#pragma endregion

		// 액터를 레벨에서 제거한다.
		void Destroy();

		inline bool HasBegunPlay() const { return m_hasBegunPlay; }
		inline bool IsActive() const { return m_isActive && !m_isPendingDestroy; }
		inline bool IsPendingDestroy() const { return m_isPendingDestroy; }

		std::shared_ptr<Level> GetOwner();
		void SetOwner(std::weak_ptr<Level> newOwner);

	protected:
		// BeginPlay 이벤트 처리 여부 플래그
		bool m_hasBegunPlay = false;

		// 액터 활성화 여부 플래그
		bool m_isActive = true;

		// 액터 삭제 예약 플래그
		bool m_isPendingDestroy = false;

		// 오너십: 액터를 소유하는 레벨 객체
		std::weak_ptr<Level> m_owner;
	};
}