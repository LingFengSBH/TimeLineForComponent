// Copyright Sun BoHeng(LingFeng) 2023


#include "AsyncTimelineNode.h"

UAsyncTimelineNode* UAsyncTimelineNode::BluepritAsyncTimeLineNode(float Length,UObject* Outer)
{
	auto Node = NewObject<UAsyncTimelineNode>(Outer);
	Node->MyOuter=Outer;
	Node->TimeLineLength=Length;
	return Node;
}

void UAsyncTimelineNode::Activate()
{
	CurrentRatio = 0;
	Ready.Broadcast(this);
	//GetWorld()->GetTimerManager().SetTimer(UpdateTimer,this,&UTimeLineNode::ExecuteUpdateDelegate,TimerRate,true);
}

void UAsyncTimelineNode::ExecuteUpdateDelegate()
{
	if(bStop)
	{
		return;
	}
	CurrentRatio += GetWorld()->DeltaTimeSeconds/TimeLineLength*(bPlayBack?-1:1);
	if (CurrentRatio>=1&&bPlayBack==false)
	{
		CurrentRatio=1;
		Update.Broadcast();
		Finished.Broadcast();
	}
	else if (CurrentRatio<=0&&bPlayBack)
	{
		CurrentRatio=0;
		Update.Broadcast();
		Finished.Broadcast();
	}
	else
	{
		Update.Broadcast();
		GetWorld()->GetTimerManager().SetTimerForNextTick(this,&UAsyncTimelineNode::ExecuteUpdateDelegate);
	}
}

void UAsyncTimelineNode::Play()
{
	GetWorld()->GetTimerManager().SetTimerForNextTick(this,&UAsyncTimelineNode::ExecuteUpdateDelegate);
}
