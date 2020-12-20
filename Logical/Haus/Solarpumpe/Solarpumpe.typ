
TYPE
	SolarpumpeIO_typ : 	STRUCT 
		Input : SolarpumpeInputs_typ;
		Output : SolarpumpeOutputs_typ;
	END_STRUCT;
	SolarpumpeInputs_typ : 	STRUCT 
		DachTemp : INT;
		RuecklaufTemp : INT;
		KesselTemp : INT;
	END_STRUCT;
	SolarpumpeOutputs_typ : 	STRUCT 
		PumpeDown : BOOL;
		PumpeUp : BOOL;
	END_STRUCT;
	SolarpumpeVisu_typ : 	STRUCT 
		PumpeUpStyle : STRING[99];
		PumpeDownStyle : STRING[99];
	END_STRUCT;
	SolarpumpeInfo_typ : 	STRUCT 
		LaufzeitDownAkt : DINT;
		LaufzeitUpAkt : DINT;
		LaufzeitDownGes : DINT;
		LaufzeitUpGes : DINT;
		LastStart : DATE_AND_TIME;
		LastStop : DATE_AND_TIME;
	END_STRUCT;
	SolarpumpeMem_typ : 	STRUCT 
		DachSollTemp : INT;
		KesselSollTemp : INT;
		RuecklaufSollTemp : INT;
		Aktiv : BOOL;
		RuecklaufTimeOffset : DATE_AND_TIME;
	END_STRUCT;
END_TYPE
