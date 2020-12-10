
#include <bur/plctypes.h>
#include <stdbool.h>
#include <AsBrStr.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
    DirCreate_DV.enable = true;
    DirCreate_DV.pDevice = (UDINT)"Home";
    DirCreate_DV.pName = (UDINT)"Datenverwaltung";
    DirCreate(&DirCreate_DV);
    
    DTGetTime_DV.enable = true;
    DTGetTime(&DTGetTime_DV);

    Visu.StatusTime = DTGetTime_DV.DT1;
    brsstrcpy((UDINT)Visu.StatusText, (UDINT)"Steuerung neu gestartet");
    
    FileInfo_0.enable = true;
    FileInfo_0.pDevice = (UDINT)"Datenverwaltung";
    FileInfo_0.pName = (UDINT)"DV.csv";
    FileInfo_0.pInfo = (UDINT)&pFileInfo;
    FileInfo(&FileInfo_0);

    Visu.Load = true;
    
}

void _CYCLIC ProgramCyclic(void)
{
    DTGetTime_DV.enable = true;
    DTGetTime(&DTGetTime_DV);

    MpRecipeCsv_DV.MpLink = &gRecipeCsv;
    MpRecipeCsv_DV.Enable = true;
    MpRecipeCsv_DV.Save = Visu.Save;
    MpRecipeCsv_DV.Load = Visu.Load;
    MpRecipeCsv_DV.DeviceName = (UDINT)"Datenverwaltung";
    MpRecipeCsv_DV.FileName = (UDINT)"DV";
    MpRecipeCsv(&MpRecipeCsv_DV);
    
    
    for(i=0;i<=MAX_DV;i++)
    {
        MpRecipeRegPar_DV[i].MpLink = &gRecipeCsv;
        MpRecipeRegPar_DV[i].Enable = true;
        MpRecipeRegPar_DV[i].PVName = (UDINT)&PVNames[i];
        MpRecipeRegPar(&MpRecipeRegPar_DV[i]);
    } 
        
    switch(State)
    {
        case STATE_DV_WAIT: 
            Visu.ButtonAktiv = true;
            if(Visu.Save)
            {
                Visu.ButtonAktiv = false;
                State = STATE_DV_SAVE;
            }
            else if(Visu.Load)
            {
                Visu.ButtonAktiv = false;
                State = STATE_DV_LOAD;
            }
            
            break;
        
        case STATE_DV_SAVE:
            if(MpRecipeCsv_DV.CommandDone)
            {
                Visu.StatusTime = DTGetTime_DV.DT1;
                brsstrcpy((UDINT)Visu.StatusText, (UDINT)"Speichern abgeschlossen");
                Visu.Save = false;
                State = STATE_DV_WAIT;
            }
            
            break;
        
        case STATE_DV_LOAD:
            if(MpRecipeCsv_DV.CommandDone)
            {       
                Visu.StatusTime = DTGetTime_DV.DT1;     
                brsstrcpy((UDINT)Visu.StatusText, (UDINT)"Laden abgeschlossen");
                Visu.Load = false;
                State = STATE_DV_WAIT;
            }
            
            break;
           
    }  
  
}


void _EXIT ProgramExit(void)
{
    MpRecipeCsv_DV.Enable = false;
    MpRecipeCsv(&MpRecipeCsv_DV);
    
//    for(i=0;i<=MAX_DV;i++)
//    {
//        MpRecipeRegPar_DV[i].Enable = false;
//        MpRecipeRegPar(&MpRecipeRegPar_DV[i]);
//    }
}

