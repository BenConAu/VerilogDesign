all: *.asm *.result

%.asm : %.psl ../PSLcc
	../PSLcc $< $@ $*.pao

%.result: %.pao
	vvp ../../PhaethonHDL/ALU_tb +ROMFILE=$< > $@