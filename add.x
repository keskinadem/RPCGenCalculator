struct numbers{
	int a;
	int b;
	char op[5];
};

program OpProg{
	version ADD_VERS{
		int addF(numbers)=1;
		int subF(numbers)=2;
		int mulF(numbers)=3;
		int divF(numbers)=4;
	}=1;
}=0x1234567;
