Const
  Fin = '';
  Fout = '';
Var
  f, c: Array[1..50000]Of Longint;
  n, k, i, j: Longint;
  a, b, x: Longint;
  fa, fb: Longint;
  ans: Longint;
Function Find(i: Longint): Longint;
Var
  t: Longint;
Begin
  If f[i] <> i Then
  Begin
    t := f[i];
    f[i] := Find(f[i]);
    c[i] := (c[t] + c[i]) Mod 3;
  End;
  Find := f[i];
End;

Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);

  ReadLn(n, k);
  Ans := 0;
  For i:=1 To n Do
    f[i] := i;
  Fillchar(c, Sizeof(c), 0);

  For i:=1 To k Do
  Begin
    Read(x, a, b);
    If (a > n) Or (b > n) Then Begin Inc(ans); Continue; End
    Else If (a = b) And (x <> 1) Then Begin Inc(ans); Continue; End
    Else If (a = b) And (x = 1) Then Continue
    Else
    Begin
      If x = 1 Then x := 0;
      fa := Find(a);
      fb := Find(b);
      If fa <> fb Then
      Begin
        j := (c[a] - x - c[b] + 9) Mod 3;
        f[fb] := fa;
        c[fb] := j;
      End
      Else
      Begin
        If ((x + c[b]) Mod 3) <> c[a] Then Inc(ans);
      End;
    End;
  End;
  WriteLn(ans);
  Close(Output);
End.
