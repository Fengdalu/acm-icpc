Const
  Fin = '';
  Fout = '';
Const
  Maxm = 10000;
  Maxn = 23;
  Inf = MaxLongint;
Var
  a, b, c: Array[1..Maxm]Of longint;
  f: Array[-1..Maxn]Of Longint;
  t, r: Array[0..Maxn]of Longint;
  i, j, k: Longint;
  n, m, Mid: Longint;
  ln, rn: Longint;
  cas, ii: Longint;
Procedure Addedge(i, j, k: Longint);
Begin
  Inc(m);
  a[m] := i;
  b[m] := j;
  c[m] := k;
End;

Function Check(Sum: Longint): Boolean;
Begin
  m := 0;
  For i:=0 To 23 Do
  Begin
    AddEdge(i - 1, i, t[i]);
    Addedge(i, i - 1, 0);
  End;

  For i:=8 To 23 Do
  Begin
    Addedge(i, i - 8, -r[i]);
  End;

  For i:=0 To 7 Do
  Begin
    Addedge(i, i + 16, sum - r[i]);
  End;

  Addedge(23, -1, -sum);

  For i:=0 To 23 Do
    f[i] := Inf;
  f[-1] := 0;
  For i:=1 To n Do
    For j:=1 To m Do
      If (f[a[j]] <> Inf) And (f[a[j]] + c[j] < f[b[j]]) Then
        f[b[j]] := f[a[j]] + c[j];
  For i:=1 To m Do
    If f[a[i]] + c[i] < f[b[i]] Then
    Begin
      Check := False;
      Exit;
    End;
  Check := True;
End;

Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);

  ReadLn(cas);
  For ii:=1 To cas Do
  Begin
    For i:=0 To 23 Do
      Read(r[i]);
    ReadLn(n);
    Fillchar(t, Sizeof(t), 0);
    For i:=1 To n Do
    Begin
      Read(j);
      Inc(t[j]);
    End;
    ln := 0;
    rn := n;
    While ln < rn - 1 Do
    Begin
      Mid := (ln + rn) Div 2;
      If Check(Mid) Then rn := Mid Else ln := Mid + 1;
    End;
    If Check(ln) Then WriteLn(ln)
    Else If Check(rn) Then WriteLn(rn)
    Else WriteLn('No Solution');
  End;
  Close(Output);
End.
