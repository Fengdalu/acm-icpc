Const
  Fin = '';
  Fout = '';

Var
  f: Array[1..100, 1..100]Of Longint;
  a: Array[1..100, 1..100]Of Longint;
  n, i, j, k: Longint;
Function Max(i, j: Longint): Longint;
Begin
  If i > j Then Max := i Else Max := j;
End;

Function find(i, j: Longint): Longint;
Begin
  If i = n Then
  Begin
    find := a[i, j];
  End
  Else
  Begin
    If f[i + 1, j] = -1 Then f[i + 1, j] := Find(i + 1, j);
    If f[i + 1, j + 1] = -1 Then f[i + 1, j + 1] := Find(i + 1, j + 1);
    find := Max(f[i + 1, j] ,f[i + 1, j + 1]) + a[i, j];
  End;
End;

Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);

  ReadLn(n);
  For i:=1 To n Do
    For j:=1 To i Do
    Begin
      Read(a[i, j]);
      f[i, j] := -1;
    End;
  WriteLn(find(1, 1));
  Close(Output);
End.
