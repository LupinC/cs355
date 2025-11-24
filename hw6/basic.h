/* ===================================================
   Macros you will need to use in pj6
   =================================================== */

/* --------------------------------------
   Const_0: outputs 0000000000000000

   Usage: make R5 = 0000000000000000

   Const_0 aa  |  R5[15..0];
   -------------------------------------- */
Define Const_0 | out[15..0];
  Sig 0000000000000000 temp;
  Or  bb temp out[15-0];
Endef;

/* --------------------------------------
   Const_1: outputs 0000000000000001

   Usage: make R6 = 0000000000000001

   Const_1 aa  |  R6[15..0];
   -------------------------------------- */
Define Const_1 | out[15..0];
  Sig 0000000000000001 temp;
  Or  bb temp out[15-0];
Endef;

/* --------------------------------------
   Const_minus1: outputs 1111111111111111

   Usage: make R7 = 1111111111111111

   Const_minus1 aa  |  R7[15..0];
   -------------------------------------- */
Define Const_minus1 | out[15..0];
  Sig 1111111111111111 temp;
  Or  bb temp out[15-0];
Endef;
   

/* --------------------------------------
   Const_AMASK: outputs 0000111111111111

   Usage: make R8 = 0000111111111111

   Const_AMASK aa  |  R8[15..0];
   -------------------------------------- */
Define Const_AMASK | out[15..0];
  Sig 0000111111111111 temp;
  Or  bb temp out[15-0];
Endef;


/* --------------------------------------
   Const_SMASK: outputs 0000000011111111

   Usage: make R9 = 0000000011111111

   Const_SMASK aa  |  R9[15..0];
   -------------------------------------- */
Define Const_SMASK | out[15..0];
  Sig 0000000011111111 temp;
  Or  bb temp out[15-0];
Endef;


/* -------------------------------------------------------------------------
   ResetableReg16: 16 bit register that you can clear (reset) with a reset
                   signal.

   When reset = 1, it reset the register to 0000000000000000
   When reset = 0, register will store input  in[15..0] when
                   the "ld" signal goes up and down once

   out[15..0] is the output = the current value stored in the register
   ------------------------------------------------------------------------- */
Define ResetableReg16 in[15..0] ld reset | out[15..0];
     Dff aa ZERO in[15] ld reset out[15];
     Dff aa ZERO in[14] ld reset out[14];
     Dff aa ZERO in[13] ld reset out[13];
     Dff aa ZERO in[12] ld reset out[12];
     Dff aa ZERO in[11] ld reset out[11];
     Dff aa ZERO in[10] ld reset out[10];
     Dff aa ZERO in[9] ld reset out[9];
     Dff aa ZERO in[8] ld reset out[8];
     Dff aa ZERO in[7] ld reset out[7];
     Dff aa ZERO in[6] ld reset out[6];
     Dff aa ZERO in[5] ld reset out[5];
     Dff aa ZERO in[4] ld reset out[4];
     Dff aa ZERO in[3] ld reset out[3];
     Dff aa ZERO in[2] ld reset out[2];
     Dff aa ZERO in[1] ld reset out[1];
     Dff aa ZERO in[0] ld reset out[0];
Endef;



Define Full_Adder CarryIn a b | CarryOut Sum;
  Xor aa a b x;
  Xor ab x CarryIn Sum;
  And bb a b y;
  And cb CarryIn x z;
  Or bc-cc y z CarryOut;
Endef;
