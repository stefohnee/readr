#ifndef FASTREAD_HSTREAMSTRING_H
#define FASTREAD_HSTREAMSTRING_H

#include <Rcpp.h>

class StreamString {
  Rcpp::RObject string_;
  int pos_, row_, col_;
  size_t size_;
  const char* addr_;

public:

  StreamString(Rcpp::CharacterVector x) : pos_(0), row_(0), col_(0) {
    string_ = x[0];
    size_ = Rf_length(string_);
    addr_ = CHAR(string_);
  }

  std::string getString(int start, int end) {
    return std::string(addr_ + start, end - start);
  }

  int pos() {
    return pos_;
  }

  char get() {
    if (pos_ >= size_)
      return EOF;

    return addr_[pos_++];
  }

  char peek() {
    if (pos_ >= size_)
      return EOF;

    return addr_[pos_];
  }

  void nextRow() {
    row_++;
    col_ = 0;
  }
  void nextCol() {
    col_++;
  }
  int col() {
    return col_;
  }
  int row() {
    return row_;
  }

};

#endif