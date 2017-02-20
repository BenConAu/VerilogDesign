all: *.pao *.result

%.pao : %.psl ../PSLcc
	../PSLcc $<

%.result: %.pao
	vvp ../../PhaethonHDL/ALU_tb +ROMFILE=$< > $@