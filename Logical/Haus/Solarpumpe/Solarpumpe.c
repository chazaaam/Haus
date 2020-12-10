
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
	if(IO.Output.PumpeDown)
		brsstrcpy((UDINT)Visu.PumpeDownStyle, (UDINT)"StatusOk");
	else
		brsstrcpy((UDINT)Visu.PumpeDownStyle, (UDINT)"StatusNOk");
	
	if(IO.Output.PumpeUp)
		brsstrcpy((UDINT)Visu.PumpeUpStyle, (UDINT)"StatusOk");
	else
		brsstrcpy((UDINT)Visu.PumpeUpStyle, (UDINT)"StatusNOk");
	
	UDINTTimeOffset = Mem.RuecklaufTimeOffset;
	
	TON_PumpUp.IN = IO.Output.PumpeDown;
	TON_PumpUp.PT = UDINTTimeOffset * 1000;
	TON(&TON_PumpUp);
	
	if(Mem.Aktiv)
	{
		if(IO.Input.DachTemp >= Mem.DachSollTemp && IO.Input.KesselTemp <= Mem.KesselSollTemp)
		{
			IO.Output.PumpeDown = true;
			
			if(TON_PumpUp.Q && IO.Input.RuecklaufTemp <= Mem.RuecklaufSollTemp)
			{
				IO.Output.PumpeUp = true;	
			}
		}
		else
		{
			IO.Output.PumpeDown = false;
			IO.Output.PumpeUp = false;
		}
		
		
	}		
	else
	{
		IO.Output.PumpeDown = false;
		IO.Output.PumpeUp = false;
	}
}

void _EXIT ProgramExit(void)
{

}

