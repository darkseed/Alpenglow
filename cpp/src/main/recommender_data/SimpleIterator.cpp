/*
 * SimpleIterator.cpp
 *
 */

#include "SimpleIterator.h"

RecDat* SimpleIterator::next() {
  return recommender_data_->get(counter_++);
}

RecDat* SimpleIterator::get(int index) const {
  if(index>=counter_) throw exception();
  return recommender_data_->get(index);
}

RecDat* SimpleIterator::get_future(int index) const {
  return recommender_data_->get(index);
}

double SimpleIterator::get_following_timestamp() const {
  if(counter_ < recommender_data_->size()){
    RecDat* next = recommender_data_->get(counter_);
    return next->time;
  } else {
    return -1;
  }
}
