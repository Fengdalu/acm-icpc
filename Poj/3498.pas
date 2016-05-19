Type Edge=Record
  t,p,c,n:Longint;
End;
Type point=Record
  x,y,n,m:Longint;
End;
Var
  Index:Array[-1..200]Of Longint;
  E,e1:Array[1..100000]Of Edge;
  h:Array[-1..200]Of Longint;
  hv:Array[0..202]Of Longint;
  p:Array[0..100]Of Point;
  eptr:Longint;
  i,j,k:Longint;
  n:Longint;
  d:Double;
  ans:Longint;
  ed:Longint;
  Cas:Longint;
  tt:Longint;
  flag:Boolean;
Function Min(i,j:Longint):Longint;
Begin
  If i<j Then Exit(i);
  Exit(j);
End;
Procedure AE(i,j,k:Longint);
Begin
  Inc(eptr);
  e[eptr].t:=j;
  e[eptr].c:=k;
  e[eptr].n:=Index[i];
  Index[i]:=eptr;
  e[eptr].p:=Succ(eptr);
  Inc(eptr);
  e[eptr].t:=i;
  e[eptr].c:=0;
  e[eptr].n:=Index[j];
  Index[j]:=eptr;
  e[eptr].p:=Pred(eptr);
End;
Function Dis(x1,y1,x2,y2:Longint):Double;
Begin
  Exit(Sqrt(Sqr(x1-x2)+Sqr(y1-y2)));
End;
Function Aug(u,t:Longint):Longint;
Var
  minh,k,d,l:Longint;
Begin
  If u=ed Then Exit(t);
  minh:=2*n+1;
  k:=Index[u];
  l:=t;
  While k<>-1 Do Begin
    If e[k].c>0 Then Begin
      If h[e[k].t]+1=h[u] Then Begin
        d:=Aug(e[k].t,Min(e[k].c,l));
        Dec(e[k].c,d);
        Inc(e[e[k].p].c,d);
        Dec(l,d);
        If l=0 Then Break;
        If h[-1]>=2*n+1 Then Exit(t-l);
      End;
      minh:=Min(minh,h[e[k].t]);
    End;
    k:=e[k].n;
  End;
  If l=t Then Begin
    Dec(hv[h[u]]);
    If hv[h[u]]=0 Then Begin h[-1]:=2*n+1;Exit(t-l);End;
    h[u]:=Succ(minh);
    Inc(hv[h[u]]);
  End;
  Exit(t-l);
End;
Function Sap(i:Longint):Longint;
Begin
  Fillchar(h,Sizeof(h),0);
  Fillchar(hv,Sizeof(hv),0);
  hv[0]:=2*n+1;
  Sap:=0;
  ed:=i;
  While h[-1]<2*n+1 Do
    Inc(Sap,Aug(-1,Maxlongint));
End;

Begin
  Readln(cas);
  For tt:=1 To Cas Do Begin
    Read(n,d);
    eptr:=0;
    ans:=0;
    For i:=-1 To 2*n-1 Do
      Index[i]:=-1;
    For i:=0 To 100 Do Begin
      p[i].x:=i*(Round(d)+1);
      p[i].y:=i*(Round(d)+1);
    End;

    For i:=0 To n-1 Do Begin
      Read(p[i].x,p[i].y,p[i].n,p[i].m);
      If p[i].n>0 Then AE(-1,i,p[i].n);
      AE(i,i+n,p[i].m);
      Inc(ans,p[i].n);
      End;
    For i:=0 To n-1 Do
      For j:=i+1 To n-1 Do
        If Dis(p[i].x,p[i].y,p[j].x,p[j].y)<=d Then Begin
          AE(i+n,j,Maxlongint);
          AE(j+n,i,Maxlongint);
      End;
    If ans=0 Then Begin Write('-1');Continue;End;
    Flag:=False;
    e1:=e;
    For i:=0 To n-1 Do Begin
      If Sap(i)=ans Then Begin Write(i,' ');Flag:=True;End;
      e:=e1;
    End;
    If Flag Then Writeln Else Writeln('-1');
  End;
End.
