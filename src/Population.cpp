#include "Population.h"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <random>
#include <stdexcept>

Population::Population(int size_pop, int num_genes, double low_val,
                       double hi_val)
    : individuals(size_pop, Individual(num_genes, low_val, hi_val)) {
  init_pop(size_pop, num_genes, low_val, hi_val);
}

void Population::init_pop(int size_pop, int num_genes, double low_val,
                          double hi_val) {
  individuals.reserve(size_pop);
  for (int i = 0; i < size_pop; ++i) {
    individuals.emplace_back(num_genes, low_val, hi_val);
    // equivalent to individuals.push_back(Individual(num_genes, low_val,
    // hi_val)) without copy and movement of the object
  }
}

void Population::show_pop(int num_elem) {
  int max_elem;
  if (num_elem >= individuals.size()) {
    max_elem = individuals.size();
  } else {
    max_elem = num_elem;
  }
  for (int i = 0; i < max_elem; ++i) {
    std::cout << "\nIndividual " << i + 1
              << " with fit = " << individuals[i].fit << ":" << std::endl;
    for (double gen : individuals[i].genes) {
      std::cout << gen << ", ";
    }
  }
  std::cout << "\n\n" << std::endl;
}

double Population::fitness(const std::vector<double> &genes) {
  double valor = 0.0;
  for (double gen : genes) {
    valor += pow(gen, 2);
  }
  return valor;
}

void Population::eval_fit() {
  for (int i = 0; i < individuals.size(); i++) {
    individuals[i].fit = fitness(individuals[i].genes);
  }
}

void Population::sortbyfit() {
  sort(individuals.begin(), individuals.end(),
       [](const Individual &a, const Individual &b) { return a.fit > b.fit; });
}

std::vector<Individual> Population::selection(int N) {
  if (N < 2 || N > individuals.size()) {
    throw std::invalid_argument("The number of parents must be greater than or "
                                "equal two, and less that the population size");
  }
  std::vector<Individual> best;
  best.push_back(individuals[0]);
  int c = 1;
  int i = 1;
  while (c < N && i < individuals.size()) {
    if (individuals[i].fit != best[c - 1].fit) {
      best.push_back(individuals[i]);
      c++;
    }
    i++;
  }
  if (best.size() < N) {
    std::cerr << "The size of selection:" << best.size()
              << "is less than the number of parents";
  }
  return best;
}

Individual Population::crossover(const Individual &A, const Individual &B) {
  if (A.genes.size() != B.genes.size()) {
    throw std::runtime_error("Parents must have the same number of genes");
  }
  int num_genes = A.genes.size();
  int punto_cruce;
  Individual child(num_genes);

  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_int_distribution<int> distribution(1,
                                                  num_genes - 1); // Cross point
  punto_cruce = distribution(generator);

  for (int i = 0; i < num_genes; ++i) {
    if (i < punto_cruce) {
      child.genes[i] = A.genes[i];
    } else {
      child.genes[i] = B.genes[i];
    }
  }
  return child;
}

void Population::mutation(Individual &individuo, double mutpb, double low_val,
                          double hi_val) {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_real_distribution<double> distribution(low_val, hi_val);
  std::uniform_real_distribution<double> probabilidad(0.0, 1.0);

  for (int i = 0; i < individuo.genes.size(); i++) {
    if (probabilidad(generator) < mutpb) {
      individuo.genes[i] = distribution(generator);
    }
  }
}

// N -> number of parents
void Population::new_generation(int N, int size_pop, double prob_mut,
                                double low_val, double hi_val) {
  std::vector<Individual> new_pop;
  std::vector<Individual> best = selection(N);
  new_pop.reserve(size_pop);

  if (size_pop < N) {
    for (int i = 0; i < size_pop; i++) {
      new_pop.emplace_back(best[i]);
    }
  } else {
    for (int i = 0; i < N; i++) {
      new_pop.emplace_back(best[i]);
    }

    for (int i = N; i < size_pop; i++) {
      int padre1_idx = rand() % N;
      int padre2_idx = rand() % N;
      while (padre2_idx ==
             padre1_idx) { // To ensure that they are not the same index
        padre2_idx = rand() % N;
      }
      if (best[padre1_idx].fit == best[padre2_idx].fit) {
        throw std::runtime_error("The parents have the same rank/fit.");
      }
      Individual child = crossover(best[padre1_idx], best[padre2_idx]);

      mutation(child, prob_mut, low_val, hi_val);

      new_pop.emplace_back(child);
    }
    individuals = new_pop;
  }
}
