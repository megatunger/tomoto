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
      std::vector<std::string> res;
      res.reserve(a.size());
      for (auto const& v : a) {
        res.push_back(Rice::detail::From_Ruby<std::string>::convert(v.value()));
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
      std::vector<tomoto::Float> res;
      res.reserve(a.size());
      for (auto const& v : a) {
        res.push_back(Rice::detail::From_Ruby<tomoto::Float>::convert(v.value()));
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
      std::vector<uint64_t> res;
      res.reserve(a.size());
      for (auto const& v : a) {
        res.push_back(Rice::detail::From_Ruby<uint64_t>::convert(v.value()));
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
