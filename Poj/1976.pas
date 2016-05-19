Const
  Fin = '';
  Fout = '';

Var
  f: Array[0..3, 0..50000]Of Longint;
  a: Array[0..50000]Of Longint;
  i, j, k: Longint;
  p: Longint;
  n, m: Longint;
  t,ii: Longint;
Function Max(i, j: Longint): Longint;
Begin
  If i > j Then Max := i Else Max := j;
End;

Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);

  ReadLn(t);
  For ii:=1 To t Do
  Begin
    ReadLn(n);
    a[0] := 0;
    For i:=1 To n Do
    Begin
      Read(a[i]);
      Inc(a[i], a[i - 1]);
    End;
    ReadLn(k);
    Fillchar(f, Sizeof(f), 0);
    For i:=1 To 3 Do
      For j:=k To n Do
        f[i, j] := Max(f[i - 1, j - k] + a[j] - a[j - k], f[i, j - 1]);
    WriteLn(f[3, n]);
  End;

  Close(Output);
End.
