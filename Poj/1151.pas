Const
  Fin = '';
  Fout = '';

Type
  Link = ^Obj;
  Obj = Record
    a, b: Longint;
    l, r: Link;
    c: Longint;
    s: Real;
End;

Type
  Line = Record
    a, b, c: Real;
    d: Boolean;
End;

Var
  Top: Link;
  i: Longint;
  ans: Real;
  x1, x: Array[1..400]Of Real;
  l: Array[1..200]Of Line;
  n: Longint;
  j, k, p, q: Real;
  cnt :Longint;
  ii: Longint;
Procedure Qsort(p, r: Longint);
Var
  xx: Real;
  i, j: Longint;
Begin
  xx := x1[p];
  i := p;
  j := r;
  While (i < j) Do
  Begin
    While (i < j) And (x1[j] > xx) Do Dec(j);
    If (i < j) Then Begin x1[i] := x1[j]; Inc(i); End;
    While (i < j) And (x1[i] < xx) Do Inc(i);
    If (i < j) Then Begin x1[j] := x1[i]; Dec(j); End;
  End;
  x1[i] := xx;
  If p < i - 1 Then Qsort(p, i - 1);
  If i + 1 < r Then Qsort(i + 1, r);
End;

Function Find(q: Real): Longint;
Var
  i, j: Longint;
  m: Longint;
Begin
  i := 1;
  j := cnt;
  While True Do
  Begin
    m := (i + j) div 2;
    If x[m] = q Then Begin Find := m; Exit; End;
    If q < x[m] Then j := m - 1
    Else i := m + 1;
  End;
End;

Procedure Qsortl(p, r: Longint);
Var
  x: Line;
  i, j: Longint;
Begin
  x := l[p];
  i := p;
  j := r;
  While i < j Do
  Begin
    While (i < j) And (l[j].c > x.c) Do Dec(j);
    If i < j Then Begin l[i] := l[j]; Inc(i); End;
    While (i < j) And (l[i].c < x.c) Do Inc(i);
    If i < j Then Begin l[j] := l[i]; Dec(j); End;
  End;
  l[i] := x;
  If p < i - 1 Then Qsortl(p, i - 1);
  If i + 1 < r Then Qsortl(i + 1, r);
End;

Procedure Make(Var Tree: Link; a, b: Longint);
Var
  m: Longint;
Begin
  New(Tree);
  Tree^.a := a;
  Tree^.b := b;
  Tree^.c := 0;
  Tree^.s := 0;
  If a < b Then
  Begin
    m := (a + b) div 2;
    Make(Tree^.l, a, m);
    Make(Tree^.r, m + 1, b);
  End;
End;

Procedure Updata(Tree: Link);
Begin
  If Tree^.c > 0 Then Tree^.s := x[Tree^.b + 1] - x[Tree^.a]
  Else If (Tree^.a = Tree^.b) Then Tree^.s := 0
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
    If a <= m then Insert(Tree^.l, a, b);
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

Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);

  ii := 0;
  While True Do
  Begin
    Read(n);
    If n = 0 Then
    Begin
      Close(Output);
      Exit;
    End;
    For i:=1 To n Do
    Begin
      Read(j, k, p, q);
      l[i].a := j;
      l[i].b := p;
      l[i].c := k;
      l[i].d := True;

      l[i + n].a := j;
      l[i + n].b := p;
      l[i + n].c := q;
      l[i + n].d := False;

      x1[i] := j;
      x1[i + n] := p;
    End;

    Qsort(1, 2 * n);
    x[1] := x1[1];
    cnt := 1;
    For i:=2 To 2 * n Do
      If x1[i] <> x1[i - 1] Then
      Begin
        Inc(cnt);
        x[cnt] := x1[i];
      End;
    For i:=1 To 2 * n Do
    Begin
      l[i].a := Find(l[i].a);
      l[i].b := Find(l[i].b);
      l[i].b := l[i].b - 1;
    End;

    Qsortl(1, 2 * n);
    Make(Top, 1, cnt - 1);
    ans := 0;
    For i:=1 To 2 * n - 1Do
    Begin
      If l[i].d Then Insert(Top, Trunc(l[i].a), Round(l[i].b))
        Else Delete(Top, Round(l[i].a), Round(l[i].b));
      ans :=  ans + (Top^.s) * (l[i + 1].c - l[i].c);
    End;

    Inc(ii);
    WriteLn('Test case #', ii);
    Write('Total explored area: ');
    WriteLn(ans: 0: 2);
    WriteLn;
  End;
End.
