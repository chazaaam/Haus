
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "ksStpHist.h"
#ifdef __cplusplus
	};
#endif
/* speichert Schritthistorie */
void ksStepHistory(struct ksStepHistory* inst)
{
	if (inst->i >= MAX_IDX_STEP_HISTORY_ENTRIES)
	{
		inst->i = 0;
	}
	
	if (inst->in_Step.Act != inst->in_Step.Next)
	{
		inst->aData[inst->i].Act = inst->in_Step.Act;
		inst->aData[inst->i].ET = inst->in_ET;
		inst->i++;
	}
	
}
