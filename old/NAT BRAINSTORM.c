task main()
{
	bool goLoop1 = true;
	bool goLoop2 = true;
	while (true)
	{
		//Loop 1
		while(goLoop1 == true)
		{
			//while(true) loop code
			wait1Msec(1);
			goLoop1 = false;
		}
		//Loop 2
		while(goLoop1 == false)
		{
			//while(true) loop code
			//wait1Msec
		}
	}
}
