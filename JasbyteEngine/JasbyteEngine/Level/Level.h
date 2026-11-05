#pragma once

namespace Jasbyte
{
	// 모든 게임 레벨의 부모 클래스이며, 게임에 배치되는 액터 관리
	class Level
	{
	public:
		Level();
		virtual ~Level();

		// 레벨을 초기화한다.
		virtual void Initialize();

#pragma region Frame Event API
		// 첫 Tick 전에 한 번 실행한다.
		virtual void Start();

		// 매 프레임 상태를 갱신한다.
		virtual void Tick(float deltaTime);

		// 화면을 그린다.
		virtual void Render();
#pragma endregion

		// 레벨 초기화 여부를 확인한다.
		inline bool HasInitialized() const { return m_hasInitialized;  }

	protected:
		// 레벨 초기화 여부 플래그
		bool m_hasInitialized = false;
	};
}
