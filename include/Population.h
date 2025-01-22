#ifndef POPULATION_H
#define POPULATION_H

#include "Individual.h"
#include <vector>

class Population {
public:
  // Constructor of population, variables are size of population, number of
  // genes of each individual and range for the ramdom values of genes
  Population(int size_pop, int num_genes, double low_val, double hi_val);
  // function to print a number of elements of the population
  void show_pop(int num_elem);
  // function that evaluates each individual in the population
  void eval_fit();
  // function that sorts individuals in the population acording their fit.
  void sortbyfit();
  // function to create a new population of M children from N parents
  void new_generation(int N, int M, double prob_mut, double low_val,
                      double hi_val);

private:
  // Vector of objects of class Individual
  std::vector<Individual> individuals;
  // function that initializes a population
  void init_pop(int size_pop, int num_genes, double low_val, double hi_val);
  // function that calculates fitness for a single individual
  double fitness(const std::vector<double> &genes);
  // function that selects the best N individuals in a population
  std::vector<Individual> selection(int N);
  // function for crossing genes from two parents
  Individual crossover(const Individual &A, const Individual &B);
  // function to mutate individual's genes
  void mutation(Individual &individuo, double mutpb, double low_val,
                double hi_val);
};

#endif
