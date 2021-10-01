#!/bin/bash

date -d "$3/$2/$1" &> /dev/null

if [ $? -eq 0 ]
then
    cal $2 $3
else
    echo INVALID DATE ENTERED
fi