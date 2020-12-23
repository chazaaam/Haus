
TYPE
	ErrorHandlingVisu_typ : 	STRUCT 
		AlarmVisible : BOOL;
		ErrorAktiv : BOOL;
		WarningAktiv : BOOL;
		InfoAktiv : BOOL;
		AlarmConfigString : STRING[1000];
		FooterImage : STRING[255];
	END_STRUCT;
	ActiveAlarms_type : 	STRUCT 
		Error : ActiveAlarmsConfig_type;
		Warning : ActiveAlarmsConfig_type;
		Info : ActiveAlarmsConfig_type;
		CountAll : UINT;
		Visible : BOOL;
	END_STRUCT;
	ActiveAlarmsConfig_type : 	STRUCT 
		UpdateFlag : UDINT;
		UpdateFlagOld : UDINT;
		ActiveAlarms : ARRAY[0..999]OF STRING[100];
		Count : UINT;
	END_STRUCT;
END_TYPE
