#include <HDP.h>

#include <rice/Module.hpp>

#include "utils.h"

void init_hdp(Rice::Module& m) {
  Rice::define_class_under<tomoto::IHDPModel, tomoto::ILDAModel>(m, "HDP")
    .define_singleton_method(
      "_new",
      *[](size_t tw, size_t k, tomoto::Float alpha, tomoto::Float eta, tomoto::Float gamma, int seed) {
        if (seed < 0) {
          seed = std::random_device{}();
        }
        return tomoto::IHDPModel::create((tomoto::TermWeight)tw, k, alpha, eta, gamma, seed);
      })
    .define_method(
      "alpha",
      *[](tomoto::IHDPModel& self) {
        return self.getAlpha();
      })
    .define_method(
      "gamma",
      *[](tomoto::IHDPModel& self) {
        return self.getGamma();
      })
    .define_method(
      "live_k",
      *[](tomoto::IHDPModel& self) {
        return self.getLiveK();
      })
    .define_method(
      "live_topic?",
      *[](tomoto::IHDPModel& self, size_t tid) {
        return self.isLiveTopic(tid);
      })
    .define_method(
      "num_tables",
      *[](tomoto::IHDPModel& self) {
        return self.getTotalTables();
      });
}
