
TYPE
	GarageIO_typ : 	STRUCT 
		Input : GarageInput_typ;
		Output : GarageOutput_typ;
	END_STRUCT;
	GarageStat_typ : 	STRUCT 
		AutoClose : BOOL;
		TON_Nachlaufzeit : TON;
	END_STRUCT;
	GarageMem_typ : 	STRUCT 
		Schliesszeit : DATE_AND_TIME;
		SchliesszeitStruct : DTStructure;
		Nachlaufzeit : DINT;
		Automatik : BOOL;
	END_STRUCT;
	GarageInput_typ : 	STRUCT 
		Opened : BOOL;
		Closed : BOOL;
		Button : BOOL;
	END_STRUCT;
	GarageOutput_typ : 	STRUCT 
		Command : BOOL;
	END_STRUCT;
	GarageVisu_typ : 	STRUCT 
		ButtonActiveOpen : BOOL;
		ButtonActiveClose : BOOL;
	END_STRUCT;
END_TYPE
