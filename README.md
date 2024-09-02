# parallel-monte-carlo-simulation-in-c
 A mini project on parallelizing a Monte Carlo simulation using OpenMP. Monte Carlo simulations are often computationally intensive, making them a good candidate for parallelization.

 # Parallel Monte Carlo Simulation to Estimate π

This is a mini project that uses OpenMP to parallelize a Monte Carlo simulation to estimate the value of π.

## Prerequisites

- C compiler with OpenMP support (e.g., GCC with `-fopenmp` flag)

## How to Run

1. Compile the program:
gcc -fopenmp -o monte_carlo monte_carlo.c

2. Run the program:
./monte_carlo

## How it Works

1. The program starts by setting the number of OpenMP threads using `omp_get_num_threads()`.
2. The main parallel region is defined using `#pragma omp parallel`.
3. Inside the parallel region, each thread seeds its random number generator with its own thread ID, and then performs a portion of the total number of samples.
4. The `#pragma omp parallel reduction(+:num_hits)` directive ensures that the `num_hits` variable is correctly updated by all threads, and the final result is the sum of all the thread's partial results.
5. After the parallel region, the estimated value of π is calculated and printed.

## Benefits of Parallelization

Parallelizing the Monte Carlo simulation using OpenMP provides the following benefits:

- **Faster Computation**: By distributing the workload across multiple threads, the program can complete the simulation much faster than a serial implementation.
- **Scalability**: As the number of available cores increases, the program can leverage more parallelism to further improve performance.
- **Efficient Resource Utilization**: The parallel implementation ensures that all available CPU cores are utilized effectively, maximizing the use of system resources.

## Future Improvements

- Implement dynamic scheduling to better handle workload imbalances.
- Explore the use of other parallelization techniques, such as MPI or CUDA, for different hardware architectures.
- Extend the project to include more complex Monte Carlo simulations or other computational problems in high-performance computing.

Feel free to explore and modify the code to suit your needs!
