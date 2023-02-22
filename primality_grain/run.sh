#!/bin/bash
#SBATCH -N 1
#SBATCH --ntasks 1
./charmrun hello 8 --mca opal_warn_on_missing_libcuda 0
