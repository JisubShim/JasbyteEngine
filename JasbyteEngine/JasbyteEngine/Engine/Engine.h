#pragma once
#include <memory>

namespace Jasbyte
{
	class Level;

	class Engine
	{
		// 엔진 설정
		struct EngineSettings
		{
			// 목표 프레임 속도
			int targetFPS = 120;
		};

	public:
		Engine();
		virtual ~Engine();

		// 싱글톤이므로 복사하지 않는다.
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;
		
		// 싱글톤 인스턴스를 반환한다.
		static Engine& Instance();

		// 게임 루프를 실행한다.
		void Run();

		// 엔진을 종료한다.
		void Quit();

		// 다음 프레임에 레벨을 로드한다.
		template<typename T, typename = std::enable_if_t<std::is_base_of<Level, T>::value>>
		void LoadLevel()
		{
			m_nextLevel = std::make_shared<T>();
		}

	protected:
		// 입력을 처리한다.
		void ProcessInput();

		// 레벨을 초기화한다.
		void OnInitialized();

		// 레벨의 액터를 초기화한다.
		void BeginPlay();

		// 매 프레임 상태를 갱신한다.
		void Tick(float deltaTime);

		// 화면을 그린다.
		void Render();

		// 이전 입력을 저장한다.
		void SavePreviousInput();

		// 엔진 종료 시 정리한다.
		void Shutdown();

	protected:
		// 엔진 설정
		EngineSettings m_settings;

		// 엔진 종료 플래그
		bool m_isQuitting = false;

		// 싱글톤 전역 객체
		static Engine* s_instance;

		// 메인 레벨
		std::shared_ptr<Level> m_currentLevel;

		// 추가 요청된 레벨
		std::shared_ptr<Level> m_nextLevel;
	};
}