Const
  Fin = '';
  Fout = '';
Const
  Maxn = 50000;
  Maxm = 50000 * 2;
Var
  t, nt, c: Array[1..Maxm]Of Longint;
  Ind, w: Array[1..Maxn]Of Longint;
  f: Array[1..Maxn]Of Int64;
  q: Array[0..Maxn]Of Longint;
  Vis: Array[1..Maxn]Of Boolean;
  n, m: Longint;
  Inf: Int64;
  cnt: Longint;
  i, j, k: Longint;
  ans: Int64;
  x, y, z: Longint;
  ii, cas: Longint;
  Flag: Boolean;
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
  Flag := True;
  For i:=1 To n Do
    f[i] := Inf;
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
  Begin
    If f[i] <> Inf Then Spfa := Spfa + f[i] * w[i]
    Else
    Begin
      Flag := False;
      Exit;
    End;
  End;
End;

Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);
  Inf := 2;
  For i:=1 To 10 Do
  Begin
    Inf := Inf * 10;
  End;

  Read(cas);
  For ii:=1 To cas Do
  Begin
    ReadLn(n, m);

    For i:=1 To n Do
      Read(w[i]);

    cnt := 0;
    Fillchar(Ind, Sizeof(Ind), $FF);
    For i:=1 To m Do
    Begin
      Read(j, k, x);
      Addedge(j, k, x);
      Addedge(k, j, x);
    End;

    If (n = 0) Or (n = 1) Then
    Begin
      WriteLn('0');
      Continue;
    End;
    ans := spfa;
    If Flag Then WriteLn(ans) Else WriteLn('No Answer');
  End;
  Close(Output);
End.
