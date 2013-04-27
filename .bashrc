# To the extent possible under law, the author(s) have dedicated all 
# copyright and related and neighboring rights to this software to the 
# public domain worldwide. This software is distributed without any warranty. 
# You should have received a copy of the CC0 Public Domain Dedication along 
# with this software. 
# If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 

# base-files version 4.1-1

# ~/.bashrc: executed by bash(1) for interactive shells.

# The latest version as installed by the Cygwin Setup program can
# always be found at /etc/defaults/etc/skel/.bashrc

# Modifying /etc/skel/.bashrc directly will prevent
# setup from updating it.

# The copy in your home directory (~/.bashrc) is yours, please
# feel free to customise it to create a shell
# environment to your liking.  If you feel a change
# would be benifitial to all, please feel free to send
# a patch to the cygwin mailing list.

# User dependent .bashrc file

# If not running interactively, don't do anything
[[ "$-" != *i* ]] && return

# Shell Options
#
# See man bash for more options...
#
# Don't wait for job termination notification
# set -o notify
#
# Don't use ^D to exit
# set -o ignoreeof
#
# Use case-insensitive filename globbing
# shopt -s nocaseglob
#
# Make bash append rather than overwrite the history on disk
# shopt -s histappend
#
# When changing directory small typos can be ignored by bash
# for example, cd /vr/lgo/apaache would find /var/log/apache
# shopt -s cdspell

# Completion options
#
# These completion tuning parameters change the default behavior of bash_completion:
#
# Define to access remotely checked-out files over passwordless ssh for CVS
# COMP_CVS_REMOTE=1
#
# Define to avoid stripping description in --option=description of './configure --help'
# COMP_CONFIGURE_HINTS=1
#
# Define to avoid flattening internal contents of tar files
# COMP_TAR_INTERNAL_PATHS=1
#
# Uncomment to turn on programmable completion enhancements.
# Any completions you add in ~/.bash_completion are sourced last.
# [[ -f /etc/bash_completion ]] && . /etc/bash_completion

# History Options
#
# Don't put duplicate lines in the history.
# export HISTCONTROL=$HISTCONTROL${HISTCONTROL+,}ignoredups
#
# Ignore some controlling instructions
# HISTIGNORE is a colon-delimited list of patterns which should be excluded.
# The '&' is a special pattern which suppresses duplicate entries.
# export HISTIGNORE=$'[ \t]*:&:[fb]g:exit'
# export HISTIGNORE=$'[ \t]*:&:[fb]g:exit:ls' # Ignore the ls command as well
#
# Whenever displaying the prompt, write the previous line to disk
# export PROMPT_COMMAND="history -a"

# Aliases
#
# Some people use a different file for aliases
# if [ -f "${HOME}/.bash_aliases" ]; then
#   source "${HOME}/.bash_aliases"
# fi
#
# Some example alias instructions
# If these are enabled they will be used instead of any instructions
# they may mask.  For example, alias rm='rm -i' will mask the rm
# application.  To override the alias instruction use a \ before, ie
# \rm will call the real rm not the alias.
#
# Interactive operation...
# alias rm='rm -i'
# alias cp='cp -i'
# alias mv='mv -i'
#
# Default to human readable figures
# alias df='df -h'
# alias du='du -h'
#
# Misc :)
# alias less='less -r'                          # raw control characters
# alias whence='type -a'                        # where, of a sort
alias grep='grep --color'                     # show differences in colour
# alias egrep='egrep --color=auto'              # show differences in colour
# alias fgrep='fgrep --color=auto'              # show differences in colour
#
# Some shortcuts for different directory listings
alias ls='ls -hF --color=tty'                 # classify files in colour
alias iconvcn='iconv -t utf-8 -f gbk'
alias ipconfig='ipconfig | iconvcn | sed /IPv4/s/119/125/'
# alias dir='ls --color=auto --format=vertical'
# alias vdir='ls --color=auto --format=long'
# alias ll='ls -l'                              # long list
# alias la='ls -A'                              # all but . and ..
# alias l='ls -CF'                              #

# Umask
#
# /etc/profile sets 022, removing write perms to group + others.
# Set a more restrictive umask: i.e. no exec perms for others:
# umask 027
# Paranoid: neither group nor others have any perms:
# umask 077

