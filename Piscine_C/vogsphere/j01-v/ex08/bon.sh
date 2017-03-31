#/bin/sh
ldapsearch -Q cn | grep BON | wc -l | bc
