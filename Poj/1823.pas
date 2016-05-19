Const
  Fin = '';
  Fout = '';

Type
  Link = ^Obj;
  Obj = Record
    l, r: Link;
    a, b: Longint;
    c, s: Longint;
    lc, rc: Longint;
End;
Var
  Top: Link;
  i, j, k: Longint;
  x, n, p: Longint;
Function Maxi(i, j, k: Longint): Longint;
Begin
  Maxi := i;
  If j > Maxi Then Maxi := j;
  If k > Maxi Then Maxi := k;
End;

Procedure Make(Var Tree: Link;a, b: Longint);
Var
  m: Longint;
Begin
  New(Tree);
  Tree^.a := a;
  Tree^.b := b;
  Tree^.c := 1;
  Tree^.s := b - a + 1;
  Tree^.lc := b - a + 1;
  Tree^.rc := b - a + 1;
  If a < b Then
  Begin
    m := (a + b) div 2;
    Make(Tree^.l, a, m);
    Make(Tree^.r, m + 1, b);
  End;
End;

Procedure Insert(Tree: Link;a, b: Longint);
Var
  m: Longint;
Begin
  If (a <= Tree^.a) And (b >= Tree^.b) Then
  Begin
    Tree^.c := 2;
    Tree^.s := 0;
    Tree^.lc := 0;
    Tree^.rc := 0;
  End
  Else
  Begin
    If Tree^.c = 1 Then
    Begin
      Tree^.l^.c := 1;
      Tree^.l^.lc := Tree^.l^.b - Tree^.l^.a + 1;
      Tree^.l^.rc := Tree^.l^.b - Tree^.l^.a + 1;
      Tree^.l^.s := Tree^.l^.b - Tree^.l^.a + 1;

      Tree^.r^.c := 1;
      Tree^.r^.lc := Tree^.r^.b - Tree^.r^.a + 1;
      Tree^.r^.rc := Tree^.r^.b - Tree^.r^.a + 1;
      Tree^.r^.s := Tree^.r^.b - Tree^.r^.a + 1;
    End;

    m := (Tree^.a + Tree^.b) div 2;
    If a <= m Then Insert(Tree^.l, a, b);
    If b > m Then Insert(Tree^.r, a, b);

    If Tree^.l^.c = Tree^.r^.c Then Tree^.c := Tree^.l^.c Else Tree^.c := 0;

    Tree^.lc := Tree^.l^.lc;
    If Tree^.l^.c = 1 Then Inc(Tree^.lc, Tree^.r^.lc);
    Tree^.rc := Tree^.r^.rc;
    If Tree^.r^.c = 1 Then Inc(Tree^.rc, Tree^.l^.rc);

    Tree^.s := Maxi(Tree^.l^.s, Tree^.r^.s, Tree^.l^.rc + Tree^.r^.lc);
  End;
End;

Procedure Delete(Tree: Link;a, b: Longint);
Var
  m: Longint;
Begin
  If Tree^.c = 1 Then Exit;
  If (a <= Tree^.a) And (b >= Tree^.b) Then
  Begin
    Tree^.c := 1;
    Tree^.lc := Tree^.b - Tree^.a + 1;
    Tree^.rc := Tree^.b - Tree^.a + 1;
    Tree^.s := Tree^.b - Tree^.a + 1;
  End
  Else
  Begin
    If Tree^.c = 2 Then
    Begin
      Tree^.l^.c := 2;
      Tree^.l^.s := 0;
      Tree^.l^.lc := 0;
      Tree^.l^.rc := 0;

      Tree^.r^.c := 2;
      Tree^.r^.s := 0;
      Tree^.r^.lc := 0;
      Tree^.r^.rc := 0;
    End;

    m := (Tree^.a + Tree^.b) div 2;
    If a <= m Then Delete(Tree^.l, a, b);
    If b > m Then Delete(Tree^.r, a, b);

    If Tree^.l^.c = Tree^.r^.c Then Tree^.c := Tree^.l^.c Else Tree^.c := 0;

    Tree^.lc := Tree^.l^.lc;
    If Tree^.l^.c = 1 Then Inc(Tree^.lc, Tree^.r^.lc);
    Tree^.rc := Tree^.r^.rc;
    If Tree^.r^.c = 1 Then Inc(Tree^.rc, Tree^.l^.rc);

    Tree^.s := Maxi(Tree^.l^.s, Tree^.r^.s, Tree^.l^.rc + Tree^.r^.lc);
  End;
End;

Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);
  ReadLn(n, p);

  Make(Top, 1, n);

  For i:=1 To p Do
  Begin
    Read(j);
    If j = 1 Then
    Begin
      Read(k, x);
      Insert(Top, k, k + x - 1);
    End
    Else If j = 2 Then
    Begin
      Read(k ,x);
      Delete(Top, k, k + x - 1);
    End
    Else WriteLn(Top^.s);
  End;
  Close(Output);
End.
