#ifndef GLOBAL_NEGATIVE_AND_POSITIVE_SAMPLE_GENERATOR
#define GLOBAL_NEGATIVE_AND_POSITIVEsSAMPLE_GENERATOR

#include <gtest/gtest_prod.h>
#include "../utils/Random.h"
#include "NegativeSampleGenerator.h"

struct GlobalPositiveAndNegativeSampleGeneratorParameters{ 
    double positive_rate,negative_rate,decay;
    bool initialize_all;
    int max_item;
    int seed; 
    int threshold;
    string decay_type;
};

class GlobalPositiveAndNegativeSampleGenerator : public NegativeSampleGenerator {
  public: 
    GlobalPositiveAndNegativeSampleGenerator(GlobalPositiveAndNegativeSampleGeneratorParameters * parameters){
      set_parameters(parameters);
    };
    void set_parameters (GlobalPositiveAndNegativeSampleGeneratorParameters * parameters);
    void set_train_matrix(SpMatrix* train_matrix_){train_matrix=train_matrix_;}
    void set_items(vector<int>* items_){ if(!initialize_all) items=items_;}
    vector <int> * generate(RecDat * rec_dat);
    void generate_positive(RecDat * rec_dat);
    vector<RecDat>*  get_implicit_train_data(RecDat* positive_sample);
    void update(RecDat* rec_dat);
  protected:
    int select(int user);
    vector <int> * items;
    vector <int> positive_relevances;
    vector <RecDat *> positive_samples;
    SpMatrix * train_matrix;
    vector<RecDat *> history;
    double positive_rate,negative_rate;
    bool initialize_all;
    int max_item;
    double decay; 
    int seed_;
    Random random_;
    int threshold;
    string decay_type;
};

#endif
