
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
	
	DT_TO_DTStructure(gCurrentDT, (UDINT)&gCurrentDTStruct);
	
	//Email Sender initialisieren
	
//	gSmtpSend.enable= true;
	gSmtpSend.pHost= (UDINT)"smtp.gmail.com";
	gSmtpSend.pSender= (UDINT)"sdillinger.tai@gmail.com"; 
	gSmtpSend.pReceiver= (UDINT)"mihawk14@web.de";
	gSmtpSend.pSubject= (UDINT)"test";
	gSmtpSend.pText= (UDINT)"test";
//	gSmtpSend.pUser = (UDINT)"sdillinger.tai@gmail.com"; 
//	gSmtpSend.pPassword= ADR(gMAIL.smpt_pw) // 'mein GMX Passwort'
//	gSmtpSend.pAttachment= ADR(AttStruc) // momentan 0
//	gSmtpSend.pDomain= 0
//	gSmtpSend.pSecurity= 0
//	gSmtpSend.timeout= 0
	gSmtpSend.port = 465; // 485,0, 0der 25
//	SmtpSend(&gSmtpSend);
}

void _EXIT ProgramExit(void)
{

}

