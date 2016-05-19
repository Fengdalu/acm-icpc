Var
  c:Array[0..30000]Of Longint;
  i,j,k,n,m:Longint;
  x,y,p,q:Longint;
  ans:Longint;
Function Find(i:Longint):Longint;
Begin
  If c[i]<>i Then
    c[i]:=Find(c[i]);
  Exit(c[i]);
End;

Begin
  //Assign(Input,'a.in');
  Reset(Input);
  While True Do Begin
    Readln(n,m);
    If (m=0)And(n=0) Then Break;
    For i:=0 To n do
      c[i]:=i;
    Ans:=0;
    For i:=1 to m Do Begin
      Read(k);
      Read(x);
      x:=Find(x);
      For j:=1 To k-1 Do Begin
        Read(y);
        y:=Find(y);
        c[y]:=x;
      End;
    End;
    x:=Find(0);
    For i:=1 To n-1 Do Begin
      y:=Find(i);
      If y=x Then Inc(ans);
    End;
    Writeln(Ans+1);
  End;
End.
