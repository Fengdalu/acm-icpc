Const
  Fin = '';
  Fout = '';
Const
  Maxn = 50000;
  Maxm = 50000 * 3;
Var
  t, nt, c: Array[1..Maxm]Of Longint;
  Ind, f, q: Array[0..Maxn]Of Longint;
  Vis: Array[0..Maxn]Of Boolean;
  cnt, i, m, j, k, n, x: Longint;
Procedure Addedge(i, j, k: Longint);
Begin
  Inc(cnt);
  t[cnt] := j;
  c[cnt] := k;
  nt[cnt] := Ind[i];
  Ind[i] := cnt;
End;

Function Spfa(): Longint;
Var
  l, r, x, k: Longint;
Begin
  For i:=1 To n Do f[i] := -MaxLongint;
  Fillchar(Vis, Sizeof(Vis), False);
  Vis[0] := True;
  l := 0;
  r := 0;
  q[l] := 0;

  While l <= r Do
  Begin
    x := q[l Mod n];
    Vis[x] := False;
    Inc(l);
    k := Ind[x];

    While k <> -1 Do
    Begin
      If f[x] + c[k] > f[t[k]] Then
      Begin
        f[t[k]] := f[x] + c[k];
        If Not Vis[t[k]] Then
        Begin
          Inc(r);
          q[r Mod n] := t[k];
          Vis[t[k]] := True;
        End;
      End;
      k := nt[k];
    End;
  End;

  Spfa := f[n] - f[0];
End;

Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);

  ReadLn(m);
  n := 0;
  Fillchar(Ind, Sizeof(INd), $FF);
  cnt := 0;

  For i:=1 To m Do
  Begin
    ReadLn(j, k, x);
    If k > n Then n := k;
    Addedge(j - 1, k, x);
  End;

  For i:=0 To n Do
  Begin
    Addedge(i, i + 1, 0);
    Addedge(i + 1, i, -1);
  End;

  WriteLn(Spfa());
  Close(Output);
End.
