Const
  Fin = '';
  Fout = '';
Const
  Maxn = 1000000;
  Maxm = 1000000;
Var
  t, nt, c: Array[1..Maxm]Of Longint;
  a0, b0, c0: Array[1..Maxm]Of Longint;
  Ind: Array[1..Maxn]Of Longint;
  f: Array[1..Maxn]Of Int64;
  q: Array[0..Maxn]Of Longint;
  Vis: Array[1..Maxn]Of Boolean;
  n, m: Longint;
  cnt: Longint;
  i, j, k: Longint;
  ans: Int64;
  ii, cas: Longint;
Procedure Addedge(i, j, k: Longint);
Begin
  Inc(cnt);
  t[cnt] := j;
  c[cnt] := k;
  nt[cnt] := Ind[i];
  Ind[i] := cnt;
End;

Function Spfa(): Int64;
Var
  l, r, x, k: Longint;
Begin
  For i:=1 To n Do
    f[i] := MaxLongint;
  f[1] := 0;
  Fillchar(Vis, Sizeof(Vis), False);
  l := 0;
  r := 0;
  q[l] := 1;
  While l <= r Do
  Begin
    x := q[l Mod n];
    Inc(l);
    Vis[x] := False;
    k := Ind[x];
    While k <> -1 Do
    Begin
      If f[t[k]] > f[x] + c[k] Then
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

  Spfa := 0;
  For i:=2 To n Do
    Spfa := Spfa + f[i];
End;

Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);

  Read(cas);
  For ii:=1 To cas Do
  Begin
    ReadLn(n, m);

    cnt := 0;
    Fillchar(Ind, Sizeof(Ind), $FF);
    For i:=1 To m Do
    Begin
      Read(a0[i], b0[i], c0[i]);
      Addedge(a0[i], b0[i], c0[i]);
    End;

    ans := spfa;

    cnt := 0;
    Fillchar(Ind, Sizeof(Ind), $FF);
    For i:=1 To m Do
    Begin
      Addedge(b0[i], a0[i], c0[i]);
    End;

    ans := ans + Spfa;
    WriteLn(ans);
  End;
  Close(Output);
End.
