
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
	
	DT_TO_DTStructure(Mem.Schliesszeit, (UDINT)&Mem.SchliesszeitStruct);

	IO.Output.Command = IO.Input.Button || Stat.AutoClose;	
	
	if(IO.Input.Closed || IO.Input.Opened)
	{
		Visu.ButtonActiveOpen = IO.Input.Closed;
		Visu.ButtonActiveClose = IO.Input.Opened;
	}
	else
	{
		Visu.ButtonActiveOpen = true;
		Visu.ButtonActiveClose = true;
	}
	
	if(Mem.Automatik)
	{
		if(Mem.Nachlaufzeit != 0)
		{
			Stat.TON_Nachlaufzeit.IN = IO.Input.Opened;
			Stat.TON_Nachlaufzeit.PT = Mem.Nachlaufzeit;
			TON(&Stat.TON_Nachlaufzeit);
		}
		else
		{
			Stat.TON_Nachlaufzeit.IN = false;
			TON(&Stat.TON_Nachlaufzeit);
		}
		
		if((Mem.SchliesszeitStruct.hour == gCurrentDTStruct.hour && 
			Mem.SchliesszeitStruct.minute == gCurrentDTStruct.minute && 
			Mem.SchliesszeitStruct.second == gCurrentDTStruct.second) ||
			Stat.TON_Nachlaufzeit.Q)
		{
			Stat.AutoClose = true;
		}
		else
		{
			Stat.AutoClose = false;	
		}
		
	}
	else
	{
		Stat.AutoClose = false;	
	}
	
}

void _EXIT ProgramExit(void)
{

}

