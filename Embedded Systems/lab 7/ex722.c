char EEPROMread(unsigned int address)
{

	//wait for the completion of writes
	while(EECR & (1<<EEPE));


	//set up address
	EEAR = address;

	//start eeprom read
	EECR |= (1<<EERE);


	//return data
	return EEDR;
}