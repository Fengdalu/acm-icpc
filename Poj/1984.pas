Const Maxm=40000;
Const Maxn=40000;
Var
  ra,rb,rx,ry:Array[1..Maxm]Of Longint;
  aa,ab,an,af,ans:Array[1..Maxm]Of Longint;
  f,x,y:Array[1..Maxn]Of Longint;
  n,m,i,j,k,w,l:Longint;
  a,b,c:Longint;
  ch:Char;
Procedure Qsort(p,r:Longint);
Var
  i,j,x:Longint;
Begin
If p<r Then Begin
  x:=af[p];
  i:=p;
  j:=r;
  While i<j Do Begin
    While (i<j)And(af[j]>x)Do Dec(j);
    If i<j Then Begin af[i]:=af[j];Inc(i);End;
    While (i<j)And(af[i]<x)Do Inc(i);
    If i<j Then Begin af[j]:=af[i];Dec(j);End;
  End;
  af[i]:=x;
  Qsort(i+1,r);
  Qsort(p,i-1);
End;
End;
Procedure Qsortn(p,r:Longint);
Var
  i,j,x:Longint;
Begin
If p<r Then Begin
  x:=an[p];
  i:=p;
  j:=r;
  While i<j Do Begin
    While (i<j)And(an[j]>x)Do Dec(j);
    If i<j Then Begin an[i]:=an[j];Inc(i);End;
    While (i<j)And(an[i]<x)Do Inc(i);
    If i<j Then Begin an[j]:=an[i];Dec(j);End;
  End;
  an[i]:=x;
  Qsort(i+1,r);
  Qsort(p,i-1);
End;
End;
Function Find(p:Longint):Longint;
Var
  sx,sy,r,q:Longint;
  tx,ty:Longint;
Begin
  r:=p;
  sx:=0;
  sy:=0;
  While f[r]<>r Do Begin
    Inc(sx,x[r]);
    Inc(sy,y[r]);
    r:=f[r];
  End;
  While f[p]<>p Do Begin
    tx:=sx;
    ty:=sy;
    Dec(sx,x[p]);
    Dec(sx,y[p]);
    f[p]:=r;
    x[p]:=tx;
    y[p]:=ty;
    p:=f[p];
  End;
  Exit(r);
End;
Procedure init;
Begin
  Fillchar(x,Sizeof(x),0);
  Fillchar(y,Sizeof(y),0);
  For i:=1 To n Do
    f[i]:=i;
End;
Begin
  //Assign(Input,'a.in');
  Reset(Input);
  Readln(n,m);
  For i:=1 To m Do Begin
    Read(j,k);
    ra[i]:=j;
    rb[i]:=k;
    Read(w);
    Read(ch);
    Readln(ch);
    If ch='N' Then rx[i]:=w;
    If ch='S' Then rx[i]:=-w;
    If ch='E' Then ry[i]:=w;
    If ch='W' Then ry[i]:=-w;
  End;
  Readln(k);
  For i:=1 To k Do Begin
    Readln(aa[i],ab[i],af[i]);
    an[i]:=i;
  End;
  Qsort(1,k);
  l:=1;
  init;
  For i:=1 To m Do Begin
    a:=Find(ra[i]);
    b:=Find(rb[i]);
    x[b]:=x[ra[i]]+rx[i]-x[rb[i]];
    y[b]:=y[ra[i]]+ry[i]-y[rb[i]];
    f[b]:=a;
    While (af[l]=i)And(l<=k) Do Begin
      a:=Find(aa[l]);
      b:=Find(ab[l]);
      If a<>b Then ans[l]:=-1 Else
        ans[l]:=Abs(x[aa[l]]-x[ab[l]])+Abs(y[aa[l]]-y[ab[l]]);
      Inc(l);
    End;
  End;
  Qsortn(1,k);
  For i:=1 To k Do
    Writeln(ans[i]);
End.
