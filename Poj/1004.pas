Var
ans:Double;
i:Longint;
j:Double;
s:String;
Begin
//Assign(Input,'a.in');
Reset(Input);
For i:=1 To 12 Do Begin
Readln(j);
ans:=ans+j;
End;
ans:=ans/12;
Writeln('$',ans:0:2);
End.

