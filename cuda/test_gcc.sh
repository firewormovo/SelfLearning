my_program=$1

# split
IFS='/ .'
read -ra LIST <<< "${my_program}" 
F=${LIST[-2]}
IFS=' '

# print
echo ${F}

# generate
gcc -o ${F} ${my_program}

