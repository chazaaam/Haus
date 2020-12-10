(********************************************************************
 * COPYRIGHT -- KS Control GmbH
 ********************************************************************
 * Library: ksTime
 * File: ksTime.fun
 * Author: JObermeier
 * Created: March 19, 2011
 ********************************************************************
 * Functions and function blocks of library ksTime
 ********************************************************************)

FUNCTION_BLOCK Stopwatch
	VAR_INPUT
		Start : BOOL;
		Reset : BOOL;
	END_VAR
	VAR_OUTPUT
		Elapsed : TIME;
	END_VAR
	VAR
		i_StartTime : TIME;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION Stopwatch_Start : BOOL (*Returns true if done*)
	VAR_INPUT
		inst : Stopwatch;
	END_VAR
END_FUNCTION

FUNCTION Stopwatch_Reset : USINT (*Returns true if done*)
	VAR_INPUT
		inst : Stopwatch;
	END_VAR
END_FUNCTION

FUNCTION Stopwatch_Stop : UDINT (*Returns elapsed time in ms*)
	VAR_INPUT
		inst : Stopwatch;
	END_VAR
END_FUNCTION

FUNCTION_BLOCK Timer
	VAR_INPUT
		Start : BOOL;
		Reset : BOOL;
		Time : TIME;
	END_VAR
	VAR_OUTPUT
		Elapsed : TIME;
		Done : BOOL;
	END_VAR
	VAR
		i_StartTime : TIME;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION Timer_Start : BOOL (*Returns true if done*)
	VAR_INPUT
		inst : Timer;
	END_VAR
END_FUNCTION

FUNCTION Timer_Reset : BOOL (*Returns true if done*)
	VAR_INPUT
		inst : Timer;
	END_VAR
END_FUNCTION

FUNCTION Timer_Stop : BOOL (*Returns true if done*)
END_FUNCTION
