Const
  Fin = '';
  Fout = '';
Var
  i, j, k: Longint;
  n: Longint;
  Max: Longint;
  c: Array[1..32001]Of Longint;
  f: Array[0..15001]Of Longint;
Procedure Insert(x, a: Longint);
Var
  y1: Longint;
Begin
  While x <= 32001 Do
  Begin
    Inc(c[x], a);
    x := x + x And (-x);
  End;
End;

Function Count(x: Longint): Longint;
Var
  ans: Longint;
Begin
  ans := 0;
  While x > 0 Do
  Begin
    Inc(ans, c[x]);
    x := x - x And (-x);
  End;
  Count := ans;
End;

Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);
  Fillchar(c, Sizeof(c), 0);
  Fillchar(f, Sizeof(f), 0);
  ReadLn(n);
  For i:=1 To n Do
  Begin
    ReadLn(j, k);
    Inc(j);
    Inc(f[Count(j)]);
    Insert(j, 1);
  End;
  For i:=0 To n - 1 Do
    WriteLn(f[i]);
End.
