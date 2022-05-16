my_program=$1
echo ${my_program}

# test1
# nvcc ${my_program} -arch=compute_35 -code=sm_35

# test2
# nvcc ${my_program} -gencode arch=compute_35,code=compute_35

# test3
nvcc ${my_program} -arch=sm_35