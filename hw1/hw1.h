//THIS CODE IS MY OWN WORK, IT WAS WRITTEN WITHOUT CONSULTING A TUTOR OR CODE WRITTEN BY OTHER STUDENTS - Lupin Cai
Switch aa A '0' ZERO;
Not aa A nA;
Switch ca B '1' ZERO;
Not ca B nB;
Switch ea C '2' ZERO;
Not ea C nC;
Switch ga D '3' ZERO;
Not ga D nD;
Switch ia E '4' ZERO;
Not ia E nE;

And ac A B C D nE O1;
And ac A B C nD E O2;
And ac A nB C D E O3;
And ac nA B C D E O4;
And ac A B nC D E O5;
And ac A B C D E O6;

Probe ad O1;
Probe ad O2;
Probe ad O3;
Probe ad O4;
Probe ad O5;
Probe ad O6;

Or ae O1 O2 O3 O4 O5 O6 Out;
Probe af Out;

And ec A B C nD nE P1;
And ec A B nC D nE P2;
And ec A B nC nD E P3;
And ec A nB C D nE P4;
And ec A nB C nD E P5;
And ec A nB nC D E P6;
And ec nA B C D nE P7;
And ec nA B C nD E P8;
And ec nA B nC D E P9;
And ec nA nB C D E P10;
And ec A B nC nD nE P11;
And ec A nB C nD nE P12;
And ec A nB nC D nE P13;
And ec A nB nC nD E P14;
And ec nA B C nD nE P15;
And ec nA B nC D nE P16;
And ec nA B nC nD E P17;
And ec nA nB C D nE P18;
And ec nA nB C nD E P19;
And ec nA nB nC D E P20;

Probe ed P1;
Probe ed P2;
Probe ed P3;
Probe ed P4;
Probe ed P5;
Probe ed P6;
Probe ed P7;
Probe ed P8;
Probe ed P9;
Probe ed P10;
Probe ed P11;
Probe ed P12;
Probe ed P13;
Probe ed P14;
Probe ed P15;
Probe ed P16;
Probe ed P17;
Probe ed P18;
Probe ed P19;
Probe ed P20;

Or ee P1 P2 P3 P4 P5 P6 P7 P8 P9 P10 P11 P12 P13 P14 P15 P16 P17 P18 P19 P20 Out2;
Probe ef Out2;

Xor ic A B C D E L1;

Probe if L1;
