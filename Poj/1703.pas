Var
  a,d:Array[0..100000]Of Longint;
  i,j,k:Longint;
  ch:char;
  t,cas:Longint;
  x,y,p,q:Longint;
  n,m:Longint;
  flag:Boolean;
Function Find(i:Longint):Longint;
Begin
  If a[i]<>i Then
    a[i]:=Find(a[i]);
  Exit(a[i]);
End;
Procedure Insert(i,j:Longint);
Var p,q:Longint;
Begin
  p:=Find(i);
  q:=Find(j);
  a[p]:=q;
End;

Begin
  //Assign(Input,'a.in');
  Reset(Input);
  Readln(cas);
  For t:=1 To Cas Do Begin
    Readln(n,m);
    For i:=1 To n Do Begin
      a[i]:=i;
      d[i]:=i;
    End;
    For i:=1 To m Do Begin
      Read(ch);
      Readln(j,k);
      If ch='D' Then Begin
        If d[j]=j Then d[j]:=k Else Insert(d[j],k);
        If d[k]=k Then d[k]:=j Else Insert(d[k],j);
      End
      Else Begin
        p:=Find(j);
        q:=Find(k);
        If p=q Then Writeln('In the same gang.')
        Else Begin
          If (Find(d[j])=q)Or(Find(d[k])=p) Then Writeln('In different gangs.')
            Else Writeln('Not sure yet.');
        End;
      End;
    End;
  End;
End.
