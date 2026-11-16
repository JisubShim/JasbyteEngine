#include "Engine.h"
#include "Level/Level.h"
#include <iostream>
#include <Windows.h>
#include <stdint.h>
#include <assert.h>

namespace Jasbyte
{
	Engine* Engine::s_instance = nullptr;

	Engine::Engine()
	{
		if (s_instance != nullptr)
		{
			std::cerr << "Engine은 하나만 생성할 수 있습니다.\n";
			std::abort();
		}

		s_instance = this;
	}

	Engine::~Engine()
	{
		s_instance = nullptr;
	}

	void Engine::Run()
	{
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
				// 레벨의 액터 초기화
				BeginPlay();

				// 업데이트
				Tick(deltaTime);

				// 렌더링
				Render();

				// 레벨 전환
				if (m_nextLevel != nullptr)
				{
					// 전환 요청된 레벨을 현재 레벨로 설정
					m_currentLevel = std::move(m_nextLevel);

					// 레벨 초기화
					OnInitialized();
				}

				// 레벨 정리
				if (m_currentLevel != nullptr)
				{
					m_currentLevel->ProcessAddAndDestroyActors();
				}

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

	Engine& Engine::Instance()
	{
		assert(s_instance != nullptr);
		return *s_instance;
	}

	void Engine::ProcessInput()
	{
	}

	void Engine::OnInitialized()
	{
		if (m_currentLevel == nullptr)
		{
			return;
		}

		m_currentLevel->OnInitialized();
	}

	void Engine::BeginPlay()
	{
		if (m_currentLevel == nullptr)
		{
			return;
		}

		m_currentLevel->BeginPlay();
	}

	void Engine::Tick(float deltaTime)
	{
		if (m_currentLevel == nullptr)
		{
			return;
		}

		m_currentLevel->Tick(deltaTime);
	}

	void Engine::Render()
	{
		if (m_currentLevel == nullptr)
		{
			return;
		}
		m_currentLevel->Render();
	}

	void Engine::SavePreviousInput()
	{
	}

	void Engine::Shutdown()
	{
	}
}