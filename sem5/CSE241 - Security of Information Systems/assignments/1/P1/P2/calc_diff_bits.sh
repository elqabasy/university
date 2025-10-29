#!/bin/bash

quick_bit_diff() {
    echo -n "$1" | xxd -b | cut -d' ' -f2-7 | tr -d ' \n' > /tmp/bits1
    echo -n "$2" | xxd -b | cut -d' ' -f2-7 | tr -d ' \n' > /tmp/bits2
    
    # Pad shorter string with zeros
    len1=$(wc -c < /tmp/bits1)
    len2=$(wc -c < /tmp/bits2)
    max_len=$((len1 > len2 ? len1 : len2))
    
    printf "%-*s" $max_len "$(cat /tmp/bits1)" | tr ' ' '0' > /tmp/bits1_pad
    printf "%-*s" $max_len "$(cat /tmp/bits2)" | tr ' ' '0' > /tmp/bits2_pad
    
    diff_count=0
    for ((i=0; i<max_len; i++)); do
        bit1=$(cat /tmp/bits1_pad | cut -c$((i+1)))
        bit2=$(cat /tmp/bits2_pad | cut -c$((i+1)))
        [ "$bit1" != "$bit2" ] && diff_count=$((diff_count + 1))
    done
    
    echo "Bits changed: $diff_count/$max_len"
    rm -f /tmp/bits1 /tmp/bits2 /tmp/bits1_pad /tmp/bits2_pad
}



quick_bit_diff $1 $2
