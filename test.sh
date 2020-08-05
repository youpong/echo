#!/bin/bash

function error() {
    echo "$@" >&2
    exit 1
}

# message args 
function assert() {
    msg=$1
    shift
    ./echo "$@" > tmp.0
    echo "$@" > tmp.1
    if ! cmp tmp.0 tmp.1; then
	error $msg
    fi
}


assert "Error: $LINENO"
assert "Error: $LINENO" ''
assert "Error: $LINENO" a bc def

# test for escape:
#   note: '\' tail of string is '\'
assert "Error: $LINENO" -e '' 'a' '\' '\t' '\n' '\\'

# '-e' in middle of args is just argument but option.
assert "Error: $LINENO" a -e '\t'

# '\a' equivarent to just 'a'
# supportted escape character is just '\t', '\n' and '\\' 
echo 'a' > tmp.0
./echo -e '\a' | cmp - tmp.0 || error "Error: expected 'a'"

echo "Ok." 
rm tmp.{0,1}
