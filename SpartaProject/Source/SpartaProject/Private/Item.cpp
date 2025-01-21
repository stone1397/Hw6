#include "Item.h"


AItem::AItem()
{
    // 씬 컴포넌트 생성
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    // 루트 컴포넌트로 만들기
    SetRootComponent(SceneRoot);

    // 스태틱 메시도 동일하게
    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    // 루트 컴포넌트의 자손으로 붙이기
    StaticMeshComp->SetupAttachment(SceneRoot);
    // 메시 적용
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Chair.SM_Chair"));
    if (MeshAsset.Succeeded())
    {
        StaticMeshComp->SetStaticMesh(MeshAsset.Object);
    }
    // 머터리얼 적용
    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
    if (MaterialAsset.Succeeded())
    {
        StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
    }

    // Tick 함수 사용을 위해 해야 할 것
    PrimaryActorTick.bCanEverTick = true;
    
    RotationSpeed = 90.0f;
}
void AItem::BeginPlay()
{
    // 부모 BeginPlay
    Super::BeginPlay();

    OnItemPickedUp(); 


    // 초기 transform 구현
    SetActorLocation(FVector(300.0f, 200.0f, 100.0f));
    SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
   // -pitch, yaw, roll (y축, z축, x축)
    SetActorScale3D(FVector(2.0f, 1.0f, 1.0f));

    FVector NewLocation(300.0f, 200.0f, 100.0f);
    FRotator NewRotation(90.0f, 0.0f, 0.0f);
    FVector NewScale(2.0f);

    FTransform NewTransform(NewRotation, NewLocation, NewScale);

    // 전체를 한 번에 바꾸는 함수
    SetActorTransform(NewTransform);
}

void AItem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //    AddActorLocalRotation(FRotator(0.0f, RotationSpeed, 0.0f));
        // 위 코드는 잘못되었다.
        // 매 프레임 호출되는 것이 문제 => 컴퓨터 사양에 영향을 받는다. => 프레임 독립적인 계산이 필요
        // 120 프레임 - 1초에 120번 호출 (DeltaTime = 1/120)
        // 30 프레임 - 1초에 30번 호출 (DeltaTime = 1/30)
        // => DeltaTime변수를 이용 (DeltaTime: 프레임당 시간)

    if (!FMath::IsNearlyZero(RotationSpeed))
    {
        AddActorLocalRotation(FRotator(RotationSpeed * DeltaTime, 0.0f, 0.0f));
    }
    // !FMath::IsNearlyZero(RotationSpeed)
    // 0에 가까운 값이어도 True (0.0000001 같은 것 때문에 조건문을 통과하지 못하는 것을 방지)
}
  
void AItem::ResetActorPosition()
{
    SetActorLocation(FVector::ZeroVector);
    // ZeroVector : 원점을 의미한다.
}

float AItem::GetRotationSpeed() const
{
    return RotationSpeed;
}

//OnItemPickedUp은 사실 내부에서 구현할 필요가 없다.





