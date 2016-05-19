Const
  Fin = 'Poj2777.in';
  Fout = 'Poj2777.out';
Type
  Obj = Record
    a, b: Longint;
    c, s: Longint;
End;
Var
  t: Array[1..100000*4]Of Obj;
  l, p, o: Longint;
  i, j, k: Longint;
  x, y, z: Longint;
  ch: Char;
  cnt: Longint;
Procedure Swap(Var i, j:Longint);
Var
  t: Longint;
Begin
  t := i;
  i := j;
  j := t;
End;
Procedure Insert(p: Longint; a, b, c: Longint);
Var m: Longint;
Begin
  If t[p].c = c Then Exit
  Else If (t[p].a >= a)  And (b >= t[p].b) Then Begin
    t[p].c := c;
    t[p].s := 1 shl (c - 1);
  End Else
  Begin
    If t[p].c > 0 Then
    Begin
      t[p * 2].c := t[p].c;
      t[p * 2].s := t[p].s;
      t[p * 2 + 1].c := t[p].c;
      t[p * 2 + 1].s := t[p].s;
    End;
    m := (T[p].a + t[p].b) div 2;
    If a <= m Then Insert(p * 2, a, b, c);
    If b > m Then Insert(p * 2 + 1, a, b, c);
    If T[p * 2].c = T[p * 2 + 1].c Then t[p].c := t[p * 2].c Else t[p].c := 0;
    t[p].s := ((t[p * 2].s) Or (t[p * 2 + 1].s));
  End;
End;
Function Count(p, a, b: Longint): Longint;
Var
  s1, s2, m: Longint;
Begin
  If (t[p].a >= a)  And (b >= t[p].b) Or (t[p].c > 0) Then Count := t[p].s
  Else
  Begin
    m := (t[p].a + t[p].b) div 2;
    s1 := 0;
    s2 := 0;
    If a <= m Then s1 := Count(p * 2, a, b);
    If b > m Then S2 := Count(p * 2 + 1, a, b);
    Count := S1 Or S2;
  End;
End;
Function Make(p, a, b: Longint): Longint;
Var
  m, s1, s2: Longint;
Begin
  t[p].a := a;
  t[p].b := b;
  t[p].c := 1;
  t[p].s := 1;
  s1 := 0;
  s2 := 0;
  If a < b Then
  Begin
    m := (a + b) div 2;
    s1 := Make(p * 2, a, m);
    s2 := Make(p * 2 + 1 ,m + 1, b);
  End;
  Exit(s1 + s2 + 1);
End;
Procedure DFS(i : Longint);
Begin
  If i <= cnt Then
  Begin
    Write('[', t[i].a, ',', t[i].b, '] ');
    DFS(i * 2);
    DFS(i * 2 + 1);
  End;
End;
Begin
  //Assign(Input, Fin);
  Reset(Input);
  //Assign(Output, Fout);
  ReWrite(Output);
  ReadLn(l, p, o);
  cnt := Make(1, 1, l);
  //DFS(1);
  For i := 1 To o Do
  Begin
    Read(ch);
    If ch = 'C' Then
    Begin
      ReadLn(x, y, z);
      If x > y Then Swap(x, y);
      Insert(1, x, y, z);
    End Else
    Begin
      ReadLn(x, y);
      If x > y then Swap(x, y);
      j := Count(1, x, y);
      k := 0;
      While j <>0 Do
      Begin
        If J mod 2 = 1 Then Inc(k);
        j := j div 2;
      End;
      WriteLn(k);
    End;
  End;
  Close(Input);
  Close(Output);
End.


