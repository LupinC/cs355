/* THIS CODE IS MY OWN WORK, IT WAS WRITTEN WITHOUT CONSULTING A TUTOR 
   OR CODE WRITTEN BY OTHER STUDENTS - Lupin Cai 
*/

/* Skeleton program file for hw2 */

Define FourBit_Adder   a3 a2 a1 a0 b3 b2 b1 b0 | CarryOut s3 s2 s1 s0;
   Full_Adder ch ZERO  a0 b0  | c1       s0;
   Full_Adder cf c1    a1 b1  | c2       s1;
   Full_Adder cd c2    a2 b2  | c3       s2;
   Full_Adder cb c3    a3 b3  | CarryOut s3;
Endef;


Define Mult4 x3 x2 x1 x0  y3 y2 y1 y0 | m7 m6 m5 m4 m3 m2 m1 m0;
/* ------------------------------------------------------------
   Write the multiply circuit here

     The 1st binary number = (x3 x2 x1 x0) - x0 is the least significant bit
     The 2nd binary number = (y3 y2 y1 y0) - y0 is the least significant bit

     The output (product) = (m7 m6 m5 m4 m3 m2 m1 m0)
					- m0 is the least significant bit
   ------------------------------------------------------------ */
	And aa x0 y0 m0;
	And aa x0 y1 q1;
	And aa x0 y2 q2;
	And aa x0 y3 q3;

	And ba x1 y0 q4;
        And ba x1 y1 q5;
        And ba x1 y2 q6;
        And ba x1 y3 q7;

	FourBit_Adder ba ZERO q3 q2 q1 q7 q6 q5 q4 | w3 w2 w1 w0 m1;
	
        And ca x2 y0 w4;
        And ca x2 y1 w5;
        And ca x2 y2 w6;
        And ca x2 y3 w7;

	FourBit_Adder bb w3 w2 w1 w0 w7 w6 w5 w4 | e3 e2 e1 e0 m2;

        And da x3 y0 t4;
        And da x3 y1 t5;
        And da x3 y2 t6;
        And da x3 y3 t7;

	FourBit_Adder bc e3 e2 e1 e0 t7 t6 t5 t4 | m7 m6 m5 m4 m3;


Endef;


