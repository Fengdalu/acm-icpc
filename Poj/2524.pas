Const Maxn=50000;
Var
  f:Array[0..Maxn]Of Longint;
  a:Array[0..Maxn]Of Boolean;
  i,j,k,cas,ans:Longint;
  x,y:Longint;
  n,m:Longint;
Function Find(I:Longint):Longint;
Begin
  If f[i]<>i Then
    F[I]:=Find(f[i]);
  Exit(f[i]);
End;
Begin
  //Assign(Input,'a.in');
  Reset(Input);
  cas:=0;
  While True Do Begin
    Inc(cas);
    Readln(n,m);
    If (n=0)And(m=0) Then Exit;
    For i:=1 To n Do
      f[i]:=i;
    Fillchar(a,Sizeof(a),False);
    For i:=1 To m Do Begin
      Readln(j,k);
      x:=Find(j);
      y:=Find(k);
      f[x]:=y;
    End;

    For i:=1 To n Do Begin
      j:=Find(i);
      a[j]:=True;
    End;
    ans:=0;
    For i:=1 To n Do
      If a[i] Then Inc(ans);
    Writeln('Case ',cas,': ',ans);
  End;
End.
