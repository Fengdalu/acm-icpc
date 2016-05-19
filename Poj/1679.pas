var
	f:array[1..100]of boolean;
	h,road,pre:array[1..100]of longint;
	map:array[1..100,1..100]of longint;
	t,i,j,k,n,m,ans:longint;
        done:boolean;

procedure GetData;
var i,j,k:longint;
begin
	fillchar(map,sizeof(map),0);

	fillchar(road,sizeof(road),0);
	fillchar(pre,sizeof(pre),0);
	readln(n,m);
	for i:=1 to m do begin
		read(j,k);
		read(map[j,k]);
		map[k,j]:=map[j,k];
	end;
        done:=false;
end;

function Prim:longint;
var ans,i,j,k,min,v:longint;
begin
        for i:=1 to n do begin
                f[i]:=false;
		h[i]:=maxlongint-1;
        end;
	h[1]:=0;
	if not done then pre[1]:=-1;
        ans:=0;
	for i:=1 to n do begin
		v:=-1;min:=maxlongint;
		for j:=1 to n do
			if (h[j]<min)and(not f[j]) then begin v:=j; min:=h[j];end;
		f[v]:=true;
		if not done then road[i]:=v;
                if h[v]=maxlongint-1 then begin
                        if not done then pre[v]:=-1;
                        h[v]:=0;
                end;
		inc(ans,h[v]);
		for j:=1 to n do
			if (map[v,j]<>0)and(not f[j])and(map[v,j]<h[j])then
				begin
				        h[j]:=map[v,j];
					if not done then pre[j]:=v;
				end;
	end;
        done:=true;
	exit(ans);
end;

procedure cal;
var i,j,k,tmp,ans1:longint;
	flag:boolean;
begin
	ans:=prim;
	flag:=false;
	for i:=2 to n do begin
                if pre[road[i]]=-1 then continue;
		tmp:=map[pre[road[i]],road[i]];

		map[pre[road[i]],road[i]]:=0;
		map[road[i],pre[road[i]]]:=0;
		ans1:=prim;
		if ans1=ans then  begin writeln('Not Unique!'); flag:=true;break; end;
		map[pre[road[i]],road[i]]:=tmp;
		map[road[i],pre[road[i]]]:=tmp;

	end;
	if not flag then writeln(ans);
end;
begin
       { assign(input,'a.in');
        reset(input);}
	readln(t);
	for i:=1 to t do begin
		Getdata;
		cal;
	end;
end.

