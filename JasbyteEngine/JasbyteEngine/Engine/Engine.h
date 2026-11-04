#pragma once

namespace Jasbyte
{
	class Engine
	{
		/// <summary>
		/// 엔진 설정
		/// </summary>
		struct EngineSettings
		{
			/// <summary>
			/// 목표 프레임 속도
			/// </summary>
			int targetFPS = 120;
		};

	public:
		Engine();
		virtual ~Engine();

		/// <summary>
		/// 게임 루프를 실행한다.
		/// </summary>
		void Run();

		/// <summary>
		/// 엔진을 종료한다.
		/// </summary>
		void Quit();

		/// <summary>
		/// 싱글톤 인스턴스를 반환한다.
		/// </summary>
		static Engine& Instance();

	protected:
		/// <summary>
		/// 입력을 처리한다.
		/// </summary>
		void UpdateInput();

		/// <summary>
		/// 게임 루프 시작 전에 한 번 초기화한다.
		/// </summary>
		void Initialize();

		/// <summary>
		/// 매 프레임 상태를 갱신한다.
		/// </summary>
		void Update(float deltaTime);

		/// <summary>
		/// 화면을 그린다.
		/// </summary>
		void Render();

		/// <summary>
		/// 이전 입력을 저장한다.
		/// </summary>
		void SavePreviousInput();

		/// <summary>
		/// 엔진 종료 시 정리한다.
		/// </summary>
		void Shutdown();

	protected:
		/// <summary>
		/// 엔진 설정
		/// </summary>
		EngineSettings m_settings;

		/// <summary>
		/// 엔진 종료 플래그
		/// </summary>
		bool m_isQuitting = false;

		/// <summary>
		/// 싱글톤 전역 객체
		/// </summary>
		static Engine* s_instance;
	};
}
