all: LittleModule.sv ModuleInstantiateTest.sv ModuleInstantiateTest.result

%.sv : %.vs ../../VSharpC
	../../VSharpC $<

ModuleInstantiateTest.result : LittleModule.sv ModuleInstantiateTest.sv ../../VSharpC
	iverilog -o temp.vvpo LittleModule.sv ModuleInstantiateTest.sv
	vvp temp.vvpo > $@

