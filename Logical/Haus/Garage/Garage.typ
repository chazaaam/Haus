
TYPE
	GarageIO_typ : 	STRUCT 
		Input : GarageInput_typ;
		Output : GarageOutput_typ;
	END_STRUCT;
	GarageInput_typ : 	STRUCT 
		Opened : BOOL;
		Closed : BOOL;
	END_STRUCT;
	GarageOutput_typ : 	STRUCT 
		Open : BOOL;
		Close : BOOL;
	END_STRUCT;
END_TYPE
