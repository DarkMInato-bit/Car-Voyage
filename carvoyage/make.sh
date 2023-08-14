#!/bin/bash

SRC_DIR=src
HEADER_DIR=header
OUT_DIR=out

# Create the output directory if it doesn't exist
mkdir -p "$OUT_DIR"

# Compile and link
if g++ -o out"/car" \
    "$SRC_DIR/carvoyage.cpp" \
    "$SRC_DIR/customer.cpp" \
    "$SRC_DIR/menu.cpp" \
    "$SRC_DIR/login.cpp" \
    "$SRC_DIR/renter.cpp" \
    -I "$HEADER_DIR"; then

    # Run the program
    cd out
    ./car
    echo "Compilation and execution completed."

else
    echo "Compilation failed."
fi

