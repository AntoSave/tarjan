#include "random.h"
#include <stdlib.h>
#include <math.h>

//Return 1 with probability p, 0 otherwise
int rand_bernoulli(double p){
    double r = rand() / RAND_MAX; //random number between 0.0 and 1.0
    return r < p;
}

//A binomial variable is generated by exectuing n bernoulli experiments with a fixed p and counting the successes
int rand_binomial(long n, double p){
    int acc = 0;
    for(int i=0; i<n; i++){
        acc += rand_bernoulli(p);
    }
    return acc;
}

int rand_binomial_2(int mean, double variance){
    double p = 1 - variance/mean;
    long n = lround(mean/p);
    return rand_binomial(n,p);
}