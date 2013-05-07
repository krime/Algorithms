# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# User specific aliases and functions
alias wget='wget --retry-connrefused'
# export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
# export LIBRARY_PATH=/usr/local/lib
# export CPATH=/usr/local/include

# less color configure
export LESS_TERMCAP_mb=$'\E[01;31m'          # begin blinking
export LESS_TERMCAP_md=$'\E[01;38;5;74m'     # begin bold
export LESS_TERMCAP_me=$'\E[01;37m'          # end mode
export LESS_TERMCAP_se=$'\E[0m'              # end standout-mode
export LESS_TERMCAP_so=$'\E[01;44;33m'       # begin standout-mode - info box
export LESS_TERMCAP_ue=$'\E[0;01;37m'        # end underline
export LESS_TERMCAP_us=$'\E[04;38;01;96m'    # begin underline

# export LESS_TERMCAP_mb=$'\E[01;31m'       # begin blinking
# export LESS_TERMCAP_md=$'\E[01;38;5;74m'  # begin bold
# export LESS_TERMCAP_me=$'\E[0m'           # end mode
# export LESS_TERMCAP_se=$'\E[0m'           # end standout-mode
# export LESS_TERMCAP_so=$'\E[38;5;246m'    # begin standout-mode - info box
# export LESS_TERMCAP_ue=$'\E[0m'           # end underline
# export LESS_TERMCAP_us=$'\E[04;38;5;146m' # begin underline

# bold blue
# export LESS_TERMCAP_mb=$'\E[01;34m'
# bold green
# export LESS_TERMCAP_md=$'\E[01;32m'
# bold white
# export LESS_TERMCAP_me=$'\E[01;37m'
# text white
# export LESS_TERMCAP_se=$'\E[0m'
# yellow with blue background
# export LESS_TERMCAP_so=$'\E[01;44;33m'
# bold yellow
# export LESS_TERMCAP_ue=$'\E[01;33m'
# bold cyan
# export LESS_TERMCAP_us=$'\E[01;36m'
# linux_logo -L redhat
# echo -en "\e[01;93m"
# fortune | cowthink
# export PS1="\[\e[s\e[53;0H\e[0;107m\e[K\e[1;90m \s v\V \e[1;37;40m \j Jobs \e[1;94;107m [\!,\#] CMD \e[1;37;40m @\H \e[1;90;107m Dev \l \e[0;30;40m \e[53;74H\e[1;90;107m \d \t CST $(date +%Y) \e[0m\e[u\]\[\e[1;34;40m\]\u \[\e[1;37;40m\][\W]\e[K\n\$ "

pr_xterm_colors () {
  [ "$TERM" = "xterm" ] && TERM='xterm-256color'
  x=`tput op`
  y=`printf %$((${COLUMNS}-6))s`
  for i in {0..256}; do
    o=00$i;echo -e ${o:${#o}-3:3} `tput setaf $i
    tput setab $i`${y// /=}$x
  done
  TERM='xterm'
}

memtotal() {
  sed -n "s/MemTotal:[\t ]\+\([0-9]\+\) kB/\1/Ip" /proc/meminfo
}

memfree() {
  sed -n "s/MemFree:[\t ]\+\([0-9]\+\) kB/\1/p" /proc/meminfo
}

meminfo() {
  echo "scale=2;$(memfree)*100/$(memtotal)"|bc -q
}

memingb() {
  echo "scale=2;$(memtotal)/1024/1024"|bc -q
}

gitstat() {
  GitBranchStat=$(git status -s 2> /dev/null)
  GitBranchStatResult=$?
  if [ ! $GitBranchStatResult -eq 0 ]; then
      echo -en "\e[m"
  elif [ "$GitBranchStat" = "" ]; then
      echo -en " \e[1;30m[\e[1;38;5;2m#"
  else
      echo -en " \e[1;30m[\e[1;38;5;78m*"
  fi
  echo -n $(git branch --color=never 2> /dev/null | sed 's@\* @@')
  if [ $GitBranchStatResult -eq 0 ]; then
      if [ "$GitBranchStat" = "" ]; then
          echo -n "#"
      else
          echo -n "*"
      fi
      echo -en '\e[1;30m]\e[m'
  fi
}

PS_HACK='\[\n\e[m\e[38;5;2m\]$(memperc) % \[\e[38;5;78m\]/ $(memingb) GB \[\e[m\e[38;5;65m\]$(< /proc/loadavg)\[\e[m \e[38;5;27m\]\d \t\[\e[1;30m\]\n[\[\e[38;5;252m\]$$:$PPID \j:\!\[\e[1;30m\]]\[\e[1;30m\][\[\e[38;5;27m\]\u@\H\[\e[1;30m\]:\[\e[1;37m\]${SSH_TTY:-$(tty)} \[\e[0;32m\]+${SHLVL}\[\e[1;30m\]] \[\e[1;30m\][\[\e[0m\]\[\e[1;37m\]\W\[\e[0m\]\[\e[1;30m\]]$(gitstat)\[\e[1;37m\]\n\$ '

PS1=${PS_HACK}

[ "$PS1" = "$PS_HACK" ] && export PROMPT_COMMAND='history -a'
# PROMPT_COMMAND='history -a;echo -en "\n\e[1m\e[38;5;2m"$MEMINFO % "\e[38;5;78m/ "$MEMINGB GB" \e[1m\e[38;5;73m$(< /proc/loadavg)\e[1m \e[38;5;33m`date +"%a %b %d %H:%M:%S"`"'

