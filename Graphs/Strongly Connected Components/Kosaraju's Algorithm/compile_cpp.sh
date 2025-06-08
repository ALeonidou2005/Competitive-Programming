#!/bin/bash

clear

PROBLEM="kosaraju"

g++-14 ${PROBLEM}.cpp -o ${PROBLEM}

./${PROBLEM}

echo
echo