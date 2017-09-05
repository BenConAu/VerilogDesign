struct TestStruct
{
  uint32 Member1;
}

module MemoryController(uint32 in1)
{
  TestStruct p1;

  clock clk;

	drive
	{
		100: __finish;
	}

  TestStruct Func1(uint32 pageNumber)
  {
      return p1;
  }

  void Func2(TestStruct foo)
  {
		  __monitor("Member = %h", foo.Member1);
  }

  state initial
  {
    if (Func1(0).Member1 == 0)
    {
      Func2(p1);
    }
  }
}