Const
  Fin = '';
  Fout = '';
Const
  Maxm = 10000;
  Maxn = 10000;
Var
  t, nt, c, p: Array[1..Maxm]Of Longint;
  Ind, h: Array[1..Maxn]Of Longint;
  Vis: Array[1..Maxn]Of Boolean;
  q: Array[0..Maxn]Of Longint;
  i, j, k, x: Longint;
  n, m, cnt: Longint;
  st, ed: Longint;
Function Min(i, j: Longint): Longint;
Begin
  If i < j Then MIn := i Else Min := j;
End;

Procedure Addedge(i, j, k: Longint);
Begin
  Inc(cnt);
  t[cnt] := j;
  c[cnt] := k;
  nt[cnt] := Ind[i];
  Ind[i] := cnt;

  Inc(cnt);
  t[cnt] := i;
  c[cnt] := 0;
  nt[cnt] := Ind[j];
  Ind[j] := cnt;

  p[cnt] := cnt - 1;
  p[cnt - 1] := cnt;
End;

Function BFS(): Boolean;
Var
  l, r, k, x: Longint;
Begin
  Fillchar(Vis, Sizeof(Vis), False);
  Fillchar(h, Sizeof(h), 0);
  l := 0;
  r := 0;
  q[l] := st;
  Vis[st] := True;
  While l <= r Do
  Begin
    x := q[l];
    k := Ind[q[l]];
    Inc(l);
    While k <> -1 Do
    Begin
      If (c[k] > 0) And (Not Vis[t[k]]) Then
      Begin
        h[t[k]] := h[x] + 1;
        Inc(r);
        q[r] := t[k];
        Vis[t[k]] := True;
      End;
      k := nt[k];
    End;
  End;
  If h[ed] = 0 Then BFS := False Else BFS := True;
End;

Function DFS(x, lim: Longint): Longint;
Var
  k, l, d: Longint;
Begin
  If x = ed Then Begin DFS := Lim; Exit; End;
  k := Ind[x];
  L := Lim;
  dFS := 0;
  While k <> -1 Do
  Begin
    If h[t[k]] = h[x] + 1 Then
    Begin
      d := DFS(t[k], Min(l, c[k]));
      Dec(c[k], d);
      Inc(c[p[k]], d);
      Dec(l, d);
      If l = 0 Then Break;
    End;
    k := nt[k];
  End;
  DFS := Lim - l;
End;

Function Dinic(): Longint;
Begin
  Dinic := 0;
  While BFS Do Dinic := Dinic + DFS(st, MaxLongint);
End;

Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);
  While Not Eof(Input) Do
  Begin
    ReadLn(m, n);
    If (m = 0) And (n = 0) Then Break;
    Fillchar(Ind, Sizeof(Ind), $FF);
    cnt := 0;
    For i:=1 To m Do
    Begin
      Read(j, k, x);
      Addedge(j, k, x);
    End;

    st := 1;
    ed := n;
    WriteLn(Dinic);
  End;
  Close(Output);
End.
