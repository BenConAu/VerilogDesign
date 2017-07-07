V# is a HDL that has the following goals:

* Create a new language for hardware development
* The compiler outputs Verilog so that any existing Verilog toolchain can be used
* The design aims to create a pit success for by splitting all code into modules and functions
* Modules have distinct states described in the language and generate FSMs in Verilog with 100% non-blocking assignments
* Modules can be verified that they transition states in a sane way
* Functions describe combinatorial logic and generate modules with 100% blocking assignments
