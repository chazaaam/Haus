
TYPE
	STATE_DV_enum : 
		(
		STATE_DV_WAIT,
		STATE_DV_SAVE,
		STATE_DV_LOAD
		);
	DatenverwaltungVisu_typ : 	STRUCT 
		Save : BOOL;
		Load : BOOL;
		ButtonAktiv : BOOL;
		StatusText : STRING[255];
		StatusTime : DATE_AND_TIME;
	END_STRUCT;
END_TYPE
