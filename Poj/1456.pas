Const maxn=10005;
Const maxp=10005;
Var
  a,b:Array[1..Maxn]Of Longint;
  c:Array[0..Maxp]Of Longint;
  n:Longint;
  f:Array[0..Maxn]Of Longint;
  i,j,k:Longint;
  cas:Longint;
Function Find(e:Longint):Longint;
Begin
  If (f[e]<>e) Then
    f[e]:=Find(f[e]);
  Exit(f[e]);
End;

Procedure Qsort(p,r:Longint);
Var x,y,i,j:Longint;
Begin
  x:=a[p];
  y:=b[p];
  i:=p;
  j:=r;
  While i<j Do Begin
    While (i<j)And((a[j]<x)Or((a[j]=x)And(b[j]<y))) Do Dec(j);
    If i<j Then Begin a[i]:=a[j];b[i]:=b[j];Inc(i);End;
    While (i<j)And((a[i]>x)Or((a[i]=x)And(b[i]>y))) Do Inc(i);
    If i<j Then Begin a[j]:=a[i];b[j]:=b[i];Dec(j);End;
  End;
  a[i]:=x;
  b[i]:=y;
  If i+1<r Then Qsort(i+1,r);
  If i-1>p Then Qsort(p,i-1);
End;
Begin
  //Assign(Input,'a.in');
  Reset(Input);
  cas:=0;
  While not Eof(Input)Do Begin
    Inc(cas);
    Read(n);
    For i:=0 To Maxp Do
      f[i]:=i;
    If eof(Input) Then Exit;
    For i:=1 To n Do
      Read(a[i],b[i]);
    Qsort(1,n);
    Fillchar(c,Sizeof(c),0);
    For i:=1 To n Do Begin
      k:=Find(b[i]-1);
      If k<>0 Then Begin
        c[k]:=a[i];
        f[k]:=k-1;
      End Else Begin
        If c[k]=0 Then c[k]:=a[i];
      End;
    End;
    k:=0;
    For I:=0 To maxp Do
      Inc(k,c[i]);
    Writeln(k);
  End;
End.

