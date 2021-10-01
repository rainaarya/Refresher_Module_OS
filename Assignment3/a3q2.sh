#!/bin/bash

add() {
    sum=0
    for number in "$@"; do
        ((sum += number))
    done
    echo Sum is $sum
}

sub() {
    subval=$1
    for number in "${@:2}"; do
        ((subval -= number))
    done
    echo Subtraction is $subval
}

mul() {
    mulval=1
    for number in "$@"; do
        ((mulval *= number))
    done
    echo Multiplication is $mulval
}

div() {
    divval=$1
    for number in "${@:2}"; do
        ((divval /= number))
    done
    echo Integer Division is $divval
}

exp() {
    expval=$1
    for number in "${@:2}"; do
        ((expval = expval ** number))
    done
    echo Exponentiation is $expval
}

case $1 in

add)
    add "${@:2}" # pass all arguments after command 'add'
    ;;

sub)
    sub "${@:2}" # pass all arguments after command 'sub'
    ;;

mul)
    mul "${@:2}" # pass all arguments after command 'mul'
    ;;

div)
    div "${@:2}" # pass all arguments after command 'div'
    ;;

exp)
    exp "${@:2}" # pass all arguments after command 'exp'
    ;;

*)
    echo "Invalid Name of First Argument"
    ;;
esac
