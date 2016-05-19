Const
  Fin = '';
  Fout = '';

Type
  Obj = Record
    s, e, ans, num: Longint;
End;
Procedure Swap(Var i, j: Obj);
Var t: Obj;
Begin
  t := i;
  i := j;
  j := t;
End;
Var
  i, j, k: Longint;
  q: Array[1..100010]Of Obj;
  c: Array[1..100010]Of Longint;
  n: Longint;
  tmp: Longint;
Function Cmp(i, j: Obj): Boolean;
Begin
  If i.e > j.e Then Cmp := True
  Else If (i.e = j.e) And (i.s < j.s) Then Cmp := True
  Else Cmp := False;
End;

Function Cmp1(i, j: Obj): Boolean;
Begin
  If i.num > j.num Then Cmp1 := True Else Cmp1 := False;
End;

Procedure Qsort1(p, r: Longint);
Var
  x: Obj;
  i, j: Longint;
Begin
  Swap(q[p], q[p + Random(r - p)]);
  x := q[p];
  i := p;
  j := r;
  While (i < j) Do
  Begin
    While (i < j) And (Cmp1(q[j], x)) Do Dec(j);
    If i < j Then Begin q[i] := q[j]; Inc(i); End;
    While (i < j) And (Cmp1(x, q[i])) Do Inc(i);
    If i < j Then Begin q[j] := q[i]; Dec(j); End;
  End;
  q[i] := x;
  If i + 1 < r Then Qsort1(i + 1, r);
  If p < i - 1 Then Qsort1(p, i - 1);
End;

Procedure Qsort(p, r: Longint);
Var
  x: Obj;
  i, j: Longint;
Begin
  Swap(q[p], q[p + Random(r - p)]);
  x := q[p];
  i := p;
  j := r;
  While (i < j) Do
  Begin
    While (i < j) And (Cmp(x, q[j])) Do Dec(j);
    If i < j Then Begin q[i] := q[j]; Inc(i); End;
    While (i < j) And (Cmp(q[i], x)) Do Inc(i);
    If i < j Then Begin q[j] := q[i]; Dec(j); End;
  End;
  q[i] := x;
  If i + 1 < r Then Qsort(i + 1, r);
  If p < i - 1 Then Qsort(p, i - 1);
End;

Function Count(i: Longint): Longint;
Begin
  Count := 0;
  While i > 0 Do
  Begin
    Inc(Count, c[i]);
    i := i - I And (-i);
  End;
End;

Procedure Insert(i, j: Longint);
Begin
  While i <= 100000 Do
  Begin
    Inc(c[i], j);
    i := i + i And (-i);
  End;
End;

Begin
  Assign(Input, Fin);
  Reset(Input);
  Assign(Output, Fout);
  Rewrite(Output);
  While True Do
  Begin
    ReadLn(n);
    Fillchar(c, Sizeof(c), 0);
    If n = 0 Then Exit;
    For i:=1 To n Do
    Begin
      ReadLn(q[i].s, q[i].e);
      Inc(q[i].s);
      Inc(q[i].e);
      q[i].num :=i;
    End;
    Qsort(1, n);
    For i:=1 To n Do
    Begin
      q[i].ans := Count(q[i].s);
      If (i > 1) And (q[i].s = q[i - 1].s) And (q[i - 1].e = q[i].e) Then Inc(tmp) Else tmp := 0;
      Dec(q[i].ans, tmp);
      Insert(q[i].s, 1);
    End;
  i := 1;
  Qsort1(1, n);
  For i:=1 To n Do
    Write(q[i].ans, ' ');
  WriteLn;
  End;
End.

