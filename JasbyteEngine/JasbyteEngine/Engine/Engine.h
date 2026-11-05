#pragma once

namespace Jasbyte
{
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

		// 게임 루프를 실행한다.
		void Run();

		// 엔진을 종료한다.
		void Quit();

		// 싱글톤 인스턴스를 반환한다.
		static Engine& Instance();

	protected:
		// 입력을 처리한다.
		void ProcessInput();

		// 게임 루프 시작 전에 한 번 초기화한다.
		void Initialize();

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
	};
}
