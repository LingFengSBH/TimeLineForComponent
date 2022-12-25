// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncTimelineNode.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTimeLineReady,UObject*,NodeObject);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTimeLineExecute);
UCLASS(BlueprintType)
class TIMELINEFORCOMPONENT_API UAsyncTimelineNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
	
	UPROPERTY(BlueprintAssignable)
	FTimeLineReady Ready;
	
	UPROPERTY(BlueprintAssignable)
	FTimeLineExecute Update;

	UPROPERTY(BlueprintAssignable)
	FTimeLineExecute Finished;
	
	UObject* MyOuter;

	UPROPERTY()
	FTimerHandle UpdateTimer;

	void ExecuteUpdateDelegate();

public:
	UPROPERTY(BlueprintReadWrite)
	float CurrentRatio;

	UPROPERTY(BlueprintReadWrite)
	bool bPlayBack;

	UPROPERTY(BlueprintReadWrite)
	bool bStop;

	float TimeLineLength;

	UFUNCTION(BlueprintCallable,meta=(HidePin="Outer",DefaultToSelf="Outer"))
	static UAsyncTimelineNode* BluepritAsyncTimeLineNode(float Length,UObject* Outer);

	UFUNCTION(BlueprintCallable)
	void Play();

	void Activate() override;
	
};
