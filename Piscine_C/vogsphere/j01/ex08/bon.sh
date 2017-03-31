#/bin/sh
ldapsearch -Q sn='*BON*' | grep 'sn:' | wc -l | cut -d " " -f7
