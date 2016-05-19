Const
  Fin = '';
  Fout = '';
  Fcmp = '';
Type
  Link = ^Obj;
  Obj = Record
    a, b: Longint;
    l, r: Link;
    c, s: Longint;
End;

Type
   Line = Record
     a, b, c: Longint;
     d: Boolean;
End;

Var
  n, i, j, k, x, y: Longint;
  Top: Link;
  lx, ly: Array[1..10000]Of Line;
  ans: Longint;
  t, p: Line;

Function Cmp(i, j: Line): Boolean;
Begin
  If i.c > j.c Then Cmp := True
  Else If (i.c = j.c) And (i.d = True) Then Cmp := False
  Else If (i.c = j.c) And (j.d = True) Then Cmp := True
  Else Cmp := False;
End;

Procedure Swap(Var i, j: Line);
Var
  t: Line;
Begin
  t := i;
  i := j;
  j := t;
End;

Procedure Qsortx(p, r: Longint);
Var
  x: Line;
  i, j: Longint;
Begin
  //Swap(lx[p], lx[p + Random(r - p)]);
  x := lx[p];
  i := p;
  j := r;
  While (i < j) Do
  Begin
    While (i < j) And (Cmp(lx[j], x)) Do Dec(j);
    If (i < j) Then Begin lx[i] := lx[j]; Inc(i); End;
    While (i < j) And (Cmp(x, lx[i])) Do Inc(i);
    If (i < j) Then Begin lx[j] := lx[i]; Dec(j); End;
  End;
  lx[i] := x;
  If i + 1 < r Then Qsortx(i + 1, r);
  If i - 1 > p Then Qsortx(p, i - 1);
End;

Procedure Qsorty(p, r: Longint);
Var
  x: Line;
  i, j: Longint;
Begin
  //Swap(ly[p], ly[p + Random(r - p)]);
  x := ly[p];
  i := p;
  j := r;
  While (i < j) Do
  Begin
    While (i < j) And (Cmp(ly[j], x)) Do Dec(j);
    If (i < j) Then Begin ly[i] := ly[j]; Inc(i); End;
    While (i < j) And (Cmp(x, ly[i])) Do Inc(i);
    If (i < j) Then Begin ly[j] := ly[i]; Dec(j); End;
  End;
  ly[i] := x;
  If i + 1 < r Then Qsorty(i + 1, r);
  If i - 1 > p Then Qsorty(p, i - 1);
End;

Procedure Make(Var Tree: Link;a ,b: Longint);
Var
  m: Longint;
Begin
  New(Tree);
  Tree^.a := a;
  Tree^.b := b;
  Tree^.c := 0;
  Tree^.s := b - a + 1;
  If a < b Then
  Begin
    m := (a + b) div 2;
    Make(Tree^.l, a, m);
    Make(Tree^.r, m + 1, b);
  End;
End;

Procedure Updata(Tree: Link);
Begin
  If Tree^.c > 0 Then Tree^.s := 0
  Else If Tree^.a = Tree^.b Then Tree^.s := 1
  Else Tree^.s := Tree^.l^.s + Tree^.r^.s;
End;

Procedure Insert(Tree: Link; a, b: Longint);
Var
  m: Longint;
Begin
  If (a <= Tree^.a) And (Tree^.b <= b) Then
  Begin
    Inc(Tree^.c);
    Updata(Tree);
  End
  Else
  Begin
    m := (Tree^.a + Tree^.b) div 2;
    If a <= m Then Insert(Tree^.l, a, b);
    If b > m Then Insert(Tree^.r, a, b);
    Updata(Tree);
  End;
End;

Procedure Delete(Tree: Link; a, b: Longint);
Var
  m: Longint;
Begin
  If (a <= Tree^.a) And (Tree^.b <= b) Then
  Begin
    Dec(Tree^.c);
    Updata(Tree);
  End
  Else
  Begin
    m := (Tree^.a + Tree^.b) div 2;
    If a <= m Then Delete(Tree^.l, a, b);
    If b > m Then Delete(Tree^.r, a, b);
    Updata(Tree);
  End;
End;

Function Find(Tree: Link; a, b: Longint): Longint;
Var
  l, r: Longint;
  m: Longint;
Begin
  If Tree^.c > 0 Then Find := 0
  Else If (a <= Tree^.a) And (Tree^.b <= b) Then Find := Tree^.s
  Else
  Begin
    m := (Tree^.a + Tree^.b) div 2;
    l := 0;
    r := 0;
    If a <= m Then l := Find(Tree^.l, a, b);
    If b > m Then r := Find(Tree^.r, a, b);
    Find := l + r;
  End;
End;

Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);

  ReadLn(n);

  For i:=1 To n Do
  Begin
    Read(j, k, x, y);
    Inc(j, 10001);
    Inc(k, 10001);
    Inc(x, 10001);
    Inc(y, 10001);

    lx[i].a := j;
    lx[i].b := x - 1;
    lx[i].c := k;
    lx[i].d := True;

    lx[i + n].a := j;
    lx[i + n].b := x - 1;
    lx[i + n].c := y;
    lx[i + n].d := False;

    ly[i].a := k;
    ly[i].b := y - 1;
    ly[i].c := j;
    ly[i].d := True;

    ly[i + n].a := k;
    ly[i + n].b := y - 1;
    ly[i + n].c := x;
    ly[i + n].d := False;
  End;

  Qsortx(1, 2 * n);
  Qsorty(1, 2 * n);

  Make(Top, 1, 20002);
  ans := 0;
  {Insert(Top, 1, 10);
  WriteLn(Find(Top, 5, 20));}

  For i:=1 To 2 * n Do
  Begin
    If lx[i].d Then
    Begin
      j := Find(Top, lx[i].a, lx[i].b);
      Inc(ans, j);
      Insert(Top, lx[i].a, lx[i].b);
    End
    Else
    Begin
      Delete(Top, lx[i].a, lx[i].b);
      Inc(ans, Find(Top, lx[i].a, lx[i].b));
    End;
  End;

  Top := Nil;
  Make(Top, 1, 20002);

  {Insert(Top, 10001, 10010);
  WriteLn(Find(Top, 10009, 10025));}

  For i:=1 To 2 * n Do
  Begin
    If ly[i].d Then
    Begin
      j := Find(Top, ly[i].a, ly[i].b);
      Inc(ans, j);
      Insert(Top, ly[i].a, ly[i].b);
    End
    Else
    Begin
      Delete(Top, ly[i].a, ly[i].b);
      Inc(ans, Find(Top, ly[i].a, ly[i].b));
    End;
  End;

  WriteLn(ans);
  Close(Output);
End.
