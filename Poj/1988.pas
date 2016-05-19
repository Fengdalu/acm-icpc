Const Maxn=100000;
Var
  f,c,d:Array[1..Maxn]Of Longint;
  m,i,j,k:Longint;
  x,y,z:Longint;
  ch:Char;
Function Find(i:Longint):Longint;
Var t:Longint;
Begin
  If f[i]<>i Then Begin
    t:=f[i];
    f[i]:=Find(f[i]);
    d[i]:=d[t]+d[i];
  End;
  Exit(f[i]);
End;

Begin
  //Assign(Input,'a.in');
  Reset(Input);
  Readln(m);
  For i:=1 To Maxn Do Begin
    c[i]:=1;
    d[i]:=0;
    f[i]:=i;
  End;
  For i:=1 To m Do Begin
    Read(ch);
    If ch='C' Then Begin
      Readln(j);
      x:=Find(j);
      Writeln(d[j]);
    End Else Begin
      Readln(j,k);
      x:=Find(j);
      y:=Find(k);
      f[x]:=y;
      d[x]:=c[y];
      c[y]:=c[x]+c[y];
    End;
  End;
End.


