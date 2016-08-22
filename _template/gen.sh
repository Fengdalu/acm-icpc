tot=''
for file in `find . -name '*.cpp' -print`
do
    tot=${tot}' '$file
done
cat $tot > t.cpp

