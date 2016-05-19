type
        edge=record
        x,y,z:longint;
end;
var
        m,n:longint;
        i,j,k:longint;
        j1,j2,k1,k2:longint;
        g:array[1..15000]of edge;
        a:array[1..2000]of longint;
        visited:array[1..15000]of boolean;
        flag:boolean;
        v:longint;
        min:longint;
procedure Swap(var i,j:edge);
var tmp:edge;
begin
        tmp:=i;
        i:=j;
        j:=tmp;
end;

procedure Qsort(p,r:longint);
var i,j:longint;
tmp:edge;

begin
        tmp:=g[p];
        i:=p;
        j:=r;
        while i<j do begin
                while (i<j)and(g[j].z>tmp.z) do dec(j);
                if i<j then begin
                        g[i]:=g[j];
                        inc(i);
                end;
                while (i<j)and(g[i].z<tmp.z) do inc(i);
                if i<j then begin
                        g[j]:=g[i];
                        dec(j);
                end;
        end;
        g[i]:=tmp;
        if i<r then Qsort(i+1,r);
        if i>p then Qsort(p,i-1);
end;
begin
        assign(input,'');
        reset(input);
        readln(n,m);
        for i:=1 to n do
                a[i]:=-1;
        for i:=1 to m do
                readln(g[i].x,g[i].y,g[i].z);
        Qsort(1,m);
        Fillchar(visited, sizeof(visited), false);
        v:=0;
        for i:=1 to n-1 do begin
        flag:=false;
        while not flag do begin
             inc(v);
             j:=g[v].x;
             k:=g[v].y;
             j1:=j;
             k1:=k;
             while a[j]<>-1 do
                j:=a[j];
             while a[k]<>-1 do
                k:=a[k];
             While a[j1]<>-1 do begin
                j2:=j1;
                j1:=a[j1];
                a[j2]:=j;
             end;
             while a[k1]<>-1 do begin
                k2:=k1;
                k1:=a[k1];
                a[k2]:=k;
             end;

             if j<>k then begin
                visited[v]:=true;
                flag:=true;
                a[k]:=j;
             end;
        end;
        end;
        min:=0;
        for i:=1 to m do
                if (min<g[i].z)and(visited[i]) then min:=g[i].z;
        writeln(min);
        writeln(n-1);
        for i:=1 to m do
               if (visited[i]) then writeln(g[i].x,' ',g[i].y);
end.