# Functions
#
# Some people use a different file for functions
# if [ -f "${HOME}/.bash_functions" ]; then
#   source "${HOME}/.bash_functions"
# fi
#
# Some example functions:
#
# a) function settitle
# settitle () 
# { 
#   echo -ne "\e]2;$@\a\e]1;$@\a"; 
# }
# 
# b) function cd_func
# This function defines a 'cd' replacement function capable of keeping, 
# displaying and accessing history of visited directories, up to 10 entries.
# To use it, uncomment it, source this file and try 'cd --'.
# acd_func 1.0.5, 10-nov-2004
# Petar Marinov, http:/geocities.com/h2428, this is public domain
# cd_func ()
# {
#   local x2 the_new_dir adir index
#   local -i cnt
# 
#   if [[ $1 ==  "--" ]]; then
#     dirs -v
#     return 0
#   fi
# 
#   the_new_dir=$1
#   [[ -z $1 ]] && the_new_dir=$HOME
# 
#   if [[ ${the_new_dir:0:1} == '-' ]]; then
#     #
#     # Extract dir N from dirs
#     index=${the_new_dir:1}
#     [[ -z $index ]] && index=1
#     adir=$(dirs +$index)
#     [[ -z $adir ]] && return 1
#     the_new_dir=$adir
#   fi
# 
#   #
#   # '~' has to be substituted by ${HOME}
#   [[ ${the_new_dir:0:1} == '~' ]] && the_new_dir="${HOME}${the_new_dir:1}"
# 
#   #
#   # Now change to the new dir and add to the top of the stack
#   pushd "${the_new_dir}" > /dev/null
#   [[ $? -ne 0 ]] && return 1
#   the_new_dir=$(pwd)
# 
#   #
#   # Trim down everything beyond 11th entry
#   popd -n +11 2>/dev/null 1>/dev/null
# 
#   #
#   # Remove any other occurence of this dir, skipping the top of the stack
#   for ((cnt=1; cnt <= 10; cnt++)); do
#     x2=$(dirs +${cnt} 2>/dev/null)
#     [[ $? -ne 0 ]] && return 0
#     [[ ${x2:0:1} == '~' ]] && x2="${HOME}${x2:1}"
#     if [[ "${x2}" == "${the_new_dir}" ]]; then
#       popd -n +$cnt 2>/dev/null 1>/dev/null
#       cnt=cnt-1
#     fi
#   done
# 
#   return 0
# }
# 
# alias cd=cd_func

[ -x ~/.ssh_agent ] && . ~/.ssh_agent
# export SSH_AGENT_PID=443
# . ~/.ssh/environment
eval "$(dircolors -b ~/.dircolors)"
# Less Colors for Man Pages
export LESS_TERMCAP_mb=$'\E[01;34m'       # begin blinking
export LESS_TERMCAP_md=$'\E[01;38;5;74m'  # begin bold
export LESS_TERMCAP_me=$'\E[0m'           # end mode
export LESS_TERMCAP_se=$'\E[0m'           # end standout-mode
export LESS_TERMCAP_so=$'\E[07;33;5;246m' # begin standout-mode - info box
export LESS_TERMCAP_ue=$'\E[0m'           # end underline
export LESS_TERMCAP_us=$'\E[04;38;5;146m' # begin underline
# export LD_LIBRARY_PATH=/lib:/usr/lib:/usr/local/lib
# export LIBRARY_PATH=/lib:/usr/lib:/usr/local/lib
# export CPATH=/usr/include:/usr/local/include
export LC_ALL=en_US.utf-8

if test -n "${PATH}"; then
  # PATH is not empty

  # Check if path is already in PATH
  if ! /bin/echo ${PATH} | /bin/grep -q "^/bin:" ; then
    # Path is not already in PATH, append it to PATH
    export PATH="/bin:${PATH}"
  fi
else
  # PATH is empty
  export PATH="/bin"
fi

export CYGWIN="binmode ntsec"
export PS1='\[\e]0;\w\a\]\n\[\e[1;94m\]\u \[\e[1;97m\][\W] \[\e[1;90;107m\] \d \t CST $(date +%Y) \[\e[0m\]\n\$ '
clear
linux_logo -f -L 21
fortune | cowthink

