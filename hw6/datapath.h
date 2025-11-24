
/* ---------------------   LINE A ---------------------------- */
/*       DO NOT CHANGE ANYTHING BETWEEN LINES A and B          */

/* -------------------------------------------------------
   Declare the ALU16 and SHIFTER16 macros
   Don't use student's solutions that may be faulty.
   These circuits are guaranteed to be correct
   ------------------------------------------------------- */
*Define ALU16 a[15..0] b[15..0] c[1..0] | s[15..0] n z;
*Define SHIFTER16 a[15..0] c[1..0] | s[15..0];

/* -------------------------------------------------------
   Include the components for assignment 6
   Available components listed in HW6 write up
   ------------------------------------------------------- */
#include "basic.h"
/* ------------------------  LINE B ------------------------- */




/* =================================================================
             **** Pj6 code BEGINS HERE  ****

   Write the DataPath macro according to the project handout
   ================================================================= */

Define DataPath mir[31..0] mbr[15..0] Phase[3..0] Reset |
                R0[15..0]  R1[15..0]  R2[15..0]  R3[15..0]  R4[15..0]  
                R5[15..0]  R6[15..0]  R7[15..0]  R8[15..0]  R9[15..0]  
                R10[15..0] R11[15..0] R12[15..0] R13[15..0] R14[15..0] 
                R15[15..0] A[15..0]   B[15..0]  ALatch[15..0] BLatch[15..0]
                AMUX[15..0] aluOut[15..0] C[15..0] N Z;
 
/* --------------------------------------------------------------------
   Write EDiSim code here to execute the micro instruction given by
   input signals mir[31..0]

   The Reset signal is used to reset the registers to 0.
   Your circuit will only "run" when Reset=0

   To run your DataPath circuit, use this command:

              run-pj6
   -------------------------------------------------------------------- */

/*Mux ab-hb control1 control0 | i[7..6] i[5..4] i[3..2] i[1..0] | o[1..0]*/

/*a and b*/
Mux aa mir[11] mir[10] mir[9] mir[8] |R15[15..0] R14[15..0] R13[15..0] R12[15..0] R11[15..0] R10[15..0] R9[15..0] R8[15..0] R7[15..0] R6[15..0] R5[15..0] R4[15..0] R3[15..0] R2[15..0]  R1[15..0] R0[15..0] | A[15..0];
Mux aa mir[15] mir[14] mir[13] mir[12] |R15[15..0] R14[15..0] R13[15..0] R12[15..0] R11[15..0] R10[15..0] R9[15..0] R8[15..0] R7[15..0] R6[15..0] R5[15..0] R4[15..0] R3[15..0] R2[15..0]  R1[15..0] R0[15..0] | B[15..0];


/*a and b latch*/
ResetableReg16  aa  A[15..0]  Phase[1]  Reset  |  ALatch[15..0];
ResetableReg16  aa  B[15..0]  Phase[1]  Reset  |  BLatch[15..0];


/*amux*/

Mux aa mir[31] | mbr[15..0] ALatch[15..0] | AMUX[15..0];

/*map ALU*/
And aa ONE mir[28] c[1];
And aa ONE mir[27] c[0];

/*condition for alu*/
ALU16 aa AMUX[15..0] BLatch[15..0] c[1..0] | aluOut[15..0] N Z;


/*map shifter*/
And aa ONE mir[26] d[1];
And aa ONE mir[25] d[0];

/*shifter*/
SHIFTER16 aa aluOut[15..0] d[1..0] | C[15..0];

Not aa Reset nReset;

/*Decoder*/
Dec aa nReset mir[19] mir[18] mir[17] mir[16] | ri15 ri14 ri13 ri12 ri11 ri10 ri9 ri8 ri7 ri6 ri5 ri4 ri3 ri2 ri1 ri0;

/*phase four*/
And aa Phase[3] ri15 rp15;
And aa Phase[3] ri14 rp14;
And aa Phase[3] ri13 rp13;
And aa Phase[3] ri12 rp12;
And aa Phase[3] ri11 rp11;
And aa Phase[3] ri10 rp10;
And aa Phase[3] ri9  rp9;
And aa Phase[3] ri8  rp8;
And aa Phase[3] ri7  rp7;
And aa Phase[3] ri6  rp6;
And aa Phase[3] ri5  rp5;
And aa Phase[3] ri4  rp4;
And aa Phase[3] ri3  rp3;
And aa Phase[3] ri2  rp2;
And aa Phase[3] ri1  rp1;
And aa Phase[3] ri0  rp0;

/*Registers*/
ResetableReg16  aa  C[15..0]  rp15  Reset  |  R15[15..0];
ResetableReg16  aa  C[15..0]  rp14  Reset  |  R14[15..0];
ResetableReg16  aa  C[15..0]  rp13  Reset  |  R13[15..0];
ResetableReg16  aa  C[15..0]  rp12  Reset  |  R12[15..0];
ResetableReg16  aa  C[15..0]  rp11  Reset  |  R11[15..0];
ResetableReg16  aa  C[15..0]  rp10  Reset  |  R10[15..0];
ResetableReg16  aa  C[15..0]  rp9  Reset  |  R9[15..0];
ResetableReg16  aa  C[15..0]  rp8  Reset  |  R8[15..0];
ResetableReg16  aa  C[15..0]  rp7  Reset  |  R7[15..0];
ResetableReg16  aa  C[15..0]  rp6  Reset  |  R6[15..0];
ResetableReg16  aa  C[15..0]  rp5  Reset  |  R5[15..0];
ResetableReg16  aa  C[15..0]  rp4  Reset  |  R4[15..0];
ResetableReg16  aa  C[15..0]  rp3  Reset  |  R3[15..0];
ResetableReg16  aa  C[15..0]  rp2  Reset  |  R2[15..0];
ResetableReg16  aa  C[15..0]  rp1  Reset  |  R1[15..0];
ResetableReg16  aa  C[15..0]  rp0  Reset  |  R0[15..0];


Endef;
