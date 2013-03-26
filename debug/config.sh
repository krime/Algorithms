for i in `find ../src/ -type f`; do
  readlink -f $i;
done >> ../tags/ctags/list

for i in `find ../hdr/ -type f`; do
  readlink -f $i;
done >> ../tags/ctags/list

cp -vi ../tags/ctags/list ../tags/cscope/cscope.files

cd ../doc && doxygen -g && cd -

export TERM=xterm-256color
( x=$(tput op) y=$(printf %$((${COLUMN}-1))s);for i in {0..256};do o=00$i;echo -e ${o:${#o}-3:3} $(tput setaf $i;tput setab $i)${y// /=}$x;done; )
