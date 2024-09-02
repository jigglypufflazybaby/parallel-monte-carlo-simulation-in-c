#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define NUM_SAMPLES 100000000

int main() {
    int num_threads;
    int num_hits = 0;

    
    #pragma omp parallel
    {
        num_threads = omp_get_num_threads();
    }

    printf("Running Monte Carlo simulation with %d threads...\n", num_threads);

    
    #pragma omp parallel reduction(+:num_hits)
    {
        
        srand(omp_get_thread_num());

        
        for (int i = 0; i < NUM_SAMPLES / num_threads; i++) {
            double x = (double)rand() / RAND_MAX;
            double y = (double)rand() / RAND_MAX;

            if (x * x + y * y <= 1) {
                num_hits++;
            }
        }
    }

    double pi_estimate = 4.0 * num_hits / NUM_SAMPLES;
    printf("Estimated value of pi: %f\n", pi_estimate);

    return 0;
}