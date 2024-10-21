
#include "ApplyRecoilAbilityTask.h"


UApplyRecoilAbilityTask* UApplyRecoilAbilityTask::CreateReduceRecoilTask(UGameplayAbility* OwningAbility, float InitialOffset, float Duration)
{
    UApplyRecoilAbilityTask* MyTask = NewAbilityTask<UApplyRecoilAbilityTask>(OwningAbility);
    MyTask->CurrentOffset = InitialOffset;
    MyTask->TargetOffset = 0.0f;
    MyTask->ReductionRate = InitialOffset / Duration;
    return MyTask;
}

void UApplyRecoilAbilityTask::Activate()
{
    // Initialize the task, maybe play some VFX/SFX
}

void UApplyRecoilAbilityTask::TickTask(float DeltaTime)
{
    if (CurrentOffset > TargetOffset)
    {
        CurrentOffset -= ReductionRate * DeltaTime;
        // Update weapon offset here
    }
    else
    {
        //OnRecoilReduced.Execute();// Broadcast();
        EndTask();
    }
}