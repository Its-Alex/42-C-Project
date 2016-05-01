#/bin/sh
groups $FT_USER | tr " " "," | sed '$!N;s/\n/ /' | tr -d '\n'
