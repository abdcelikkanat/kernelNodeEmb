//
//
//

#ifndef FAST_BERN_MODEL_H
#define FAST_BERN_MODEL_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <random>
#include <iomanip>
#include "math.h"
#include "Unigram.h"
#include "Vocabulary.h"
#include <algorithm>

using namespace std;

class Model {

private:
    string corpusFile, kernel;
    unsigned int dim_size, window_size, negative_sample_size, num_of_iters;
    double sigma, lr, min_lr, decay_rate, lambda;

    unsigned long vocab_size;
    unordered_map <string, int> node2Id;
    vector <Node> vocab_items;
    int total_nodes;
    double **emb0, **emb1;

    default_random_engine generator;
    Unigram uni;

public:

    Model(string &corpusFile, string &kernel, double &sigma,
          unsigned int &dimension, unsigned int &window, unsigned int &neg,
          double &lr, double &min_lr, double &decay_rate, double &lambda, unsigned int &iter);
    ~Model();
    double sigmoid(double z);
    void update_rule_gaussian_kernel(vector <double> labels, int centerId, vector <int> contextIds, double current_lr);
    void inf_poly_kernel(double alpha, vector <double> labels, int centerId, vector <int> contextIds);
    void run();
    void save_embeddings(string file_path);
    void save_embeddings(string file_path, int layerId);


};



#endif //FAST_BERN_MODEL_H
