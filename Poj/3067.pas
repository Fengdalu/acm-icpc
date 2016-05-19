Const
  Fin = '';
  Fout = '';

Type
  Road = Record
    x, y: Longint;
End;

Var
  r: Array[1..1000000]Of Road;
  c: Array[1..1000]Of Longint;
  n, m, k: Longint;
  ii, t, i, j: Longint;
  ans: int64;
Function Test(a, b: Road): Boolean;
Begin
  If a.y > b.y Then Test := True
  Else If (a.y = b.y) And (a.x > b.x) Then Test := True
  Else Test := False;
End;

Procedure Qsort(p, t: Longint);
Var
  x: Road;
  i, j: Longint;
Begin
  x := r[p];
  i := p;
  j := t;
  While i < j Do
  Begin
    While (i < j) And (Test(x, r[j])) Do Dec(j);
    If (i < j) Then Begin r[i] := r[j]; Inc(i); End;
    While (i < j) And (Test(r[i], x)) Do Inc(i);
    If (i < j) Then Begin r[j] := r[i]; Dec(j); End;
  End;
  r[i] := x;
  If i + 1 < t Then Qsort(i + 1, t);
  If p < i - 1 Then Qsort(p, i - 1);
End;

Function Count(x: Longint): Longint;
Var
  ans: Longint;
Begin
  ans := 0;
  While x > 0 Do
  Begin
    Inc(ans, c[x]);
    x := x - x And (-x);
  End;
  Count := ans;
End;

Procedure Insert(x, a: Longint);

Begin
  While x <= n Do
  Begin
    Inc(c[x], a);
    x := x + x And (-x);
  End;
End;

Begin
  Assign(Input, Fin);
  Reset(Input);
  Assign(Output, Fout);
  Rewrite(Output);
  ReadLn(t);
  For ii:=1 To t Do
  Begin
    ReadLn(n, m, k);
    Fillchar(c, Sizeof(c), 0);
    For i:=1 To k Do
      ReadLn(r[i].x, r[i].y);
    Qsort(1, k);
    ans := 0;
    For i:=1 To k Do
    Begin
      Inc(ans, Count(r[i].x - 1));
      Insert(r[i].x, 1);
    End;
    WriteLn('Test case ', ii, ': ', ans);
  End;
  Close(Output);
End.