# Prompt Colors Definition
# Prompt Style
# 0=None 1=BOLD 4=UNDERSCORE 5=BLINK 7=REVERSE 8=CONCEALED
_PNR_='\e[0m'
_PBD_='\e[1m'
_PUL_='\e[4m'
_PBL_='\e[5m'
_PRV_='\e[7m'
_PHD_='\e[8m'
# Prompt Colors
# 1st BIT
# 3=NORMAL    FOREGROUND     4=NORMAL    BACKGROUND
# 9=HIGHLIGHT FOREGROUND    10=HIGHLIGHT BACKGROUND
# 2nd BIT
# 0=BLACK(DARK) 1=RED     2=GREEN 3=YELLOW
# 4=BLUE        5=MAGENTA 6=CYAN  7=WHITE
_FND_='\e[30m'
_FNR_='\e[31m'
_FNG_='\e[32m'
_FNY_='\e[33m'
_FNB_='\e[34m'
_FNM_='\e[35m'
_FNC_='\e[36m'
_FNW_='\e[37m'
_BND_='\e[40m'
_BNR_='\e[41m'
_BNG_='\e[42m'
_BNY_='\e[43m'
_BNB_='\e[44m'
_BNM_='\e[45m'
_BNC_='\e[46m'
_BNW_='\e[47m'
_FHD_='\e[90m'
_FHR_='\e[91m'
_FHG_='\e[92m'
_FHY_='\e[93m'
_FHB_='\e[94m'
_FHM_='\e[95m'
_FHC_='\e[96m'
_FHW_='\e[97m'
_BHD_='\e[100m'
_BHR_='\e[101m'
_BHG_='\e[102m'
_BHY_='\e[103m'
_BHB_='\e[104m'
_BHM_='\e[105m'
_BHC_='\e[106m'
_BHW_='\e[107m'

_PCOLS_=$(tput cols)
_PLINS_=$(tput lines)

PS_SHEL="\[$_PBD_$_FHD_$_BHW_\] \s v\V \[$_PNR_\]"
PS_JOBS="\[$_PBD_$_FNW_$_BND_\] \j Jobs \[$_PNR_\]"
PS_CMDS="\[$_PBD_$_FHB_$_BHW_\] [\#/\!] \[$_PNR_\]"
PS_HOST="\[$_PBD_$_FNC_$_BND_\] \H \[$_PNR_\]"
PS_DEVC="\[$_PBD_$_FHD_$_BHW_\] \l \[$_PNR_\]"
PS_DATE="\[$_PBD_$_FHD_$_BHW_\] \d \t \[$_PNR_\]"
PS_PIDS="\[$_PBD_$_FND_$_BNW_\] $$:$PPID \[$_PNR_\]"
PS_SINS="\[$_PBD_$_FHD_$_BHW_\] +$SHLVL \[$_PNR_\]"
PS_SSHT="\[$_PBD_$_FHC_$_BHD_\] ${SSH_TTY:-lo} \[$_PNR_\]"
PS_SEPR="\[$_PNR_$_FND_$_BND_\] "
PS_OVLN="\[\e[$((_PLINS_-1));0H\]$_PUL_`printf %${_PCOLS_}s`\[$_PNR_\]"
PS_STAT="${PS_OVLN}${PS_SHEL}${PS_JOBS}${PS_CMDS}${PS_PIDS}${PS_SINS}${PS_HOST}${PS_SSHT}${PS_DEVC}\e[${_PLINS_};$((_PCOLS_-20))H${PS_DATE}"

PS_PMPT="\[$_PBD_$_FNB_$_BND_\]\u \[$_PBD_$_FNW_$_BND_\][\W]"
PS_NORM="\n\[\e[s\e[$_PCOLS_;0H\e[K${PS_STAT}\e[0m\e[u\]\[${PS_PMPT}\e[K\n\$ "

PS_HACK='\[\e[1;30m\]\n[\[\e[38;5;246m\]$$:$PPID \j:\!\[\e[1;30m\]]\[\e[1;30m\][\[\e[38;5;27m\]\u@\H\[\e[1;30m\]:\[\e[0;37m\]${SSH_TTY:-\l} \[\e[0;32m\]+${SHLVL}\[\e[1;30m\]] \[\e[1;37m\]\w\[\e[0;37m\]\n\$ '
PS1=${PS_HACK}

MEMTOTAL=$(sed -n "s/MemTotal:[\t ]\+\([0-9]\+\) kB/\1/Ip" /proc/meminfo)
MEMUSAGE=$(sed -n "s/MemFree:[\t ]\+\([0-9]\+\) kB/\1/p" /proc/meminfo)
MEMINFO=$(echo "scale=2;$MEMUSAGE*100/$MEMTOTAL"|bc -q)
MEMINGB=$(echo "scale=2;$MEMTOTAL/1024/1024"|bc -q)
[ "$PS1" = "$PS_HACK" ] && PROMPT_COMMAND='history -a;echo -en "\n\e[m\e[38;5;2m"$MEMINFO % "\e[38;5;78m/ "$MEMINGB GB" \e[m\e[38;5;65m$(< /proc/loadavg)\e[m \e[38;5;27m`date +"%a %b %d %H:%M:%S"`"'

