Type edge=Record
  t,c,n:Longint;
End;
Var
  e:Array[1..150000]Of Edge;
  Index:Array[1..30000]Of Longint;
  i,j,k,w:Longint;
  f:Array[1..30000]Of Longint;
  q:Array[0..30000]Of Longint;
  Iq:Array[1..30000]Of Boolean;
  n,m:Longint;
  l,r:Longint;
  eptr:Longint;
Procedure AE(i,j,k:Longint);
Begin
  Inc(eptr);
  e[eptr].c:=k;
  e[eptr].t:=j;
  e[eptr].n:=Index[i];
  Index[i]:=eptr;
End;
Begin
  Readln(n,m);
  eptr:=0;
  For i:=1 To n Do
    Index[i]:=-1;
  For i:=1 To m Do Begin
    Readln(j,k,w);
    AE(j,k,w);
  End;
  l:=0;
  r:=l;
  q[0]:=1;
  For i:=1 To n Do
    f[i]:=Maxlongint;
  f[1]:=0;
  Iq[1]:=True;
  While l<=r Do Begin
    i:=q[r mod n];
    k:=Index[q[r]];
    Iq[i]:=False;
    Dec(r);
    While k<>-1 Do Begin
      If e[k].c+f[i]<f[e[k].t] Then Begin
        f[e[k].t]:=e[k].c+f[i];
        If Not Iq[e[k].t] Then Begin
          Inc(r);
          q[r mod n]:=e[k].t;
          Iq[e[k].t]:=True;
        End;
      End;
      k:=e[k].n;
    End;
  End;
  Writeln(f[n]);
End.
