#include <rice/rice.hpp>

void init_lda(Rice::Module& m);
void init_slda(Rice::Module& m);

extern "C"
void Init_ext()
{
  auto m = Rice::define_module("Tomoto")
    .define_singleton_function(
      "isa",
      []() {
        #ifdef __AVX2__
          return "avx2";
        #elif defined(__AVX__)
          return "avx";
        #elif defined(__SSE2__) || defined(__x86_64__) || defined(_WIN64)
          return "sse2";
        #else
          return "none";
        #endif
      });

  init_lda(m);
  init_slda(m);
}
