
TYPE
	KsStepData_type : 	STRUCT 
		Last : DINT;
		Act : DINT;
		Next : DINT; (*nur f�r single step*)
		Reset : DINT; (*step after reset*)
	END_STRUCT;
	ksStepHistoryEntry : 	STRUCT 
		Act : USINT;
		ET : TIME;
	END_STRUCT;
END_TYPE
