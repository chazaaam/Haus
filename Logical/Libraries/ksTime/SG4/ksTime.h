/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _KSTIME_
#define _KSTIME_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifdef _SG4
		#include "astime.h"
#endif
#ifdef _SG3
		#include "astime.h"
#endif
#ifdef _SGC
		#include "astime.h"
#endif

/* Datatypes and datatypes of function blocks */
typedef struct Stopwatch
{
	/* VAR_OUTPUT (analog) */
	plctime Elapsed;
	/* VAR (analog) */
	plctime i_StartTime;
	/* VAR_INPUT (digital) */
	plcbit Start;
	plcbit Reset;
} Stopwatch_typ;

typedef struct Timer
{
	/* VAR_INPUT (analog) */
	plctime Time;
	/* VAR_OUTPUT (analog) */
	plctime Elapsed;
	/* VAR (analog) */
	plctime i_StartTime;
	/* VAR_INPUT (digital) */
	plcbit Start;
	plcbit Reset;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
} Timer_typ;



/* Prototyping of functions and function blocks */
void Stopwatch(struct Stopwatch* inst);
void Timer(struct Timer* inst);
plcbit Stopwatch_Start(struct Stopwatch* inst);
unsigned char Stopwatch_Reset(struct Stopwatch* inst);
unsigned long Stopwatch_Stop(struct Stopwatch* inst);
plcbit Timer_Start(struct Timer* inst);
plcbit Timer_Reset(struct Timer* inst);
plcbit Timer_Stop();


#ifdef __cplusplus
};
#endif
#endif /* _KSTIME_ */

