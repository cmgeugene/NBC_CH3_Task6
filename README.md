## 내일배움캠프 Unreal 트랙 6번 과제
시연 영상 URL : https://youtu.be/3MTxpUJZnHQ

### 필수 기능
+ 서로 다른 동작 로직을 가진 Actor 클래스 2개 이상 구현
    + `MovingPlatform` - 수평이동을 하는 액터
    + `RotationgPlatform` - 회전이동을 하는 액터
    + `ScalingActor` - 커졌다 작아졌다를 반복하는 액터
+ `Tick`함수 기반 동적 Transform 변경
  + `GetActorLocation()`으로 액터의 현재 위치를 구하고 지정된 값을 `현재 위치`에 더함. 이후 매 프레임 `SetActorLocation(현재 위치)`로 이동을 구현
  + `AddActorLocalRotation`으로 지정된 방향으로 계속 회전값을 주도록 함.
  + 이동과 비슷하게 `GetActorScale3D`와 `SetActorScale3D` 로 크기 증가를 구현하였음.
+ 리플렉션 적용 - 주요 변수는 헤더 파일에서 `UPROPERTY()`로 선언하여 에디터상에서 수정, 변경 사항이 확인 가능하도록 하였음

### 도전 기능
+ 타이머 활용
  + `FTimerHandle`, `GetWorldTimerManager().SetTimer()` 을 활용하여 지정된 시간마다 특정 함수를 호출하도록 함.
  + 연속한 4개의 발판 중 홀수 번째 발판과 짝수 번째 발판이 번갈아 나타나도록 설정
+ 랜덤 퍼즐 생성
  + 게임 시작시(`BeginPlay()`에 구현) 플랫폼을 임의 좌표에 특정 갯수 스폰 되도록 함.
  + `FMath::RandRange` 와 `FMath::FRandRange`로 스폰 범위, 각도를 조절 가능

### 개인 구현 사항
+ 각 구현 사항마다 플래그를 설정하여 플래그에 따라 편도, 왕복 여부를 설정하도록 함
+ 랜덤 퍼즐을 생성하는 `SpawnActor.cpp`의 경우 에디터 상에서 스폰될 블루프린트를 설정할 수 있도록 `TSubClassOf` 를 사용하였음

### 진행 도중 겪었던 난관
+ `TSubClassOf`를 적용할 때 공식문서를 참고했음에도 리플렉션 적용이 바로 되지 않았음. 에디터와 VS를 모두 종료한 후 다시 빌드했더니 정상 작동함.
