#!/bin/bash

add() {
    sum=0
    for number in "$@"; do  #loop over all arguments passed
        ((sum += number))
    done
    echo Sum is $sum
}

sub() {
    subval=$1
    for number in "${@:2}"; do  #loop over all arguments passed after the 1st argument passed
        ((subval -= number))
    done
    echo Subtraction is $subval
}

mul() {
    mulval=1
    for number in "$@"; do     #loop over all arguments passed
        ((mulval *= number))
    done
    echo Multiplication is $mulval
}

div() {
    divval=$1
    for number in "${@:2}"; do #loop over all arguments passed after the 1st argument passed
        ((divval /= number))
    done
    echo Integer Division is $divval
}

exp() {
    expval=$1
    for number in "${@:2}"; do  #loop over all arguments passed after the 1st argument passed
        ((expval = expval ** number))
    done
    echo Exponentiation is $expval
}

case $1 in  #Use switch case on first argument entered

add)  #if the argument was 'add'
    add "${@:2}" # pass all arguments after command 'add'
    ;;

sub)  #if the argument was 'sub'
    sub "${@:2}" # pass all arguments after command 'sub'
    ;;

mul)  #if the argument was 'mul'
    mul "${@:2}" # pass all arguments after command 'mul'
    ;;

div)  #if the argument was 'div'
    div "${@:2}" # pass all arguments after command 'div'
    ;;

exp)  #if the argument was 'exo'
    exp "${@:2}" # pass all arguments after command 'exp'
    ;;

*)  #Otherwise, it means the first argument is Invalid
    echo "Invalid Name of First Argument"
    ;;
esac
