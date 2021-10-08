#!/bin/bash

date -d "$3/$2/$1" &> /dev/null #check date using date -d and redirect stdout and stderr to /dev/null (dont display anything)

if [ $? -eq 0 ] #If the previous statement was executed without any error(error code 0), the date is valid
then
    cal $2 $3   #print calender of month and year if date is Valid
else
    echo INVALID DATE ENTERED   #otherwise, date entered is Invalid
fi