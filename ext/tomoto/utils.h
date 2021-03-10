#pragma once

#include <rice/rice.hpp>

using Rice::Array;
using Rice::Object;

namespace Rice::detail
{
  template<>
  struct To_Ruby<std::vector<tomoto::Float>>
  {
    static VALUE convert(std::vector<tomoto::Float> const & x)
    {
      Array res;
      for (auto const& v : x) {
        res.push(v);
      }
      return res;
    }
  };

  template<>
  struct To_Ruby<std::vector<uint32_t>>
  {
    static VALUE convert(std::vector<uint32_t> const & x)
    {
      Array res;
      for (auto const& v : x) {
        res.push(v);
      }
      return res;
    }
  };

  template<>
  struct To_Ruby<std::vector<uint64_t>>
  {
    static VALUE convert(std::vector<uint64_t> const & x)
    {
      Array res;
      for (auto const& v : x) {
        res.push(v);
      }
      return res;
    }
  };

  template<>
  struct From_Ruby<std::vector<std::string>>
  {
    static std::vector<std::string> convert(VALUE x)
    {
      Array a = Array(x);
      std::vector<std::string> res(a.size());
      for (long i = 0; i < a.size(); i++) {
        res[i] = Rice::detail::From_Ruby<std::string>::convert(a[i].value());
      }
      return res;
    }
  };

  template<>
  struct From_Ruby<std::vector<tomoto::Float>>
  {
    static std::vector<tomoto::Float> convert(VALUE x)
    {
      Array a = Array(x);
      std::vector<tomoto::Float> res(a.size());
      for (long i = 0; i < a.size(); i++) {
        res[i] = Rice::detail::From_Ruby<tomoto::Float>::convert(a[i].value());
      }
      return res;
    }
  };

  template<>
  struct From_Ruby<std::vector<uint64_t>>
  {
    static std::vector<uint64_t> convert(VALUE x)
    {
      Array a = Array(x);
      std::vector<uint64_t> res(a.size());
      for (long i = 0; i < a.size(); i++) {
        res[i] = Rice::detail::From_Ruby<uint64_t>::convert(a[i].value());
      }
      return res;
    }
  };
}

inline tomoto::RawDoc buildDoc(Object words) {
  tomoto::RawDoc doc;
  doc.rawWords = Rice::detail::From_Ruby<std::vector<std::string>>::convert(words.value());
  return doc;
}
