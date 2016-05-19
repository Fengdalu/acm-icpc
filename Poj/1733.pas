Var
  a,b,c:Array[0..10010]Of Longint;
  f,w:Array[0..10010]Of Longint;
  num,hash:Array[0..10010]Of Longint;
  i,j,k,x,y,n,m,cnt:Longint;
  ch:Char;
Procedure Qsort(p,r:Longint);
Var x,y,i,j:Longint;
Begin
  x:=hash[p];
  y:=num[p];
  i:=p;
  j:=r;
  While i<j Do Begin
    While (i<j)And(hash[j]<x) Do Dec(j);
    If i<j Then Begin hash[i]:=hash[j];num[i]:=num[j];Inc(i);End;
    While (i<j)And(Hash[i]>x) Do Inc(i);
    If i<j Then Begin hash[j]:=hash[i];num[j]:=num[i];Dec(j);End;
  End;
  hash[i]:=x;
  num[i]:=y;
  If i+1<r then Qsort(i+1,r);
  If i-1>p then Qsort(p,i-1);
End;
Function Find(i:Longint):Longint;
Var t:Longint;
Begin
  If f[i]<>i Then Begin
    t:=f[i];
    f[i]:=Find(f[i]);
    w[i]:=w[t] Xor w[i];
  End;
  Exit(f[i]);
End;
Begin
  //Assign(Input,'a.in');
  Reset(Input);
  Readln(m);
  Readln(m);
  For i:=1 to m Do Begin
    Read(j,k);
    Read(ch);
    Readln(ch);
    If ch='o' Then c[i]:=1 Else c[i]:=0;
    hash[i*2]:=j-1;
    num[i*2]:=i*2;
    hash[i*2+1]:=k;
    num[i*2+1]:=i*2+1;
  End;
  Qsort(1,m*2+1);
  cnt:=0;
  For i:=1 To 2*m+1 Do Begin
    If hash[i]<>hash[i-1] Then Inc(cnt);
    If odd(num[i]) Then b[num[i] div 2]:=cnt
    Else a[num[i]div 2]:=cnt;
  End;
  For i:=1 To cnt Do Begin
    f[i]:=i;
    w[i]:=0;
  End;
  For i:=1 To m Do Begin
    j:=Find(a[i]);
    k:=Find(b[i]);
    //Writeln(j,' ',k);
    If j=k Then Begin
      If (w[a[i]])Xor(w[b[i]])<>c[i] Then  Begin Writeln(i-1);Exit;End;
    End
    Else Begin
      w[j]:=c[i] Xor w[a[i]] Xor w[b[i]];
      f[j]:=k;
    End;
  End;
  Writeln(m);
End.

