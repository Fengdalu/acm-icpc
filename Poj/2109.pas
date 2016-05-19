Const
  Fin = '';
  Fout = '';
Var
  n, p: Double;
  i :Longint;
Begin
  Assign(Input, Fin);
  Assign(Output, Fout);
  Reset(Input);
  Rewrite(Output);

  While Not Eof(Input) Do
  Begin
    Readln(n, p);
    i := 0;
    WriteLn(exp(Ln(p) / n):0:0);
  End;
  Close(Output);
End.
