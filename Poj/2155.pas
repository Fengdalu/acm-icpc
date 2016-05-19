Const
  Fin = '';
  Fout = '';

Var
  c: Array[1..1010, 1..1010]Of Longint;
  x, y, x1, y1: Longint;
  ii: Longint;
  i, k ,j, p, n: Longint;
  ch: Char;
Function Count(x, y: Longint): Longint;
Var
  y1, ans: Longint;
Begin
  ans := 0;
  While x > 0 Do
  Begin
    y1 := y;
    While y1 > 0 Do
    Begin
      Inc(ans, c[x, y1]);
      y1 := y1 - y1 And (-y1);
    End;
    x := x - (x And (-x));
  End;
  Count := ans;
End;

Procedure Insert(x, y, a: Longint);
Var
  y1: Longint;
Begin
  If (x = 0) Or (y = 0) Then Exit;
  While x <= n Do
  Begin
    y1 := y;
    While y1 <= n Do
    Begin
      Inc(c[x, y1], a);
      y1 := y1 + (y1 And (-y1));
    End;
    x := x + (x And (-x));
  End;
End;

Begin
  Assign(Input, Fin);
  Reset(Input);
  Assign(Output, Fout);
  Rewrite(Output);
  ReadLn(k);
  For ii:=1 To k Do
  Begin
    ReadLn(n, j);
    Inc(n);
    Fillchar(c, Sizeof(c), 0);
    For i:=1 To j Do
    Begin
      Read(ch);
      If ch = 'C' Then
      Begin
        ReadLn(x, y, x1, y1);
        Insert(x - 1, y - 1, 1);
        Insert(x - 1, y1, 1);
        Insert(x1, y - 1, 1);
        Insert(x1, y1, 1);
      End
      Else
      Begin
        ReadLn(x, y);
        p := Count(n, n) - Count(x - 1, n) - Count(n, y - 1) +Count(x - 1, y - 1);
        WriteLn(p mod 2);
      End;
    End;
    WriteLn;
  End;
  Close(Input);
  Close(Output);
End.
