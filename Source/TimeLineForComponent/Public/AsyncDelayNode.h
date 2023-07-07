// Copyright Sun BoHeng(LingFeng) 2023

#pragma once

#include "TimeLineForComponent.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncDelayNode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDelayFinished);
UCLASS()
class TIMELINEFORCOMPONENT_API UAsyncDelayNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	UPROPERTY(BlueprintAssignable,Category = "TimeLineForComponent")
	FOnDelayFinished Finished;

	UFUNCTION(BlueprintCallable,BlueprintInternalUseOnly,Category = "TimeLineForComponent",meta=(HidePin="Outer",DefaultToSelf="Outer"))
	static UAsyncDelayNode* BlueprintAsyncDelayNode(float Duration,UObject* Outer);
private:
	FTimerHandle DelayHandle;
	float DelayDuration;
	
	void Execute();
	void Activate() override;
};
