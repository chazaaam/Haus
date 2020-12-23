
#include <bur/plctypes.h>
#include <stdbool.h>
#include <string.h>
#include <AsBrStr.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{    
//	MpAlarmXSet(&gAlarmXCore, StackerAlarmStrings[z].Name[i]);
//               
//	MpAlarmXReset(&gAlarmXCore, StackerAlarmStrings[z].Name[i]);
    
}

void _CYCLIC ProgramCyclic(void)
{
    /* Alarmsystem */
    MpAlarmXCore_1.MpLink = &gAlarmXCore;
    MpAlarmXCore_1.Enable = true;
    MpAlarmXCore_1.ErrorReset = ResetMpError;
    MpAlarmXCore(&MpAlarmXCore_1);  
                    
    Visu.AlarmVisible = (MpAlarmXCore_1.PendingAlarms != 0);
    
    // AlarmConfig
    brsstrcpy((UDINT)Visu.AlarmConfigString, (UDINT)ALARMLIST_CONFIG); 
    
    // Überprüfen welche Severities aktiv sind
    Visu.ErrorAktiv = false;
    Visu.WarningAktiv = false;
    Visu.InfoAktiv = false;
    if(MpAlarmXCheckReaction(&gAlarmXCore, "ErrorAktiv"))
        Visu.ErrorAktiv = true;
    else if(MpAlarmXCheckReaction(&gAlarmXCore, "WarningAktiv"))
        Visu.WarningAktiv = true;
    else if(MpAlarmXCheckReaction(&gAlarmXCore, "InfoAktiv"))
        Visu.InfoAktiv = true;
        
    // Auswertung Aktiver Alarme
    // Error
    MpAlarmXQuery_0.MpLink = &gAlarmXCore;;
    MpAlarmXQuery_0.Enable = true;
    MpAlarmXQuery_0.ErrorReset = ResetMpError;
    MpAlarmXQuery_0.Mode = mpALARMX_QUERY_MODE_ALL ;
    MpAlarmXQuery_0.Name = (UDINT)"ActiveErrors";
    MpAlarmXQuery_0.Execute = (ActiveAlarms.Error.UpdateFlag != ActiveAlarms.Error.UpdateFlagOld);
    MpAlarmXQuery(&MpAlarmXQuery_0);
   
    if(MpAlarmXQuery_0.CommandDone)
    {
        ActiveAlarms.Error.Count = MpAlarmXQuery_0.Info.RowsRead;
        ActiveAlarms.Error.UpdateFlagOld = ActiveAlarms.Error.UpdateFlag;
    }
    
    // Warning
    MpAlarmXQuery_1.MpLink = &gAlarmXCore;;
    MpAlarmXQuery_1.Enable = true;
    MpAlarmXQuery_1.ErrorReset = ResetMpError;
    MpAlarmXQuery_1.Mode = mpALARMX_QUERY_MODE_ALL ;
    MpAlarmXQuery_1.Name = (UDINT)"ActiveWarnings";
    MpAlarmXQuery_1.Execute = (ActiveAlarms.Warning.UpdateFlag != ActiveAlarms.Warning.UpdateFlagOld);
    MpAlarmXQuery(&MpAlarmXQuery_1);
    
    if(MpAlarmXQuery_1.CommandDone)
    {
        ActiveAlarms.Warning.Count = MpAlarmXQuery_1.Info.RowsRead;
        ActiveAlarms.Warning.UpdateFlagOld = ActiveAlarms.Warning.UpdateFlag;
    }
    
    // Info
    MpAlarmXQuery_2.MpLink = &gAlarmXCore;;
    MpAlarmXQuery_2.Enable = true;
    MpAlarmXQuery_2.ErrorReset = ResetMpError;
    MpAlarmXQuery_2.Mode = mpALARMX_QUERY_MODE_ALL ;
    MpAlarmXQuery_2.Name = (UDINT)"ActiveInfos";
    MpAlarmXQuery_2.Execute = (ActiveAlarms.Info.UpdateFlag != ActiveAlarms.Info.UpdateFlagOld);
    MpAlarmXQuery(&MpAlarmXQuery_2);
    
    if(MpAlarmXQuery_2.CommandDone)
    {
        ActiveAlarms.Info.Count = MpAlarmXQuery_2.Info.RowsRead;
        ActiveAlarms.Info.UpdateFlagOld = ActiveAlarms.Info.UpdateFlag;
    }
    
    ActiveAlarms.CountAll = ActiveAlarms.Error.Count + ActiveAlarms.Warning.Count + ActiveAlarms.Info.Count;
    ActiveAlarms.Visible = (ActiveAlarms.CountAll != 0);
        
    if(Visu.ErrorAktiv)
        brsstrcpy((UDINT)Visu.FooterImage, (UDINT)"Media/Images/BHS/Alarme/224_Warning_act.svg");
    else if(Visu.WarningAktiv)
        brsstrcpy((UDINT)Visu.FooterImage, (UDINT)"Media/Images/BHS/Alarme/226_Attention_act.svg");
    else if(Visu.InfoAktiv)
        brsstrcpy((UDINT)Visu.FooterImage, (UDINT)"Media/Images/BHS/Alarme/180_Maintenance_act.svg");
    else
        brsstrcpy((UDINT)Visu.FooterImage, (UDINT)"Media/Images/BHS/Alarme/224_Warning_ena.svg");
	
	
        
}

void _EXIT ProgramExit(void)
{
    MpAlarmXCore_1.Enable = false;
    MpAlarmXCore(&MpAlarmXCore_1);  
}
