
#include <bur/plctypes.h>
#include <stdbool.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{

}

void _CYCLIC ProgramCyclic(void)
{
	DTGetTime_1.enable = true;
	DTGetTime(&DTGetTime_1);
	
	gCurrentDT = DTGetTime_1.DT1;
}

void _EXIT ProgramExit(void)
{

}

