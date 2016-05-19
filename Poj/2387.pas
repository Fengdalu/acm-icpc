Const
  Fin = '';
  Fout = '';
Const
  Maxn = 2000;
  Maxm = 4000;
  Inf = MaxLongint;
Var
  a, b, c: Array[1..Maxm]Of Longint;
  f: Array[1..Maxn]Of Longint;
  i, j, k, x: Longint;
  n, m, m0: Longint;
Procedure Addedge(i, j, k: Longint);
Begin
  Inc(m);
  a[m] := i;
  b[m] := j;
  c[m] := k;
End;

Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);

  ReadLn(m0, n);
  m := 0;
  For i:=1 To m0 Do
  Begin
    ReadLn(j, k, x);
    Addedge(j, k, x);
    Addedge(k, j, x);
  End;
  For i:=1 To n Do
    f[i] := Inf;
  f[1] := 0;
  For i:=1 To n Do
    For j:=1 To m Do
      If (f[a[j]] <> Inf) And (f[a[j]] + c[j] < f[b[j]]) Then
        f[b[j]] := f[a[j]] + c[j];

  WriteLn(f[n]);
  Close(Output);
End.
