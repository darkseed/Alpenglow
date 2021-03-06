#include "UniformNegativeSampleGenerator.h"

vector<int>* UniformNegativeSampleGenerator::generate(RecDat* rec_dat){
  if(!filter_repeats_){
    int learnt = 0;
    samples.clear();
    int user_activity = train_matrix_->row_size(rec_dat->user);
    while(learnt < negative_rate_ && learnt<(int)items_->size()-user_activity){
      int item = items_->at((int)(rnd_.get()*(items_->size())));
      if(!train_matrix_->has_value(rec_dat->user,item)){
        learnt++;
        samples.push_back(item);
      }
    }  
    return &samples;
  } else {
    int number_of_generated = 0;
    int available = items_->size();
    samples.clear();
    while(number_of_generated < negative_rate_ && available>0){
      int idx = ((int)(rnd_.get()*available));
      int item = items_->at(idx);
      if(!train_matrix_->has_value(rec_dat->user,item)){
        number_of_generated++;
        samples.push_back(item);
      }
      items_->at(idx)=items_->at(available-1);
      items_->at(available-1) = item;
      available--;
    }  
    return &samples;
  }
}

