// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncDelayNode.h"
UAsyncDelayNode* UAsyncDelayNode::BlueprintAsyncDelayNode(float Duration,UObject* Outer)
{
	auto Node = NewObject<UAsyncDelayNode>(Outer);
	Node->DelayDuration=Duration;
	return Node;
}

void UAsyncDelayNode::Activate()
{
	GetWorld()->GetTimerManager().SetTimer(DelayHandle,this,&UAsyncDelayNode::Execute,DelayDuration);
}

void UAsyncDelayNode::Execute()
{
	if (Finished.IsBound())
	{
		Finished.Broadcast();
	}
	SetReadyToDestroy();
}
