#!/bin/bash
# generated with the help of ai

# This makes the loop do nothing if a folder has no .in files,
# instead of processing the literal string "*.in"
shopt -s nullglob

# Loop over the directory names
for dir in tiny small medium big
do
    # Loop over all files ending in .in inside that directory
    for file in "$dir"/*.in
    do
        echo $file
        ./trz.e < $file > ${file%.in}.out
    done
done