#include "Population.h"
#include <iostream>

int main() {
  int num_generations = 50;
  int size_pob = 50;
  int num_genes = 10;
  double mutpb = 0.2;   // mutation probability
  double low_val = 0.0; // Lowest value for the range of gene values
  double hi_val = 1.0;  // Highest value --
  int n_parents = 2;    // Number of parents in each new generation

  Population population(size_pob, num_genes, low_val,
                        hi_val); // Create population
  population.eval_fit();         // Evaluate population
  population.sortbyfit();        // Sort by fit value

  for (int ng = 0; ng < num_generations; ng++) {
    std::cout << "------------------- Generation: " << ng
              << "-------------------" << std::endl;
    std::cout << "Best 3 Individuals:" << "\n";
    population.show_pop(3); // Show 3 elements of population
    population.new_generation(n_parents, size_pob, mutpb, low_val, hi_val);
    population.eval_fit();
    population.sortbyfit();
  }
  return 0;
}
