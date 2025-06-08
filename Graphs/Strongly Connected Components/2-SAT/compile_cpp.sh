#!/bin/bash

clear

PROBLEM="2-SAT"

g++-14 ${PROBLEM}.cpp -o ${PROBLEM}

./${PROBLEM}

echo
echo