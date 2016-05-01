#/bin/sh
ldapsearch -Q -LLL "(uid=Z*)" | grep "cn: " | cut -d " " -f2,3 | sort -r
