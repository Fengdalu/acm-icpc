Const
  Fin = '';
  Fout = '';
Var
  t, next: Array[1..200000]Of Longint;
  c, pre, num: Array[1..100000]Of Longint;
  Index: Array[1..100000]OF Longint;
  visit, a: Array[1..100000]Of Boolean;
  cnt: Longint;
  cnt1: Longint;
  n, m, i, j, k, x: Longint;
  ch: char;
Procedure Addedge(i, j: Longint);
Begin
  Inc(cnt);
  t[cnt] := j;
  next[cnt] := Index[i];
  Index[i] := cnt;
End;

Procedure DFS(i: Longint);
Var k: Longint;
Begin
  k := Index[i];
  Visit[i] := True;
  Inc(cnt1);
  num[i] := cnt1;
  While k <> -1 Do
  Begin
    If Not visit[t[k]] Then DFS(t[k]);
    k := next[k];
  End;
  visit[i] := True;
  pre[i] := cnt1;
End;

Procedure Insert(i, j: Longint);
Begin
  While i <= cnt1 Do
  Begin
    Inc(c[i], j);
    i := i + i And (-i);
  End;
End;

Function Count(i: longint): Longint;
Begin
  Count := 0;
  While i > 0 Do
  Begin
    Inc(Count, c[i]);
    i := i - i And (-i);
  End;
End;

Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);
  ReadLn(n);
  For i:=1 To n Do Index[i] := -1;
  cnt := 0;
  For I:=1 To n-1 Do
  Begin
    ReadLn(k, j);
    Addedge(j, k);
    Addedge(k, j);
  End;

  Fillchar(visit, Sizeof(visit), False);
  cnt1 := 0;
  DFS(1);
  Fillchar(a, Sizeof(a), True);
  For i:=1 To cnt1 Do Insert(i, 1);
  ReadLn(m);
  j := 5;
  For i:=1 To m Do
  Begin
    Read(ch);
    If ch = 'C' Then
    Begin
      ReadLn(j);
      If a[num[j]] Then Insert(num[j], -1) Else Insert(num[j], 1);
      a[num[j]] := Not a[num[j]];
    End
    Else
    Begin
      ReadLn(j);
      x := Count(pre[j]);
      k :=  Count(num[j] - 1);
      WriteLn(x - k);
    End;
  End;
  Close(Input);
  Close(Output);
End.
