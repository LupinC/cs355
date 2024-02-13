/* ---------------------------------------------------------------------
   Skeleton project file alu-shf.h
   --------------------------------------------------------------------- */

/* ------------------------------------------------------------------------
   THIS CODE IS MY OWN WORK, IT WAS WRITTEN WITHOUT CONSULTING A TUTOR OR 
   CODE WRITTEN BY OTHER STUDENTS - your name 
   ------------------------------------------------------------------------ */

/* -------------------------------------------------------------
   If you wish, you can define help circuits to do the project
   here (before the 2 circuits that you need to define below)

   The main circuit files are:  help-ALU and help-SHIFT
   They have include "basic.h" before including THIS circuit file.
   So you can use any of these circuits in this project without
   having to define them: (see basic.h for details

        Full_Adder COORD  a b c_in | c_out s;
	Decoder2x4 COORD  c[1..0] | s[3..0];
   ------------------------------------------------------------- */

/* Define any help circuits used in this project here */
Define One_Bit_ALU a b c_in s[1..0] | z c_out;
 /* ========================
    Compute all outputs
    ======================== */
 And 1a a b Out_And;
 Not 1a a   Out_NotA;
 Full_Adder 1a a b c_in | c_out1 Out_Sum;

 /* =============================
    Select the desired output
    ============================= */
 Decoder2x4 2c  s[1] s[0]  | d[3..0];
 And 2c d[3] Out_NotA  Out_NotA1;
 And 2c d[2] a  Out_A;
 And 2c d[1] Out_And  Out_And1;
 And 2c d[0] Out_Sum  Out_Sum1;

 And 2c ONE c_out1   c_out;        /* cout for adder */

 /* =================================
    Collect the desired output to z
    ================================= */
 Or  2c Out_NotA1 Out_A Out_And1 Out_Sum1 z;
Endef;

/* --------------------------------------------------
   Write the circuits for pj3 below
   -------------------------------------------------- */

Define ALU16 a[15..0] b[15..0] c[1..0] | s[15..0] N Z;
/* Complete the 16 bit ALU circuit here */
/* After completing this circuit, you can use help-ALU to test it */

	One_Bit_ALU ch a[0] b[0] ZERO  c[1] c[0] | s[0] ca1;
	One_Bit_ALU cg a[1] b[1] ca1   c[1] c[0] | s[1] ca2;
	One_Bit_ALU cf a[2] b[2] ca2   c[1] c[0] | s[2] ca3;
	One_Bit_ALU ce a[3] b[3] ca3   c[1] c[0] | s[3] ca4;
        One_Bit_ALU ch a[4] b[4] ca4   c[1] c[0] | s[4] ca5;
        One_Bit_ALU cg a[5] b[5] ca5   c[1] c[0] | s[5] ca6;
        One_Bit_ALU cf a[6] b[6] ca6   c[1] c[0] | s[6] ca7;
        One_Bit_ALU ce a[7] b[7] ca7   c[1] c[0] | s[7] ca8;
        One_Bit_ALU ch a[8] b[8] ca8   c[1] c[0] | s[8] ca9;
        One_Bit_ALU cg a[9] b[9] ca9   c[1] c[0] | s[9] ca10;
        One_Bit_ALU cf a[10] b[10] ca10   c[1] c[0] | s[10] ca11;
        One_Bit_ALU ce a[11] b[11] ca11   c[1] c[0] | s[11] ca12;
        One_Bit_ALU ch a[12] b[12] ca12   c[1] c[0] | s[12] ca13;
        One_Bit_ALU cg a[13] b[13] ca13   c[1] c[0] | s[13] ca14;
        One_Bit_ALU cf a[14] b[14] ca14   c[1] c[0] | s[14] ca15;
        One_Bit_ALU ce a[15] b[15] ca15   c[1] c[0] | s[15] c_out;
	
	And aa s[15..0] N;
	Or aa s[15..0] tmp;
	Not aa tmp Z;



Endef;




Define SHIFTER16 a[15..0] c[1..0] | s[15..0];
/* Complete the 16 bit shifter circuit here */
/* After completing this circuit, you can use help-SHIFT to test it */




   /* Bit 15 */  Mux aa ZERO | ZERO       a[14] | left[15];
   /* Bit 14 */  Mux aa ZERO | a[14]      a[13] | left[14];
   /* Bit 13 */  Mux aa ZERO | a[13]      a[12] | left[13];
   /* Bit 12 */  Mux aa ZERO | a[12]      a[11] | left[12];
   /* Bit 11 */  Mux aa ZERO | a[11]      a[10] | left[11];
   /* Bit 10 */  Mux aa ZERO | a[10]      a[9] | left[10];
   /* Bit  9 */  Mux aa ZERO | a[9]       a[8] | left[9];
   /* Bit  8 */  Mux aa ZERO | a[8]       a[7] | left[8];
   /* Bit 7 */  Mux aa ZERO | a[7]       a[6] | left[7];
   /* Bit 6 */  Mux aa ZERO | a[6]       a[5] | left[6];
   /* Bit 5 */  Mux aa ZERO | a[5]       a[4] | left[5];
   /* Bit 4 */  Mux aa ZERO | a[4]       a[3] | left[4];
   /* Bit 3 */  Mux aa ZERO | a[3]       a[2] | left[3];
   /* Bit 2 */  Mux aa ZERO | a[2]       a[1] | left[2];
   /* Bit 1 */  Mux aa ZERO | a[1]       a[0] | left[1];
   /* Bit 0 */  Mux aa ZERO | a[0]       ZERO | left[0];



   /* Bit 15 */  Mux aa ONE | ZERO        a[14] | right[15];
   /* Bit 14 */  Mux aa ONE | a[14]      a[13] | right[14];
   /* Bit 13 */  Mux aa ONE | a[13]      a[12] | right[13];
   /* Bit 12 */  Mux aa ONE | a[12]      a[11] | right[12];
   /* Bit 11 */  Mux aa ONE | a[11]      a[10] | right[11];
   /* Bit 10 */  Mux aa ONE | a[10]      a[9] | right[10];
   /* Bit  9 */  Mux aa ONE | a[9]       a[8] | right[9];
   /* Bit  8 */  Mux aa ONE | a[8]       a[7] | right[8];
   /* Bit  7 */  Mux aa ONE | a[7]       a[6] | right[7];
   /* Bit  6 */  Mux aa ONE | a[6]       a[5] | right[6];
   /* Bit  5 */  Mux aa ONE | a[5]       a[4] | right[5];
   /* Bit  4 */  Mux aa ONE | a[4]       a[3] | right[4];
   /* Bit  3 */  Mux aa ONE | a[3]       a[2] | right[3];
   /* Bit  2 */  Mux aa ONE | a[2]       a[1] | right[2];
   /* Bit  1 */  Mux aa ONE | a[1]       a[0] | right[1];
   /* Bit  0 */  Mux aa ONE | a[0]       ZERO  | right[0];


  And aa ZERO a OutZero;

 Decoder2x4 2c  c[1] c[0]  | d[3..0];
 And 2c d[3] OutZero  Out_NotUsed;
 And 2c d[2] left  Out_left;
 And 2c d[1] right  Out_right;
 And 2c d[0] a  Out_A;


Endef;


