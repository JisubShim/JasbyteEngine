#include "Engine.h"
#include <iostream>
#include <Windows.h>
#include <stdint.h>
#include <assert.h>

namespace Jasbyte
{
	Engine* Engine::s_instance = nullptr;

	Engine::Engine()
	{
		assert(!s_instance);
		s_instance = this;
	}

	Engine::~Engine()
	{
		s_instance = nullptr;
	}

	void Engine::Run()
	{
		// 초기화
		Initialize();

		LARGE_INTEGER frequency;
		LARGE_INTEGER counter;

		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&counter);

		int64_t currentTicks = counter.QuadPart;
		int64_t previousTicks = currentTicks;

		// 목표 프레임 시간
		float targetFrameTime = 1.0f / m_settings.targetFPS;

		while (m_isQuitting == false)
		{
			// 입력 처리
			ProcessInput();

			// 현재 시간 확인 및 저장
			QueryPerformanceCounter(&counter);
			currentTicks = counter.QuadPart;

			// 이전 프레임 이후 지난 시간
			float deltaTime = static_cast<float>(currentTicks - previousTicks) / static_cast<float>(frequency.QuadPart);

			if (deltaTime >= targetFrameTime) // 프레임 제한
			{
				// 업데이트
				Tick(deltaTime);

				// 렌더링
				Render();

				// 처리된 입력을 이전 프레임 입력으로 저장
				SavePreviousInput();

				// 이전 프레임 시간 기록
				previousTicks = currentTicks;
			}
		}

		// 엔진 리소스 정리
		Shutdown();
	}

	void Engine::Quit()
	{
		m_isQuitting = true;
	}

	void Engine::ProcessInput()
	{
	}

	void Engine::Initialize()
	{
	}

	void Engine::Tick(float deltaTime)
	{
		std::cout << "delta time: " << deltaTime << ", FPS: " << 1.0f / deltaTime << '\n';
	}

	void Engine::Render()
	{
	}

	void Engine::SavePreviousInput()
	{
	}

	void Engine::Shutdown()
	{
	}
}
