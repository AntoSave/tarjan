/* 
 * Course: High Performance Computing 2022/2023 
 * 
 * Lecturer: Francesco Moscato  fmoscato@unisa.it 
 *
 * Group:
 * Langella	Antonio   0622702011   a.langella31@studenti.unisa.it
 * Marsico Michele   0622702012   m.marsico10@studenti.unisa.it
 * Paolino Salvatore   0622702016   s.paolino6@studenti.unisa.it 
 * Risi Davide   0622702013   d.risi2@studenti.unisa.it
 * 
 * Copyright (C) 2023 - All Rights Reserved 
 *
 * This file is part of Parallelize-Tarjan-MPI-CUDA. 
 *
 * Parallelize-Tarjan-MPI-CUDA is free software: you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, or 
 * (at your option) any later version. 
 *
 * Parallelize-Tarjan-MPI-CUDA is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * GNU General Public License for more details. 
 *
 * You should have received a copy of the GNU General Public License 
 * along with Parallelize-Tarjan-MPI-CUDA.  If not, see <http://www.gnu.org/licenses/>. 
 * 
 */

/**
 * @file random.c
 * @brief ....
 */

#include "random.h"
#include <stdlib.h>
#include <math.h>

/**
 * @brief Extract a random variable distributed with Bernoulli distribution. The variable takes the value 1 with probability p and 0 with probability 1-p.
 * 
 * @param p probability of the variable assuming the value 1
 * @return the random variable 
 */
int rand_bernoulli(double p){
    double r = (double) rand() / RAND_MAX; //random number between 0.0 and 1.0
    return r < p;
}

/**
 * @brief Extract a random variable distributed with Binomial distribution. A binomial variable is generated by exectuing n Bernoulli experiments with a fixed  probability p and counting the numbersuccesses.
 * @param n number of experiments
 * @param p probability of the variable assuming the value 1
 * @return the random variable 
 */
int rand_binomial(long n, double p){
    int acc = 0;
    for(int i=0; i<n; i++){
        acc += rand_bernoulli(p);
    }
    return acc;
}

/**
 * @brief Extract a random variable distributed with Binomial distribution with a given mean and variance.
 * @param mean the mean of the Binomial distibution
 * @param variance the variance of the Binomial distibution
 * @return the random variable 
 */
int rand_binomial_2(int mean, double variance){
    double p = 1 - variance/mean;
    long n = lround(mean/p);
    return rand_binomial(n,p);
}