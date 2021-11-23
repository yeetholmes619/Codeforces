#!/bin/bash

read tpe
k="2"

if [ "$tpe" = "$k" ]; then
        echo "Enter file name: "
        python take2.py > o1.sh
        bash o1.sh
else
        echo "Enter file name: "
        python take.py > o1.sh
        bash o1.sh
fi
