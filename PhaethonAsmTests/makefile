all: *.pao *.result

%.pao : %.asm
	../PhaethonAsm/PhaethonAsm $< $@

%.result: %.pao
	vvp ../PhaethonHDL/ALU_tb +ROMFILE=$< > $@