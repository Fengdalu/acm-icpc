Const
  Fin = '';
  Fout = '';
Var
  a: Array[1..100000]Of Longint;
  n, m: Longint;
  mid: Longint;
  l, r: Longint;
  i, j, k: Longint;
Begin
  Assign(Input, Fin);
  Reset(INput);
  Assign(Output, Fout);
  Rewrite(Output);

  ReadLn(n, m);
  r := 0;
  l := 0;
  For i:=1 To n Do
  Begin
    Read(a[i]);
    Inc(r, a[i]);
    If a[i] > l Then l := a[i];
  End;
  While l < r Do
  Begin
    mid := (l + r) div 2;
    i := 0;
    j := 0;
    For k:=1 To n Do
    Begin
      Inc(j, a[k]);
      If j > Mid Then
      Begin
        j := a[k];
        Inc(i);
      End;
    End;
    Inc(i);
    If i > m Then l := Mid + 1 Else r := Mid;
  End;
  WriteLn(l);
  Close(Output);
End.
