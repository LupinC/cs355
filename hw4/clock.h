/* ===================================================================
   Skeleton file for CS355 pj4: 4 Phase clock and MPC
   =================================================================== */

/* --------------------------------------------------------------------------
   THIS CODE IS MY OWN WORK, IT WAS WRITTEN WITHOUT CONSULTING A TUTOR 
   OR CODE WRITTEN BY OTHER STUDENTS - Lupin Cai 
   -------------------------------------------------------------------------- */

/* -------------------------------------------------------------
   If you wish, you can define help circuits to do the project
   here (before the 2 circuits that 
   The main circuit files are:  help-CLK and help-MPC
   They have include "basic.h" before including THIS circuit file.
   So you can use any of these circuits in this project without
   having to define them: (see basic.h for details

        Full_Adder COORD  a b c_in | c_out s;
        Decoder2x4 COORD  c[1..0] | s[3..0];
   ------------------------------------------------------------- */

/* Define any help circuits used in this project here */

Define Eight_Bit_Adder   a[7..0] b[7..0] | CarryOut s[7..0];
   Full_Adder ca ZERO  a[0] b[0]  | c1       s[0];
   Full_Adder cb c1    a[1] b[1]  | c2       s[1];
   Full_Adder cc c2    a[2] b[2]  | c3       s[2];
   Full_Adder cd c3    a[3] b[3]  | c4       s[3];
   Full_Adder ce c4    a[4] b[4]  | c5       s[4];
   Full_Adder cf c5    a[5] b[5]  | c6       s[5];
   Full_Adder cg c6    a[6] b[6]  | c7       s[6];
   Full_Adder ch c7    a[7] b[7]  | CarryOut s[7];

Endef;


/* --------------------------------------------------
   Write the circuits for pj4 below
   -------------------------------------------------- */

Define Four_Phase_Clock Reset Clk | Ph1 Ph2 Ph3 Ph4;
/* Write the 4-phase clock circuit here */
/* After completing this circuit, you can use help-CLK to test it */
	
	Not cc q1 q1_bar;
	Xor cc q1 q0 xor1;
//	Not cc Reset notReset1;
//	And cc xor1 notReset1 and1;
	//Probe cc and1;
	Dff bd-dd ZERO xor1 Clk Reset q1;

	Not cg q0 q0_bar;
	And cg q1_bar q0_bar and2;
	And cg q1 q0_bar and3;
	Or cg and2 and3 and4;
	Dff bd-dh ZERO and4 Clk Reset q0;

//	Probe ad q1;
//	Probe ah q0;	

	Decoder2x4 aa q1 q0 |s[3..0];
	And aa s[0] ONE Ph1;
	And aa s[1] ONE Ph2;
	And aa s[2] ONE Ph3;
	And aa s[3] ONE Ph4;

Endef;



Define PC_with_Branching Reset Clk Branch Addr[7..0] | MPC[7..0];
/* Write the PC circuit here */
/* After completing this circuit, you can use help-PC to test it */
	
/* addr + 1 */

	And aa ZERO ZERO b[7];
        And aa ZERO ZERO b[6];
        And aa ZERO ZERO b[5];
        And aa ZERO ZERO b[4];
        And aa ZERO ZERO b[3];
        And aa ZERO ZERO b[2];
        And aa ZERO ZERO b[1];
        And aa ONE ONE b[0];

	Eight_Bit_Adder bb  MPC[7..0] b[7..0] | CarryOut plusOne[7..0];

/*mux*/

	Mux ab-hb Branch | Addr[7..0] plusOne[7..0] | v[7..0];

/*dff*/
	Dff bd-dd ZERO v[7] Clk Reset MPC[7];
        Dff bd-dd ZERO v[6] Clk Reset MPC[6];
        Dff bd-dd ZERO v[5] Clk Reset MPC[5];
        Dff bd-dd ZERO v[4] Clk Reset MPC[4];
        Dff bd-dd ZERO v[3] Clk Reset MPC[3];
        Dff bd-dd ZERO v[2] Clk Reset MPC[2];
        Dff bd-dd ZERO v[1] Clk Reset MPC[1];
        Dff bd-dd ZERO v[0] Clk Reset MPC[0];

//      Eight_Bit_Adder bb  MPC[7..0] b[7..0] | CarryOut MPC[7..0];


Endef;


