Const
  Fin = '';
  Fout = '';
Type
  Obj2 = Array[1..2]Of Longint;
Type
  Link = ^Obj;
  Obj = Record
    a, b: Longint;
    l, r: Link;
    c: Obj2;
End;
Var
  Top: Link;
  ans: Obj2;
  i, j, k: Longint;
  n: Longint;
Function Max(i, j: Longint): Longint;
Begin
  If i > j Then Max := i Else Max := j;
End;
Function Min(i, j: Longint): Longint;
Begin
  If i < j Then Min := i Else Min := j;
End;
Procedure Make(Var Tree: Link; a, b: Longint);
Var
  m: Longint;
Begin
  New(Tree);
  Tree^.a := a;
  Tree^.b := b;
  If a < b Then
  Begin
    m := (a + b) div 2;
    Make(Tree^.l, a, m);
    Make(Tree^.r, m + 1, b);
    Tree^.c[1] := Max(Tree^.l^.c[1], Tree^.r^.c[1]);
    Tree^.c[2] := Min(Tree^.l^.c[2], Tree^.r^.c[2]);
  End
  Else
  Begin
    Read(Tree^.c[1]);
    Tree^.c[2] := Tree^.c[1];
  End;
End;

Function Find(Tree: Link; a, b:  Longint): Obj2;
Var
  m: Longint;
  x, y: Obj2;
Begin
  If (a <= Tree^.a) And (b >= Tree^.b) Then Find := Tree^.c
  Else
  Begin
    m := (Tree^.a + Tree^.b) div 2;
    x[1] := - MaxLongint;
    x[2] := MaxLongint;
    y[1] := - MaxLongint;
    y[2] := MaxLongint;
    If a <= m Then x := Find(Tree^.l, a, b);
    If b > m Then y := Find(Tree^.r, a, b);
    Find[1] := Max(x[1], y[1]);
    Find[2] := Min(x[2], y[2]);
  End;
End;

Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);
  ReadLn(n, k);
  Make(Top, 1, n);
  For i:=1 To n - k + 1 Do
  Begin
    ans := Find(Top, i, i + k - 1);
    Write(ans[2], ' ');
  End;
  WriteLn;
  For i:=1 To n - k + 1 Do
  Begin
    ans := Find(Top, i, i + k - 1);
    Write(ans[1], ' ');
  End;
Close(Output);
End.
