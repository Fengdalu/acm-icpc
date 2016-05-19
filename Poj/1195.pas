Const
  Fin = '';
  Fout = '';

Var
 s, i, j, k, p: Longint;
 c: Array[1..1024, 1..1024]Of Longint;
Procedure Insert(x, y, a: Longint);
Var
  y1: Longint;
Begin
  While x <= s Do
  Begin
    y1 := y;
    While y1 <= s Do
    Begin
      Inc(c[x, y1], a);
      y1 := y1 + (y1 And (-y1));
    End;
    x := x + x And (-x);
  End;
End;

Function Count(x, y: Longint): Longint;
Var
  ans, y1: Longint;
Begin
  ans := 0;
  While x > 0 Do
  Begin
    y1 := y;
    While y1 > 0 Do
    Begin
      Inc(ans, c[x, y1]);
      y1 := y1 - (y1 And (-y1));
    End;
    x := x - x And (-x);
  End;
  Count := ans;
End;

Begin
  Assign(Input, Fin);
  Reset(Input);
  Assign(Output, Fout);
  Rewrite(Output);
  While True Do
  Begin
    Read(i);
    Case i Of
      0:
      Begin
        ReadLn(s);
        Fillchar(c, Sizeof(c), 0);
      End;
      1:
      Begin
        ReadLn(i, j, k);
        Insert(i + 1, j + 1, k);
      End;
      2:
      Begin
        ReadLn(i, j, k, p);
        Inc(i);
        Inc(j);
        inc(k);
        Inc(p);
        WriteLn(Count(k, p) + Count(i - 1, j - 1) - Count(k, j - 1) - Count(i - 1, p));
      End;
      3:
      Begin
        Close(Input);
        Close(Output);
        Exit;
      End;

    End;
  End;
End.




