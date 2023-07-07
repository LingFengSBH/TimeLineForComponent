// Copyright Sun BoHeng(LingFeng) 2023

#pragma once

#include "TimeLineForComponent.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncTimelineNode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTimeLineReady,UObject*,NodeObject);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTimeLineExecute);
UCLASS(BlueprintType)
class TIMELINEFORCOMPONENT_API UAsyncTimelineNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
	
	UPROPERTY(BlueprintAssignable,Category = "TimeLineForComponent")
	FTimeLineReady Ready;
	
	UPROPERTY(BlueprintAssignable,Category = "TimeLineForComponent")
	FTimeLineExecute Update;

	UPROPERTY(BlueprintAssignable,Category = "TimeLineForComponent")
	FTimeLineExecute Finished;
	
	UObject* MyOuter;

	UPROPERTY()
	FTimerHandle UpdateTimer;

	void ExecuteUpdateDelegate();

public:
	UPROPERTY(BlueprintReadWrite,Category = "TimeLineForComponent")
	float CurrentRatio;

	UPROPERTY(BlueprintReadWrite,Category = "TimeLineForComponent")
	bool bPlayBack;

	UPROPERTY(BlueprintReadWrite,Category = "TimeLineForComponent")
	bool bStop;

	float TimeLineLength;

	UFUNCTION(BlueprintCallable,BlueprintInternalUseOnly,Category = "TimeLineForComponent",meta=(HidePin="Outer",DefaultToSelf="Outer"))
	static UAsyncTimelineNode* BluepritAsyncTimeLineNode(float Length,UObject* Outer);

	UFUNCTION(BlueprintCallable,Category = "TimeLineForComponent")
	void Play();

	void Activate() override;
	
};
