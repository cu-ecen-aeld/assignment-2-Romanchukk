#!/bin/sh
#My writer.sh

if [ $# -lt 2 ]
then
    echo "error: Correct parameters were not specified"
    exit 1
fi

FILESTR=$1
WRITESTR=$2
DIRSTR=$(dirname ${FILESTR})

if [ -d ${DIRSTR} ]
then
    echo ${WRITESTR} > ${FILESTR}
else
    mkdir -p "${DIRSTR}"
    echo ${WRITESTR} > ${FILESTR}
fi

if [ $? -gt 0 ]
then
    echo "error: File could not be created"
    exit 1
fi