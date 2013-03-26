tag:=global idutils ctags cscope
tags:=$(addprefix tags/,$(tag))

.PHONY: tags

tags: $(tags)

tags/global:
	-cd .. && gtags $@ && cd -

tags/idutils:
	-cd .. && mkid -o tags/idutils/ID && cd -

tags/ctags:
	-[ -f ../tags/ctags/list ] && ctags -L ../tags/ctags/list -o ../tags/ctags/tags

tags/cscope:
	-cd ../tags/cscope/ && cscope -b -q -k && cd -
