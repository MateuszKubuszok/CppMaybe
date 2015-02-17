#ifndef MAYBE_HPP_INCLUDED
#define MAYBE_HPP_INCLUDED

#include <functional>
#include <vector>

namespace maybe {

template <class Type>
class Maybe {
 public:
  typedef std::vector<void*> Absence;
  typedef std::vector<Type>  Presence;

  static Maybe absent() { return Maybe(); }
  static Maybe present(Type value) { return Maybe(value); }

  bool isAbsent() const { return presence_.empty(); }
  bool isPresent() const { return !presence_.empty(); }

  Absence forAbsent() const { return absence_; }
  Presence forPresent() const { return presence_; }

  template <class Callback>
  const Maybe& ifAbsent(Callback callback) const {
    if (isAbsent())
      callback();
    return *this;
  }

  template <class Callback>
  const Maybe& ifPresent(Callback callback) const {
    if (isPresent())
      callback(presence_[0]);
    return *this;
  }

 private:
  const Absence  absence_;
  const Presence presence_;

  Maybe():           absence_(1, nullptr), presence_() {}
  Maybe(Type value): absence_(),           presence_(1, value) {}
};

}  // namespace maybe

#endif  // MAYBE_HPP_INCLUDED
