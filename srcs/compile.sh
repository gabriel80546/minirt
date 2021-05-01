#!/bin/bash
compile=`cat warp_compile_sani.sh | echo $(</dev/stdin)`
compile=`cat warp_compile_val.sh | echo $(</dev/stdin)`
compile=`cat warp_compile_val_o.sh | echo $(</dev/stdin)`
echo $compile
$compile
