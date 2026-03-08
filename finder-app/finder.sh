#!/bin/sh
#My finder.sh

if [ $# -lt 2 ]
then
    echo "error: Correct parameters were not specified"
    exit 1
fi

FILESTR=$1
SRCHSTR=$2

if [ -d $1 ]
then
    filenum=$(grep -r ${SRCHSTR}  "${FILESTR}" | cut -d: -f1 | sort | uniq | wc -l)
    matchnum=$(grep -r ${SRCHSTR} "${FILESTR}" | wc -l)
    echo "The number of files are ${filenum} and the number of matching lines are ${matchnum}"
else
    echo "error: argument filesdir does not represent a directory on the filesystem"
    exit 1
fi

