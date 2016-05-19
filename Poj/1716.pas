Const Maxn=10000;
Const Maxm=1000000;
Var
  c,t,nt:Array[-1..Maxm]Of Longint;
  Ind,f,q:Array[-1..Maxn]Of Longint;
  Inq:Array[-1..Maxn]Of Boolean;
  i,j,k,n,m:Longint;
  x,y,z,cnt:Longint;
Procedure AE(i,j,k:Longint);
Begin
  Inc(cnt);
  t[cnt]:=j;
  c[cnt]:=k;
  nt[cnt]:=ind[i];
  ind[i]:=cnt;
End;
Function SPfa():Longint;
Var v,i,j,k,l,r:Longint;
Begin
  For i:=-1 To 10000 Do
    f[i]:=-Maxlongint;
  Fillchar(inq,Sizeof(inq),False);
  f[-1]:=0;
  l:=0;
  r:=0;
  q[l]:=-1;
  While l<=r Do Begin
    v:=q[l mod n];
    Inc(l);
    Inq[v]:=False;
    k:=Ind[v];
    While k<>-1 Do Begin
      If f[v]+c[k]>f[t[k]] Then Begin
        f[t[k]]:=f[v]+c[k];
        If Not inq[t[k]] Then Begin
          Inc(r);
          q[r mod n]:=t[k];
          Inq[t[k]]:=True;
        End;
      End;
      k:=nt[k];
    End;
  End;
  Exit(f[n]-f[-1]);
End;
Begin
  //Assign(Input,'a.in');
  Reset(Input);
  Readln(m);
  n:=0;
  cnt:=0;
  For I:=-1 To Maxn Do
    Ind[i]:=-1;
  For i:=1 To m Do Begin
    Readln(x,y);
    AE(x-1,y,2);
    If y>n Then N:=y;
  End;
  For I:=-1 To n-1 Do Begin
    AE(i,i+1,0);
    AE(i+1,i,-1);
  End;
  Writeln(spfa);
End.
