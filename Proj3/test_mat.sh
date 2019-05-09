#!/bin/sh

set -v

./matrix_math -inp A
./matrix_math -inp A -out XX
cat XX.mtx
./matrix_math -add A A -out ZZ
cat ZZ.mtx


./matrix_math -add A B
./matrix_math -add A A
./matrix_math -sub B A
./matrix_math -sub B B
./matrix_math -mul A A
./matrix_math -mul B A
./matrix_math -mul F F3


./matrix_math -eq A A
./matrix_math -eq A B


./matrix_math -smul A 5
./matrix_math -smul A 0

./matrix_math -sdiv A 5
./matrix_math -sdiv A 0

./matrix_math -h

