// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncDelayNode.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDelayFinished);
UCLASS()
class TIMELINEFORCOMPONENT_API UAsyncDelayNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	UPROPERTY(BlueprintAssignable)
	FOnDelayFinished Finished;

	UFUNCTION(BlueprintCallable,meta=(HidePin="Outer",DefaultToSelf="Outer"))
	static UAsyncDelayNode* BlueprintAsyncDelayNode(float Duration,UObject* Outer);
private:
	FTimerHandle DelayHandle;
	float DelayDuration;
	
	void Execute();
	void Activate() override;
};
