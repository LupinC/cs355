     /* -------------------------------------------------------------------------
        HW5 TODO:

          Write the binary number pattern for the 10 machine instructions
	  specified in the homework assignmnet write up below.

        Each machine instruction is 32 bits or 4 bytes
	You can write each byte of the machine instruction in this format:

			0bXXXXXXXX    where X is 0 or 1

	A number starting with 0b is treated as a binary number by the compiler

 	To help you obtain the bit pattern, I have align the bit along
	with the meaning of each bit using the acronym below.
        (You need to read the acronym vertically !!!)

	You ONLY need to change the bits under: 

			AMux, ALU, Shif, EnC, CCCC, BBBB, AAAA

	You DO NOT need to change the bits under:

			Cond, MBR, MAR, RD, WR, branch address
        -------------------------------------------------------------------------- */
             

     // -------------------------------------------------------------------------- 
     //    Read    |    ACCAASSM    MRWE  
     //    acronym |    MooLLhhB    ADRn
     //    this    |    unnUUiiR    R  C                    branch
     //    way     V    xdd  ff         CCCC    BBBBAAAA    address   
     // -------------------------------------------------------------------------- 
     /* instr. 0: */  0b00010000, 0b00010000, 0b00001000, 0b00000000,   // DO NOT
     /* instr. 1: */  0b10010000, 0b00010001, 0b00000000, 0b00000000,   // REMOVE
     /* instr. 2: */  0b00000000, 0b00010010, 0b01101000, 0b00000000,   // ANY COMMAS !!!
     /* instr. 3: */  0b10000000, 0b00010011, 0b10010000, 0b00000000,   //
     /* instr. 4: */  0b00010100, 0b00010100, 0b00001001, 0b00000000,   // Do NOT
     /* instr. 5: */  0b00000010, 0b00010000, 0b10001001, 0b00000000,   // comment out
     /* instr. 6: */  0b10011100, 0b00010001, 0b00000000, 0b00000000,   // any row
     /* instr. 7: */  0b00010010, 0b00010010, 0b00001000, 0b00000000,   //
     /* instr. 8: */  0b00000100, 0b00010011, 0b01101001, 0b00000000,   // Only change
     /* instr. 9: */  0b00000100, 0b00010100, 0b10011001, 0b00000000,   // some 0 to 1


     /* Warning: DO NOT REMOVE ANY , (comma) in the above lines         */
     /*          It will cause a lot of syntax errors if you do !!!     */
     /*                                                                 */
     /* ONLY make changes to the 0 digits AFTER  0b                     */
     /* In fact, you only need to change some 0's into 1's              */
     /* The 0's that you don't need to change, don't need to be updated */
     /*                                                                 */
     /* If you mistakenly changed some 0's to 1, you may change the 1   */
     /* back to 0. Make sure that each pattern has 8 bits after 0b      */
     /* (because it is a byte pattern)					*/

