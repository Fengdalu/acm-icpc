var
  a,b:array[0..101,0..101]of integer;
  tf:array[0..101,0..101]of boolean;
  r,c:integer;
  i,j:integer;
  max:integer;
function search(i,j:integer):integer;
  var max,m,n:integer;
  begin
    if (not tf[i,j]) then
      begin
        max:=1;
        for m:=i-1 to i+1 do
          for n:=j-1 to j+1 do
            begin
              if (abs(m-i)=1)xor(abs(n-j)=1) then
                begin
                  if a[m,n]<a[i,j] then
                    begin
                      if (not tf[m,n]) then
                        begin
                          b[m,n]:=search(m,n);
                          tf[m,n]:=true;
                        end;
                      if b[m,n]>max then max:=b[m,n];
                    end;
                end;
            end;
        search:=max+1;
      end
    else
      search:=b[i,j];
  end;


begin
  read(r,c);
  fillchar(tf,sizeof(tf),false);
  for i:=0 to r+1 do
    for j:=0to c+1 do
      if (i=0)or(j=0)or(i=r+1)or(j=c+1)
        then a[i,j]:=maxint else read(a[i,j]);
  for i:=1 to r do
    for j:=1 to c do
      b[i,j]:=1;
  for i:=1 to r do
    for j:=1 to c do
        if (a[i+1,j]>=a[i,j])and(a[i-1,j]>=a[i,j])and(a[i,j+1]>=a[i,j])and(a[i,j-1]>=a[i,j])
          then tf[i,j]:=true;   
  max:=0;
  for i:=1 to r do
    for j:=1 to c do
    begin
      b[i,j]:=search(i,j);
      if b[i,j]>max then max:=b[i,j];
    end;
  writeln(max);
end.
