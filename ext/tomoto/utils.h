#pragma once

#include <rice/rice.hpp>

using Rice::Array;
using Rice::Object;

namespace Rice::detail
{
  template<>
  struct To_Ruby<std::vector<tomoto::Float>>
  {
    static Object convert(std::vector<tomoto::Float> const & x)
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
    static Object convert(std::vector<uint32_t> const & x)
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
    static Object convert(std::vector<uint64_t> const & x)
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
    static std::vector<std::string> convert(Object x)
    {
      Array a = Array(x);
      std::vector<std::string> res;
      res.reserve(a.size());
      for (auto const& v : a) {
        res.push_back(from_ruby<std::string>(v));
      }
      return res;
    }
  };

  template<>
  struct From_Ruby<std::vector<tomoto::Float>>
  {
    static Foo convert(std::vector<tomoto::Float> x)
    {
      Array a = Array(x);
      std::vector<tomoto::Float> res;
      res.reserve(a.size());
      for (auto const& v : a) {
        res.push_back(from_ruby<tomoto::Float>(v));
      }
      return res;
    }
  };

  template<>
  struct From_Ruby<std::vector<uint64_t>>
  {
    static std::vector<uint64_t> convert(Object x)
    {
      Array a = Array(x);
      std::vector<uint64_t> res;
      res.reserve(a.size());
      for (auto const& v : a) {
        res.push_back(from_ruby<uint64_t>(v));
      }
      return res;
    }
  };
}

inline tomoto::RawDoc buildDoc(std::vector<std::string>& words) {
  tomoto::RawDoc doc;
  doc.rawWords = words;
  return doc;
}
