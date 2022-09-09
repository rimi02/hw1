#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"
using namespace std;



ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

 void ULListStr::push_back(const std::string& val)
{
  Item *temp = new Item;
  temp->val = val;
  temp->next = NULL;
  if(head_ == NULL){
    head_ = temp;
    tail_ = temp;
  }
  else{
    tail_->next = temp;
    tail_ = temp;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val)
{
  Item *temp = new Item;
  temp->val = val;
  temp->next = head_;
  head_ = temp;
  if(tail_ == NULL){
    tail_ = temp;
  }
  size_++;
}

void ULListStr::pop_back()
{
  if(head_ == NULL){
    throw std::invalid_argument("Bad location");
  }
  else if(head_ == tail_){
    delete head_;
    head_ = NULL;
    tail_ = NULL;
  }
  else{
    Item *temp = head_;
    while(temp->next != tail_){
      temp = temp->next;
    }
    delete tail_;
    tail_ = temp;
    tail_->next = NULL;
  }
  size_--;
}

void ULListStr::pop_front()
{
  if(head_ == NULL){
    throw std::invalid_argument("Bad location");
  }
  else if(head_ == tail_){
    delete head_;
    head_ = NULL;
    tail_ = NULL;
  }
  else{
    Item *temp = head_;
    head_ = head_->next;
    delete temp;
  }
  size_--;
}

std::string const & ULListStr::back() const
{
  if(tail_ == NULL){
    throw std::invalid_argument("Bad location");
  }
  return tail_->val;
}

std::string const & ULListStr::front() const
{
  if(head_ == NULL){
    throw std::invalid_argument("Bad location");
  }
  return head_->val;
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc >= size_){
    return NULL;
  }
  Item *temp = head_;
  for(size_t i = 0; i < loc; i++){
    temp = temp->next;
  }
  return &(temp->val);
}