# 코딩 컨벤션

## 이름 규칙

| 대상 | 규칙 | 예시 |
|---|---|---|
| 클래스, 구조체, enum | PascalCase | `Engine`, `EngineSettings` |
| 함수 | PascalCase | `UpdateInput()` |
| 지역 변수, 매개변수 | camelCase | `deltaTime` |
| bool 변수 | `is`, `has`, `can` + camelCase | `isQuitting` |
| 클래스 멤버 변수 (`private`, `protected`) | `m_` + camelCase | `m_settings` |
| static 멤버 변수 | `s_` + camelCase | `s_instance` |
| 데이터 구조체의 공개 필드 | camelCase, 접두사 없음 | `targetFrameRate` |
| 상수 | `k` + PascalCase | `kMaxEntities` |
| 파일 | 클래스 이름과 동일 | `Engine.h`, `Engine.cpp` |
| 네임스페이스 | PascalCase | `Jasbyte` |

- 접근 수준은 이름에 넣지 않는다.
- `_`로 시작하는 이름은 쓰지 않는다.

## 주석

- 선언 설명은 `/// <summary>` 형식으로 쓴다.
- 주석은 너무 세세하게 달지 않고, 핵심만 간단히 적는다.
- 함수 주석은 `~한다.` 문장으로 쓴다. 예: `게임 루프를 실행한다.`
- 변수 주석은 마침표 없는 명사형으로 쓴다. 예: `엔진 종료 플래그`
- `~하는 함수`처럼 선언만 봐도 알 수 있는 말은 쓰지 않는다.

### 예시
```cpp
/// <summary>
/// 게임 루프를 실행한다.
/// </summary>
void Run();

/// <summary>
/// 엔진 종료 플래그
/// </summary>
bool m_isQuitting = false;
```

## 중괄호

- 여는 중괄호는 항상 다음 줄에 쓴다 (Allman 스타일).
- 함수, 클래스, 네임스페이스, `if`, `for`, `while`에 모두 적용한다.

### 예시
```cpp
int main()
{
}
```

## 코드 작성

- 소유하는 포인터는 `std::unique_ptr`, raw 포인터는 빌려 쓸 때만 사용한다.
- `enum` 대신 `enum class`를 사용한다.
- 헤더에 `using namespace`를 쓰지 않고, 가능하면 전방 선언으로 include를 줄인다.